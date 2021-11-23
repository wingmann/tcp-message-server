#include "connection.h"

Connection::Connection(QObject* parent) : QObject{parent}, socket_{new QTcpSocket{this}}
{
    connect(socket_, &QTcpSocket::readyRead, this, &Connection::onReadyRead);
    connect(socket_, &QTcpSocket::disconnected, this, &Connection::onDisconnected);
}

Connection::Connection(QObject* parent, QTcpSocket* socket) : QObject{parent}, socket_{socket}, isValid_{true}
{
    connect(socket_, &QTcpSocket::readyRead, this, &Connection::onReadyRead);
    connect(socket_, &QTcpSocket::disconnected, this, &Connection::onDisconnected);
}

const bool& Connection::isValid() const
{
    return isValid_;
}

void Connection::sendMessage(const QString& message)
{
    QByteArray data;
    QDataStream dataStream(&data, QTcpSocket::WriteOnly);
    dataStream.setVersion(QDataStream::Qt_DefaultCompiledVersion);

    // Placeholder for block size.
    dataStream << std::uint16_t{};

    // Append the message.
    dataStream << message;

    // Go back to beginning.
    dataStream.device()->seek(0);

    // Overwrite placeholder with actual block size.
    dataStream << static_cast<uint16_t>(data.size() - sizeof(std::uint16_t));

    socket_->write(data);
}

bool Connection::connectTo(const QString& host, std::uint16_t port)
{
    socket_->connectToHost(host, port);
    return isValid_ = socket_->waitForConnected(5000);
}

void Connection::onReadyRead()
{
    QDataStream receive(socket_);
    receive.setVersion(QDataStream::Qt_DefaultCompiledVersion);

    // On first call: only read the block size.
    if (!blockSize_)
    {
        if (socket_->bytesAvailable() < sizeof(std::uint16_t))
            return;
        receive >> blockSize_;
    }

    // Partial data received?
    if (socket_->bytesAvailable() < blockSize_)
        return;

    // At this point: all data received, we can process it.
    QString message;
    receive >> message;

    emit messageReceived(message);

    // Reset for next message.
    blockSize_ = 0;
}

void Connection::onDisconnected()
{
    isValid_ = false;
    socket_->deleteLater();
    socket_ = nullptr;
}

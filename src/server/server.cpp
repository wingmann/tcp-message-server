#include "server.h"

Server::Server(QObject* parent) : QObject{parent}
{
}

bool Server::startListening(const uint16_t& port)
{
    bool isListening{};

    if (!server_)
    {
        server_ = new QTcpServer{this};
        isListening = server_->listen(QHostAddress::AnyIPv4, port);

        if (isListening)
            connect(server_, &QTcpServer::newConnection, this, &Server::onNewConnection);
    }
    return isListening;
}

void Server::sendMessage(const QString& message)
{
    for (Connection* connection : connections_)
        if (connection->isValid())
            connection->sendMessage(message);
}

void Server::onNewConnection()
{
    auto connection = new Connection{this, server_->nextPendingConnection()};
    connections_.insert(connection);
    connect(connection, &Connection::messageReceived, this, &Server::onMessageReceived);
}

void Server::onMessageReceived(const QString& message)
{
    emit messageReceived(message);
}

#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QString>
#include <QtNetwork/QTcpSocket>

class Connection : public QObject {
private:
    Q_OBJECT

    QTcpSocket* socket_;
    std::uint16_t blockSize_{};
    bool isValid_{};

public:
    /**
     * @brief Constructor for client usage.
     * @param parent
     */
    explicit Connection(QObject* parent = nullptr);

    /**
     * @brief Constructor for server usage.
     * @param parent
     * @param socket
     */
    Connection(QObject* parent, QTcpSocket* socket);

    [[nodiscard]] const bool& isValid() const;
    void sendMessage(const QString& message);
    bool connectTo(const QString& host, std::uint16_t port);

private slots:
    void onReadyRead();
    void onDisconnected();

signals:
    void messageReceived(QString message);
};

#endif // CONNECTION_H

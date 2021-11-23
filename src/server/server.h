#ifndef SERVER_H
#define SERVER_H

#include "connection.h"

#include <QObject>
#include <QSet>
#include <QString>
#include <QtNetwork/QTcpServer>

/// @brief TCP Server implementation.
class Server final : public QObject
{
private:
    Q_OBJECT

    QTcpServer* server_{};
    QSet<Connection*> connections_{};

public:
    /// @brief Constructor.
    /// @param parent Pointer to the parent object initialization.
    explicit Server(QObject* parent = nullptr);

    bool startListening(const std::uint16_t& port);

    void sendMessage(const QString& message);

private slots:
    void onNewConnection();

    // All clients connected here.
    void onMessageReceived(const QString& message);

signals:
    void messageReceived(const QString& message);
};

#endif // SERVER_H

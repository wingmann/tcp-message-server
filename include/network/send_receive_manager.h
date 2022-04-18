#ifndef MANAGER_H
#define MANAGER_H

#include "client.h"
#include "server.h"

#include <QMainWindow>

namespace Ui { class SendReceiveManager; }

/**
 * Manager for sending and receiving messages from client to server and vice versa.
 */
class SendReceiveManager final : public QMainWindow {
    Q_OBJECT

    /**
     * Member object of graphical interface class.
     */
    Ui::SendReceiveManager* ui_{};

    Server* server_{};
    Client* client1_{};
    Client* client2_{};

public:
    /**
     * Constructor.
     * @param parent Pointer to the parent object initialization.
     */
    explicit SendReceiveManager(QWidget* parent = nullptr);
    ~SendReceiveManager() override;

private slots:
    void on_serverLineEdit_returnPressed();
    void on_clientLineEdit1_returnPressed();
    void on_clientLineEdit2_returnPressed();

    void onServerMessageReceived(const QString& message);
    void onClient1MessageReceived(const QString& message);
    void onClient2MessageReceived(const QString& message);
};

#endif // MANAGER_H

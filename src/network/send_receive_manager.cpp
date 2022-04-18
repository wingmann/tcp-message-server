#include "send_receive_manager.h"
#include "./ui_send_receive_manager.h"

SendReceiveManager::SendReceiveManager(QWidget* parent)
    : QMainWindow{parent},
      ui_{new Ui::SendReceiveManager}
{
    const char address[]{"localhost"};
    const std::uint16_t port{8080};

    ui_->setupUi(this);

    server_ = new Server{this};
    ui_->serverListWidget->addItem(server_->startListening(port)
        ? "Server started."
        : "Server failed to start.");

    client1_ = new Client{this};
    ui_->clientListWidget1->addItem(client1_->connectTo(address, port)
        ? "Connected."
        : "Failed to connect.");

    client2_ = new Client{this};
    ui_->clientListWidget2->addItem(client2_->connectTo(address, port)
        ? "Connected."
        : "Failed to connect.");

    connect(server_, &Server::messageReceived, this, &SendReceiveManager::onServerMessageReceived);
    connect(client1_, &Client::messageReceived, this, &SendReceiveManager::onClient1MessageReceived);
    connect(client2_, &Client::messageReceived, this, &SendReceiveManager::onClient2MessageReceived);
}

SendReceiveManager::~SendReceiveManager()
{
    delete ui_;
}

void SendReceiveManager::on_serverLineEdit_returnPressed()
{
    server_->sendMessage(ui_->serverLineEdit->text());
    ui_->serverListWidget->addItem(ui_->serverLineEdit->text());
    ui_->serverLineEdit->clear();
}

void SendReceiveManager::on_clientLineEdit1_returnPressed()
{
    client1_->sendMessage(ui_->clientLineEdit1->text());
    ui_->clientListWidget1->addItem(ui_->clientLineEdit1->text());
    ui_->clientLineEdit1->clear();
}

void SendReceiveManager::on_clientLineEdit2_returnPressed()
{
    client2_->sendMessage(ui_->clientLineEdit2->text());
    ui_->clientListWidget2->addItem(ui_->clientLineEdit2->text());
    ui_->clientLineEdit2->clear();
}

void SendReceiveManager::onServerMessageReceived(const QString& message)
{
    ui_->serverListWidget->addItem(message);
}

void SendReceiveManager::onClient1MessageReceived(const QString& message)
{
    ui_->clientListWidget1->addItem(message);
}

void SendReceiveManager::onClient2MessageReceived(const QString& message)
{
    ui_->clientListWidget2->addItem(message);
}

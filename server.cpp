#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    server->listen(QHostAddress::Any, 1234);
}

void Server::newConnection()
{
    while (server->hasPendingConnections()) {
        QTcpSocket *client = server->nextPendingConnection();
        connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
        connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
        clients.append(client);
    }
}

void Server::readyRead()
{
    QTcpSocket *sender = qobject_cast<QTcpSocket *>(QObject::sender());
    QByteArray data = sender->readAll();
    for (int i = 0; i < clients.size(); i++) {
        if (clients.at(i) != sender) {
            clients.at(i)->write(data);
        }
    }
}

void Server::disconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    clients.removeOne(client);
    client->deleteLater();
}

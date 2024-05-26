#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:

public slots:
    void newConnection();
    void readyRead();
    void disconnected();

private:
    QTcpServer *server;
    QList<QTcpSocket *> clients;
};

#endif // SERVER_H

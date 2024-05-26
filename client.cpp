#include "client.h"

Client::Client(QWidget *parent) : QWidget(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    messagesTextEdit = new QTextEdit(this);
    messagesTextEdit->setReadOnly(true);
    messageLineEdit = new QLineEdit(this);
    sendButton = new QPushButton("Отправить", this);
    layout = new QVBoxLayout(this);

    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));

    layout->addWidget(messagesTextEdit);
    layout->addWidget(messageLineEdit);
    layout->addWidget(sendButton);

    setLayout(layout);

    socket->connectToHost("127.0.0.1", 1234);
}

void Client::connected()
{
    qDebug() << "Соединение установлено";
}

void Client::readyRead()
{
    QByteArray data = socket->readAll();
    QString message = QString::fromLatin1(data);
    messagesTextEdit->append(QString("Interlocutor: %1").arg(message));
}

void Client::sendMessage()
{
    QString message = messageLineEdit->text();
    socket->write(message.toLatin1());
    messagesTextEdit->append(QString("You: %1").arg(message));
    messageLineEdit->clear();
}

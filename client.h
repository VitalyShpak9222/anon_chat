#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);

signals:

public slots:
    void connected();
    void readyRead();
    void sendMessage();

private:
    QTcpSocket *socket;
    QTextEdit *messagesTextEdit;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;
    QVBoxLayout *layout;
};

#endif // CLIENT_H

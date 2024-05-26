#include "client.h"
#include "server.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Server server;
    Client client1;
    Client client2;
    client1.show();
    client2.show();
    return a.exec();
}

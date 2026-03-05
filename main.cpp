#include "test.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QLabel hello(HELLOWORLD);
    hello.setWindowTitle("Qt Cloud Build");
    hello.resize(400, 200);
    hello.setAlignment(Qt::AlignCenter);
    hello.show();
    return app.exec();
}
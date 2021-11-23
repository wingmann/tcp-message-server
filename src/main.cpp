#include "send_receive_manager.h"

#include <QApplication>

int main(int argc, char** argv)
{
#ifdef WIN32
    // Sets the graphical style of the application.
    QApplication::setStyle("fusion");
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Round);
#endif

    QApplication app{argc, argv};

    SendReceiveManager manager;
    manager.show();

    return QApplication::exec();
}

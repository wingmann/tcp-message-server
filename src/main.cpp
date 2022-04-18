#include "send_receive_manager.h"

#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app{argc, argv};

#if WIN32 || WIN64
    // Sets the graphical style of the application.
    QApplication::setStyle("fusion");
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Round);
#endif

    SendReceiveManager manager;
    manager.show();

    return QApplication::exec();
}

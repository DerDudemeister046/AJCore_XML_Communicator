#include "xml_communicator_widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XML_Communicator_Widget w;
    w.show();
    return a.exec();
}

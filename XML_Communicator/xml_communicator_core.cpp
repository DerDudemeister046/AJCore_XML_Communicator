#include "xml_communicator_core.h"

XML_Communicator_Core::XML_Communicator_Core(QObject *parent) : QObject(parent)
{

}

QString XML_Communicator_Core::getDownloadpath()
{
    return downloadpath;
}

void XML_Communicator_Core::setDownloadpath(QString downloadpath)
{
    this->downloadpath = downloadpath;
}

void XML_Communicator_Core::downloadXML(QString xmlurl)
{
    qDebug() << xmlurl;
}

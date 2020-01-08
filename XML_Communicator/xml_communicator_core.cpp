#include "xml_communicator_core.h"

XML_Communicator_Core::XML_Communicator_Core(QObject *parent) : QObject(parent)
{
    qDebug() << "XML_Communicator_Core: initialize...";

    setDownloadpath("./");
    setSource("http://127.0.0.1/xml_testfile.xml");
    qDebug() << "XML_Communicator_Core: initialization done";
}

QString XML_Communicator_Core::getDownloadpath()
{
    qDebug() << "XML_Communicator_Core: returning downloadpath";
    return downloadpath;
}

void XML_Communicator_Core::setDownloadpath(QString downloadpath)
{
    qDebug() << "XML_Communicator_Core: setting downloadpath";
    this->downloadpath = downloadpath;
}

QString XML_Communicator_Core::getSource()
{
    qDebug() << "XML_Communicator_Core: returning download source";
    return source;
}

void XML_Communicator_Core::setSource(QString source)
{
    qDebug() << "XML_Communicator_Core: setting download source";
    this->source = source;
}

void XML_Communicator_Core::downloadXML(QString xmlurl)
{
    qDebug() << "XML_Communicator_Core: download xml from: " << xmlurl;

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fileIsReady(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(getSource())));
}

void XML_Communicator_Core::fileIsReady(QNetworkReply *reply)
{
    qDebug() << "XML_Communicator_Core: File is ready...";
    tempfile.open();
    tempfile.write(reply->readAll());
    tempfile.close();
    tempfile.open();
    qDebug() << "XML_Communicator_Core: content is written to tempfile";
    qDebug() << "FILEOUTPUT: " << tempfile.readAll();
    tempfile.flush();
    tempfile.close();
    qDebug() << "XML_Communicator_Core: tempfile cleared";
}

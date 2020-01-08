#include "xml_communicator_core.h"

XML_Communicator_Core::XML_Communicator_Core(QObject *parent) : QObject(parent)
{
    qDebug() << "XCC: -> initialize...";
    setDownloadpath("./");
    setSource("http://127.0.0.1/xml_testfile.xml");
    qDebug() << "XCC: -> initialization done";
}

QString XML_Communicator_Core::getDownloadpath()
{
    qDebug() << "XCC: -> returning downloadpath";
    return downloadpath;
}

void XML_Communicator_Core::setDownloadpath(QString downloadpath)
{
    qDebug() << "XCC: -> setting downloadpath";
    this->downloadpath = downloadpath;
}

QString XML_Communicator_Core::getSource()
{
    qDebug() << "XCC: -> returning download source";
    return source;
}

void XML_Communicator_Core::setSource(QString source)
{
    qDebug() << "XCC: -> setting download source";
    this->source = source;
}

void XML_Communicator_Core::downloadXML(QString xmlurl)
{
    qDebug() << "XCC: -> download xml from: " << xmlurl;

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fileIsReady(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(getSource())));
}

void XML_Communicator_Core::readXML()
{
    tempfile.open();
    qDebug() << "XCC: -> Reading content of tempfile...";
    qDebug() << tempfile.readAll();
    tempfile.close();
}

void XML_Communicator_Core::flushFile()
{
    qDebug() << "XCC: -> tempfile is being flushed!";
    tempfile.open();
    tempfile.flush();
    tempfile.close();
}

void XML_Communicator_Core::saveToDisk()
{
    QString filename = QFileDialog::getSaveFileName(nullptr, tr("Datei Speichern"),"",tr("XML-Datei (*.xml);;Alle Dateien(*)"));
    if (filename.isEmpty())
    {
        qDebug() << "XCC: -> Filename is empty! Aborting saving to disk!";
    }
    else
    {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly))
        {
            qDebug() << "XCC: -> ERROR:" << file.errorString();
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_12);
        tempfile.open();
        out << tempfile.readAll();
        tempfile.close();
        qDebug() << "XCC: -> file written to disk";
    }
}




// SLOTS & SIGNALS

void XML_Communicator_Core::fileIsReady(QNetworkReply *reply)
{
    qDebug() << "XCC: -> File is ready...";
    // Flushing file to have a clean start everytime the file is downloaded
    flushFile();
    tempfile.open();
    tempfile.write(reply->readAll());
    tempfile.close();
}

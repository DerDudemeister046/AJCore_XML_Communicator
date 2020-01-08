#include "xml_communicator_core.h"

XML_Communicator_Core::XML_Communicator_Core(QObject *parent) : QObject(parent)
{
    qDebug() << "XCC:->\t initialize...";
    setDownloadpath("./");
    setFileName("default.txt");
    setSource("http://127.0.0.1/xml_testfile.xml");
    qDebug() << "XCC:->\t initialization done";
}

QString XML_Communicator_Core::getDownloadpath()
{
    qDebug() << "XCC:->\t returning downloadpath";
    return downloadpath;
}

void XML_Communicator_Core::setDownloadpath(QString downloadpath)
{
    qDebug() << "XCC:->\t setting downloadpath:\t\t" << downloadpath;
    this->downloadpath = downloadpath;
}

QString XML_Communicator_Core::getSource()
{
    qDebug() << "XCC:->\t returning download source";
    return source;
}

void XML_Communicator_Core::setSource(QString source)
{
    qDebug() << "XCC:->\t setting download source:\t" << source;
    this->source = source;
}

QString XML_Communicator_Core::getFileName()
{
    qDebug() << "XCC:->\t returning filename";
    return fileName;
}

void XML_Communicator_Core::setFileName(QString fileName)
{
    qDebug() << "XCC:->\t setting filename:\t\t" << fileName;
    this->fileName = fileName;
}

void XML_Communicator_Core::downloadXML(QString xmlurl)
{
    qDebug() << "XCC:->\t download xml from:t" << xmlurl;

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fileIsReady(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(getSource())));
}

void XML_Communicator_Core::readXML()
{
    tempfile.open();
    qDebug() << "XCC:->\t Reading content of tempfile...";
    qDebug() << tempfile.readAll();
    tempfile.close();
}

void XML_Communicator_Core::flushFile()
{
    qDebug() << "XCC:->\t tempfile is being flushed!";
    tempfile.open();
    tempfile.flush();
    tempfile.close();
}

void XML_Communicator_Core::saveToDisk()
{
    QString filename = QFileDialog::getSaveFileName(nullptr, tr("Datei Speichern"),"",tr("XML-Datei (*.xml);;Alle Dateien(*)"));
    if (filename.isEmpty())
    {
        qDebug() << "XCC:->\t Filename is empty! Aborting saving to disk!";
    }
    else
    {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
        {
            qDebug() << "XCC:->\t ERROR:\t" << file.errorString();
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_12);
        tempfile.open();
        out << tempfile.readAll();
        tempfile.close();
        qDebug() << "XCC:->\t file written to disk";
        file.close();
    }
}

void XML_Communicator_Core::loadFromDisk()
{
    QString filename = QFileDialog::getOpenFileName(nullptr, tr("Datei Öffnen"),"",tr("XML-Datei (*.xml);;Alle Dateien(*)"));
    if (filename.isEmpty())
    {
        qDebug() << "XCC:->\t Filename is empty! File can't be loaded";
    }
    else
    {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
        {
            qDebug() << "XCC:->\t ERROR:" << file.errorString();
        }
        //QDataStream in(&file);
        QTextStream in(&file);
        //in.setVersion(QDataStream::Qt_5_12);
        tempfile.open();
        tempfile.flush();
        qDebug() << "XCC:->\t file loaded from disk";
        //qDebug() << "XCC: ->" << in.readAll();
        QByteArray ba = in.readAll().toLocal8Bit(); // convert textstream to bytearray to be written to tempfile
        tempfile.write(ba);
        tempfile.close();
    }
}

void XML_Communicator_Core::saveToDiskSilent()
{
    if (getFileName() == "" || getFileName().isEmpty())
    {
        qDebug() << "XCC:->\t Filename is empty! Aborting saving to disk!";
    }
    else
    {
        QFile file(getFileName());
        if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
        {
            qDebug() << "XCC:->\t ERROR:" << file.errorString();
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_12);
        tempfile.open();
        out << tempfile.readAll();
        tempfile.close();
        qDebug() << "XCC:->\t file written(silent) to disk";
        file.close();
    }
}

void XML_Communicator_Core::loadDiskSilent()
{
    if (getFileName() == "" || getFileName().isEmpty())
    {
        qDebug() << "XCC:->\t Filename is empty! File can't be loaded";
    }
    else
    {
        QFile file(getFileName());
        if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
        {
            qDebug() << "XCC:->\t ERROR:" << file.errorString();
        }
        //QDataStream in(&file);
        QTextStream in(&file);
        //in.setVersion(QDataStream::Qt_5_12);
        tempfile.open();
        tempfile.flush();
        qDebug() << "XCC:->\t file loaded from disk";
        //qDebug() << "XCC: ->" << in.readAll();
        QByteArray ba = in.readAll().toLocal8Bit(); // convert textstream to bytearray to be written to tempfile
        tempfile.write(ba);
        tempfile.close();
    }
}




// SLOTS & SIGNALS

void XML_Communicator_Core::fileIsReady(QNetworkReply *reply)
{
    qDebug() << "XCC:->\t File is ready...";
    // Flushing file to have a clean start everytime the file is downloaded
    flushFile();
    tempfile.open();
    tempfile.write(reply->readAll());
    tempfile.close();
}

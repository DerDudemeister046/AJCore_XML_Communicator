#ifndef XML_COMMUNICATOR_CORE_H
#define XML_COMMUNICATOR_CORE_H

//---!---
#include <QObject>
#include <QTemporaryFile>   // Handle Tempfiles
#include <QNetworkAccessManager>
#include <QNetworkReply>
//---#---
#include <QDebug>   // DEBUGGING ONLY

class XML_Communicator_Core : public QObject
{
    Q_OBJECT
public:
    explicit XML_Communicator_Core(QObject *parent = nullptr);

    // GET- & SET-Methods

    QString getDownloadpath();  // returns path the file will be downloaded to
    void setDownloadpath(QString downloadpath); // sets the path the file will be saved to

    QString getSource();            // returns source of xml file
    void setSource(QString source); // sets source of xml file

    // Class functions
    void downloadXML(QString xmlurl);
private:
    QTemporaryFile tempfile;
    QString source;             // source of the xml file
    QString downloadpath;       // holds path the file will be saved to


signals:

public slots:
    void fileIsReady(QNetworkReply *reply);
};

#endif // XML_COMMUNICATOR_CORE_H

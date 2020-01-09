#ifndef XML_COMMUNICATOR_CORE_H
#define XML_COMMUNICATOR_CORE_H

//---!---
#include <QObject>
#include <QFile>
#include <QTemporaryFile>           // Handle Tempfiles
#include <QNetworkAccessManager>    // handle network requests
#include <QNetworkReply>            // handle reply from network request
#include <QFileDialog>              // dialog for load and save files
#include <QTextCodec>               // For UTF-8 formating
//---$---
#include "xml_communicator_docmgr.h"
//---#---
#include <QDebug>   // DEBUGGING ONLY

class XML_Communicator_Core : public QObject, public XML_Communicator_DocMGR
{
    Q_OBJECT
public:
    explicit XML_Communicator_Core(QObject *parent = nullptr);

    // GET- & SET-Methods
    QString getDownloadpath();                      // returns path the file will be downloaded to
    void setDownloadpath(QString downloadpath);     // sets the path the file will be saved to
    QString getSource();                            // returns source of xml file
    void setSource(QString source);                 // sets source of xml file
    QString getFileName();                          // returns filename is going to be read
    void setFileName(QString fileName);             // sets filename that is going to be written
    // Class functions
    void downloadXML(QString xmlurl);               // downloads xml file into tempfile from given destination
    void readFile();                                 // reads content of tempfile
    void flushFile();                               // empties the tempfile
    // File save and load
    void saveToDisk(bool dialog);                   // saves tempfile to disk
    void loadFromDisk(bool dialog);                 // loads file from disk to tempfile
    //
    void processFile(QString tag, QString attribute);
private:
    QTemporaryFile tempfile;                        // temporary file content storage when downloaded from server / uploaded by user
    QFile file;
    QString source;                                 // source of the xml file
    QString downloadpath;                           // holds path the file will be saved to
    QString fileName;                               // name of file to be handled

signals:

public slots:
    void fileIsReady(QNetworkReply *reply);
};

#endif // XML_COMMUNICATOR_CORE_H

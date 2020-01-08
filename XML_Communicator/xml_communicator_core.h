#ifndef XML_COMMUNICATOR_CORE_H
#define XML_COMMUNICATOR_CORE_H

//---!---
#include <QObject>
#include <QTemporaryFile>           // Handle Tempfiles
#include <QNetworkAccessManager>    // handle network requests
#include <QNetworkReply>            // handle reply from network request
#include <QFileDialog>              // dialog for load and save files
//---#---
#include <QDebug>   // DEBUGGING ONLY

class XML_Communicator_Core : public QObject
{
    Q_OBJECT
public:
    explicit XML_Communicator_Core(QObject *parent = nullptr);

    // GET- & SET-Methods

    QString getDownloadpath();                      // returns path the file will be downloaded to
    void setDownloadpath(QString downloadpath);     // sets the path the file will be saved to

    QString getSource();                            // returns source of xml file
    void setSource(QString source);                 // sets source of xml file

    QString getFileName();
    void setFileName(QString fileName);

    // Class functions
    void downloadXML(QString xmlurl);               // downloads xml file into tempfile from given destination
    void readXML();                                 // reads content of tempfile
    void flushFile();                               // empties the tempfile
    // File save and load
    void saveToDisk();                              // saves tempfile to disk
    void loadFromDisk();                            // loads file from disk to tempfile
    void saveToDiskSilent();                        // saves with given filename, no dialog prompted
    void loadDiskSilent();                          // loads with given filename, no dialog prompted
private:
    QTemporaryFile tempfile;
    QString source;                                 // source of the xml file
    QString downloadpath;                           // holds path the file will be saved to
    QString fileName;                               // name of file to be handled

signals:

public slots:
    void fileIsReady(QNetworkReply *reply);
};

#endif // XML_COMMUNICATOR_CORE_H

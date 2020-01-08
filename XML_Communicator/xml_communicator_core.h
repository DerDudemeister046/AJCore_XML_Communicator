#ifndef XML_COMMUNICATOR_CORE_H
#define XML_COMMUNICATOR_CORE_H

#include <QObject>
#include <QDebug>

class XML_Communicator_Core : public QObject
{
    Q_OBJECT
public:
    explicit XML_Communicator_Core(QObject *parent = nullptr);

    // GET- & SET-Methods

    QString getDownloadpath();  // returns path the file will be downloaded to
    void setDownloadpath(QString downloadpath); // sets the path the file will be saved to

    // Class functions
    void downloadXML(QString xmlurl);
private:
    QString downloadpath;       // holds path the file will be saved to

signals:

public slots:
};

#endif // XML_COMMUNICATOR_CORE_H

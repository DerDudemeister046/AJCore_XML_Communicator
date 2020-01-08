#ifndef XML_DOCUMENT_MANAGER_H
#define XML_DOCUMENT_MANAGER_H

#include <QObject>
#include <QTemporaryFile>       // To handle file passed by XML_Communicator_Core
#include <QDomDocument>         // XML File to be processed
#include <QDebug>

class XML_Document_Manager : public QObject
{
    Q_OBJECT
public:
    explicit XML_Document_Manager(QObject *parent = nullptr);
    // Class functions
    void processDocument(QTemporaryFile *temp);
    QString getFromDocument(QString attribute, QString tag);
private:
    QDomDocument document;
    QDomElement root;
signals:

public slots:
};

#endif // XML_DOCUMENT_MANAGER_H

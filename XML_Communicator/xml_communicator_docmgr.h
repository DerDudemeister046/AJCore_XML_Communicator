/*
 *  This class contains functions to handle xml documents.
 *
 */

#ifndef XML_DOCUMENTMANAGEMENT_H
#define XML_DOCUMENTMANAGEMENT_H

#include <QtCore>
#include <QTemporaryFile>       // To handle file passed by XML_Communicator_Core
#include <QDomDocument>         // XML-File to be processed

#include <QDebug>

class XML_Communicator_DocMGR
{
public:
    XML_Communicator_DocMGR();

    // SET- & GET-Methods
    // Class Functions
    bool initializeDocument(QTemporaryFile *temp);    // initializes XML-File and root node -> needs to be called to make class work
    void processXMLDocument();  // starts the process of interpreting XML-File
    QString getFromDocument(QString tag, QString attribute); // returns value from XML-File as QString
    // Helper Functions
    void startTest(); // testing function to be removed in final version
    bool subchildTest(QDomNode *node); // checks if a given node has subchildren
private:
    QDomDocument *document;
};

#endif // XML_DOCUMENTMANAGEMENT_H

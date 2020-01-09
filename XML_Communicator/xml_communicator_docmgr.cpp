#include "xml_communicator_docmgr.h"

XML_Communicator_DocMGR::XML_Communicator_DocMGR()
{
    document = new QDomDocument;
}

bool XML_Communicator_DocMGR::initializeDocument(QTemporaryFile *temp)
{
    bool success = false; // gets true if document got loaded propperly

    qDebug() << "\nXDM:->\tSetting tempfile content to document";
    if (!document->setContent(temp)) // fail check if document can be set, if not abort
    {
        qDebug() << "XDM:->\tSetting document content failed!\n";
        return success;
    }
    else
    {
        qDebug() << "XDM:->\tSetting document content succeeded!\n";
        //QDomElement documentElement = document->documentElement();
        success = true;
    }
    return success;
}

void XML_Communicator_DocMGR::processXMLDocument()
{
    qDebug() << "\nXDM:->\tStart processing document";

    qDebug() << "XDM:->\tProcessing finished\n";
}

QString XML_Communicator_DocMGR::getFromDocument(QString tag, QString attribute)
{
    qDebug() << "XDM:->\tGetting from document:\n\tAttribute:\t" << attribute
             << "\n\tTAG:\t\t" << tag;
    QString result = "";
    QDomElement rt = document->firstChildElement(); // setting local root document must be initialized at this point
    QDomNodeList nlist = rt.elementsByTagName(tag);
    for (int i=0; i<nlist.count(); i++)
    {
        QDomNode node = nlist.at(i);
        if(node.isElement())
        {
            QDomElement item = node.toElement();
            qDebug() << "\nXDM:->\tFOUND element in document:\n\tAttribute:\t" << item.attribute(attribute);
            result = item.attribute(attribute);
        }
    }
    return result;
}

void XML_Communicator_DocMGR::startTest()
{

}

bool XML_Communicator_DocMGR::subchildTest(QDomNode *node)
{
    bool finish = false;

    if (node->hasChildNodes())
    {
        finish = true;
    }
    else
    {
        finish = false;
    }
    return finish;
}

#include "xml_document_manager.h"

XML_Document_Manager::XML_Document_Manager(QObject *parent) : QObject(parent)
{

}

void XML_Document_Manager::processDocument(QTemporaryFile *temp)
{
    qDebug() << "XDM:->\tStart processing document";

    qDebug() << "XDM:->\tProcessing finished";
}

QString XML_Document_Manager::getFromDocument(QString attribute, QString tag)
{
    qDebug() << "XDM:->\tGetting element from document:\nAttribute:\t" << attribute
             << "\nTAG:\t" << tag;
    QString result = "";
    QDomNodeList nlist = root.elementsByTagName(tag);
    for (int i=0; i<nlist.count(); i++)
    {
        QDomNode node = nlist.at(i);
        if(node.isElement())
        {
            QDomElement item = node.toElement();
            //qDebug() << item.attribute(attribute);
            result = item.attribute(attribute);
        }
    }
    return result;
}

void XML_Document_Manager::populateLists()
{

}

void XML_Document_Manager::traverse(const QDomNode &node)
{
    QDomNode domNode = node.firstChild();
    while(!domNode.isNull())
    {
        if(domNode.isElement())
        {
            QDomElement domElement = domNode.toElement();
            if (!domElement.isNull())
            {
                if (domElement.hasChildNodes())
                {
                    qDebug() << domElement.nodeValue();
                }


                qDebug() << "DOM ELEMENT:\t\t" << domElement.tagName() << domElement.text();
            }
        }
        traverse(domNode);
        domNode=domNode.nextSibling();
    }
}

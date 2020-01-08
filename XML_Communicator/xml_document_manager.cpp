#include "xml_document_manager.h"

XML_Document_Manager::XML_Document_Manager(QObject *parent) : QObject(parent)
{

}

void XML_Document_Manager::processDocument(QTemporaryFile *temp)
{
    qDebug() << "XDM:->\tStart processing document";
    document.setContent(temp);
    root = document.documentElement();
    QDomNode n = root.firstChild();
    while (!n.isNull())
    {
        QDomElement e = n.toElement();
        qDebug() << "XDM:->\tTAG:\t" << e.tagName();

        QDomNodeList nodelist = root.elementsByTagName(e.tagName());
        for (int i=0; i<nodelist.count(); i++)
        {
            QDomNode node = nodelist.at(i);
            if(node.isElement())
            {
                QDomElement item = node.toElement();

                QDomNodeList abc = node.childNodes();

                for (int i=0; i<abc.size(); i++)
                {
                    QDomElement elm = abc.at(i).toElement();
                    qDebug() << "XDM:->\tSUBTAG:" << elm.tagName();
                }


            }
        }


        n = n.nextSibling();
    }
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
            qDebug() << item.attribute(attribute);
            result = item.attribute(attribute);
        }
    }
    return result;
}

void XML_Document_Manager::populateLists()
{

}


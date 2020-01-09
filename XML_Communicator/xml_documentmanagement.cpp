#include "xml_documentmanagement.h"

XML_DocumentManagement::XML_DocumentManagement()
{
    document = new QDomDocument;
}

bool XML_DocumentManagement::initializeDocument(QTemporaryFile *temp, QString documentName)
{
    bool success = false; // gets true if document got loaded propperly

    qDebug() << "NEW:XDM:->\tSetting tempfile content to document";
    if (!document->setContent(temp)) // fail check if document can be set, if not abort
    {
        qDebug() << "NEW:XDM:->\tSetting document content failed!";
        return success;
    }
    else
    {
        qDebug() << "NEW:XDM:->\tSetting document content succeeded!";
        QDomElement documentElement = document->documentElement();
        QDomNode node = documentElement.firstChild();

        while(!node.isNull())
        {
            QDomElement element = node.toElement();
            if(!element.isNull())
            {
                qDebug() << "NEW:XDM:->\tTagName:" << element.tagName();
            }

            subchildTest(&node);
            node = node.nextSibling();
        }
    }
    return success;
}

void XML_DocumentManagement::processXMLDocument(QTemporaryFile *temp)
{
    qDebug() << "NEW:XDM:->\tStart processing document";

    qDebug() << "NEW:XDM:->\tProcessing finished";
}

void XML_DocumentManagement::startTest()
{
    /*
    QDomNodeList nlist = root.elementsByTagName(tag);
    for (int i=0; i<nlist.count(); i++)
    {
        QDomNode node = nlist.at(i);
        if(node.isElement())
        {
            QDomElement item = node.toElement();
            qDebug() << item.attribute(attribute);
        }
    }
    */
}

bool XML_DocumentManagement::subchildTest(QDomNode *node)
{
    bool finish = false;

    if (node->hasChildNodes())
    {
        /*
        QDomElement element = node->toElement();



        if (!element.isNull())
        {
            qDebug() << "NEW:XDM:->\tFound new Subchild Element:\t" << element.tagName();
            finish = true;
        }
        */

        QDomNodeList nodelist = node->childNodes();
        qDebug() << "NEW:XDM:->\tNODELIST LENGTH:\t" << nodelist.size();

        //QDomNode n = nodelist.at(0);

        for (int i=0; i<nodelist.size(); i++)
        {
            QDomElement e = nodelist.at(i).toElement();
            if (!e.isNull())
            {
                qDebug() << "NEW:XDM:->\tNODEVALUE1:\t" << e.tagName();
                qDebug() << "NEW:XDM:->\tNODEVALUE2:\t" <<nodelist.at(i).nodeValue();
                QDomNode newnode = nodelist.at(i);
                subchildTest(&newnode);
            }
        }
    }
    else
    {
        qDebug() << "NEW:XDM:->\tNo Subchildren have been found.";
        qDebug() << "NEW:XDM:->\tGetting values of element";


        qDebug() << "NEW:XDM:->\tVALUE:\t" << node->nextSibling().nodeValue();

        finish = false;
    }
    return finish;
}

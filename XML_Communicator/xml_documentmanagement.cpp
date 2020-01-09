#include "xml_documentmanagement.h"

XML_DocumentManagement::XML_DocumentManagement()
{
    document = new QDomDocument;
}

bool XML_DocumentManagement::initializeDocument(QTemporaryFile *temp, QString documentName)
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


        QDomElement documentElement = document->documentElement();
        /*
        while(!node.isNull())
        {
            QDomElement element = node.toElement();
            if(!element.isNull())
            {
                qDebug() << "\nXDM:->\tTagName:" << element.tagName();
            }
            //subchildTest(&node);
            node = node.nextSibling();
        }
        */
        success = true;
    }
    return success;
}

void XML_DocumentManagement::processXMLDocument()
{
    qDebug() << "\nXDM:->\tStart processing document";

    qDebug() << "XDM:->\tProcessing finished\n";
}

QString XML_DocumentManagement::getFromDocument(QString tag, QString attribute)
{
    /*
    QDomElement documentElement = document->documentElement();
    QDomNode node = documentElement.firstChild();

    QString value = "";

    while(!node.isNull())
    {
        QDomElement element = node.toElement();
        if(!element.isNull())
        {
            qDebug() << "\nXDM:->\tVALUE:" << element.attribute(tag,attribute);
            value = element.attribute(tag, attribute);
            qDebug() << "\nXDM:->\tRETURN:" << value;
        }
        //subchildTest(&node);
        node = node.nextSibling();
    }
    qDebug() << "\nXDM:->\tRETURN___:" << value;
    return value;
    */

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
        qDebug() << "\nXDM:->\tSubchild found. Checking further...\n";

        QDomNodeList nodelist = node->childNodes(); // creating a list of all childnodes
        qDebug() << "XDM:->\tNODELIST LENGTH:\t" << nodelist.size();

        // looping through the nodelist
        for (int i=0; i<nodelist.size(); i++)
        {
            QDomElement e = nodelist.at(i).toElement();
            if (!e.isNull())    // if element then do
            {
                qDebug() << "\nXDM:->\tElement found at:\t" << i;
                qDebug() << "XDM:->\tELEMENT_TAG:\t\t" << e.tagName();
                qDebug() << "XDM:->\tNODE_VALUE:\t\t" << nodelist.at(i).nodeValue();
                QDomNode newnode = nodelist.at(i);

                //subchildTest(&newnode);
                if (subchildTest(&newnode))
                {
                    qDebug() << "XDM:->\tPING!";
                    finish = true;
                }

            }
        }
        */
        finish = true;
    }
    else
    {
        /*
        qDebug() << "XDM:->\tNo Subchildren have been found.";
        QString x = "";
        x = node->toElement().attribute("host");
        if (x != "")
        {
            qDebug() << "XDM:->\tGetting values of element";
            qDebug() << "XDM:->\tVALUE:\t" << node->toElement().attribute("host");
        }
        */
        finish = false;
    }
    return finish;
}

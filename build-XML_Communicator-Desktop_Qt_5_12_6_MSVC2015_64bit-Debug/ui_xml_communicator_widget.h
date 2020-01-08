/********************************************************************************
** Form generated from reading UI file 'xml_communicator_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XML_COMMUNICATOR_WIDGET_H
#define UI_XML_COMMUNICATOR_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XML_Communicator_Widget
{
public:
    QGridLayout *gridLayout;
    QPushButton *readXML_btn;
    QPushButton *loadFile_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *flushFile_btn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *saveFile_btn;
    QFrame *line;
    QPushButton *startDownload_btn;
    QPushButton *silent_test_btn;

    void setupUi(QWidget *XML_Communicator_Widget)
    {
        if (XML_Communicator_Widget->objectName().isEmpty())
            XML_Communicator_Widget->setObjectName(QString::fromUtf8("XML_Communicator_Widget"));
        XML_Communicator_Widget->resize(273, 166);
        gridLayout = new QGridLayout(XML_Communicator_Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        readXML_btn = new QPushButton(XML_Communicator_Widget);
        readXML_btn->setObjectName(QString::fromUtf8("readXML_btn"));

        gridLayout->addWidget(readXML_btn, 1, 1, 1, 1);

        loadFile_btn = new QPushButton(XML_Communicator_Widget);
        loadFile_btn->setObjectName(QString::fromUtf8("loadFile_btn"));

        gridLayout->addWidget(loadFile_btn, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        flushFile_btn = new QPushButton(XML_Communicator_Widget);
        flushFile_btn->setObjectName(QString::fromUtf8("flushFile_btn"));

        gridLayout->addWidget(flushFile_btn, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        saveFile_btn = new QPushButton(XML_Communicator_Widget);
        saveFile_btn->setObjectName(QString::fromUtf8("saveFile_btn"));

        gridLayout->addWidget(saveFile_btn, 4, 1, 1, 1);

        line = new QFrame(XML_Communicator_Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 3);

        startDownload_btn = new QPushButton(XML_Communicator_Widget);
        startDownload_btn->setObjectName(QString::fromUtf8("startDownload_btn"));

        gridLayout->addWidget(startDownload_btn, 0, 1, 1, 1);

        silent_test_btn = new QPushButton(XML_Communicator_Widget);
        silent_test_btn->setObjectName(QString::fromUtf8("silent_test_btn"));

        gridLayout->addWidget(silent_test_btn, 6, 1, 1, 1);


        retranslateUi(XML_Communicator_Widget);

        QMetaObject::connectSlotsByName(XML_Communicator_Widget);
    } // setupUi

    void retranslateUi(QWidget *XML_Communicator_Widget)
    {
        XML_Communicator_Widget->setWindowTitle(QApplication::translate("XML_Communicator_Widget", "XML_Communicator_Widget", nullptr));
        readXML_btn->setText(QApplication::translate("XML_Communicator_Widget", "Datei auslesen", nullptr));
        loadFile_btn->setText(QApplication::translate("XML_Communicator_Widget", "Datei Laden", nullptr));
        flushFile_btn->setText(QApplication::translate("XML_Communicator_Widget", "Datei leeren", nullptr));
        saveFile_btn->setText(QApplication::translate("XML_Communicator_Widget", "Datei Speichern", nullptr));
        startDownload_btn->setText(QApplication::translate("XML_Communicator_Widget", "Starte Download", nullptr));
        silent_test_btn->setText(QApplication::translate("XML_Communicator_Widget", "Ohne GUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XML_Communicator_Widget: public Ui_XML_Communicator_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XML_COMMUNICATOR_WIDGET_H

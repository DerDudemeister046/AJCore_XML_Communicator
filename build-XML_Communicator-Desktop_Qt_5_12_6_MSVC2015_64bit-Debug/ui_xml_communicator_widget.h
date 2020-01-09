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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XML_Communicator_Widget
{
public:
    QGridLayout *gridLayout;
    QPushButton *flushFile_btn;
    QPushButton *readXML_btn;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_2;
    QPushButton *silent_test_btn;
    QLabel *label_2;
    QPushButton *loadFile_btn;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *attribut_le;
    QLabel *label;
    QFrame *line;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QLineEdit *tag_le;
    QPushButton *startDownload_btn;
    QPushButton *saveFile_btn;
    QPushButton *evaluate_btn;
    QFrame *line_3;
    QTextEdit *textEdit;

    void setupUi(QWidget *XML_Communicator_Widget)
    {
        if (XML_Communicator_Widget->objectName().isEmpty())
            XML_Communicator_Widget->setObjectName(QString::fromUtf8("XML_Communicator_Widget"));
        XML_Communicator_Widget->resize(564, 519);
        gridLayout = new QGridLayout(XML_Communicator_Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        flushFile_btn = new QPushButton(XML_Communicator_Widget);
        flushFile_btn->setObjectName(QString::fromUtf8("flushFile_btn"));

        gridLayout->addWidget(flushFile_btn, 2, 2, 1, 1);

        readXML_btn = new QPushButton(XML_Communicator_Widget);
        readXML_btn->setObjectName(QString::fromUtf8("readXML_btn"));

        gridLayout->addWidget(readXML_btn, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 4, 1, 1);

        line_2 = new QFrame(XML_Communicator_Widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 5, 0, 1, 5);

        silent_test_btn = new QPushButton(XML_Communicator_Widget);
        silent_test_btn->setObjectName(QString::fromUtf8("silent_test_btn"));

        gridLayout->addWidget(silent_test_btn, 4, 3, 1, 1);

        label_2 = new QLabel(XML_Communicator_Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 8, 2, 1, 1);

        loadFile_btn = new QPushButton(XML_Communicator_Widget);
        loadFile_btn->setObjectName(QString::fromUtf8("loadFile_btn"));

        gridLayout->addWidget(loadFile_btn, 4, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 2);

        attribut_le = new QLineEdit(XML_Communicator_Widget);
        attribut_le->setObjectName(QString::fromUtf8("attribut_le"));

        gridLayout->addWidget(attribut_le, 8, 3, 1, 1);

        label = new QLabel(XML_Communicator_Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 8, 0, 1, 1);

        line = new QFrame(XML_Communicator_Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 2);

        tag_le = new QLineEdit(XML_Communicator_Widget);
        tag_le->setObjectName(QString::fromUtf8("tag_le"));

        gridLayout->addWidget(tag_le, 8, 1, 1, 1);

        startDownload_btn = new QPushButton(XML_Communicator_Widget);
        startDownload_btn->setObjectName(QString::fromUtf8("startDownload_btn"));

        gridLayout->addWidget(startDownload_btn, 0, 2, 1, 1);

        saveFile_btn = new QPushButton(XML_Communicator_Widget);
        saveFile_btn->setObjectName(QString::fromUtf8("saveFile_btn"));

        gridLayout->addWidget(saveFile_btn, 4, 1, 1, 1);

        evaluate_btn = new QPushButton(XML_Communicator_Widget);
        evaluate_btn->setObjectName(QString::fromUtf8("evaluate_btn"));

        gridLayout->addWidget(evaluate_btn, 8, 4, 1, 1);

        line_3 = new QFrame(XML_Communicator_Widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 7, 0, 1, 5);

        textEdit = new QTextEdit(XML_Communicator_Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 6, 0, 1, 5);


        retranslateUi(XML_Communicator_Widget);

        QMetaObject::connectSlotsByName(XML_Communicator_Widget);
    } // setupUi

    void retranslateUi(QWidget *XML_Communicator_Widget)
    {
        XML_Communicator_Widget->setWindowTitle(QApplication::translate("XML_Communicator_Widget", "XML_Communicator_Widget", nullptr));
        flushFile_btn->setText(QApplication::translate("XML_Communicator_Widget", "Datei leeren", nullptr));
        readXML_btn->setText(QApplication::translate("XML_Communicator_Widget", "Datei auslesen", nullptr));
        silent_test_btn->setText(QApplication::translate("XML_Communicator_Widget", "Ohne GUI", nullptr));
        label_2->setText(QApplication::translate("XML_Communicator_Widget", "Attribut", nullptr));
        loadFile_btn->setText(QApplication::translate("XML_Communicator_Widget", "Datei Laden", nullptr));
        label->setText(QApplication::translate("XML_Communicator_Widget", "Tag", nullptr));
        startDownload_btn->setText(QApplication::translate("XML_Communicator_Widget", "Starte Download", nullptr));
        saveFile_btn->setText(QApplication::translate("XML_Communicator_Widget", "Datei Speichern", nullptr));
        evaluate_btn->setText(QApplication::translate("XML_Communicator_Widget", "Auswerten", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XML_Communicator_Widget: public Ui_XML_Communicator_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XML_COMMUNICATOR_WIDGET_H

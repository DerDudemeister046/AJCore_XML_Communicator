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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XML_Communicator_Widget
{
public:
    QGridLayout *gridLayout;
    QPushButton *startDownload_btn;

    void setupUi(QWidget *XML_Communicator_Widget)
    {
        if (XML_Communicator_Widget->objectName().isEmpty())
            XML_Communicator_Widget->setObjectName(QString::fromUtf8("XML_Communicator_Widget"));
        XML_Communicator_Widget->resize(273, 117);
        gridLayout = new QGridLayout(XML_Communicator_Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        startDownload_btn = new QPushButton(XML_Communicator_Widget);
        startDownload_btn->setObjectName(QString::fromUtf8("startDownload_btn"));

        gridLayout->addWidget(startDownload_btn, 0, 0, 1, 1);


        retranslateUi(XML_Communicator_Widget);

        QMetaObject::connectSlotsByName(XML_Communicator_Widget);
    } // setupUi

    void retranslateUi(QWidget *XML_Communicator_Widget)
    {
        XML_Communicator_Widget->setWindowTitle(QApplication::translate("XML_Communicator_Widget", "XML_Communicator_Widget", nullptr));
        startDownload_btn->setText(QApplication::translate("XML_Communicator_Widget", "Starte Download", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XML_Communicator_Widget: public Ui_XML_Communicator_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XML_COMMUNICATOR_WIDGET_H

#include "xml_communicator_widget.h"
#include "ui_xml_communicator_widget.h"

XML_Communicator_Widget::XML_Communicator_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::XML_Communicator_Widget)
{
    ui->setupUi(this);
}

XML_Communicator_Widget::~XML_Communicator_Widget()
{
    delete ui;
}


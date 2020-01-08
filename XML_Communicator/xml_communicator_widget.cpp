#include "xml_communicator_widget.h"
#include "xml_communicator_core.h"
#include "ui_xml_communicator_widget.h"

XML_Communicator_Widget::XML_Communicator_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::XML_Communicator_Widget)
{
    ui->setupUi(this);
    core = new XML_Communicator_Core(this);
    core->downloadXML("HALLO WELT!");
}

XML_Communicator_Widget::~XML_Communicator_Widget()
{
    delete ui;
}


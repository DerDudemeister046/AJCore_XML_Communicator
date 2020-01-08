#include "xml_communicator_widget.h"
#include "xml_communicator_core.h"
#include "ui_xml_communicator_widget.h"

XML_Communicator_Widget::XML_Communicator_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::XML_Communicator_Widget)
{
    ui->setupUi(this);
    core = new XML_Communicator_Core(this);

}

XML_Communicator_Widget::~XML_Communicator_Widget()
{
    delete ui;
}


void XML_Communicator_Widget::on_startDownload_btn_clicked()
{
    core->downloadXML(core->getSource());
}

void XML_Communicator_Widget::on_readXML_btn_clicked()
{
    core->readXML();
}

void XML_Communicator_Widget::on_flushFile_btn_clicked()
{
    core->flushFile();
}

void XML_Communicator_Widget::on_saveFile_btn_clicked()
{

}

void XML_Communicator_Widget::on_loadFile_btn_clicked()
{

}

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
    core->readFile();
}

void XML_Communicator_Widget::on_flushFile_btn_clicked()
{
    core->flushFile();
}

void XML_Communicator_Widget::on_saveFile_btn_clicked()
{
    core->saveToDisk(true);
}

void XML_Communicator_Widget::on_loadFile_btn_clicked()
{
    core->loadFromDisk(true);
}

void XML_Communicator_Widget::on_silent_test_btn_clicked()
{
    core->setFileName("dummy.txt");
    core->saveToDisk(false);
    core->loadFromDisk(false);
    core->readFile();
}

void XML_Communicator_Widget::on_evaluate_btn_clicked()
{
    core->processFile(ui->tag_le->text(), ui->attribut_le->text());
}

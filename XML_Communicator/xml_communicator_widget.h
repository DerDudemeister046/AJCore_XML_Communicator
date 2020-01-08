#ifndef XML_COMMUNICATOR_WIDGET_H
#define XML_COMMUNICATOR_WIDGET_H

#include <QWidget>



#include "xml_communicator_core.h"

QT_BEGIN_NAMESPACE
namespace Ui { class XML_Communicator_Widget; }
QT_END_NAMESPACE

class XML_Communicator_Widget : public QWidget
{
    Q_OBJECT

public:
    XML_Communicator_Widget(QWidget *parent = nullptr);
    ~XML_Communicator_Widget();

private slots:
    void on_startDownload_btn_clicked();

    void on_readXML_btn_clicked();

    void on_flushFile_btn_clicked();

    void on_saveFile_btn_clicked();

    void on_loadFile_btn_clicked();

    void on_silent_test_btn_clicked();

private:
    Ui::XML_Communicator_Widget *ui;
    XML_Communicator_Core *core;

};
#endif // XML_COMMUNICATOR_WIDGET_H

#ifndef XML_COMMUNICATOR_WIDGET_H
#define XML_COMMUNICATOR_WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class XML_Communicator_Widget; }
QT_END_NAMESPACE

class XML_Communicator_Widget : public QWidget
{
    Q_OBJECT

public:
    XML_Communicator_Widget(QWidget *parent = nullptr);
    ~XML_Communicator_Widget();

private:
    Ui::XML_Communicator_Widget *ui;
};
#endif // XML_COMMUNICATOR_WIDGET_H

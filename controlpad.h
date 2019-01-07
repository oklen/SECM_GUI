#ifndef CONTROLPAD_H
#define CONTROLPAD_H
#include <QComboBox>
#include <QLineEdit>
#include <sigma/sigmacontrol.h>
#include <picontorl.h>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <thread>
#include <QCloseEvent>

#define chi(name) QString::fromLocal8Bit(name)
class ControlPad:public QWidget
{
    Q_OBJECT
public:
    explicit ControlPad(QWidget* parent=nullptr);
    sigmaControl *sigma;
    QComboBox PortNames;
    QLineEdit bandRate;
    QPushButton comPb;
    QLineEdit sendContent;
    QPushButton Send;
    QTextBrowser *history;
    QLabel *sigmaPos;
    static bool working;
    const char* sigmaLabel ="SigmaPos: X:";
    const char* df[2] {" Y:"," Z:"};
    QString nowPos;
    void closeEvent(QCloseEvent* event);
private slots:
    void SetConfig();
    void sendcommand();
};
#endif // CONTROLPAD_H

#ifndef SRC_PROJECT_SMARTCALC_H_
#define SRC_PROJECT_SMARTCALC_H_

#include "stylesheet.h"
#include "credit.h"
#include "deposit.h"
#include "helpers.h"
#include "qcustomplot.h"
#include <QGridLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

extern "C" {
    #include "s21_calculation.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class SmartCalc;
}
QT_END_NAMESPACE

class SmartCalc: public QMainWindow {
    Q_OBJECT

    public: SmartCalc(QWidget *parent = nullptr);
    ~SmartCalc();

    private:
        Ui::SmartCalc * ui;

    Credit * creditForm = creditForm = new Credit();
    Deposit * depositForm = new Deposit();

    QWidget * defaultFormWidget;
    QWidget * mainFormWidget_right;
    QWidget * mainFormWidget_left;
    QWidget * mainFormWidget;
    QWidget * graphFormWidget;

    QGridLayout * defaultFormLayout;
    QGridLayout * mainFormLayout_left;
    QGridLayout * mainFormLayout_right;
    QGridLayout * mainFormLayout;
    QGridLayout * graphFormLayout;

    QCustomPlot * widget;
    QLineEdit * MaxX;
    QLineEdit * MinX;

    QPushButton * Button_openGraph;

    void mainModeUI();
    void defaultFormUI();
    void grapfForm();
    void createForm();

    bool graphForm_flag;
    void createForm_two();
    void makeGraph(my_str * str_pol);

    public slots:
        void openGraph();
        void digitClicked();
        void functionsClicked();
        void operationsClicked();
        void equalClicked();
        void clearClicked();
        void backspaceClicked();
        void openCreditCalc();
        void openDepositCalc();
        QString get_Text();
};

#endif  // SRC_PROJECT_SMARTCALC_H_


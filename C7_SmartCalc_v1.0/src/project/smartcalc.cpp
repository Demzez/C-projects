#include "smartcalc.h"
#include "ui_smartcalc.h"

SmartCalc::SmartCalc(QWidget * parent): QMainWindow(parent), ui(new Ui::SmartCalc) {
    ui->setupUi(this);
    createForm();
    graphForm_flag = false;
}

SmartCalc::~SmartCalc() {
    delete ui;
}

void SmartCalc::digitClicked() {
    QString clickedNum = ((QPushButton*) sender())->text();
    QString cur_str = ui->lineEdit->text();
    if (!cur_str.endsWith(")")) {
        ui->lineEdit->setText((ui->lineEdit->text() == "0" ? "" :
                                 ui->lineEdit->text()) + clickedNum);
    }  // add operation condition
}

void SmartCalc::functionsClicked() {
    QPushButton * clickedButton = qobject_cast < QPushButton * > (sender());
    QString cur_str = ui->lineEdit->text();
    QString sep = ".";
    int flag = cur_str.endsWith("+") || cur_str.endsWith("-") ||
        cur_str.endsWith("/") || cur_str.endsWith("^") || cur_str.endsWith("*") ||
        cur_str.endsWith(" mod ") || cur_str.isEmpty() || cur_str.endsWith("(") ? TRUE : FALSE;
    if (flag) {
        if (clickedButton->text() != "\u221A")
            ui->lineEdit->setText(ui->lineEdit->text() + clickedButton->text() + "(");
        else
            ui->lineEdit->setText(ui->lineEdit->text() + "sqrt" + "(");
    }
}

void SmartCalc::operationsClicked() {
    QPushButton * clickedButton = qobject_cast < QPushButton * > (sender());
    QString cur_str = ui->lineEdit->text();
    QString sep = ".";
    int flag = cur_str.endsWith("+") || cur_str.endsWith("-") ||
        cur_str.endsWith("/") || cur_str.endsWith("^") || cur_str.endsWith("*") ||
        cur_str.endsWith(" mod ") || cur_str.isEmpty() ||
        cur_str.endsWith(sep) || cur_str.endsWith("(") ? FALSE : TRUE;

    if (clickedButton->text() == "+" && (flag || cur_str.endsWith("(")))
        ui->lineEdit->setText(cur_str + "+");
    else if (clickedButton->text() == "-" && (flag || cur_str.endsWith("(")))
        ui->lineEdit->setText(cur_str + "-");
    else if (clickedButton->text() == "\u00F7" && flag)
        ui->lineEdit->setText(cur_str + "/");
    else if (clickedButton->text() == "x\u207F" && flag)
        ui->lineEdit->setText(cur_str + "^");
    else if (clickedButton->text() == "%" && flag)
        ui->lineEdit->setText(cur_str + " mod ");
    else if (clickedButton->text() == "(" && !flag && !cur_str.endsWith(sep))
        ui->lineEdit->setText(cur_str + "(");
    else if (clickedButton->text() == ")" && flag)
        ui->lineEdit->setText(cur_str + ")");
    else if (clickedButton->text() == "*" && flag)
        ui->lineEdit->setText(cur_str + "*");
    else if (cur_str.isEmpty() && clickedButton->text() == "-")
        ui->lineEdit->setText("-");
    else if (cur_str.isEmpty() && clickedButton->text() == "+")
        ui->lineEdit->setText("+");
    else if (clickedButton->text() == sep && flag)
        ui->lineEdit->setText(cur_str + sep);
}

void SmartCalc::equalClicked() {
    unsigned int str_length = ui->lineEdit->text().length();
    char * str = new char(str_length);
    my_str * str_pol = NULL;
    my_str * pol_ind;
    str_pol = NULL;
    QByteArray strL = ui->lineEdit->text().toLatin1();
    strncpy(str, strL, str_length + 1);
    double ans = 0.0;
    if (Notation(&str_pol, str)) {
        if (ui->lineEdit->text().contains("X")) {
            if (MinX->text().isEmpty() || MaxX->text().isEmpty())
                errorMsg("Введите ОБЛАСТ[И] определения!");
            // else if ()
            //   errorMsg("Ошибка в выражение");
            else
                makeGraph(str_pol);
        } else if (calc(str_pol, & ans, 0.0)) {
            // QString result;
            // QByteArray resultL = "";
            // while (str_pol != NULL) {
            // resultL += QByteArray((char*)str_pol->info, strlen(str_pol->info));
            // str_pol =str_pol->next;
            // }
            // result = resultL;
            QString result = QString::number(ans);
            ui->lineEdit->setText(result);
        } else if (str_length > 255) {
            ui->lineEdit->setText("ERROR. Введено больше 255 символов");
        } else {
            ui->lineEdit->setText("ERROR");
        }
    } else {
        ui->lineEdit->setText("ERROR");
    }
    delete(str);
}

void SmartCalc::makeGraph(my_str * str_pol) {
    double left = MinX->text().toDouble();
    double right = MaxX->text().toDouble();
    QVector < double > y(1000), x(1000);
    int stat = 1;
    for (int i = 0; i < 1000; i++) {
        x[i] = (i == 0) ? left : x[i - 1] + (right - left) / 1000;
        double buf_y = 0.0;
        double buf_x = x[i];
        if (!calc(str_pol, & buf_y, buf_x)) {
            stat = 0;
            break;
        }
        y[i] = buf_y;
    }
    if (stat) {
        QCustomPlot * graphPlot = widget;
        graphPlot->addGraph();
        graphPlot->graph(0)->setData(x, y);
        // give the axes some labels:
        graphPlot->xAxis->setLabel("x");
        graphPlot->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        graphPlot->xAxis->setRange(left, right);
        graphPlot->yAxis->setRange(*std::min_element(y.begin(), y.end()),
                                       *std::max_element(y.begin(), y.end()));
        graphPlot->replot();
    } else {
        QMessageBox msgText;
        msgText.setText("Некоррентная числовая запись! Попробуйте еще раз.");
        msgText.exec();
    }
}

void SmartCalc::clearClicked() {
    QString cur_str = "";
    ui->lineEdit->setText(cur_str);
}

void SmartCalc::backspaceClicked() {
    QString cur_str = ui->lineEdit->text();
    cur_str.chop(1);
    ui->lineEdit->setText(cur_str);
}

void SmartCalc::openCreditCalc() {
    if (!creditForm->isVisible())
        creditForm->show();
}

void SmartCalc::openDepositCalc() {
    if (!depositForm->isVisible())
        depositForm->show();
}

QString SmartCalc::get_Text() {
    return ui->lineEdit->text();
}

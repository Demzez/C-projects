#include "credit.h"

#include "ui_credit.h"

Credit::Credit(QWidget * parent):
    QWidget(parent),
    ui(new Ui::Credit) {
        ui->setupUi(this);
        // remove?
        ui->result_pay->setTextInteractionFlags(Qt::TextSelectableByMouse);
        ui->result_proc->setTextInteractionFlags(Qt::TextSelectableByMouse);
        ui->result_pay_proc->setTextInteractionFlags(Qt::TextSelectableByMouse);

        connect(ui->button_OK, SIGNAL(clicked()), this, SLOT(calculateCredit()));
    }

Credit::~Credit() {
    delete ui;
}

void Credit::calculateCredit() {
    QString credit_sum = ui->credit_sum_line->text();
    QString credit_time = ui->credit_time_line->text();
    QString credit_rate = ui->interest_rate_line->text();
    if (verification(credit_sum) && verification(credit_rate) && verification_digit(credit_time)) {
        double sum = credit_sum.toDouble();
        int time = credit_time.toInt();
        double final_rate = credit_rate.toDouble();
        if ((time <= 600) && (final_rate < 100) && (time > 0) && (final_rate > 0) && (sum >= 0)) {
            if (ui->button_annu->isChecked())
                annuChecked(sum, time, final_rate);
            if (ui->button_diff->isChecked())
                diffChecked(sum, time, final_rate);
        } else {
            errorMsg("Некоррентная числовая запись! Попробуйте еще раз.");
        }
    } else {
        errorMsg("Некоррентная числовая запись! Попробуйте еще раз.");
    }
}

void Credit::annuChecked(double sum, int time, double final_rate) {
    double rate_in_month = final_rate / 12.0 / 100.0;
    double annuitent = rate_in_month * pow((rate_in_month + 1), time) / (pow((rate_in_month + 1), time) - 1);
    double pay_in_month = sum * annuitent;
    pay_in_month = floor(pay_in_month * 100 + 0.5) / 100;
    double debt = pay_in_month * time;
    ui->result_pay->setText(QString::number(pay_in_month, 'f', 2));
    ui->result_proc->setText(QString::number(debt - sum, 'f', 1) + "0");
    ui->result_pay_proc->setText(QString::number(debt, 'f', 1) + "0");
}

void Credit::diffChecked(double sum, int time, double final_rate) {
    double final_pay_month = sum / time;
    double interest_in_month = 0.0, sum_proc = 0.0, sum_dolg = 0.0;
    double pay_1 = 0.0;
    for (int i = 0; i < time; i++) {
        interest_in_month = (((sum - (final_pay_month * i)) * final_rate) / 12.0) / 100;
        if (i == 0)
            pay_1 = final_pay_month + interest_in_month;
        sum_proc += interest_in_month;
    }
    sum_dolg = sum + sum_proc;
    ui->result_pay->setText(QString::number(pay_1, 'f', 2) + " ... " + QString::number(final_pay_month + interest_in_month, 'f', 2));
    ui->result_proc->setText(QString::number(sum_proc, 'f', 2));
    ui->result_pay_proc->setText(QString::number(sum_dolg, 'f', 2));
}

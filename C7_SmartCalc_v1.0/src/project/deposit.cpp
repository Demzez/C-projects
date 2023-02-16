#include "deposit.h"

#include "ui_deposit.h"

Deposit::Deposit(QWidget * parent):
    QWidget(parent),
    ui(new Ui::Deposit) {
        ui->setupUi(this);
        index_vyp = 0;
        index_pop = 0;
        index_snyat = 0;
        connect(ui->button_OK, SIGNAL(clicked()), this, SLOT(calculateDeposit()));
    }

Deposit::~Deposit() {
    delete ui;
}

void Deposit::calculateDeposit() {
    QString dep_amount = ui->dep_amountLine->text();
    QString dep_time = ui->dep_timeLine->text();
    QString dep_per = ui->dep_perLine->text();
    QString dep_tax = ui->dep_taxLine->text();
    QString dep_replen = ui->dep_replenLine->text();
    QString dep_withd = ui->dep_withdLine->text();

    if (verification(dep_amount) && verification(dep_per) && verification(dep_tax) &&
        verification_digit(dep_time) && verification(dep_replen) && verification(dep_withd)) {
        double sum = dep_amount.toDouble();
        int time = dep_time.toInt();
        double rate = dep_per.toDouble();
        double tax_rate = dep_tax.toDouble();
        double sum_replen = dep_replen.toDouble();
        double sum_withd = dep_withd.toDouble();
        double sum_prec = 0.0, NDFL = 0.0, NDFL_year = 0.0;

        if (time <= 600 && rate < 100 && time > 0 && rate >= 0 && sum >= 0 &&
            sum_replen >= 0 && sum_withd >= 0 && tax_rate >= 0 && tax_rate < 100) {

            double limit_tax = tax_rate * 10000;
            QDate date_now = ui->dateEdit->date();
            QDate date_end = date_now.addMonths(time);
            QDate date_replen = date_now_add(date_now, index_pop);
            QDate date_withd = date_now_add(date_now, index_snyat);
            QDate date_tax;
            QDate date_payout = date_payout_index(date_now, index_vyp);
            int year_now = date_now.year();

            date_tax = date_payout;
            if (index_vyp == 0) {
                date_tax.setDate(date_now.year(), 12, 31);
            } else if (index_vyp == 6) {
                date_tax = date_now;
            } else {
                while ((int) date_tax.year() == year_now) {
                    QDate date_tax_temp = date_payout_index(date_tax, index_vyp);
                    if ((int) date_tax_temp.year() == year_now)
                        date_tax = date_tax_temp;
                    else break;
                }
            }

            if (ui->capitalRadio->isChecked() && index_vyp != 6)
                capitalClicked(date_now, date_end, sum, rate, limit_tax, sum_replen, sum_withd, sum_prec, date_replen, date_withd,
                    date_payout, date_tax, NDFL, NDFL_year);
            else
                capitalNotClicked(date_now, date_end, sum, rate, limit_tax, sum_replen, sum_withd, sum_prec, date_replen, date_withd,
                    date_tax, NDFL, NDFL_year);

        } else {
            errorMsg("Введены некорректные данные! Попробуйте еще раз");
        }
    } else {
        errorMsg("Введены некорректные данные! Попробуйте еще раз");
    }
}

void Deposit::capitalClicked(QDate date_now, QDate date_end, double sum, double rate, double limit_tax, double sum_replen, double sum_withd,
    double sum_prec, QDate date_replen, QDate date_withd, QDate date_payout, QDate date_tax, double NDFL, double NDFL_year) {
    double sum_capital = 0.0;
    while (date_now != date_end) {
        date_now = date_now.addDays(1);
        double days_year = date_now.daysInYear();
        double summa_kapital_temp = sum * (1 + (rate / (100.0 * days_year))) - sum;
        sum_capital = sum_capital + summa_kapital_temp;
        NDFL_year += summa_kapital_temp;
        if (index_snyat != 0 && date_now == date_withd) {
            sum -= sum_withd;
            if (sum < 0) {
                sum += sum_withd;
            }
            date_withd = date_now_add(date_now, index_snyat);
        }
        if (date_now == date_withd) {
            sum_prec += sum_capital;
            sum += sum_capital;
            sum_capital = 0;
            date_payout = date_payout_index(date_now, index_vyp);
        }
        if (date_now == date_tax) {
            if (NDFL_year > limit_tax && date_tax.year() != 2022) NDFL = NDFL + ((NDFL_year - limit_tax) * 0.13);
            NDFL_year = 0;
            if (index_vyp == 1) {
                date_tax = date_tax.addDays(364);
                QDate temp_date = date_tax.addDays(7);
                if (temp_date.year() == date_tax.year()) {
                    date_tax.setDate(temp_date.year(), temp_date.month(), temp_date.day());
                }
            } else date_tax = date_tax.addYears(1);
        }
        if (index_pop != 0 && date_now == date_replen) {
            sum += sum_replen;
            date_replen = date_now_add(date_now, index_pop);
        }
        if (date_now == date_end) {
            sum_prec += sum_capital;
            sum += sum_capital;
            if (NDFL_year > limit_tax) NDFL = NDFL + ((NDFL_year - limit_tax) * 0.13);
        }
    }
    ui->result_proc->setText(QString::number(sum_prec, 'f', 2));
    ui->result_nalog->setText(QString::number(NDFL, 'f', 2));
    ui->result_summa_vklad->setText(QString::number(sum, 'f', 2));
}

void Deposit::capitalNotClicked(QDate date_now, QDate date_end, double sum, double rate, double limit_tax, double sum_replen, double sum_withd,
    double sum_prec, QDate date_replen, QDate date_withd, QDate date_tax, double NDFL, double NDFL_year) {
    while (date_now != date_end) {
        date_now = date_now.addDays(1);
        double days_year = date_now.daysInYear();
        double profit = (sum * rate) / (days_year * 100.0);
        sum_prec += profit;
        NDFL_year += profit;
        if (date_now == date_tax) {
            if (NDFL_year > limit_tax && date_tax.year() != 2022) NDFL = NDFL + ((NDFL_year - limit_tax) * 0.13);
            NDFL_year = 0;
            if (index_vyp == 1) {
                date_tax = date_tax.addDays(364);
                QDate temp_date = date_tax.addDays(7);
                if (temp_date.year() == date_tax.year()) {
                    date_tax.setDate(temp_date.year(), temp_date.month(), temp_date.day());
                }
            } else
                date_tax = date_tax.addYears(1);
        }
        if (date_now == date_end && NDFL_year > limit_tax) NDFL = NDFL + ((NDFL_year - limit_tax) * 0.13);
        if (index_pop != 0 && date_now == date_replen) {
            sum += sum_replen;
            date_replen = date_now_add(date_now, index_pop);
        }
        if (index_snyat != 0 && date_now == date_withd) {
            sum -= sum_withd;
            if (sum < 0) {
                sum = 0;
                break;
            }
            date_withd = date_now_add(date_now, index_snyat);
        }
    }

    if (index_vyp == 6 && ui->capitalRadio->isChecked())
        sum = sum + sum_prec;

    ui->result_proc->setText(QString::number(sum_prec, 'f', 2));
    ui->result_nalog->setText(QString::number(NDFL, 'f', 2));
    ui->result_summa_vklad->setText(QString::number(sum, 'f', 2));
}

void Deposit::on_Box_vyplaty_activated(int index) {
    index_vyp = index;
}

void Deposit::on_Box_popoln_activated(int index) {
    index_pop = index;
    if (index == 0) {
        ui->dep_replenLine->setEnabled(false);
        ui->dep_replenLine->setStyleSheet("QLineEdit { background: rgb(200, 211, 201); border: 2px solid black;}");
    } else {
        ui->dep_replenLine->setEnabled(true);
        ui->dep_replenLine->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); border: 2px solid black;}");
    }
}

void Deposit::on_Box_snyat_activated(int index) {
    index_snyat = index;
    if (index == 0) {
        ui->dep_withdLine->setEnabled(false);
        ui->dep_withdLine->setStyleSheet("QLineEdit { background: rgb(200, 211, 201); border: 2px solid black;}");
    } else {
        ui->dep_withdLine->setEnabled(true);
        ui->dep_withdLine->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); border: 2px solid black;}");
    }
}

QDate date_now_add(QDate date_now, int index) {
    QDate result;
    if (index == 1) {
        result = date_now.addMonths(1);
    }
    if (index == 2) {
        result = date_now.addMonths(2);
    }
    if (index == 3) {
        result = date_now.addMonths(3);
    }
    if (index == 4) {
        result = date_now.addMonths(6);
    }
    if (index == 5) {
        result = date_now.addYears(1);
    }
    return result;
}

QDate date_payout_index(QDate date_now, int index) {
    QDate result;
    if (index == 0) {
        result = date_now.addDays(1);
    }
    if (index == 1) {
        result = date_now.addDays(7);
    }
    if (index == 2) {
        result = date_now.addMonths(1);
    }
    if (index == 3) {
        result = date_now.addMonths(3);
    }
    if (index == 4) {
        result = date_now.addMonths(6);
    }
    if (index == 5) {
        result = date_now.addYears(1);
    }
    if (index == 6) {
        result = date_now.addMonths(1);
    }
    return result;
}

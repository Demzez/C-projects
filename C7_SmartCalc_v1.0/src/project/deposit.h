#ifndef SRC_PROJECT_DEPOSIT_H_
#define SRC_PROJECT_DEPOSIT_H_

#include <QWidget>
#include <QDate>
#include "helpers.h"

namespace Ui {
class Deposit;
}

class Deposit: public QWidget {
    Q_OBJECT

    public: Deposit(QWidget * parent = nullptr);
    ~Deposit();

    private slots:
        void calculateDeposit();
        void capitalClicked(QDate date_now, QDate date_end, double sum, double rate,
                            double limit_tax, double sum_replen, double sum_withd,
                            double sum_prec, QDate date_replen, QDate date_withd, QDate date_payout,
                            QDate date_tax, double NDFL, double NDFL_year);
        void capitalNotClicked(QDate date_now, QDate date_end, double sum, double rate,
                               double limit_tax, double sum_replen, double sum_withd,
                               double sum_prec, QDate date_replen, QDate date_withd,
                               QDate date_tax, double NDFL, double NDFL_year);
        void on_Box_vyplaty_activated(int index);
        void on_Box_popoln_activated(int index);
        void on_Box_snyat_activated(int index);

    private:
        Ui::Deposit * ui;

    int index_vyp;
    int index_pop;
    int index_snyat;
};

QDate date_now_add(QDate date_now, int index);
QDate date_payout_index(QDate date_now, int index);

#endif  // SRC_PROJECT_DEPOSIT_H_

#ifndef SRC_PROJECT_CREDIT_H_
#define SRC_PROJECT_CREDIT_H_

#include <QWidget>
#include "helpers.h"

namespace Ui {
class Credit;
}

class Credit: public QWidget {
    Q_OBJECT

    public: Credit(QWidget * parent = nullptr);
    ~Credit();

    private slots:
        void calculateCredit();
        void annuChecked(double sum, int time, double final_rate);
        void diffChecked(double sum, int time, double final_rate);

    private:
        Ui::Credit * ui;
};

#endif  // SRC_PROJECT_CREDIT_H_

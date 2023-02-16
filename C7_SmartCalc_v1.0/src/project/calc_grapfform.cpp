#include "smartcalc.h"


void SmartCalc::grapfForm() {
    QGridLayout * gridLayout_2;
    QLabel * label_2;
    QLabel * label;

    graphFormLayout = new QGridLayout();
    graphFormLayout->setObjectName(QString::fromUtf8("gridLayout"));
    widget = new QCustomPlot();
    widget->setObjectName(QString::fromUtf8("widget"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
    widget->setSizePolicy(sizePolicy);
    widget->setMinimumSize(QSize(0, 57));

    graphFormLayout->addWidget(widget, 0, 0, 1, 2);

    gridLayout_2 = new QGridLayout();
    gridLayout_2->setSpacing(0);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    gridLayout_2->setContentsMargins(0, 0, 0, 0);

    label_2 = new QLabel();
    label_2->setObjectName(QString::fromUtf8("label_2"));

    label_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    label_2->setMinimumSize(QSize(0, 0));
    label_2->setStyleSheet("color: black;");
    QFont font;
    font.setFamilies({
        QString::fromUtf8("Arial")
    });
    font.setPointSize(13);
    label_2->setFont(font);

    gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

    label = new QLabel();
    label->setObjectName(QString::fromUtf8("label"));

    label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    label->setMinimumSize(QSize(0, 0));
    label->setStyleSheet("color: black;");
    label->setFont(font);

    gridLayout_2->addWidget(label, 0, 0, 1, 1);

    MaxX = new QLineEdit();
    MaxX->setObjectName(QString::fromUtf8("MaxX"));

    MaxX->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    MaxX->setMinimumSize(QSize(0, 0));
    MaxX->setStyleSheet("color: black;");
    QFont font1;
    font1.setPointSize(13);
    MaxX->setFont(font1);

    gridLayout_2->addWidget(MaxX, 0, 3, 1, 1);

    MinX = new QLineEdit();
    MinX->setObjectName(QString::fromUtf8("MinX"));

    MinX->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    MinX->setMinimumSize(QSize(0, 20));
    MinX->setStyleSheet("color: black;");
    MinX->setFont(font1);

    gridLayout_2->addWidget(MinX, 0, 1, 1, 1);

    graphFormLayout->addLayout(gridLayout_2, 1, 0, 2, 1);

    label_2->setText(QCoreApplication::translate("Graph", "Max x", nullptr));
    label->setText(QCoreApplication::translate("Graph", "Min x", nullptr));

    graphFormWidget = new QWidget(this);
    graphFormWidget->setLayout(graphFormLayout);

}

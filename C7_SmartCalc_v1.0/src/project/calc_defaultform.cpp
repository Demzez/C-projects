#include "smartcalc.h"

#include "ui_smartcalc.h"

void SmartCalc::defaultFormUI() {
    QPushButton * Button_Backspace =
        new QPushButton(QString::fromUtf8("\u232B"), this);
    QPushButton * Button_Clear = new QPushButton(QString::fromUtf8("C"), this);
    QPushButton * Button_Credit = new QPushButton(QString::fromUtf8("Credit calc"), this);
    QPushButton * Button_Deposit = new QPushButton(QString::fromUtf8("Deposit calc"), this);
    Button_openGraph = new QPushButton(QString::fromUtf8("Open graph\nform"), this);

    Button_Credit->setStyleSheet(StyleSheetCalcsButton);
    Button_Deposit->setStyleSheet(StyleSheetCalcsButton + "border-top: 0.5px");

    Button_openGraph->setStyleSheet(StyleSheetGraphButton);

    Button_Backspace->setStyleSheet(StyleSheetBackSpace);
    ui->lineEdit->setStyleSheet(StyleSheetLine);
    Button_Clear->setStyleSheet(StyleSheetBackSpace);

    Button_Backspace->setSizePolicy(QSizePolicy::Preferred,
        QSizePolicy::Preferred);
    Button_Clear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    defaultFormLayout = new QGridLayout();
    defaultFormLayout->setSpacing(0);
    defaultFormLayout->setContentsMargins(0, 0, 0, 0);

    defaultFormLayout->addWidget(ui->lineEdit, 0, 0, 2, 5);
    defaultFormLayout->addWidget(Button_Credit, 2, 0, 1, 2);
    defaultFormLayout->addWidget(Button_Deposit, 3, 0, 1, 2);
    defaultFormLayout->addWidget(Button_Backspace, 2, 3, 2, 1);
    defaultFormLayout->addWidget(Button_Clear, 2, 4, 2, 1);
    defaultFormLayout->addWidget(Button_openGraph, 2, 2, 2, 1); //2 1 1 2

    defaultFormWidget = new QWidget(this);
    defaultFormWidget->setLayout(defaultFormLayout);

    connect(Button_Credit, SIGNAL(clicked()), this, SLOT(openCreditCalc()));
    connect(Button_Deposit, SIGNAL(clicked()), this, SLOT(openDepositCalc()));
    connect(Button_Backspace, SIGNAL(clicked()), this, SLOT(backspaceClicked()));
    connect(Button_Clear, SIGNAL(clicked()), this, SLOT(clearClicked()));
    connect(Button_openGraph, SIGNAL(clicked()), this, SLOT(openGraph()));

    Button_Backspace->setShortcut(QKeySequence(Qt::Key_Backspace));
    Button_Clear->setShortcut(QKeySequence(Qt::Key_Escape));

    Button_Credit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Deposit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_openGraph->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
}

void SmartCalc::createForm() {
    setWindowTitle("SmartCalc v1.0");
    setWindowOpacity(0.98);
    setMinimumSize(685, 450);
    setMaximumSize(685, 450);
    setStyleSheet("background-color: white");

    ui->lineEdit->setPlaceholderText("0");
    ui->lineEdit->setAlignment(Qt::AlignRight);
    ui->lineEdit->setReadOnly(true);

    mainModeUI();
    defaultFormUI();
    grapfForm();

    mainFormWidget = new QWidget;
    mainFormLayout = new QGridLayout;
    mainFormLayout->setSpacing(0);
    mainFormLayout->addWidget(defaultFormWidget, 0, 0, 1, 7);
    mainFormLayout->addWidget(mainFormWidget_left, 1, 0, 2, 4); // 1, 0, 2, 4
    mainFormLayout->addWidget(mainFormWidget_right, 1, 4, 2, 3); // 1, 4, 2, 5

    mainFormWidget->setLayout(mainFormLayout);
    setCentralWidget(mainFormWidget);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
}

void SmartCalc::createForm_two() {
    mainFormWidget = new QWidget;
    mainFormLayout = new QGridLayout;

    setWindowTitle("SmartCalc v1.0");
    setWindowOpacity(0.98);
    setMinimumSize(1200, 450);
    setMaximumSize(1200, 450);
    setStyleSheet("background-color: white");
    mainFormLayout->addWidget(defaultFormWidget, 0, 0, 1, 7);
    mainFormLayout->addWidget(mainFormWidget_left, 1, 0, 2, 4); // 1, 0, 2, 4
    mainFormLayout->addWidget(mainFormWidget_right, 1, 4, 2, 3); // 1, 4, 2, 5
    mainFormLayout->addWidget(graphFormWidget, 0, 8, 3, 3); // 0 5 3 3

    mainFormWidget->setLayout(mainFormLayout);
    setCentralWidget(mainFormWidget);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
}

void SmartCalc::openGraph() {
    if (!graphForm_flag) {
        delete mainFormLayout;
        createForm_two();
        Button_openGraph->setText("Close graph\nform");
        graphForm_flag = true;
    } else {
        delete mainFormLayout;
        createForm();
        Button_openGraph->setText("Open graph\nform");
        graphForm_flag = false;
    }
}

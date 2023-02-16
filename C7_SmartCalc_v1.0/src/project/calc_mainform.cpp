#include "smartcalc.h"

#include "ui_smartcalc.h"

void SmartCalc::mainModeUI() {
    QPushButton * Button_0 = new QPushButton("0");
    QPushButton * Button_1 = new QPushButton("1");
    QPushButton * Button_2 = new QPushButton("2");
    QPushButton * Button_3 = new QPushButton("3");
    QPushButton * Button_4 = new QPushButton("4");
    QPushButton * Button_5 = new QPushButton("5");
    QPushButton * Button_6 = new QPushButton("6");
    QPushButton * Button_7 = new QPushButton("7");
    QPushButton * Button_8 = new QPushButton("8");
    QPushButton * Button_9 = new QPushButton("9");
    QPushButton * Button_Dot = new QPushButton(".");
    QPushButton * Button_Plus = new QPushButton("+");
    QPushButton * Button_Mod = new QPushButton("%");
    QPushButton * Button_Minus = new QPushButton(QString::fromUtf8("-"));
    QPushButton * Button_Mult = new QPushButton(QString::fromUtf8("*"));
    QPushButton * Button_Div = new QPushButton(QString::fromUtf8("\u00F7"));
    QPushButton * Button_Equal = new QPushButton("=");
    QPushButton * Button_FX = new QPushButton(QString::fromUtf8("X"));

    Button_0->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Plus->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Mod->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Minus->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Dot->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Mult->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Div->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Equal->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_FX->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    Button_0->setStyleSheet(StyleSheetNumbers);
    Button_1->setStyleSheet(StyleSheetNumbers);
    Button_2->setStyleSheet(StyleSheetNumbers);
    Button_3->setStyleSheet(StyleSheetNumbers);
    Button_4->setStyleSheet(StyleSheetNumbers);
    Button_5->setStyleSheet(StyleSheetNumbers);
    Button_6->setStyleSheet(StyleSheetNumbers);
    Button_7->setStyleSheet(StyleSheetNumbers);
    Button_8->setStyleSheet(StyleSheetNumbers);
    Button_9->setStyleSheet(StyleSheetNumbers);
    Button_Plus->setStyleSheet(StyleSheetSigns);
    Button_Mod->setStyleSheet(StyleSheetSigns);
    Button_Minus->setStyleSheet(StyleSheetSigns);
    Button_Dot->setStyleSheet(StyleSheetSigns);
    Button_Mult->setStyleSheet(StyleSheetSigns);
    Button_Div->setStyleSheet(StyleSheetSigns);
    Button_Equal->setStyleSheet(StyleSheetSigns);
    Button_FX->setStyleSheet(StyleSheetSigns);

    mainFormLayout_left = new QGridLayout(); // removed 'this'
    mainFormLayout_left->setSpacing(0);
    mainFormLayout_left->setContentsMargins(0, 0, 0, 0);

    mainFormLayout_left->addWidget(Button_7, 0, 0, 1, 1);
    mainFormLayout_left->addWidget(Button_8, 0, 1, 1, 1);
    mainFormLayout_left->addWidget(Button_9, 0, 2, 1, 1);
    mainFormLayout_left->addWidget(Button_Div, 0, 3, 1, 1);
    mainFormLayout_left->addWidget(Button_Mod, 0, 4, 1, 1);
    mainFormLayout_left->addWidget(Button_4, 1, 0, 1, 1);
    mainFormLayout_left->addWidget(Button_5, 1, 1, 1, 1);
    mainFormLayout_left->addWidget(Button_6, 1, 2, 1, 1);
    mainFormLayout_left->addWidget(Button_Mult, 1, 3, 1, 1);
    mainFormLayout_left->addWidget(Button_FX, 1, 4, 1, 1);
    mainFormLayout_left->addWidget(Button_1, 2, 0, 1, 1);
    mainFormLayout_left->addWidget(Button_2, 2, 1, 1, 1);
    mainFormLayout_left->addWidget(Button_3, 2, 2, 1, 1);
    mainFormLayout_left->addWidget(Button_Minus, 2, 3, 1, 1);
    mainFormLayout_left->addWidget(Button_Equal, 2, 4, 2, 1);
    mainFormLayout_left->addWidget(Button_0, 3, 0, 1, 2);
    mainFormLayout_left->addWidget(Button_Dot, 3, 2, 1, 1);
    mainFormLayout_left->addWidget(Button_Plus, 3, 3, 1, 1);

    mainFormWidget_left = new QWidget(this);
    mainFormWidget_left->setLayout(mainFormLayout_left);

    connect(Button_0, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(Button_1, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(Button_2, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(Button_3, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(Button_4, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(Button_5, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(Button_6, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(Button_7, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(Button_8, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(Button_9, SIGNAL(clicked()), this, SLOT(digitClicked()));

    Button_0->setShortcut(QKeySequence(Qt::Key_0));
    Button_1->setShortcut(QKeySequence(Qt::Key_1));
    Button_2->setShortcut(QKeySequence(Qt::Key_2));
    Button_3->setShortcut(QKeySequence(Qt::Key_3));
    Button_4->setShortcut(QKeySequence(Qt::Key_4));
    Button_5->setShortcut(QKeySequence(Qt::Key_5));
    Button_6->setShortcut(QKeySequence(Qt::Key_6));
    Button_7->setShortcut(QKeySequence(Qt::Key_7));
    Button_8->setShortcut(QKeySequence(Qt::Key_8));
    Button_9->setShortcut(QKeySequence(Qt::Key_9));

    connect(Button_Plus, SIGNAL(clicked()), this, SLOT(operationsClicked()));
    connect(Button_Minus, SIGNAL(clicked()), this, SLOT(operationsClicked()));
    connect(Button_Mult, SIGNAL(clicked()), this, SLOT(operationsClicked()));
    connect(Button_Div, SIGNAL(clicked()), this, SLOT(operationsClicked()));
    connect(Button_Mod, SIGNAL(clicked()), this, SLOT(operationsClicked()));
    connect(Button_Dot, SIGNAL(clicked()), this, SLOT(operationsClicked()));
    connect(Button_Equal, SIGNAL(clicked()), this, SLOT(equalClicked()));
    connect(Button_FX, SIGNAL(clicked()), this, SLOT(digitClicked()));

    Button_Plus->setShortcut(QKeySequence(Qt::Key_Plus));
    Button_Mod->setShortcut(QKeySequence(Qt::SHIFT | Qt::Key_5));
    Button_Minus->setShortcut(QKeySequence(Qt::Key_Minus));
    Button_Mult->setShortcut(QKeySequence(Qt::SHIFT | Qt::Key_8));
    Button_Div->setShortcut(QKeySequence("/")); // !!
    Button_Dot->setShortcut(QKeySequence(Qt::Key_Period));
    Button_Equal->setShortcut(QKeySequence(Qt::Key_Return));
    Button_FX->setShortcut(QKeySequence(Qt::Key_X));

    QPushButton * Button_Sin = new QPushButton("sin");
    QPushButton * Button_Asin = new QPushButton("asin");
    QPushButton * Button_leftBracket = new QPushButton(QString::fromUtf8("("));
    QPushButton * Button_rightBracket = new QPushButton(QString::fromUtf8(")"));
    QPushButton * Button_Cos = new QPushButton("cos");
    QPushButton * Button_Acos = new QPushButton("acos");
    QPushButton * Button_Ln = new QPushButton("ln");
    QPushButton * Button_Tan = new QPushButton("tan");
    QPushButton * Button_Atan = new QPushButton("atan");
    QPushButton * Button_Log = new QPushButton("log");
    QPushButton * Button_Xned = new QPushButton(QString::fromUtf8("x\u207F"));
    QPushButton * Button_Sqrt = new QPushButton(QString::fromUtf8("\u221A"));

    Button_Sin->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Asin->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_leftBracket->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_rightBracket->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Cos->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Acos->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Ln->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Tan->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Atan->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Log->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Xned->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button_Sqrt->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    Button_Cos->setStyleSheet(StyleSheetSpecSigns);
    Button_Acos->setStyleSheet(StyleSheetSpecSigns);
    Button_Sin->setStyleSheet(StyleSheetSpecSigns);
    Button_Asin->setStyleSheet(StyleSheetSpecSigns);
    Button_leftBracket->setStyleSheet(StyleSheetSpecSigns);
    Button_Tan->setStyleSheet(StyleSheetSpecSigns);
    Button_Atan->setStyleSheet(StyleSheetSpecSigns);
    Button_Ln->setStyleSheet(StyleSheetSpecSigns);
    Button_Log->setStyleSheet(StyleSheetSpecSigns);
    Button_rightBracket->setStyleSheet(StyleSheetSpecSigns);
    Button_Xned->setStyleSheet(StyleSheetSpecSigns);
    Button_Sqrt->setStyleSheet(StyleSheetSpecSigns);

    mainFormLayout_right = new QGridLayout(); // removed 'this'
    mainFormLayout_right->setSpacing(0);
    mainFormLayout_right->setContentsMargins(0, 0, 0, 0);

    mainFormLayout_right->addWidget(Button_Sin, 0, 0, 1, 1);
    mainFormLayout_right->addWidget(Button_Asin, 0, 1, 1, 1);
    mainFormLayout_right->addWidget(Button_leftBracket, 1, 3, 1, 1);
    mainFormLayout_right->addWidget(Button_rightBracket, 2, 3, 1, 1);
    mainFormLayout_right->addWidget(Button_Cos, 1, 0, 1, 1);
    mainFormLayout_right->addWidget(Button_Acos, 1, 1, 1, 1);
    mainFormLayout_right->addWidget(Button_Ln, 1, 2, 1, 1);
    mainFormLayout_right->addWidget(Button_Tan, 2, 0, 1, 1);
    mainFormLayout_right->addWidget(Button_Atan, 2, 1, 1, 1);
    mainFormLayout_right->addWidget(Button_Log, 2, 2, 1, 1);
    mainFormLayout_right->addWidget(Button_Xned, 0, 2, 1, 1);
    mainFormLayout_right->addWidget(Button_Sqrt, 0, 3, 1, 1);
    //mainFormLayout_right->addWidget(Button_Clear, 0, 3, 1, 1);

    mainFormWidget_right = new QWidget(this);
    mainFormWidget_right->setLayout(mainFormLayout_right);

    connect(Button_Asin, SIGNAL(clicked()), this, SLOT(functionsClicked()));
    connect(Button_Log, SIGNAL(clicked()), this, SLOT(functionsClicked()));
    connect(Button_Ln, SIGNAL(clicked()), this, SLOT(functionsClicked()));
    connect(Button_Sin, SIGNAL(clicked()), this, SLOT(functionsClicked()));
    connect(Button_Acos, SIGNAL(clicked()), this, SLOT(functionsClicked()));
    connect(Button_Cos, SIGNAL(clicked()), this, SLOT(functionsClicked()));
    connect(Button_Atan, SIGNAL(clicked()), this, SLOT(functionsClicked()));
    connect(Button_Tan, SIGNAL(clicked()), this, SLOT(functionsClicked()));
    connect(Button_Xned, SIGNAL(clicked()), this, SLOT(operationsClicked()));
    connect(Button_leftBracket, SIGNAL(clicked()), this, SLOT(operationsClicked()));
    connect(Button_rightBracket, SIGNAL(clicked()), this, SLOT(operationsClicked()));
    connect(Button_Sqrt, SIGNAL(clicked()), this, SLOT(functionsClicked()));

    Button_leftBracket->setShortcut(QKeySequence("("));
    Button_rightBracket->setShortcut(QKeySequence(")"));
}

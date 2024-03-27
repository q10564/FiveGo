/********************************************************************************
** Form generated from reading UI file 'fiveGo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIVEGO_H
#define UI_FIVEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fiveGoClass
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_localhost;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *btn_connect;
    QPushButton *btn_start;
    QPushButton *btn_defult;
    QPushButton *btn_history;
    QSpacerItem *verticalSpacer;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox;
    QPushButton *btn_send;

    void setupUi(QWidget *fiveGoClass)
    {
        if (fiveGoClass->objectName().isEmpty())
            fiveGoClass->setObjectName(QStringLiteral("fiveGoClass"));
        fiveGoClass->resize(850, 514);
        fiveGoClass->setMinimumSize(QSize(850, 514));
        fiveGoClass->setMaximumSize(QSize(850, 514));
        QFont font;
        font.setPointSize(9);
        fiveGoClass->setFont(font);
        fiveGoClass->setStyleSheet(QString::fromUtf8("/*\n"
"ElegantDark Style Sheet for QT Applications\n"
"Author: Jaime A. Quiroga P.\n"
"Company: GTRONICK\n"
"Last updated: 17/04/2018\n"
"Available at: https://github.com/GTRONICK/QSS/blob/master/ElegantDark.qss\n"
"*/\n"
"QWidget {\n"
"	background-color:rgb(82, 82, 82);\n"
"}\n"
"QTextEdit {\n"
"	background-color:rgb(62, 62, 62);\n"
"	color: rgb(0, 255, 0);\n"
"}\n"
"QPushButton{\n"
"	border-radius:25px;\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-bottom-color: rgb(58, 58, 58);\n"
"	border-bottom-width: 1px;\n"
"	border-style: solid;\n"
"	color: rgb(255, "
                        "255, 255);\n"
"	padding: 2px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(77, 77, 77, 255), stop:1 rgba(97, 97, 97, 255));\n"
"}\n"
"QPushButton:hover{\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(180, 180, 180, 255), stop:1 rgba(110, 110, 110, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(180, 180, 180, 255), stop:1 rgba(110, 110, 110, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(180, 180, 180, 255), stop:1 rgba(110, 110, 110, 255));\n"
"	border-bottom-color: rgb(115, 115, 115);\n"
"	border-bottom-width: 1px;\n"
"	border-style: solid;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 2px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(107, 107, 107, 255), stop:1 rgba(157, 157, 157, 255));\n"
"}\n"
"QPushButton:"
                        "pressed{\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(62, 62, 62, 255), stop:1 rgba(22, 22, 22, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-bottom-color: rgb(58, 58, 58);\n"
"	border-bottom-width: 1px;\n"
"	border-style: solid;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 2px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(77, 77, 77, 255), stop:1 rgba(97, 97, 97, 255));\n"
"}\n"
"QPushButton:disabled{\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
""
                        "	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-bottom-color: rgb(58, 58, 58);\n"
"	border-bottom-width: 1px;\n"
"	border-style: solid;\n"
"	color: rgb(0, 0, 0);\n"
"	padding: 2px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(57, 57, 57, 255), stop:1 rgba(77, 77, 77, 255));\n"
"}\n"
"QLineEdit {\n"
"	border-width: 1px; border-radius: 4px;\n"
"	border-color: rgb(200, 200, 200);\n"
"	border-style: inset;\n"
"	padding: 0 8px;\n"
"	color: rgb(255, 255, 255);\n"
"	background:rgb(100, 100, 100);\n"
"	selection-background-color: rgb(187, 187, 187);\n"
"	selection-color: rgb(60, 63, 65);\n"
"}\n"
"QLineEdit::hover {\n"
"	border-color: rgb(10, 255, 10);\n"
"}\n"
"QLabel {\n"
"	color:rgb(255,255,255);	\n"
"}\n"
"QProgressB"
                        "ar {\n"
"	text-align: center;\n"
"	color: rgb(240, 240, 240);\n"
"	border-width: 1px; \n"
"	border-radius: 10px;\n"
"	border-color: rgb(158, 158, 158);\n"
"	border-style: outset;\n"
"	background-color:rgb(77,77,77);\n"
"}\n"
"QProgressBar::chunk {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0.7, x2:0.5, y2:0.3, stop:0 rgba(10, 200, 10, 255), stop:1 rgba(20, 200, 20, 255));\n"
"	border-radius: 10px;\n"
"}\n"
"QMenuBar {\n"
"	background:rgb(82, 82, 82);\n"
"}\n"
"QMenuBar::item {\n"
"	color:rgb(223,219,210);\n"
"	spacing: 3px;\n"
"	padding: 1px 4px;\n"
"	background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"	background:rgb(115, 115, 115);\n"
"}\n"
"QMenu::item:selected {\n"
"	color:rgb(255,255,255);\n"
"	border-width:2px;\n"
"	border-style:solid;\n"
"	padding-left:18px;\n"
"	padding-right:8px;\n"
"	padding-top:2px;\n"
"	padding-bottom:3px;\n"
"	background:qlineargradient(spread:pad, x1:0.5, y1:0.7, x2:0.5, y2:0.3, stop:0 rgba(87, 97, 106, 255), stop:1 rgba(93, 103, 113, 255));\n"
""
                        "	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(62, 62, 62, 255));\n"
"	border-bottom-color: rgb(58, 58, 58);\n"
"	border-bottom-width: 1px;\n"
"}\n"
"QMenu::item {\n"
"	color:rgb(223,219,210);\n"
"	background-color:rgb(78,78,78);\n"
"	padding-left:20px;\n"
"	padding-top:4px;\n"
"	padding-bottom:4px;\n"
"	padding-right:10px;\n"
"}\n"
"QMenu{\n"
"	background-color:rgb(78,78,78);\n"
"}\n"
"QTabWidget {\n"
"	color:rgb(0,0,0);\n"
"	background-color:rgb(247,246,246);\n"
"}\n"
"QTabWidget::pane {\n"
"		border-color: rgb(77,77,77);\n"
"		background-color:rgb(101,101,101);\n"
"		border-style: solid;\n"
"		border-width: 1px;\n"
"    	border-radius: 6px;"
                        "\n"
"}\n"
"QTabBar::tab {\n"
"	padding:2px;\n"
"	height:40px;\n"
"	width:80px;\n"
"	color:rgb(250,250,250);\n"
"  	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(77, 77, 77, 255), stop:1 rgba(97, 97, 97, 255));\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"  	border-top-right-radius:4px;\n"
"   border-top-left-radius:4px;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:0.6, x2:0.5, y2:0.4, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(95, 92, 93, 255));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.4, y1:0.5, x2:0.6, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(95, 92, 93, 255));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.6, y1:0.5, x2:0.4, y2:0.5, stop:0 rgba(115, 115, 115, 255), stop:1 rgba(95, 92, 93, 255));\n"
"	border-bottom-color: rgb(101,101,101);\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:last:selected, QTabBar::tab:hover {\n"
"  	background-color:rgb(101,101,101);\n"
"  	margin-left: 0px;\n"
"  	margin-rig"
                        "ht: 1px;\n"
"	border-bottom-color: #37efba;\n"
"}\n"
"QTabBar::tab:!selected {\n"
"    	margin-top: 1px;\n"
"		margin-right: 1px;\n"
"}\n"
"QCheckBox {\n"
"	color:rgb(223,219,210);\n"
"	padding: 2px;\n"
"}\n"
"QCheckBox:hover {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	padding-left: 1px;\n"
"	padding-right: 1px;\n"
"	padding-bottom: 1px;\n"
"	padding-top: 1px;\n"
"	border-width:1px;\n"
"	border-color: rgb(87, 197, 106);\n"
"	background-color:qlineargradient(spread:pad, x1:0.5, y1:0.7, x2:0.5, y2:0.3, stop:0 rgba(87, 97, 106, 150), stop:1 rgba(93, 103, 113, 150));\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	border-width:1px;\n"
"	border-color: rgb(180,180,180);\n"
"  	background-color:rgb(20,200,20);\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	border-width:1px;\n"
"	border-color: rgb(87, 97, 106);\n"
"  	background-color:rgb(255,255,255);\n"
"}\n"
"QStatusBar {\n"
"	color:rgb(240,240,240);\n"
"}\n"
""
                        "QComboBox{\n"
"	color:rgb(240,240,240);\n"
"}\n"
"QGroupBox{\n"
"color: rgb(255, 255, 255);\n"
"border: 3px solid gray;\n"
"border-radius:20px;\n"
"margin-top:4px;\n"
"font-family:\346\245\267\344\275\223;\n"
"font:bold 20px;\n"
"}\n"
"QGroupBox::title\n"
"{\n"
"	subcontrol-origin:margin;\n"
"	subcontrol-position:top center;\n"
"	padding:1px;\n"
"}\n"
"QGroupBox::enabled{\n"
"	border: 3px solid gray;\n"
"}\n"
"QGroupBox::!enabled {\n"
"	border: 1px solid gray;\n"
"}\n"
"QSpinBox{\n"
"	color: rgb(255, 255, 255);\n"
"	height:20px;\n"
"}\n"
"QSpinBox:hover{\n"
"	border-color: rgb(10, 255, 10);\n"
"}\n"
"QDoubleSpinBox{\n"
"	color: rgb(255, 255, 255);\n"
"	height:20px;\n"
"}\n"
"QDoubleSpinBox:hover{\n"
"	border-color: rgb(10, 255, 10);\n"
"}\n"
"QRadioButton{\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QSider::sub-page::horizontal{\n"
"	color: rgb(0, 255, 0);\n"
"}\n"
""));
        horizontalLayout_6 = new QHBoxLayout(fiveGoClass);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(fiveGoClass);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_localhost = new QLineEdit(fiveGoClass);
        lineEdit_localhost->setObjectName(QStringLiteral("lineEdit_localhost"));
        lineEdit_localhost->setEnabled(false);

        horizontalLayout->addWidget(lineEdit_localhost);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(fiveGoClass);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(fiveGoClass);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        btn_connect = new QPushButton(fiveGoClass);
        btn_connect->setObjectName(QStringLiteral("btn_connect"));
        btn_connect->setMinimumSize(QSize(120, 50));
        btn_connect->setMaximumSize(QSize(16777215, 50));
        btn_connect->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(btn_connect);

        btn_start = new QPushButton(fiveGoClass);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btn_start);

        btn_defult = new QPushButton(fiveGoClass);
        btn_defult->setObjectName(QStringLiteral("btn_defult"));
        btn_defult->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btn_defult);

        btn_history = new QPushButton(fiveGoClass);
        btn_history->setObjectName(QStringLiteral("btn_history"));
        btn_history->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btn_history);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_6 = new QLabel(fiveGoClass);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_7 = new QLabel(fiveGoClass);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(50, 50));
        label_7->setMaximumSize(QSize(50, 100));
        label_7->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        label_5 = new QLabel(fiveGoClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_4 = new QLabel(fiveGoClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(50, 50));
        label_4->setMaximumSize(QSize(50, 50));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout);

        graphicsView = new QGraphicsView(fiveGoClass);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(490, 490));
        graphicsView->setMaximumSize(QSize(490, 481));

        horizontalLayout_6->addWidget(graphicsView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        textEdit = new QTextEdit(fiveGoClass);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setMaximumSize(QSize(150, 16777215));

        verticalLayout_2->addWidget(textEdit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        comboBox = new QComboBox(fiveGoClass);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaximumSize(QSize(100, 16777215));
        comboBox->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_5->addWidget(comboBox);

        btn_send = new QPushButton(fiveGoClass);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        horizontalLayout_5->addWidget(btn_send);

        horizontalLayout_5->setStretch(0, 4);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_2);


        retranslateUi(fiveGoClass);

        QMetaObject::connectSlotsByName(fiveGoClass);
    } // setupUi

    void retranslateUi(QWidget *fiveGoClass)
    {
        fiveGoClass->setWindowTitle(QApplication::translate("fiveGoClass", "\344\272\224\345\255\220\346\243\213\345\260\217\346\270\270\346\210\217", Q_NULLPTR));
        label->setText(QApplication::translate("fiveGoClass", "\346\234\254\345\234\260IP", Q_NULLPTR));
        label_3->setText(QApplication::translate("fiveGoClass", "\345\257\271\346\226\271IP", Q_NULLPTR));
        btn_connect->setText(QApplication::translate("fiveGoClass", "\345\217\221\350\265\267\345\257\271\345\261\200", Q_NULLPTR));
        btn_start->setText(QApplication::translate("fiveGoClass", "\345\215\225\346\234\272\345\274\200\345\247\213", Q_NULLPTR));
        btn_defult->setText(QApplication::translate("fiveGoClass", "\351\207\215\346\226\260\345\274\200\345\247\213", Q_NULLPTR));
        btn_history->setText(QApplication::translate("fiveGoClass", "\346\237\245\347\234\213\345\216\206\345\217\262\345\257\271\345\261\200", Q_NULLPTR));
        label_6->setText(QApplication::translate("fiveGoClass", "\344\275\240\347\232\204\346\243\213\345\255\220", Q_NULLPTR));
        label_7->setText(QString());
        label_5->setText(QApplication::translate("fiveGoClass", "\345\275\223\345\211\215\346\243\213\345\255\220", Q_NULLPTR));
        label_4->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("fiveGoClass", "\345\277\253\347\202\271\345\220\247\346\210\221\347\255\211\345\276\227\350\212\261\345\204\277\344\271\237\350\260\242\345\225\246", Q_NULLPTR)
         << QApplication::translate("fiveGoClass", "\344\270\215\350\246\201\350\265\260\345\206\263\346\210\230\345\210\260\345\244\251\344\272\256", Q_NULLPTR)
         << QApplication::translate("fiveGoClass", "\344\275\240\346\230\257MM\357\274\214\350\277\230\346\230\257GG", Q_NULLPTR)
        );
        btn_send->setText(QApplication::translate("fiveGoClass", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fiveGoClass: public Ui_fiveGoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIVEGO_H

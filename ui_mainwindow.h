/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *sudokuBoard;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QPushButton *solveBtn;
    QPushButton *clearBtn;
    QPushButton *generateBtn;
    QCheckBox *checkBox;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(879, 717);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sudokuBoard = new QTableWidget(centralwidget);
        if (sudokuBoard->columnCount() < 9)
            sudokuBoard->setColumnCount(9);
        if (sudokuBoard->rowCount() < 9)
            sudokuBoard->setRowCount(9);
        sudokuBoard->setObjectName(QString::fromUtf8("sudokuBoard"));
        sudokuBoard->setGeometry(QRect(20, 130, 541, 541));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Semilight"));
        font.setPointSize(24);
        sudokuBoard->setFont(font);
        sudokuBoard->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sudokuBoard->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sudokuBoard->setAlternatingRowColors(false);
        sudokuBoard->setRowCount(9);
        sudokuBoard->setColumnCount(9);
        sudokuBoard->horizontalHeader()->setVisible(false);
        sudokuBoard->horizontalHeader()->setMinimumSectionSize(60);
        sudokuBoard->horizontalHeader()->setDefaultSectionSize(60);
        sudokuBoard->verticalHeader()->setVisible(false);
        sudokuBoard->verticalHeader()->setDefaultSectionSize(60);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(190, 130, 20, 541));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(6);
        line->setFrameShape(QFrame::VLine);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(370, 130, 20, 541));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(6);
        line_2->setFrameShape(QFrame::VLine);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(20, 300, 541, 16));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(6);
        line_3->setFrameShape(QFrame::HLine);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(20, 480, 541, 16));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(6);
        line_4->setFrameShape(QFrame::HLine);
        solveBtn = new QPushButton(centralwidget);
        solveBtn->setObjectName(QString::fromUtf8("solveBtn"));
        solveBtn->setGeometry(QRect(590, 320, 261, 131));
        QFont font1;
        font1.setPointSize(48);
        solveBtn->setFont(font1);
        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
        clearBtn->setGeometry(QRect(590, 270, 261, 41));
        QFont font2;
        font2.setPointSize(16);
        clearBtn->setFont(font2);
        generateBtn = new QPushButton(centralwidget);
        generateBtn->setObjectName(QString::fromUtf8("generateBtn"));
        generateBtn->setGeometry(QRect(590, 220, 261, 41));
        generateBtn->setFont(font2);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(640, 460, 151, 21));
        QFont font3;
        font3.setPointSize(12);
        checkBox->setFont(font3);
        checkBox->setChecked(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 550, 281, 41));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(640, 490, 151, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(690, 510, 51, 20));
        label_2->setFont(font3);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(630, 510, 31, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(780, 510, 21, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(630, 10, 191, 191));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/img/img/sudoku star logo.png")));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 20, 511, 101));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Rage Italic"));
        font4.setPointSize(78);
        label_6->setFont(font4);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(solveBtn, SIGNAL(clicked()), clearBtn, SLOT(hide()));
        QObject::connect(solveBtn, SIGNAL(clicked()), generateBtn, SLOT(hide()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sudoku Star", nullptr));
        solveBtn->setText(QApplication::translate("MainWindow", "Solve!!!", nullptr));
        clearBtn->setText(QApplication::translate("MainWindow", "Clear Board", nullptr));
        generateBtn->setText(QApplication::translate("MainWindow", "Generate New Puzzle", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Visualize Solutions", nullptr));
        label->setText(QApplication::translate("MainWindow", "Visualization slows down the solver, allowing you to see \n"
"the logic behind it in action. Disable this if you want to \n"
"see sudoku puzzles solved in a matter of milliseconds!", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Speed", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Slow", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Fast", nullptr));
        label_5->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Sudoku Star", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

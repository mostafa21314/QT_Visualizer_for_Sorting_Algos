/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Radix_Button;
    QPushButton *Heap_Button;
    QPushButton *Tree_Button;
    QPushButton *Insertion_Button;
    QPushButton *Quick_Button;
    QPushButton *Bubble_Button;
    QPushButton *Merge_button;
    QPushButton *Comb_Button;
    QPushButton *Counting_Button;
    QPushButton *Quick_Button_2;
    QPushButton *Shell_Button;
    QLabel *label;
    QGraphicsView *graphicsView;
    QLabel *CompCount;
    QLineEdit *ArraySize;
    QPushButton *arraySize_Button;
    QPushButton *Generate_Button;
    QPushButton *SetDelayButton;
    QLineEdit *DelayTiming;
    QPushButton *Selection_Sort;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1337, 784);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Radix_Button = new QPushButton(centralwidget);
        Radix_Button->setObjectName("Radix_Button");
        Radix_Button->setGeometry(QRect(640, 560, 93, 29));
        Heap_Button = new QPushButton(centralwidget);
        Heap_Button->setObjectName("Heap_Button");
        Heap_Button->setGeometry(QRect(1110, 560, 71, 29));
        Tree_Button = new QPushButton(centralwidget);
        Tree_Button->setObjectName("Tree_Button");
        Tree_Button->setGeometry(QRect(940, 560, 71, 29));
        Insertion_Button = new QPushButton(centralwidget);
        Insertion_Button->setObjectName("Insertion_Button");
        Insertion_Button->setGeometry(QRect(420, 560, 111, 29));
        Quick_Button = new QPushButton(centralwidget);
        Quick_Button->setObjectName("Quick_Button");
        Quick_Button->setGeometry(QRect(220, 560, 93, 29));
        Bubble_Button = new QPushButton(centralwidget);
        Bubble_Button->setObjectName("Bubble_Button");
        Bubble_Button->setGeometry(QRect(320, 560, 93, 29));
        Merge_button = new QPushButton(centralwidget);
        Merge_button->setObjectName("Merge_button");
        Merge_button->setGeometry(QRect(540, 560, 93, 29));
        Comb_Button = new QPushButton(centralwidget);
        Comb_Button->setObjectName("Comb_Button");
        Comb_Button->setGeometry(QRect(850, 560, 81, 29));
        Counting_Button = new QPushButton(centralwidget);
        Counting_Button->setObjectName("Counting_Button");
        Counting_Button->setGeometry(QRect(740, 560, 101, 29));
        Quick_Button_2 = new QPushButton(centralwidget);
        Quick_Button_2->setObjectName("Quick_Button_2");
        Quick_Button_2->setGeometry(QRect(120, 560, 93, 29));
        Shell_Button = new QPushButton(centralwidget);
        Shell_Button->setObjectName("Shell_Button");
        Shell_Button->setGeometry(QRect(20, 560, 93, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 600, 141, 20));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 20, 1291, 531));
        CompCount = new QLabel(centralwidget);
        CompCount->setObjectName("CompCount");
        CompCount->setGeometry(QRect(180, 600, 63, 20));
        ArraySize = new QLineEdit(centralwidget);
        ArraySize->setObjectName("ArraySize");
        ArraySize->setGeometry(QRect(470, 600, 113, 25));
        arraySize_Button = new QPushButton(centralwidget);
        arraySize_Button->setObjectName("arraySize_Button");
        arraySize_Button->setGeometry(QRect(300, 600, 131, 29));
        Generate_Button = new QPushButton(centralwidget);
        Generate_Button->setObjectName("Generate_Button");
        Generate_Button->setGeometry(QRect(1190, 560, 101, 29));
        SetDelayButton = new QPushButton(centralwidget);
        SetDelayButton->setObjectName("SetDelayButton");
        SetDelayButton->setGeometry(QRect(640, 600, 151, 29));
        DelayTiming = new QLineEdit(centralwidget);
        DelayTiming->setObjectName("DelayTiming");
        DelayTiming->setGeometry(QRect(820, 600, 113, 25));
        Selection_Sort = new QPushButton(centralwidget);
        Selection_Sort->setObjectName("Selection_Sort");
        Selection_Sort->setGeometry(QRect(1020, 560, 91, 31));
        MainWindow->setCentralWidget(centralwidget);
        graphicsView->raise();
        Radix_Button->raise();
        Heap_Button->raise();
        Tree_Button->raise();
        Insertion_Button->raise();
        Quick_Button->raise();
        Bubble_Button->raise();
        Merge_button->raise();
        Comb_Button->raise();
        Counting_Button->raise();
        Quick_Button_2->raise();
        Shell_Button->raise();
        label->raise();
        CompCount->raise();
        ArraySize->raise();
        arraySize_Button->raise();
        Generate_Button->raise();
        SetDelayButton->raise();
        DelayTiming->raise();
        Selection_Sort->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1337, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Radix_Button->setText(QCoreApplication::translate("MainWindow", "Radix Sort", nullptr));
        Heap_Button->setText(QCoreApplication::translate("MainWindow", "Heap Sort", nullptr));
        Tree_Button->setText(QCoreApplication::translate("MainWindow", "Tree Sort", nullptr));
        Insertion_Button->setText(QCoreApplication::translate("MainWindow", "Insertion Sort", nullptr));
        Quick_Button->setText(QCoreApplication::translate("MainWindow", "Quick Sort", nullptr));
        Bubble_Button->setText(QCoreApplication::translate("MainWindow", "Bubble Sort", nullptr));
        Merge_button->setText(QCoreApplication::translate("MainWindow", "Merge Sort", nullptr));
        Comb_Button->setText(QCoreApplication::translate("MainWindow", "Comb Sort", nullptr));
        Counting_Button->setText(QCoreApplication::translate("MainWindow", "Counting Sort", nullptr));
        Quick_Button_2->setText(QCoreApplication::translate("MainWindow", "Quick Sort 2", nullptr));
        Shell_Button->setText(QCoreApplication::translate("MainWindow", "Shell Sort", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Comaprisons count :", nullptr));
        CompCount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        arraySize_Button->setText(QCoreApplication::translate("MainWindow", "Set Size Of Array", nullptr));
        Generate_Button->setText(QCoreApplication::translate("MainWindow", "Regenerate Array", nullptr));
        SetDelayButton->setText(QCoreApplication::translate("MainWindow", "set Delay Time", nullptr));
        Selection_Sort->setText(QCoreApplication::translate("MainWindow", "Selection Sort", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

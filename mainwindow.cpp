#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<vector>
#include <QGraphicsRectItem>
#include<qwidget.h>
#include"qgraphicsview.h"
#include <QPen>
#include <QColor>
#include<ctime>
#include<QTimer>
#include<QtGlobal>
#include<cstdlib>
#include<iostream>
#include<QtCore>
using namespace std;
int dtime;
bool repeat=false;
int NUM;
bool h=true;
int elementwidth;
int elementheight;
QGraphicsRectItem** rectangle;
QGraphicsRectItem *placeHolder;
QBrush blackBrush(Qt::black);
QBrush whiteBrush(Qt::white);
QBrush greenBrush(Qt::green);
int compare;
QBrush redBrush(Qt::red);
QPen blackPen(Qt::black);
QPen redPen(Qt::red);

QPen whitePen(Qt::white);

int* temparr;
int xcoordinate = -1250;
int ycoordinate = 475;
  QGraphicsScene *scene;

  void Delay(int x)
  {
  QTimer timer;//  THIS PART WAS TAKEN FROM CHATGPT
                    timer.start(x);     //Start the timer with a 5-second interval


                    QObject::connect(&timer, &QTimer::timeout, []()// Connect a lambda function to the timer's timeout signal
                    {
                        qDebug();
                    });
                    QEventLoop loop;   // Wait for the timer to finish
                    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
                    loop.exec();

  }


  void MainWindow::on_arraySize_Button_clicked()
  {
ui->CompCount->setText("0");
      if(repeat)
      {
          for(int i=0;i<NUM;i++)
          {
              scene->removeItem(rectangle[i]);
              scene->update();
              Delay(dtime);
          }
      }
      int x;
     x= ui->ArraySize->text().toInt();
     NUM=x;
   rectangle= new QGraphicsRectItem*[NUM];
   temparr=new int[NUM];
   elementwidth=10;
if(NUM<50)
    elementheight=6;
else
    elementheight=3;
  }


  int getMax()
  {
      int max = *(temparr);
      for (int i = 1; i < NUM; i++)
      {
          if (*(temparr + i) > max)
              max = *(temparr + i);
      }

      return max;
  }





int nextGap(int x)
{
    int gap = x/1.3;

    if(gap < 1)
        return 1;

        return gap;
}

  int getMin()
     {
         int min = *(temparr);
         for (int i = 1; i < NUM; i++)
         {
             if (*(temparr + i) < min)
                 min = *(temparr + i);
         }

         return min;
     }


void Filling(int* arr,int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++) // loop that fills the array with the required data elements (numbers from 0 to size-1)
    {
        *(arr + i) = i;
    }
    for (int i = 2; i < size; i++) // loop that shuffles the content of the array randomly
    {
        int j = (rand() % i) + 1;
        int temp=*(arr+i);
        *(arr+i)=*(arr+j);
        *(arr+j)=temp;
    }
}
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *q, int low, int high, QLabel* com) {

    int pivot = q[low];
    int temp = high;

    for (int i = high; i > low; i--) {
        rectangle[i]->setBrush(redBrush);
        rectangle[low]->setBrush(redBrush);
        scene->update();
        Delay(dtime);
        if (q[i] > pivot)
        {
            Swap(q[i], q[temp--]);
            rectangle[i]->setRect(xcoordinate+(elementwidth*i), ycoordinate, elementwidth, -q[i]*elementheight);
            rectangle[temp]->setRect(xcoordinate+(elementwidth*temp), ycoordinate, elementwidth, -q[temp]*elementheight);
            scene->update();
            Delay(dtime);
        }
        compare++;
    com->setText(QString::number(compare));
        rectangle[i]->setBrush(whiteBrush);
        rectangle[low]->setBrush(whiteBrush);
    }
    Swap(q[low], q[temp]);
    rectangle[low]->setRect(xcoordinate+(elementwidth*low), ycoordinate, elementwidth, -q[low]*elementheight);
    rectangle[temp]->setRect(xcoordinate+(elementwidth*temp), ycoordinate, elementwidth, -q[temp]*elementheight);
    rectangle[low]->setBrush(greenBrush);
    rectangle[temp]->setBrush(greenBrush);
    scene->update();
    Delay(dtime);

    // Reset the colors of all rectangles
    for (int i = low; i <= high; i++) {
        rectangle[i]->setBrush(whiteBrush);
        rectangle[i]->setRect(xcoordinate+(elementwidth*i), ycoordinate, elementwidth, -q[i]*elementheight);
        scene->update();
        Delay(dtime);
        scene->update();
        Delay(dtime);
    }
    scene->update();
    Delay(dtime);

    return temp;
}





void heapify(int *arr, int n, int i,QLabel* com) {
    int largest = i;  // Initialize largest as root
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2
 compare++;
 com->setText(QString::number(compare));
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
       { largest = l;}
 compare++;
  com->setText(QString::number(compare));
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
       { largest = r;}

    // If largest is not root
    if (largest != i) {
        rectangle[i]->setBrush(redBrush);
              rectangle[largest]->setBrush(redBrush);
              scene->update();
              Delay(dtime);
        swap(arr[i], arr[largest]);
        rectangle[i]->setRect(xcoordinate + (elementwidth * i), ycoordinate, elementwidth, -arr[i] * elementheight);
               rectangle[largest]->setRect(xcoordinate + (elementwidth * largest), ycoordinate, elementwidth, -arr[largest] * elementheight);
               scene->update();
               Delay(dtime);


               rectangle[i]->setBrush(Qt::white);
               rectangle[largest]->setBrush(Qt::white);
               scene->update();
               Delay(dtime);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest,com);

    }

    else
      {
          // Set the brush color for the sorted rectangle to green
          rectangle[i]->setBrush(greenBrush);
          scene->update();
          Delay(dtime);
      }
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(blackBrush);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Generate_Button_clicked()
{
     Filling(temparr,NUM);
    for(int i=0;i<NUM;i++)
    {

    // Create a QGraphicsRectItem
    rectangle[i] = new QGraphicsRectItem();

    // Set the rectangle's width and height
    rectangle[i]->setRect(xcoordinate+(elementwidth*i), ycoordinate, elementwidth, -temparr[i]*elementheight);
    rectangle[i]->setPen(blackPen);
    rectangle[i]->setBrush(whiteBrush);
    // Add the rectangle to the QGraphicsScene
    scene->addItem(rectangle[i]);
    scene->update();
            Delay(dtime);
    }
    repeat=true;

}


void MainWindow::on_Heap_Button_clicked()
{
    compare=0;
    // Build heap (rearrange array)
       for (int i = NUM / 2 - 1; i >= 0; i--)
           heapify(temparr, NUM, i,ui->CompCount);
ui->CompCount->setText(QString::number(compare));
       // One by one extract an element from heap
       for (int i = NUM - 1; i > 0; i--) {
           // Move current root to end
           Swap(temparr[0], temparr[i]);
           rectangle[0]->setRect(xcoordinate + (elementwidth * 0), ycoordinate, elementwidth, -temparr[0] * elementheight);
           rectangle[i]->setRect(xcoordinate+(elementwidth*i), ycoordinate, elementwidth, -temparr[i]*elementheight);
           rectangle[i]->setBrush(greenBrush);
           scene->update();
           Delay(dtime);
           // call max heapify on the reduced heap
           heapify(temparr, i, 0,ui->CompCount);
           ui->CompCount->setText(QString::number(compare));
       }

}



void MainWindow::on_Tree_Button_clicked()
{


}


void MainWindow::on_Comb_Button_clicked()
{
    int gap = NUM;
        bool swapped = true;

        while(gap != 1 || swapped == true)
        {
            gap = nextGap(gap);
            swapped = false;

            for(int i = 0; i<NUM - gap; i++)
            {
                compare++;
                 ui->CompCount->setText(QString::number(compare));
                if(temparr[i] > temparr[i+gap])
                {
                    Swap(temparr[i], temparr[i+gap]);
                    // set the color of the compared rectangles to red
                                 rectangle[i]->setBrush(redBrush);
                                 rectangle[i+gap]->setBrush(redBrush);
                                 scene->update();
                                 Delay(dtime);

                                 // update the rectangle positions after the swap
                                 rectangle[i]->setRect(xcoordinate + (elementwidth * i), ycoordinate, elementwidth, -temparr[i] * elementheight);
                                 rectangle[i+gap]->setRect(xcoordinate + (elementwidth * (i+gap)), ycoordinate, elementwidth, -temparr[i+gap] * elementheight);
                                 scene->update();
                                 Delay(dtime);

                                 // set the color of the compared rectangles to white
                                 rectangle[i]->setBrush(whiteBrush);
                                 rectangle[i+gap]->setBrush(whiteBrush);
                                 scene->update();
                                 Delay(dtime);
                    swapped = true;
                }

            }

        }
        for (int i = 0; i < NUM; i++)
        {
            // set the color of the sorted rectangles to green
            rectangle[NUM-i-1]->setBrush(greenBrush);

            // update the position of the sorted rectangles
            rectangle[NUM-i-1]->setRect(xcoordinate + (elementwidth * (NUM-i-1)), ycoordinate, elementwidth, -temparr[NUM-i-1] * elementheight);

            scene->update();
            Delay(dtime);
        }
}


void MainWindow::on_Counting_Button_clicked()
{




}


void MainWindow::on_Bubble_Button_clicked()
{
    compare=0;
    int i,j;
       for(i=0; i<NUM-1;i++)
       {
           for(j=0; j<NUM-i-1;j++)
           {
               rectangle[j]->setBrush(redBrush);
               rectangle[j+1]->setBrush(redBrush);
               scene->update();
               Delay(dtime);
               compare++;
               ui->CompCount->setText(QString::number(compare));
               if(*(temparr+j)>*(temparr+j+1))
               {
                   Swap(*(temparr+j), *(temparr+j+1));
                   rectangle[j]->setRect(xcoordinate+(elementwidth*j), ycoordinate, elementwidth, -temparr[j]*elementheight);
                   rectangle[j+1]->setRect(xcoordinate+(elementwidth*(j+1)), ycoordinate, elementwidth, -temparr[j+1]*elementheight);
                   scene->update();
                   Delay(dtime);


               }
               rectangle[j]->setBrush(whiteBrush);
               rectangle[j+1]->setBrush(greenBrush);
           }
       }
       rectangle[1]->setBrush(greenBrush);
scene->update();

}



void MainWindow::on_SetDelayButton_clicked()
{
  dtime=  ui->DelayTiming->text().toInt();
}


void MainWindow::on_Shell_Button_clicked()
{
    compare = 0;
    ui->CompCount->setText(QString::number(compare));
    int i, j;
    for (int gap = NUM / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < NUM; i++)
        {
            int temp = temparr[i];
            j = i;

            // set the color of the compared rectangles to red
            rectangle[j]->setBrush(redBrush);
            rectangle[j-gap]->setBrush(redBrush);
           scene->update();
            Delay(dtime);

            while (j >= gap && temparr[j-gap] > temp)
            {
                compare++;
                ui->CompCount->setText(QString::number(compare));

                // swap the rectangles when swapping the array elements
                rectangle[j]->setRect(xcoordinate + (elementwidth * (j - gap)), ycoordinate, elementwidth, -temparr[j - gap] * elementheight);
                rectangle[j - gap]->setRect(xcoordinate + (elementwidth * j), ycoordinate, elementwidth, -temparr[j] * elementheight);
                scene->update();
                Delay(dtime);

                temparr[j] = temparr[j-gap];
                rectangle[j]->setRect(xcoordinate + (elementwidth * j), ycoordinate, elementwidth, -temparr[j] * elementheight);
                rectangle[j-gap]->setRect(xcoordinate + (elementwidth * (j-gap)), ycoordinate, elementwidth, -temparr[j-gap] * elementheight);
                rectangle[j]->setBrush(whiteBrush);
                rectangle[j-gap]->setBrush(whiteBrush);
                scene->update();
                Delay(dtime);
                j -= gap;
            }


            temparr[j] = temp;
            rectangle[j]->setRect(xcoordinate + (elementwidth * j), ycoordinate, elementwidth, -temparr[j] * elementheight);
            rectangle[i]->setRect(xcoordinate + (elementwidth * i), ycoordinate, elementwidth, -temparr[i] * elementheight);
            scene->update();
            Delay(dtime);
            rectangle[i]->setBrush(whiteBrush);
            rectangle[j]->setBrush(whiteBrush);
            scene->update();
            Delay(dtime);
            compare++;
            ui->CompCount->setText(QString::number(compare));
        }
    }

    for (int i = 0; i < NUM; i++)
    {
        // set the color of the sorted rectangles to green
        rectangle[NUM-i-1]->setBrush(greenBrush);

        // update the position of the sorted rectangles
        rectangle[NUM-i-1]->setRect(xcoordinate + (elementwidth * (NUM-i-1)), ycoordinate, elementwidth, -temparr[NUM-i-1] * elementheight);

        scene->update();
        Delay(dtime);
    }
}



void MainWindow::on_Insertion_Button_clicked()
{
    compare = 0;
     int key, i, j;
     for (i = 1; i < NUM; i++)
     {
         key = temparr[i];
         for (j = i - 1; j >= 0; j--)
         {
             if (temparr[j] <= key) {
                 compare++;
                 ui->CompCount->setText(QString::number(compare));
                 break;
             }

             rectangle[j]->setBrush(redBrush);             // set the brush color for the elements being compared to red

             rectangle[j + 1]->setBrush(redBrush);

             scene->update();             // update the scene with a delay

             Delay(dtime);

             temparr[j + 1] = temparr[j];

             // update the position of the rectangles being compared
             rectangle[j]->setRect(xcoordinate + (elementwidth * (j + 1)), ycoordinate, elementwidth, -temparr[j] * elementheight);
             rectangle[j + 1]->setRect(xcoordinate + (elementwidth * j), ycoordinate, elementwidth, -temparr[j + 1] * elementheight);

             rectangle[j]->setBrush(whiteBrush);
             rectangle[j + 1]->setBrush(whiteBrush);

             scene->update();             // update the scene with a delay

             compare++;
             ui->CompCount->setText(QString::number(compare));
         }

         if (temparr[j] <= key)
         {
             temparr[j + 1] = key;

             // update the position of the sorted rectangles
             rectangle[j + 1]->setRect(xcoordinate + (elementwidth * (j + 1)), ycoordinate, elementwidth, -temparr[j + 1] * elementheight);
             rectangle[i]->setRect(xcoordinate + (elementwidth * i), ycoordinate, elementwidth, -temparr[i] * elementheight);

             // set the brush color for the sorted rectangles to green
             rectangle[j + 1]->setBrush(greenBrush);
             rectangle[i]->setBrush(greenBrush);

             // update the scene with a delay
             scene->update();
             compare++;
             ui->CompCount->setText(QString::number(compare));
         }
     }
     for(int i=0;i<NUM;i++)
     {
         rectangle[NUM-i-1]->setRect(xcoordinate + (elementwidth * (NUM-1-i)), ycoordinate, elementwidth, -temparr[NUM-i-1] * elementheight);
         rectangle[NUM-i-1]->setBrush(greenBrush);
         scene->update();
         Delay(dtime);
     }
}



void MainWindow::on_Quick_Button_clicked()
{
    compare=0;
    // Initialize the stack
    int stack[NUM];

    // Initialize the top of the stack
    int top = -1;

    // Push the initial values of low and high to the stack
    stack[++top] = 0;
    stack[++top] = NUM - 1;

    // Loop until the stack is empty
    while (top >= 0) {
        // Pop the values of low and high from the stack
        int high = stack[top--];
        int low = stack[top--];

        // Partition the array and get the pivot index
        int pivotIndex = partition(temparr, low, high,ui->CompCount);

        // Push the values of low and high to the stack for the left subarray
        if (pivotIndex - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivotIndex - 1;
        }

        // Push the values of low and high to the stack for the right subarray
        if (pivotIndex + 1 < high) {
            stack[++top] = pivotIndex + 1;
            stack[++top] = high;
        }
    }
  /*  for(int i=0;i<NUM;i++)
    {
        rectangle[NUM-i-1]->setRect(xcoordinate + (elementwidth * (NUM-1-i)), ycoordinate, elementwidth, -temparr[NUM-i-1] * elementheight);
        rectangle[NUM-i-1]->setBrush(greenBrush);
        scene->update();
        Delay(dtime);
    }*/

}

int randomPartition(int *q, int low, int high,QLabel* com)
{
    srand(time(NULL));      //random seed generator
    int randomIndex = (rand() % (high - low)) + low;   //Assigns random index between highest index and lowest index

    Swap(q[randomIndex],q[low]); //swaps random index element with first element
    rectangle[randomIndex]->setRect(xcoordinate + (elementwidth * randomIndex), ycoordinate, elementwidth, -temparr[randomIndex] * elementheight);
    rectangle[low]->setRect(xcoordinate + (elementwidth * (low)), ycoordinate, elementwidth, -temparr[low] * elementheight);
    scene->update();
    Delay(dtime);
    return partition(q, low, high,com); //uses same partition function as base class
}
void MainWindow::on_Quick_Button_2_clicked()
{
    compare=0;
    // Initialize the stack
    int stack[NUM];

    // Initialize the top of the stack
    int top = -1;

    // Push the initial values of low and high to the stack
    stack[++top] = 0;
    stack[++top] = NUM - 1;

    // Loop until the stack is empty
    while (top >= 0) {
        // Pop the values of low and high from the stack
        int high = stack[top--];
        int low = stack[top--];

        // Partition the array and get the pivot index
        int pivotIndex = randomPartition(temparr, low, high,ui->CompCount);

        // Push the values of low and high to the stack for the left subarray
        if (pivotIndex - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivotIndex - 1;
        }

        // Push the values of low and high to the stack for the right subarray
        if (pivotIndex + 1 < high) {
            stack[++top] = pivotIndex + 1;
            stack[++top] = high;
        }
    }
  /*  for(int i=0;i<NUM;i++)
    {
        rectangle[NUM-i-1]->setRect(xcoordinate + (elementwidth * (NUM-1-i)), ycoordinate, elementwidth, -temparr[NUM-i-1] * elementheight);
        rectangle[NUM-i-1]->setBrush(greenBrush);
        scene->update();
        Delay(dtime);
    }*/

}

void merge(int arr[], int l, int m, int r,QLabel* com)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            rectangle[k]->setRect(xcoordinate + (elementwidth * k), ycoordinate, elementwidth, -temparr[k] * elementheight);
            rectangle[k]->setBrush(greenBrush);
            scene->update();
            i++;
        }
        else {
            arr[k] = R[j];
            rectangle[k]->setRect(xcoordinate + (elementwidth * k), ycoordinate, elementwidth, -temparr[k] * elementheight);
            rectangle[k]->setBrush(greenBrush);
            scene->update();
            j++;
        }
        k++;

        if(i<n1)
        {
            rectangle[i]->setBrush(redBrush);
            scene->update();
            Delay(5);

        }
        if(j<n2)
        {
            rectangle[m+1+j]->setBrush(redBrush);
            scene->update();
            Delay(5);


        }


        compare++; // Increment the counter whenever two elements are compared
        com->setText(QString::number(compare));

        if(i>0)
        {
            rectangle[i-1]->setBrush(whiteBrush);
            scene->update();
        }

        if(j>0)
        {
            rectangle[m+j]->setBrush(whiteBrush);
            scene->update();
        }
    }

    while (i < n1) {
        arr[k] = L[i];
        rectangle[k]->setRect(xcoordinate + (elementwidth * k), ycoordinate, elementwidth, -temparr[k] * elementheight);
        rectangle[k]->setBrush(greenBrush);
        scene->update();
        Delay(5);

        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        rectangle[k]->setRect(xcoordinate + (elementwidth * k), ycoordinate, elementwidth, -temparr[k] * elementheight);
        rectangle[k]->setBrush(greenBrush);
        scene->update();
        Delay(5);
        j++;
        k++;
    }

    for(int p=1;p<=r;p++)
    {
        rectangle[p]->setBrush(greenBrush);
        scene->update();
        Delay(5);
    }
}


void mergeSort(int arr[], int l, int r,QLabel* com)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m,com);
        mergeSort(arr, m + 1, r,com);
        merge(arr, l, m, r,com);
    }
}


void MainWindow::on_Merge_button_clicked()
{
compare=0;
 mergeSort(temparr, 0, NUM - 1,ui->CompCount);

}


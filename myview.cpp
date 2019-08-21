#include "myview.h"
#include "myitem.h"
#include <QKeyEvent>
#include <QTimer>


extern MyItem Cell[80][80];
bool   Cell_temp[80][80];

void copy_from_item(){
    for(int i=0; i<80; i++){
        for(int j=0; j<80; j++){
            Cell_temp[i][j] = Cell[i][j].Life ;
        }
    }
}


bool Live_Or_die(int r, int c){
    int sum;
      if (Cell_temp[r][c]==true){sum = -1;}
      if (Cell_temp[r][c]==false){sum = 0;}
      int i,j,tempt;
       for(i=-1;i<=1;i++){
           for(j=-1;j<=1;j++){
                 if (Cell_temp[r+i][c+j]==true){tempt = 1;}
                 if (Cell_temp[r+i][c+j]==false){tempt = 0;}
           sum = sum + tempt;}

           }

       if (Cell_temp[r][c]==true){
           if(sum<2){ return false;}
           if(sum==2 || sum==3){return true;}
           if(sum>3){return false;}
       }
       if (Cell_temp[r][c]== false){
           if(sum==3){return true;}
           else{return false;}
           }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
MyView::MyView(QWidget * parent):
    QGraphicsView (parent)
{
}

void MyView::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Plus){
        copy_from_item();
        //the cell evolves
        for(int i=0; i<80; i++){
            for(int j=0; j<80;j++){
               Cell[i][j].Life = Live_Or_die(i, j);
               if(Cell[i][j].Life == true){Cell[i][j].brushColor = Qt::black;}
               else{Cell[i][j].brushColor= Qt::white;}
               Cell[i][j].setRotation(360);
            }
        }
    }
    QGraphicsView::keyPressEvent(event);
}

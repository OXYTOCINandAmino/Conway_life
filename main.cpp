#include <QApplication>
#include "myitem.h"
#include "myview.h"
#include <QTime>

MyItem Cell[80][80];

int main(int argc, char * argv[]){
   QApplication app(argc,argv);
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
   QGraphicsScene scene;

   scene.setSceneRect(0,0,800,800);


   for(int i=0; i<80; i++){
       for(int j=0; j<80;j++){
           Cell[i][j] .setPos(i*10, j*10);
           scene.addItem(&Cell[i][j]);
       }
   }
   MyView view;
   view.setScene(&scene);
   view.setBackgroundBrush(QPixmap("../myview/background.jpg"));
   view.show();

//   QTimer timer;
//   QObject::connect(&timer,&QTimer::timeout,&scene,&QGraphicsScene::advance);
//   timer.start(3000);

   return app.exec();
}


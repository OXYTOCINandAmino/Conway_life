#include "myitem.h"
#include <QPainter>
#include <QCursor>


MyItem::MyItem()
{
    Life = false;
    brushColor = Qt::white;
    setFlag(QGraphicsItem::ItemIsFocusable);

}

QRectF MyItem::boundingRect() const{
    qreal adjust = 0.5;
    return QRectF(-adjust,-adjust,10+adjust,10+adjust);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

    painter -> setBrush(brushColor);
    painter -> drawRect(0,0,10,10);
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setFocus();
    setCursor(Qt::ClosedHandCursor);
    setRotation(360);
    Life = !Life;
    if(Life == true){
        brushColor = Qt::black;
    }
    else{
        brushColor = Qt::white;
    }
    return;
}


//void MyItem::advance(int phase){
//    if(!phase){
//        return;
//    }
//    Life = !Life;
//    if(Life == true){
//        setColor(Qt::black);
//    }
//    else{
//        setColor(Qt::white);
//    }
//        setRotation(360);

//}

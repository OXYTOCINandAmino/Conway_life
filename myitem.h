#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsItem>

class MyItem : public QGraphicsItem
{

public:
    MyItem();
    QColor brushColor;
    bool   Life;

    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // MYITEM_H

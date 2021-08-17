#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H

#include<QPainter>
#include<QColor>
#include<QJsonObject>

class drawableComponent
{
public:
    static int pageColor;
    static QColor backGroundColor;
    bool selected = false;
    drawableComponent();
    virtual void draw(QPainter &painter)=0;
    virtual bool isInYourRange(int x,int y)=0;
    virtual void select(QPainter &painter)=0;
    virtual QJsonObject createJsonObject()=0;
    virtual void move(int xChange,int yChange)=0;
    virtual void resize(int xChange,int yChange,QString edge)=0;
    virtual QString isItResize(QPoint point)=0;
};

#endif // DRAWABLECOMPONENT_H

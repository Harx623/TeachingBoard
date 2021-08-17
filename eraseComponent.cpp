#include "eraseComponent.h"
#include <QJsonArray>

void eraseComponent::setPenWidth(int value)
{
    penWidth = 2*value;
}

eraseComponent::eraseComponent(){

}

QColor eraseComponent::getPenColor() const
{
    return penColor;
}

void eraseComponent::setPenColor()
{
    penColor = drawableComponent::backGroundColor;
}

int eraseComponent::getPenWidth() const
{
    return penWidth;
}

QList<QPoint> eraseComponent::getCorrdinates() const
{
    return coordinates;
}

void eraseComponent::setCorrdinates(const QList<QPoint> &value)
{
    coordinates = value;
}

void eraseComponent::draw(QPainter &painter)
{
    QPen pen;
    setPenColor();
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setWidth(penWidth+6);
    pen.setColor(penColor);
    painter.setPen(pen);
    int initialX,initialY;
       int j=0;
       if(coordinates.size()!=0)
       {
       initialX=coordinates.at(0).x();
       initialY=coordinates.at(0).y();
       }
       while(j<coordinates.size()-1 && coordinates.size()>1)
       {
           int finalX=coordinates.at(j+1).x();
           int finalY=coordinates.at(j+1).y();
           if(initialX >115 && finalX > 115 && initialX < 1245 && finalX < 1245 && initialY > 80 && finalY > 80 && initialY < 685 && finalY < 685){
               painter.drawLine(initialX,initialY,finalX,finalY);
           }
           initialX=finalX;
           initialY=finalY;
           j++;
       }
}

bool eraseComponent::isInYourRange(int x, int y)
{
    for(int i=0;i<this->coordinates.size();i++)
    {
        if(this->coordinates.at(i).x()+1>x && x<this->coordinates.at(i).x()-1 && this->coordinates.at(i).y()-1<y && y<this->coordinates.at(i).y()+1) return true;
    }
    return false;
}

void eraseComponent::select(QPainter &painter){

}

void eraseComponent::move(int xChange, int yChange){

}

void eraseComponent::resize(int xChange, int yChange, QString edge){

}

QString eraseComponent::isItResize(QPoint point){
    return "no";
}

QJsonObject eraseComponent::createJsonObject(){
    QJsonObject obj;
    QJsonArray xcor,ycor;
    int i =0;
    while(i<coordinates.size()){
        QPoint p = coordinates.value(i);
        xcor.insert(i,p.x());
        ycor.insert(i,p.y());
        i++;
    }
    obj.insert("xcor",xcor);
    obj.insert("ycor",ycor);
    obj.insert("pWidth",penWidth);
    return obj;
}

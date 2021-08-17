#include "freehandComponent.h"
#include<QJsonArray>

void freehandComponent::draw(QPainter &painter)
{
    QPen pen;
    pen.setWidth(penWidth);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setColor(penColor);
    switch(penType){
        case 0:     pen.setStyle(Qt::SolidLine);
            break;
        case 1:    pen.setStyle(Qt::DotLine);
            break;
        case 2: pen.setStyle(Qt::DashLine);
            break;
    }
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
           if(initialX >110 && finalX > 110 && initialX < 1250 && finalX < 1250 && initialY > 75 && finalY > 75 && initialY < 690 && finalY < 690){
               painter.drawLine(initialX,initialY,finalX,finalY);
           }
           initialX=finalX;
           initialY=finalY;
           j++;
       }
}

bool freehandComponent::isinDrawingBoard(QPoint point){
    if(point.x()>110 && point.x()<1256 && point.y()>75 && point.y()<690) return true;
    return false;
}

bool freehandComponent::isInYourRange(int x, int y)
{
    for(int i=0;i<this->coordinates.size();i++)
    {
        if(this->coordinates.at(i).x()+1>x && x<this->coordinates.at(i).x()-1 && this->coordinates.at(i).y()-1<y && y<this->coordinates.at(i).y()+1) return true;
    }
    return false;
}

void freehandComponent::select(QPainter &painter)
{
    QPen pen;
    pen.setWidth(penWidth+9);
    pen.setColor(penColor);
    painter.setPen(pen);
    for(int i=0;i<this->coordinates.size();i+=20) painter.drawPoint(this->coordinates.at(i));
    painter.drawPoint(this->coordinates.at(this->coordinates.size()-1));
}

void freehandComponent::move(int xChange, int yChange)
{
    for(int i=0;i<this->coordinates.size();i++)
    {
        coordinates.replace(i,QPoint(coordinates.at(i).x()+xChange,coordinates.at(i).y()+yChange));
    }
}

void freehandComponent::resize(int xChange, int yChange, QString edge)
{
move(xChange,yChange);
}

QString freehandComponent::isItResize(QPoint point){
    return "no";
}

QJsonObject freehandComponent::createJsonObject()
{
    QString clr = penColor.name();
    QJsonObject obj;
    QJsonArray xcor,ycor;
    int i =0;
    while(i<coordinates.size()){
        QPoint p = coordinates.value(i);
        xcor.insert(i,p.x());
        ycor.insert(i,p.y());
        i++;
    }
    obj.insert("dType","freehand");
    obj.insert("xcor",xcor);
    obj.insert("ycor",ycor);
    obj.insert("color",clr);
    obj.insert("pWidth",penWidth);
    obj.insert("pType",penType);
    return obj;
}

const QList<QPoint> &freehandComponent::getCorrdinates() const
{
    return coordinates;
}

void freehandComponent::setCorrdinates(const QList<QPoint> &newCorrdinates)
{
    coordinates = newCorrdinates;
}

const QColor &freehandComponent::getPenColor() const
{
    return penColor;
}

void freehandComponent::setPenColor(const QColor &newPenColor)
{
    penColor = newPenColor;
}

int freehandComponent::getPenWidth() const
{
    return penWidth;
}

void freehandComponent::setPenWidth(int newPenWidth)
{
    penWidth = newPenWidth;
}

int freehandComponent::getPenType() const
{
    return penType;
}

void freehandComponent::setPenType(int newPenType)
{
    penType = newPenType;
}

freehandComponent::freehandComponent()
{

}

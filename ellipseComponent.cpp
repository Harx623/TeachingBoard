#include "ellipseComponent.h"



void ellipseComponent::draw(QPainter &painter)
{
    QPen pen;
    pen.setWidth(penWidth);
    pen.setColor(penColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    switch(penType){
        case 0:     pen.setStyle(Qt::SolidLine);
            break;
        case 1:    pen.setStyle(Qt::DotLine);
            break;
    case 2: pen.setStyle(Qt::DashLine);
            break;
    }
    painter.setPen(pen);
    painter.drawEllipse(initialPoint.x(),initialPoint.y(),finalPoint.x()-initialPoint.x(),finalPoint.y()-initialPoint.y());
}

bool ellipseComponent::isInYourRange(int x, int y)
{
 if(x>initialPoint.x() && x<finalPoint.x() && y>initialPoint.y() && y<finalPoint.y()) return  true;
 return false;
}

void ellipseComponent::select(QPainter &painter)
{
    QPen pen;
    pen.setWidth(penWidth+9);
    pen.setColor(penColor);
    painter.setPen(pen);
    painter.drawPoint(initialPoint.x(),(initialPoint.y()+finalPoint.y())/2);
    painter.drawPoint(finalPoint.x(),(initialPoint.y()+finalPoint.y())/2);
    painter.drawPoint((initialPoint.x()+finalPoint.x())/2,initialPoint.y());
    painter.drawPoint((initialPoint.x()+finalPoint.x())/2,finalPoint.y());
}

void ellipseComponent::move(int xChange, int yChange)
{
    this->initialPoint.setX(initialPoint.x()+xChange);
    this->initialPoint.setY(initialPoint.y()+yChange);
    this->finalPoint.setX(finalPoint.x()+xChange);
    this->finalPoint.setY(finalPoint.y()+yChange);
}

void ellipseComponent::resize(int xChange, int yChange, QString edge)
{
    if(edge == "top"){
        initialPoint.setY(initialPoint.y()+yChange);
    }
    if(edge == "left"){
        initialPoint.setX(initialPoint.x()+xChange);
    }
    if(edge == "right"){
        finalPoint.setX(finalPoint.x()+xChange);
    }
    if(edge == "bottom"){
        finalPoint.setY(finalPoint.y()+yChange);
    }
}

QString ellipseComponent::isItResize(QPoint point){
    if(point.x()>((initialPoint.x()+finalPoint.x())/2)-10 && point.x()<((initialPoint.x()+finalPoint.x())/2)+10 && point.y()>initialPoint.y() && point.y()<initialPoint.y()+10){
        return "top";
    }
    if(point.x()>initialPoint.x() && point.x()<initialPoint.x()+10 && point.y()>((initialPoint.y()+finalPoint.y())/2)-10 && point.y()<((initialPoint.y()+finalPoint.y())/2)+10){
        return "left";
    }
    if(point.x()>finalPoint.x()-10 && point.x()<finalPoint.x() && point.y()>((initialPoint.y()+finalPoint.y())/2)-10 && point.y()<((initialPoint.y()+finalPoint.y())/2)+10){
        return "right";
    }
    if(point.x()>((initialPoint.x()+finalPoint.x())/2)-10 && point.x()<((initialPoint.x()+finalPoint.x())/2)+10 && point.y()>finalPoint.y()-10 && point.y()<finalPoint.y()){
        return "bottom";
    }
    return "no";
}

QJsonObject ellipseComponent::createJsonObject()
{
    QString clr = penColor.name();
    QJsonObject obj;
    obj.insert("IPointX",initialPoint.x());
    obj.insert("IPointY",initialPoint.y());
    obj.insert("FPointX",finalPoint.x());
    obj.insert("FPointY",finalPoint.y());
    obj.insert("pColor",clr);
    obj.insert("pWidth",penWidth);
    obj.insert("pType",penType);
    return obj;
}

QPoint ellipseComponent::getInitialPoint() const
{
    return initialPoint;
}

void ellipseComponent::setInitialPoint(QPoint newInitialPoint)
{
    initialPoint = newInitialPoint;
}

QPoint ellipseComponent::getFinalPoint() const
{
    return finalPoint;
}

void ellipseComponent::setFinalPoint(QPoint newFinalPoint)
{
    finalPoint = newFinalPoint;
}

const QColor &ellipseComponent::getPenColor() const
{
    return penColor;
}

void ellipseComponent::setPenColor(const QColor &newPenColor)
{
    penColor = newPenColor;
}

int ellipseComponent::getPenWidth() const
{
    return penWidth;
}

void ellipseComponent::setPenWidth(int newPenWidth)
{
    penWidth = newPenWidth;
}

int ellipseComponent::getPenType() const
{
    return penType;
}

void ellipseComponent::setPenType(int newPenType)
{
    penType = newPenType;
}

ellipseComponent::ellipseComponent()
{

}

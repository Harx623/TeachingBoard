#include "lineComponent.h"

int lineComponent::getPentype() const
{
    return pentype;
}

void lineComponent::setPentype(int newPentype)
{
    pentype = newPentype;
}

lineComponent::lineComponent(){

}

void lineComponent::draw(QPainter &painter)
{
    QPen pen;
    pen.setWidth(penWidth);
    pen.setColor(penColor);
    switch(pentype){
        case 0:     pen.setStyle(Qt::SolidLine);
            break;
        case 1:    pen.setStyle(Qt::DotLine);
            break;
    case 2: pen.setStyle(Qt::DashLine);
            break;
    }
    painter.setPen(pen);
    painter.drawLine(initialPoint,finalPoint);
}

bool lineComponent::isInYourRange(int x, int y)
{
    if(x>initialPoint.x() && x<finalPoint.x() && y>initialPoint.y() && y<finalPoint.y()) return  true;
    return false;
}

void lineComponent::select(QPainter &painter)
{
    QPen pen;
    pen.setWidth(penWidth);
    pen.setColor(penColor);
    painter.setPen(pen);
    painter.drawPoint(initialPoint);
    painter.drawPoint(finalPoint);
}

void lineComponent::move(int xChange, int yChange)
{
    initialPoint.setX(initialPoint.x()+xChange);
    initialPoint.setY(initialPoint.y()+yChange);
    finalPoint.setX(finalPoint.x()+xChange);
    finalPoint.setY(finalPoint.y()+yChange);
}

void lineComponent::resize(int xChange, int yChange, QString edge)
{

}

QString lineComponent::isItResize(QPoint point){

}

QJsonObject lineComponent::createJsonObject()
{
    QString clr = penColor.name();
    QJsonObject obj;
    obj.insert("IPointX",initialPoint.x());
    obj.insert("IPointY",initialPoint.y());
    obj.insert("FPointX",finalPoint.x());
    obj.insert("FPointY",finalPoint.y());
    obj.insert("pColor",clr);
    obj.insert("pWidth",penWidth);
    obj.insert("pType",pentype);
    return obj;
}

QPoint lineComponent::getFinalPoint() const
{
    return finalPoint;
}

void lineComponent::setFinalPoint(const QPoint &value)
{
    finalPoint = value;
}

QPoint lineComponent::getInitialPoint() const
{
    return initialPoint;
}

void lineComponent::setInitialPoint(const QPoint &value)
{
    initialPoint = value;
}

const QColor &lineComponent::getPenColor() const
{
    return penColor;
}

void lineComponent::setPenColor(const QColor &newPenColor)
{
    penColor = newPenColor;
}

int lineComponent::getPenWidth() const
{
    return penWidth;
}

void lineComponent::setPenWidth(int newPenWidth)
{
    penWidth = newPenWidth;
}



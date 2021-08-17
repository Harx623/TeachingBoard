#include "rectangleComponent.h"

void rectangleComponent::draw(QPainter &painter)
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
    painter.drawRect(initialPoint.x(),initialPoint.y(),finalPoint.x()-initialPoint.x(),finalPoint.y()-initialPoint.y());
}

bool rectangleComponent::isInYourRange(int x, int y)
{
    if(x>initialPoint.x() && x<finalPoint.x() && y>initialPoint.y() && y<finalPoint.y()) return  true;
    return false;
}

void rectangleComponent::select(QPainter &painter)
{
    QPen pen;
    pen.setWidth(penWidth+9);
    pen.setColor(penColor);
    painter.setPen(pen);
    painter.drawPoint(initialPoint);
    painter.drawPoint(finalPoint.x(),initialPoint.y());
    painter.drawPoint(initialPoint.x(),finalPoint.y());
    painter.drawPoint(finalPoint);
}

void rectangleComponent::move(int xChange, int yChange)
{
    initialPoint.setX(initialPoint.x()+xChange);
    initialPoint.setY(initialPoint.y()+yChange);
    finalPoint.setY(finalPoint.y()+yChange);
    finalPoint.setX(finalPoint.x()+xChange);
}

void rectangleComponent::resize(int xChange, int yChange, QString edge)
{
    if(edge == "xx"){
        initialPoint.setX(initialPoint.x()+xChange);
        initialPoint.setY(initialPoint.y()+yChange);
    }
    if(edge == "xy"){
        finalPoint.setX(finalPoint.x()+xChange);
        initialPoint.setY(initialPoint.y()+yChange);
    }
    if(edge == "yx"){
        initialPoint.setX(initialPoint.x()+xChange);
        finalPoint.setY(finalPoint.y()+yChange);
    }
    if(edge == "yy"){
        finalPoint.setX(finalPoint.x()+xChange);
        finalPoint.setY(finalPoint.y()+yChange);
    }
}

QString rectangleComponent::isItResize(QPoint point){
    if(point.x()>initialPoint.x() && point.x()<initialPoint.x()+10 && point.y()>initialPoint.y() && point.y()<initialPoint.y()+10){
        return "xx";
    }
    if(point.x()>finalPoint.x()-10 && point.x()<finalPoint.x() && point.y()>initialPoint.y() && point.y()<initialPoint.y()+10){
        return "xy";
    }
    if(point.x()>initialPoint.x() && point.x()<initialPoint.x()+10 && point.y()>finalPoint.y()-10 && point.y()<finalPoint.y()){
        return "yx";
    }
    if(point.x()>finalPoint.x()-10 && point.x()<finalPoint.x() && point.y()>finalPoint.y()-10 && point.y()<finalPoint.y()){
        return "yy";
    }
    return "no";
}

QJsonObject rectangleComponent::createJsonObject()
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

QPoint rectangleComponent::getInitialPoint() const
{
    return initialPoint;
}

void rectangleComponent::setInitialPoint(QPoint newInitialPoint)
{
    initialPoint = newInitialPoint;
}

QPoint rectangleComponent::getFinalPoint() const
{
    return finalPoint;
}

void rectangleComponent::setFinalPoint(QPoint newFinalPoint)
{
    finalPoint = newFinalPoint;
}

const QColor &rectangleComponent::getPenColor() const
{
    return penColor;
}

void rectangleComponent::setPenColor(const QColor &newPenColor)
{
    penColor = newPenColor;
}

int rectangleComponent::getPenWidth() const
{
    return penWidth;
}

void rectangleComponent::setPenWidth(int newPenWidth)
{
    penWidth = newPenWidth;
}

int rectangleComponent::getPenType() const
{
    return penType;
}

void rectangleComponent::setPenType(int newPenType)
{
    penType = newPenType;
}

rectangleComponent::rectangleComponent()
{

}

#include "imageComponent.h"


QString imageComponent::getUrl() const
{
    return url;
}

void imageComponent::setUrl(const QString &value)
{
    url = value;
}

void imageComponent::draw(QPainter &painter){
    img.load(url);
    float aspectRatio =(float) img.width()/img.height();
    finalPoint.setX(initialPoint.x()+300*aspectRatio);
    finalPoint.setY(initialPoint.y()+300);
    target.setRect(initialPoint.x(),initialPoint.y(),300*aspectRatio,300);
    painter.drawImage(target,img);
}

void imageComponent::select(QPainter &painter){
    QPen pen;
    pen.setWidth(10);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawPoint(initialPoint);
    painter.drawPoint(finalPoint.x(),initialPoint.y());
    painter.drawPoint(initialPoint.x(),finalPoint.y());
    painter.drawPoint(finalPoint);
}

bool imageComponent::isInYourRange(int x, int y){
    if(x>initialPoint.x() && x<finalPoint.x() && y>initialPoint.y() && y<finalPoint.y()) return  true;
    return false;
}

void imageComponent::move(int xChange, int yChange){
    int flag = 1;
    int width = finalPoint.x()-initialPoint.x();
    int height = finalPoint.y()-initialPoint.y();
    if(initialPoint.x()<115){
        initialPoint.setX(115);
        finalPoint.setX(115+width);
        flag = 0;
    }
    if(initialPoint.y()<80){
        initialPoint.setY(80);
        finalPoint.setY(80+height);
        flag = 0;
    }
    if(finalPoint.x()>1250){
        finalPoint.setX(1250);
        initialPoint.setX(1250-width);
        flag = 0;
    }
    if(finalPoint.y()>685){
        finalPoint.setY(685);
        initialPoint.setY(685-height);
        flag = 0;
    }
    if(flag){
        initialPoint.setX(initialPoint.x()+xChange);
        initialPoint.setY(initialPoint.y()+yChange);
        finalPoint.setY(finalPoint.y()+yChange);
        finalPoint.setX(finalPoint.x()+xChange);
    }
}

void imageComponent::resize(int xChange, int yChange, QString edge){
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

QString imageComponent::isItResize(QPoint point){
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

QJsonObject imageComponent::createJsonObject()
{
    QJsonObject obj;
    obj.insert("url",url);
    return obj;
}

#ifndef IMAGECOMPONENT_H
#define IMAGECOMPONENT_H
#include "drawableComponent.h"

class imageComponent:public drawableComponent{
private:
    QString url;
    QPoint initialPoint = QPoint(150,150);
    QPoint finalPoint;
    QRect target;
    QImage img;
public:
    void draw(QPainter &painter) override;
    bool isInYourRange(int x, int y) override;
    void select(QPainter &painter) override;
    void move(int xChange, int yChange) override;
    void resize(int xChange, int yChange, QString edge) override;
    QString isItResize(QPoint point) override;
    QJsonObject createJsonObject() override;

    QString getUrl() const;
    void setUrl(const QString &value);
};

#endif // IMAGECOMPONENT_H

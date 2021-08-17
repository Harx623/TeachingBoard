#ifndef ELLIPSECOMPONENT_H
#define ELLIPSECOMPONENT_H
#include "drawableComponent.h"

class ellipseComponent:public drawableComponent
{
private:
    QPoint initialPoint,finalPoint;
    QColor penColor;
    int penWidth;
    int penType;


public:
    ellipseComponent();

    void draw(QPainter &painter) override;
    bool isInYourRange(int x, int y) override;
    void select(QPainter &painter) override;
    void move(int xChange, int yChange) override;
    void resize(int xChange,int yChange,QString edge) override;
    QString isItResize(QPoint point) override;
    QJsonObject createJsonObject() override;

    QPoint getInitialPoint() const;
    void setInitialPoint(QPoint newInitialPoint);
    QPoint getFinalPoint() const;
    void setFinalPoint(QPoint newFinalPoint);
    const QColor &getPenColor() const;
    void setPenColor(const QColor &newPenColor);
    int getPenWidth() const;
    void setPenWidth(int newPenWidth);
    int getPenType() const;
    void setPenType(int newPenType);
};

#endif // ELLIPSECOMPONENT_H

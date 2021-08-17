#ifndef LINECOMPONENT_H
#define LINECOMPONENT_H
#include"drawableComponent.h"

class lineComponent:public drawableComponent
{
private:
    QPoint initialPoint;
    QPoint finalPoint;
    QColor penColor;
    int penWidth;
    int pentype;
public:
    lineComponent();
    void draw(QPainter &painter) override;
    bool isInYourRange(int x, int y) override;
    void select(QPainter &painter) override;
    void move(int xChange, int yChange) override;
    void resize(int xChange,int yChange,QString edge) override;
    QString isItResize(QPoint point) override;
    QJsonObject createJsonObject() override;

    QPoint getInitialPoint() const;
    void setInitialPoint(const QPoint &value);
    QPoint getFinalPoint() const;
    void setFinalPoint(const QPoint &value);

    const QColor &getPenColor() const;
    void setPenColor(const QColor &newPenColor);
    int getPenWidth() const;
    void setPenWidth(int newPenWidth);
    int getPentype() const;
    void setPentype(int newPentype);
};

#endif // LINECOMPONENT_H

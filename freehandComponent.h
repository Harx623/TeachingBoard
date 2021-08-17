#ifndef FREEHANDCOMPONENT_H
#define FREEHANDCOMPONENT_H
#include"drawableComponent.h"

class freehandComponent:public drawableComponent
{
private:
    QList<QPoint> coordinates;
    QColor penColor;
    int penWidth;
    int penType;

public:
    freehandComponent();
    void draw(QPainter &painter) override;
    bool isinDrawingBoard(QPoint point);
    bool isInYourRange(int x, int y) override;
    void select(QPainter &painter) override;
    void move(int xChange, int yChange) override;
    void resize(int xChange,int yChange,QString edge) override;
    QString isItResize(QPoint point) override;
    QJsonObject createJsonObject() override;

    const QList<QPoint> &getCorrdinates() const;
    void setCorrdinates(const QList<QPoint> &newCorrdinates);
    const QColor &getPenColor() const;
    void setPenColor(const QColor &newPenColor);
    int getPenWidth() const;
    void setPenWidth(int newPenWidth);
    int getPenType() const;
    void setPenType(int newPenType);
};

#endif // FREEHANDCOMPONENT_H

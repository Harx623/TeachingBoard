#ifndef ERASECOMPONENT_H
#define ERASECOMPONENT_H
#include "drawableComponent.h"

class eraseComponent:public drawableComponent{
private:
    QList<QPoint> coordinates;
    QColor penColor;
    int penWidth;

public:
    eraseComponent();
    void draw(QPainter &painter) override;
    bool isInYourRange(int x, int y) override;
    virtual void select(QPainter &painter) override;
    virtual void move(int xChange,int yChange) override;
    virtual void resize(int xChange,int yChange,QString edge) override;
    virtual QString isItResize(QPoint point) override;
    QJsonObject createJsonObject() override;

    QList<QPoint> getCorrdinates() const;
    void setCorrdinates(const QList<QPoint> &value);
    QColor getPenColor() const;
    void setPenColor();
    int getPenWidth() const;
    void setPenWidth(int value);

};

#endif // ERASECOMPONENT_H

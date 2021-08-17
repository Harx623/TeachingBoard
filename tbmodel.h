#ifndef TBMODEL_H
#define TBMODEL_H

#include <QtCore>
#include "drawableComponent.h"
#include "lineComponent.h"
#include "pageInformation.h"
#include <QList>
#include<QFileDialog>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonDocument>
#include<QMessageBox>
#include<QString>

class TBModel
{
private :
    QList<QList<drawableComponent *> *> components;
    QList<drawableComponent *> *page;
    drawableComponent *com;
    QList<PageInformation *> pageInfo;
    QPoint initialPoint;
    QList<QPoint> points;
    int i = -1;
    QString r;

public:
    bool isMoving = false;
    bool isResizing = false;
    TBModel();
    void save(QString fileName);
    void open(QString file);
    int getSize(int pageNumber);
    void add(drawableComponent *component,int pageNumber);
    void drawAll(QPainter &painter,int pageNumber);
    void clear(int pageNumber);
    void select(QPoint point,QPainter &painter,int pageNumber);
    void move(QPoint p,int pageNumber);
    void resize(QPoint point, QString edge,int pageNumber);
    void setInitialPoint(QPoint point);
    void moveOrResize(QPoint point,int pageNumber);
    void addNewPage();
    int getNumberOfPages();
    void setPageInfo(int pageNumber,PageInformation *info);
    PageInformation *getPageInformation(int pageNumber);
    drawableComponent * popLastElement(int pageNumber);
    QList<drawableComponent *> getAllComponents(int pageNumber);
};

#endif // TBMODEL_H

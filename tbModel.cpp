#include "tbmodel.h"
#include<QJsonDocument>
#include<QDebug>
#include<QMessageBox>

TBModel::TBModel()
{
    components.append(new QList<drawableComponent *>());
}
void TBModel::add(drawableComponent *component,int pageNumber)
{
    (this->components.value(pageNumber))->append(component);
}

int TBModel::getSize(int pageNumber){
    return components.value(pageNumber)->size();
}

void TBModel::drawAll(QPainter &painter,int pageNumber)
{
    if(pageNumber>components.size() || pageNumber<0) return;
    page=components.value(pageNumber);
    if(page->size() == 0) return;
    for(int i=0;i<page->size();i++)
    {
        com=page->at(i);
        com->draw(painter);
    }
}

void TBModel::clear(int pageNumber)
{
    this->components.value(pageNumber)->clear();
}

void TBModel::select(QPoint point, QPainter &painter,int pageNumber){
    if(pageNumber>components.size() || pageNumber<0) return;
    page=components.value(pageNumber);
    if(page->size() == 0) return;
    if(isMoving){
        page->at(i)->select(painter);
        return;
    }
    for(i=page->size()-1;i>=0;i--){
        if(page->at(i)->isInYourRange(point.x(),point.y())){
            page->at(i)->selected = true;
            page->at(i)->select(painter);
            break;
        }
    }
    for(int j = page->size()-1;j>=0;j--){
        if(j!=i){
            page->at(j)->selected = false;
        }
    }
}

void TBModel::move(QPoint p,int pageNumber){
    if(i == -1) return;
    if(isResizing) return;
    if(pageNumber>components.size() || pageNumber<0) return;
    page=components.value(pageNumber);
    if(page->size() == 0) return;
    if(page->at(i)->isInYourRange(p.x(),p.y())){
        isMoving = true;
        page->at(i)->move(p.x()-initialPoint.x(),p.y()-initialPoint.y());
        initialPoint = p;
    }
}

void TBModel::setInitialPoint(QPoint point){
    this->initialPoint = point;
}

void TBModel::moveOrResize(QPoint point,int pageNumber){
    if(pageNumber>components.size() || pageNumber<0) return;
    page=components.value(pageNumber);
    if(page->size() == 0) return;
    if(isResizing){
        resize(point, r,pageNumber);
    }
    if(i==-1)return;
    if(page->at(i)->isInYourRange(point.x(),point.y())){
        r = page->at(i)->isItResize(point);
        if(r != "no" && !isMoving){
            resize(point,r,pageNumber);
        }else{
            move(point,pageNumber);
        }
    }
}

void TBModel::addNewPage()
{
    components.append(new QList<drawableComponent *>());
}

int TBModel::getNumberOfPages()
{
    return this->components.size();
}

void TBModel::setPageInfo(int pageNumber, PageInformation *info)
{
        pageInfo.insert(pageNumber,info);
}

PageInformation *TBModel::getPageInformation(int pageNumber)
{
    return pageInfo.value(pageNumber);
}

drawableComponent *TBModel::popLastElement(int pageNumber)
{
    this->com=this->components.at(pageNumber)->last();
    this->components.at(pageNumber)->pop_back();
    return this->com;
}

QList<drawableComponent *> TBModel::getAllComponents(int pageNumber)
{
    QList<drawableComponent *> c;
    for(int i=0;i<this->components.at(pageNumber)->size();i++) c.append(this->components.at(pageNumber)->at(i));
    return c;
}

void TBModel::resize(QPoint point, QString edge,int pageNumber){
    if(pageNumber>components.size() || pageNumber<0) return;
    page=components.value(pageNumber);
    if(page->size() == 0) return;
    QString name;
    if(i==-1) return;
    if(isResizing || page->at(i)->isInYourRange(point.x(),point.y())){
        isResizing = true;
        page->at(i)->resize(point.x()-initialPoint.x(),point.y()-initialPoint.y(),edge);
        initialPoint = point;
    }else{
        return ;
    }
}

void TBModel::save(QString fileName){
    QFile output(fileName);
    if(!output.open(QIODevice::WriteOnly|QIODevice::Text)){
        QMessageBox *qmb = new QMessageBox();
        qmb->setText("Cannot open the File");
    }
    QJsonDocument document,draw;
    QJsonObject doc;
    doc.insert("pageColor",drawableComponent::pageColor);
    //doc.insert("sheetColor",drawableComponent::backGroundColor);
    QByteArray data_json;
    QJsonArray listArray,fullArray;
    int i = 0,j = 0;
    QList<drawableComponent *> *drawable;
    while(i<components.size()){
        drawable = components.value(i);
        while(j<drawable->size()){
            com = drawable->value(j);
            QJsonObject obj = com->createJsonObject();
            listArray.push_back(obj);
            j++;
        }
        fullArray.push_back(listArray);
        //drawable->clear();
        i++;
    }
    document.setArray(fullArray);
    data_json=document.toJson();
    output.write(data_json);
    output.close();
}

void TBModel::open(QString file)
{
//    QString dataString;
//    QFile inputFile(file);
//    if(!inputFile.open(QIODevice::ReadOnly|QIODevice::Text)){
//       qDebug()<<"File Not Found";
//       return;
//    }else
//    {
//        dataString=inputFile.readAll();
//        qDebug()<<dataString;
//    }
//    QJsonDocument JOpenDoc = QJsonDocument::fromJson(dataString.toUtf8());
//    QJsonArray JArray = JOpenDoc.array();
//    int i=0,j=0;
//    foreach(const QJsonValue & value, JArray){
//        foreach(const QJsonValue & v, value){

//        }
//    }
//    inputFile.close();
}

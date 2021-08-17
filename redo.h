#ifndef REDO_H
#define REDO_H

#include<drawableComponent.h>
#include<QStack>
#include<tbmodel.h>

class Redo
{
public:
    Redo();
    void add(drawableComponent *component);
    drawableComponent *popLast();
    QStack<drawableComponent *> getAll();
    void clear();
    int getStackSize();
private:
    QStack<drawableComponent *> component;
    TBModel *model;

};

#endif // REDO_H

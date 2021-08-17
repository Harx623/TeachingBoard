#ifndef UNDO_H
#define UNDO_H

#include<drawableComponent.h>
#include<QStack>
#include<tbmodel.h>

class Undo
{
public:
    Undo();
    void add(drawableComponent *component);
    drawableComponent *popLast();
    QStack<drawableComponent *> getAll();
    void clear();
    int getStackSize();
    drawableComponent *getElement(int index);
private:
    QStack<drawableComponent *> component;
    TBModel *model;
};

#endif // UNDO_H

#include "redo.h"

Redo::Redo()
{

}

void Redo::add(drawableComponent *component)
{
    this->component.push(component);
}

drawableComponent *Redo::popLast()
{
    if(this->component.size()==0) return NULL;
    return this->component.pop();

}

QStack<drawableComponent *> Redo::getAll()
{
    QStack<drawableComponent *> tempList;
    while(!this->component.isEmpty()) tempList.push(this->component.pop());
    return tempList;
}

void Redo::clear()
{
    this->component.clear();

}

int Redo::getStackSize()
{
    return this->component.size();

}

#include "undo.h"

Undo::Undo()
{

}

void Undo::add(drawableComponent *component)
{
    this->component.push(component);
}

drawableComponent *Undo::popLast()
{
        if(this->component.size()==0) return NULL;
        return this->component.pop();
}

QStack<drawableComponent *> Undo::getAll()
{
    QStack<drawableComponent *> tempList;
    while(!this->component.isEmpty()) tempList.push(this->component.pop());
    return tempList;
}

void Undo::clear()
{
    this->component.clear();

}

int Undo::getStackSize()
{
    return this->component.size();
}

drawableComponent *Undo::getElement(int index)
{
    return this->component.at(index);
}

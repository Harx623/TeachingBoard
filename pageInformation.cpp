#include "pageInformation.h"

PageInformation::PageInformation()
{

}

int PageInformation::getPageType() const
{
    return pageType;
}

void PageInformation::setPageType(int newPageType)
{
    pageType = newPageType;
}

int PageInformation::getPageColor() const
{
    return this->pageColor;
}

void PageInformation::setPageColor(int newPageColor)
{
    pageColor = newPageColor;
}

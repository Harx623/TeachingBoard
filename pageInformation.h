#ifndef PAGEINFORMATION_H
#define PAGEINFORMATION_H


class PageInformation
{
public:
    PageInformation();
    int getPageType() const;
    void setPageType(int newPageType);

    int getPageColor() const;
    void setPageColor(int newPageColor);

private:
    int pageType;
    int pageColor;
};

#endif // PAGEINFORMATION_H

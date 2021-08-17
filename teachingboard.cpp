#include "teachingboard.h"
#include "ui_teachingboard.h"

int drawableComponent::pageColor = 2;
QColor drawableComponent::backGroundColor = QColor(255,255,255);

TeachingBoard::TeachingBoard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TeachingBoard)
{
    ui->setupUi(this);
    this->tbModel=new TBModel();
    this->coordinates=new QList<QPoint>();
    this->undoList=new QList<Undo *>();
    this->undoList->append(new Undo());
    this->redoList=new QList<Redo *>();
    this->redoList->append(new Redo());
    this->component=NULL;
    this->pageMode= 3;
    this->pageNumber=0;
    this->mode="freehandComponent";
    this->proxyMode="freehandComponent";
    this->penColor=QColor(0,0,0,255);
    //this->pageColor=QColor(75,75,75);
    this->ui->sheetBackgroundTypeFrame->setVisible(false);
    this->ui->sheetBackgroundColorFrame->setVisible(false);
    this->ui->lineColorFrame->setVisible(false);
    this->ui->shapeFrame->setVisible(false);
    ui->lineWidthButton->setVisible(false);
    this->ui->lineTypeFrame->setVisible(false);
    ui->sheetReviewFrame->setVisible(false);
    drawingRect.setRect(110,75,1146,615);
    info=new PageInformation();
    info->setPageColor(2);
    info->setPageType(3);
    tbModel->setPageInfo(0,info);

}

TeachingBoard::~TeachingBoard()
{
    delete ui;
}

//00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
//0000000000000000000000000000000000 PUBLIC FUNCTIONS 0000000000000000000000000000000000000000
//00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

bool TeachingBoard::isClickedInDrawingRange(QPoint point)
{
    if(sheetBackgroundVar == 1 && (point.x()>180 && point.x()<410 && point.y()>71 && point.y()<216)){
        return false;
    }
    if(sheetReviewVar == 1 && (point.x()>10 && point.x()<1356 && point.y()>75 && point.y()<175)){
        return false;
    }
    if(sheetTypeVar == 1 && (point.x()>15 && point.x()<245 && point.y()>71 && point.y()<181)){
        return false;
    }
    if(point.x()>110 && point.x()<1256 && point.y()>75 && point.y()<690) return true;
    return false;
}

void TeachingBoard::checkSheetFrame(int var){
    if(var == 1 ){
        on_sheetReviewButton_clicked();
    }
    if(var == 2){
        on_backgroundTypeButton_clicked();
    }
    if(var == 3){
        on_backgroundColorButton_clicked();
    }
    if(var == 0){
        return;
    }
}

void TeachingBoard::checkColorSettingsFrame(int var){
    if(var == 1){
        on_lineColorFrameCloseButton_clicked();
    }
    if(var == 2){
        on_lineTypeFrameClosrButton_clicked();
    }
    if(var == 0){
        return;
    }
}

void TeachingBoard::closeSheetFrame(QPoint point){
    if(sheetBackgroundVar == 1 && !(point.x()>180 && point.x()<410 && point.y()>71 && point.y()<216)){
        checkSheetFrame(sheetFrameVar);
    }
    if(sheetReviewVar == 1 && !(point.x()>10 && point.x()<1356 && point.y()>75 && point.y()<175)){
        checkSheetFrame(sheetFrameVar);
    }
    if(sheetTypeVar == 1 && !(point.x()>15 && point.x()<245 && point.y()>71 && point.y()<181)){
        checkSheetFrame(sheetFrameVar);
    }
}

//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000000 PAINT EVENT STARTS BELOW 000000000000000000000000000000000
//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

void TeachingBoard::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.fillRect(0,0,1366,768,QColor(75,75,75));
    painter.fillRect(drawingRect,QColor(255,255,255));
    switch(drawableComponent::pageColor){
    case 1: painter.fillRect(drawingRect,QColor(0,0,0));
            drawableComponent::backGroundColor = QColor(0,0,0);
        break;
    case 2: painter.fillRect(drawingRect,QColor(255,255,255));
            drawableComponent::backGroundColor = QColor(255,255,255);
        break;
    case 3: painter.fillRect(drawingRect,QColor(88, 133, 255));
            drawableComponent::backGroundColor = QColor(88,133,255);
        break;
    case 4: painter.fillRect(drawingRect,QColor(57, 158, 84));
            drawableComponent::backGroundColor = QColor(57,158,84);
        break;
    case 5: painter.fillRect(drawingRect,QColor(224, 72, 52));
            drawableComponent::backGroundColor = QColor(224,72,52);
        break;
    }
    int i;
    QPen pen;
    pen.setWidth(2);
    if(drawableComponent::pageColor != 2){
        pen.setColor(QColor(255,255,255,200));
    }else{
        pen.setColor(QColor(31, 31, 31,250));
    }
    painter.setPen(pen);
    switch(pageMode){
    case 1:
        for(i = 90;i<690;i = i+20){
            painter.drawLine(110,i,1256,i);
        }
        break;
    case 2:
/*        for(i = 90;i<690;i = i+25){
            painter.drawLine(110,i,1256,i);
        }
        for(i=115;i<1256;i=i+25){
            painter.drawLine(i,85,i,690);
        }
 */
        for(int i=90;i<690;i+=40)
        {
            painter.drawLine(110,i,1256,i);
        }
        for(int i=115;i<1256;i+=40)
        {
            painter.drawLine(i,85,i,690);
        }
        pen.setWidth(1);
        pen.setColor(QColor(0,150,0));
        painter.setPen(pen);
        for(int i=110;i<690;i+=20)
        {
            painter.drawLine(110,i,1256,i);
        }
        for(int i=135;i<1256;i+=20)
        {
            painter.drawLine(i,85,i,690);
        }

        break;
    case 3:
        break;
    case 4:
        int j;
        for(i = 90;i<690;i = i+20){
            for(j = 115;j<1256;j = j+20){
                painter.drawPoint(j,i);
            }
        }
    }
    if(mode == "clear"){
        QList<drawableComponent * > com=tbModel->getAllComponents(this->pageNumber);
        undoList->at(pageNumber)->clear();
        for(int i=0;i<com.size();i++) undoList->at(pageNumber)->add(com.at(i));
        tbModel->clear(pageNumber);
        this->mode = proxyMode;
        this->wasCleared=true;
    }

    if(mode=="undo" && this->undoClick==true)
    {
        if(tbModel->getSize(this->pageNumber)>0)
        {
            this->component=tbModel->popLastElement(this->pageNumber);
            if(component!=NULL) this->undoList->at(this->pageNumber)->add(this->component);
        }else
        {
            if(this->wasCleared==true)
            {
                QStack<drawableComponent *> com=this->undoList->at(this->pageNumber)->getAll();
                while(!com.isEmpty()) tbModel->add(com.pop(),this->pageNumber);
                this->wasCleared=false;
            }
        }
        this->undoClick=false;
        this->mode=this->proxyMode;
    }

   if(mode=="redo" && this->redoClick==true)
    {
       qDebug()<<"redo error point 1";
        if(undoList->at(pageNumber)->getStackSize()>0)
        {
            component=this->undoList->at(pageNumber)->popLast();
            redoList->at(this->pageNumber)->add(component);
            tbModel->add(component,this->pageNumber);
        }
        this->redoClick=false;
        this->mode=this->proxyMode;
    }

        tbModel->drawAll(painter,pageNumber);


    if(mode=="lineComponent")
    {
        line=new lineComponent();
        line->setInitialPoint(initialPoint);
        line->setFinalPoint(finalPoint);
        line->setPentype(lineType);
        line->setPenWidth(this->ui->lineWidthSlider->value());
        line->setPenColor(penColor);
        line->draw(painter);
        component=line;
    }

    if(mode=="rectangleComponent")
    {
        rectangle=new rectangleComponent();
        rectangle->setInitialPoint(initialPoint);
        rectangle->setFinalPoint(finalPoint);
        rectangle->setPenColor(penColor);
        rectangle->setPenType(lineType);
        rectangle->setPenWidth(this->ui->lineWidthSlider->value());
        rectangle->draw(painter);
        component=rectangle;
  }

    if(mode=="ellipseComponent")
    {
        ellipse=new ellipseComponent();
        ellipse->setInitialPoint(initialPoint);
        ellipse->setFinalPoint(finalPoint);
        ellipse->setPenType(lineType);
        ellipse->setPenWidth(this->ui->lineWidthSlider->value());
        ellipse->setPenColor(penColor);
        ellipse->draw(painter);
        component=ellipse;
    }

    if(mode=="freehandComponent")
    {
        freehand=new freehandComponent();
        freehand->setCorrdinates(*coordinates);
        freehand->setPenColor(penColor);
        freehand->setPenType(lineType);
        freehand->setPenWidth(this->ui->lineWidthSlider->value());
        if(coordinates->size()>1)
        {
        freehand->draw(painter);
        }
        component=freehand;
    }

    if(mode=="select")
    {
        tbModel->select(initialPoint,painter,pageNumber);
    }

    if(mode == "erase"){
        eraser = new eraseComponent();
        eraser->setCorrdinates(*coordinates);
        eraser->setPenWidth(ui->lineWidthSlider->value());
        eraser->draw(painter);
        component = eraser;
    }


    if(mode == "image")
    {
        image = new imageComponent();
        image->setUrl(url);
        image->draw(painter);
        component = image;
    }


}


//00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000000000000 MOUSE EVENT STARTS HERE 00000000000000000000000000000000
//00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

void TeachingBoard::mouseMoveEvent(QMouseEvent *event)
{
    if(mode == "freehandComponent" || mode == "erase" || isClickedInDrawingRange(event->pos())){
        coordinates->append((event->pos()));
    }
    if(isClickedInDrawingRange(event->pos()) && isPressed){
        mouseMoved = 1;
        finalPoint = event->pos();
        if(mode == "select"){
            initialPoint = finalPoint;
            tbModel->moveOrResize(finalPoint,pageNumber);
        }
        update();
    }
}

void TeachingBoard::mousePressEvent(QMouseEvent *event)
{
    closeSheetFrame(event->pos());
    if(isClickedInDrawingRange(event->pos()))
    {
       initialPoint=event->pos();
       isPressed=true;
       if(mode == "select"){
           tbModel->setInitialPoint(initialPoint);
           update();
       }
       if(mode=="freehandComponent") coordinates->append(initialPoint);
    }
}

void TeachingBoard::mouseReleaseEvent(QMouseEvent *event)
{
    isPressed=false;
    if(isClickedInDrawingRange(event->pos()) && mode != "select"){
        finalPoint = event->pos();
        int temp;
        if(initialPoint.x() > finalPoint.x()){
            temp = initialPoint.x();
            initialPoint.setX(finalPoint.x());
            finalPoint.setX(temp);
        }
        if(initialPoint.y() > finalPoint.y()){
            temp = initialPoint.y();
            initialPoint.setY(finalPoint.y());
            finalPoint.setY(temp);
        }
        update();
    }
    if(mode == "select"){
        tbModel->isMoving = false;
        tbModel->isResizing = false;
    }
    if(component!=NULL)
    {
        tbModel->add(component,pageNumber);
        component=NULL;
        if(mode=="freehandComponent" || mode == "erase")
        {
            this->coordinates=new QList<QPoint>();
        }
    }
}

void TeachingBoard::mouseDoubleClickEvent(QMouseEvent *event){

}

//0000000000000000000000000000000000000000000000000000000000000000000000000000000000
//00000000000000000000000000 PRIVATE SLOTS STARTS HERE 00000000000000000000000000000
//0000000000000000000000000000000000000000000000000000000000000000000000000000000000


void TeachingBoard::on_backgroundTypeButton_clicked()
{
    if(sheetTypeVar == 0){
        checkSheetFrame(sheetFrameVar);
        this->ui->sheetBackgroundTypeFrame->setVisible(true);
        ui->sheetBackgroundTypeFrame->setGeometry(15,71,230,110);
        sheetTypeVar = 1;
        sheetFrameVar = 2;
    }
    else{
        ui->sheetBackgroundTypeFrame->setVisible(false);
        sheetTypeVar = 0;
        sheetFrameVar = 0;
    }
}

void TeachingBoard::on_backgroundColorButton_clicked()
{
    if(sheetBackgroundVar == 0){
        checkSheetFrame(sheetFrameVar);
        ui->sheetBackgroundColorFrame->setVisible(true);
        ui->sheetBackgroundColorFrame->setGeometry(180,71,230,145);
        sheetBackgroundVar = 1;
        sheetFrameVar = 3;
    }else{
        ui->sheetBackgroundColorFrame->setVisible(false);
        sheetBackgroundVar = 0;
        sheetFrameVar = 0;
    }
}

void TeachingBoard::on_lineColorButton_clicked()
{
    checkColorSettingsFrame(colorFrameVar);
    on_lineTypeFrameClosrButton_clicked();
    ui->lineColorFrame->setVisible(true);
    ui->lineWidthSlider->setVisible(false);
    ui->lineWidthButton->setVisible(true);
    ui->lineColorFrame->setGeometry(30,200,50,265);
    ui->colorSettingsFrame->setGeometry(30,200,50,375);
    ui->lineTypeButton->setGeometry(5,280,40,40);
    ui->lineWidthButton->setGeometry(5,335,40,40);
    ui->lineWidthSlider->setGeometry(5,390,40,135);
    colorFrameVar = 1;
}

void TeachingBoard::on_lineColorFrameCloseButton_clicked(){
    ui->lineColorFrame->setVisible(false);
    ui->lineWidthSlider->setVisible(true);
    ui->lineWidthButton->setVisible(false);
    ui->colorSettingsFrame->setGeometry(30,200,50,265);
    ui->lineTypeButton->setGeometry(5,60,40,40);
    ui->lineWidthButton->setGeometry(5,115,40,40);
    ui->lineWidthSlider->setGeometry(5,115,40,135);
    colorFrameVar = 0;
}

void TeachingBoard::on_lineTypeButton_clicked()
{
    checkColorSettingsFrame(colorFrameVar);
    this->ui->lineTypeFrame->setVisible(true);
    this->ui->colorSettingsFrame->setGeometry(30,200,50,420);
    this->ui->lineTypeFrame->setGeometry(30,260,50,190);
    this->ui->lineWidthSlider->setGeometry(5,265,40,135);
    colorFrameVar = 2;
}

void TeachingBoard::on_lineTypeFrameClosrButton_clicked()
{
    this->ui->lineTypeFrame->setVisible(false);
    this->ui->colorSettingsFrame->setGeometry(30,200,50,265);
    this->ui->lineWidthSlider->setGeometry(5,115,40,135);
    colorFrameVar = 0;
}

void TeachingBoard::on_solidLineButton_clicked()
{
    this->lineType=0;
}

void TeachingBoard::on_dottedLineButton_clicked()
{
    this->lineType=1;
}

void TeachingBoard::on_dashLine_clicked()
{
    this->lineType=2;
}

void TeachingBoard::on_shapeButton_clicked()
{
    ui->shapeFrame->setVisible(true);
    ui->shapeFrame->setGeometry(1286,200,50,190);
    ui->paletteFrame->setGeometry(1286,150,50,425);
    ui->addImageButton->setGeometry(5,245,40,40);
    ui->eraseButton->setGeometry(5,290,40,40);
    ui->selectButton->setGeometry(5,335,40,40);
    ui->commentButton->setGeometry(5,380,40,40);
}

void TeachingBoard::on_shapeFrameCloseButton_clicked()
{
    ui->shapeFrame->setVisible(false);
    ui->paletteFrame->setGeometry(1286,200,50,275);
    ui->addImageButton->setGeometry(5,95,40,40);
    ui->eraseButton->setGeometry(5,140,40,40);
    ui->selectButton->setGeometry(5,185,40,40);
    ui->commentButton->setGeometry(5,230,40,40);
}

void TeachingBoard::on_penButton_clicked()
{
    this->mode="freehandComponent";
    this->proxyMode="freehandComponent";
}

void TeachingBoard::on_rectangleButton_clicked()
{
    this->mode="rectangleComponent";
    this->proxyMode="rectangleComponent";
}

void TeachingBoard::on_lineButton_clicked()
{
    this->mode="lineComponent";
    this->proxyMode="lineComponent";
}

void TeachingBoard::on_ellipseButton_clicked()
{
    this->mode="ellipseComponent";
    this->proxyMode="ellipseComponent";
}

void TeachingBoard::on_selectButton_clicked()
{
    this->mode="select";
}

void TeachingBoard::on_clearSheetButton_clicked()
{
    mode = "clear";
    update();
}

void TeachingBoard::on_eraseButton_clicked()
{
    mode="erase";
    ui->lineWidthSlider->setValue(1);
}

void TeachingBoard::on_addImageButton_clicked()
{
    mode = "image";
    url = QFileDialog::getOpenFileName(this,"Select Image","C:/Users/HP/Pictures/wallpapers","Image files (*.jpg *.png *.jpeg)");
    update();
}

void TeachingBoard::on_yellowLineButton_clicked()
{
    penColor = QColor(255,234,8);
    ui->lineColorButton->setStyleSheet("background-color: rgb(255, 234, 8); border-radius:20px;");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(255, 234, 8);border-radius:20px;");
}

void TeachingBoard::on_redLineButton_clicked()
{
    penColor = QColor(230, 0, 0);
    updatePageInfoToTbModel();
    ui->lineColorButton->setStyleSheet("background-color: rgb(230, 0, 0);border-radius:20px;");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(230, 0, 0);border-radius:20px;");
}

void TeachingBoard::on_greenLineButton_clicked()
{
    penColor = QColor(87, 238, 77);
    updatePageInfoToTbModel();
    ui->lineColorButton->setStyleSheet("background-color: rgb(87,238,77);border-radius:20px;");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(87, 238 ,77);border-radius:20px;");
}

void TeachingBoard::on_blackLineButton_clicked()
{
    penColor = QColor(3, 3, 3);
    updatePageInfoToTbModel();
    ui->lineColorButton->setStyleSheet("background-color: rgb(3, 3, 3);border-radius:20px;");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(3, 3, 3);border-radius:20px;");
}

void TeachingBoard::on_whiteLineButton_clicked()
{
    penColor = QColor(255, 255, 255);
    updatePageInfoToTbModel();
    ui->lineColorButton->setStyleSheet("background-color: rgb(255, 255, 255); border-style: solid; border-color: black; border-width: 1px; border-radius:20px;");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:20px;");
}

void TeachingBoard::on_blueLineButton_clicked()
{
    penColor = QColor(102, 130, 255);
    updatePageInfoToTbModel();
    ui->lineColorButton->setStyleSheet("background-color: rgb(102, 130, 255);border-radius:20px;");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(102, 130, 255);border-radius:20px;");
}

void TeachingBoard::on_blackBackgroundColorButton_clicked()
{
    drawableComponent::pageColor = 1;
    penColor = QColor(255, 255, 255);
    update();
    updatePageInfoToTbModel();
    ui->lineColorButton->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:20px;border-style: solid; border-color: black; border-width: 1px;");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:20px;");
}

void TeachingBoard::on_whiteBackgroundColorButton_clicked()
{
    drawableComponent::pageColor = 2;
    update();
    updatePageInfoToTbModel();
    ui->lineColorButton->setStyleSheet("background-color: rgb(0, 0, 0);");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(0, 0, 0);border-radius:20px;");
}

void TeachingBoard::on_blueBackgroundColorButton_clicked()
{
    drawableComponent::pageColor = 3;
    penColor = QColor(255, 255, 255);
    update();
    updatePageInfoToTbModel();
    ui->lineColorButton->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:20px; border-style: solid; border-color: black; border-width: 1px;");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:20px;");
}

void TeachingBoard::on_greenBackgroundColorButton_clicked()
{
    drawableComponent::pageColor = 4;
    penColor = QColor(255, 255, 255);
    update();
    updatePageInfoToTbModel();
    ui->lineColorButton->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:20px; border-style: solid; border-color: black; border-width: 1px;");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:20px;");
}

void TeachingBoard::on_rustBackgroundColorButton_clicked()
{
    drawableComponent::pageColor = 5;
    penColor = QColor(255, 255, 255);
    update();
    ui->lineColorButton->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:20px; border-style: solid; border-color: black; border-width: 1px;");
    ui->lineColorFrameCloseButton->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:20px;");
    updatePageInfoToTbModel();
}

void TeachingBoard::on_ruledSheetButton_clicked()
{
    this->pageMode= 1;
    updatePageInfoToTbModel();
    update();
}

void TeachingBoard::on_graphSheetButton_clicked()
{
    this->pageMode = 2;
    updatePageInfoToTbModel();
    update();
}

void TeachingBoard::on_plainSheetButton_clicked()
{
    this->pageMode=3;
    updatePageInfoToTbModel();
    update();
}

void TeachingBoard::on_gridSheetButton_clicked()
{
    this->pageMode=4;
    updatePageInfoToTbModel();
    update();
}

void TeachingBoard::on_sheetReviewButton_clicked()
{
    if(sheetReviewVar == 0){
        checkSheetFrame(sheetFrameVar);
        ui->sheetReviewFrame->setVisible(true);
        sheetReviewVar = 1;
        sheetFrameVar = 1;
    }
    else{
        ui->sheetReviewFrame->setVisible(false);
        sheetReviewVar = 0;
        sheetFrameVar = 0;
    }
}

void TeachingBoard::on_lineWidthButton_clicked()
{
    checkColorSettingsFrame(colorFrameVar);
}

void TeachingBoard::on_pageNumber1Button_clicked()
{
    on_sheetReviewButton_clicked();
    pageNumber=0;
    info=tbModel->getPageInformation(pageNumber);
    drawableComponent::pageColor=info->getPageColor();
    this->pageMode=info->getPageType();
    update();
}

void TeachingBoard::on_addNewPageButton_clicked()
{
        tbModel->addNewPage();
        this->undoList->append(new Undo());
        this->redoList->append(new Redo());
        QString s;
         int PNumber=tbModel->getNumberOfPages();
         info=new PageInformation();
         info->setPageColor(2);
         info->setPageType(3);
         tbModel->setPageInfo(PNumber-1,info);
         QPushButton *button=new QPushButton(s.setNum(PNumber),this->ui->sheetReviewFrame);
         button->setGeometry(this->ui->addNewPageButton->geometry());
         QObject::connect(button, &QPushButton::clicked,[=](){
             on_sheetReviewButton_clicked();
             this->pageNumber=PNumber-1;
             info=tbModel->getPageInformation(pageNumber);
             drawableComponent::pageColor=info->getPageColor();
             this->pageMode=info->getPageType();
             update();
             });
         button->setObjectName("pageNumber"+QString::number(PNumber)+"Button");
         button->setVisible(true);
         this->ui->addNewPageButton->setGeometry(this->ui->addNewPageButton->pos().x()+70,this->ui->addNewPageButton->pos().y(),this->ui->addNewPageButton->geometry().width(),this->ui->addNewPageButton->geometry().height());
         if(tbModel->getNumberOfPages()>16) this->ui->addNewPageButton->setVisible(false);
         this->pageNumber=PNumber-1;
         info=tbModel->getPageInformation(pageNumber);
         drawableComponent::pageColor=info->getPageColor();
         this->pageMode=info->getPageType();
         update();
         updateSheetReviewButton();
}

void TeachingBoard::updatePageInfoToTbModel()
{
    info=new PageInformation();
    info->setPageColor(drawableComponent::pageColor);
    info->setPageType(this->pageMode);
    tbModel->setPageInfo(pageNumber,info);
}

void TeachingBoard::on_previousSheetButton_clicked()
{
    if(this->pageNumber>0)
    {
    this->pageNumber--;
    info=tbModel->getPageInformation(pageNumber);
    drawableComponent::pageColor=info->getPageColor();
    this->pageMode=info->getPageType();
    update();
    updateSheetReviewButton();
    }
}

void TeachingBoard::on_nextSheetButton_clicked()
{
    int PNumber=tbModel->getNumberOfPages();
    if(this->pageNumber<PNumber-1)
    {
    this->pageNumber++;
    info=tbModel->getPageInformation(pageNumber);
    drawableComponent::pageColor=info->getPageColor();
    this->pageMode=info->getPageType();
    update();
    updateSheetReviewButton();
    }else{
        on_sheetReviewButton_clicked();
        on_addNewPageButton_clicked();
    }
}

void TeachingBoard::on_undoButton_clicked()
{
    this->proxyMode=this->mode;
    this->undoClick=true;
    this->mode="undo";
    update();
}

void TeachingBoard::on_redoButton1_clicked()
{
    this->proxyMode=this->mode;
    this->redoClick=true;
    this->mode="redo";
    update();
}

void TeachingBoard::updateSheetReviewButton(){
    QString pn,tp;
    int totalPage = tbModel->getNumberOfPages();
    pn.setNum(pageNumber+1);
    tp.setNum(totalPage);
    ui->sheetReviewButton->setText(pn+" / "+tp);
}

void TeachingBoard::on_saveButtton_clicked()
{
    QString jsonFilter = "JSON(*.json)";
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),"C:/Users/HP/Desktop/",tr(".yha"));
    tbModel->save(fileName+".yha");
}

void TeachingBoard::on_openButton_clicked()
{
   QString openFile = QFileDialog::getOpenFileName(this,tr("Open File"), "C:/Users/HP/Desktop/","*.yha");
   tbModel->open(openFile);
}

#ifndef TEACHINGBOARD_H
#define TEACHINGBOARD_H

#include <QMainWindow>
#include<QString>
#include<QPainter>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QFileDialog>
#include<QPushButton>
#include<QString>

#include"tbmodel.h"
#include"lineComponent.h"
#include"rectangleComponent.h"
#include"ellipseComponent.h"
#include"freehandComponent.h"
#include"imageComponent.h"
#include"pageInformation.h"
#include"eraseComponent.h"
#include"undo.h"
#include"redo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TeachingBoard; }
QT_END_NAMESPACE

class TeachingBoard : public QMainWindow
{
    Q_OBJECT

public:
    TeachingBoard(QWidget *parent = nullptr);
    ~TeachingBoard();
    void checkColorSettingsFrame(int var);
    void checkSheetFrame(int var);
    void closeSheetFrame(QPoint point);

private slots:
    void on_backgroundTypeButton_clicked();

    void on_backgroundColorButton_clicked();

    void on_lineColorButton_clicked();

    void on_lineTypeButton_clicked();

    void on_shapeButton_clicked();

    void updateSheetReviewButton();

    void on_penButton_clicked();

    void on_lineColorFrameCloseButton_clicked();

    void on_shapeFrameCloseButton_clicked();

    void on_rectangleButton_clicked();

    void on_lineButton_clicked();

    void on_selectButton_clicked();

    void on_eraseButton_clicked();

    void on_yellowLineButton_clicked();

    void on_redLineButton_clicked();

    void on_greenLineButton_clicked();

    void on_blackLineButton_clicked();

    void on_whiteLineButton_clicked();

    void on_blueLineButton_clicked();

    void on_ellipseButton_clicked();

    void on_blackBackgroundColorButton_clicked();

    void on_whiteBackgroundColorButton_clicked();

    void on_blueBackgroundColorButton_clicked();

    void on_greenBackgroundColorButton_clicked();

    void on_rustBackgroundColorButton_clicked();

    void on_graphSheetButton_clicked();

    void on_ruledSheetButton_clicked();

    void on_clearSheetButton_clicked();

    void on_plainSheetButton_clicked();

    void on_gridSheetButton_clicked();

    void on_sheetReviewButton_clicked();

    void on_lineWidthButton_clicked();

    void on_lineTypeFrameClosrButton_clicked();

    void on_solidLineButton_clicked();

    void on_dottedLineButton_clicked();

    void on_dashLine_clicked();

    void on_addImageButton_clicked();

    void on_pageNumber1Button_clicked();

    void on_addNewPageButton_clicked();

    void updatePageInfoToTbModel();

    void on_previousSheetButton_clicked();

    void on_nextSheetButton_clicked();

    void on_undoButton_clicked();

    void on_redoButton1_clicked();

    void on_saveButtton_clicked();

    void on_openButton_clicked();

private:
    Ui::TeachingBoard *ui;
    QString mode,proxyMode;
    int pageMode;
    int pageNumber;
    QString url;
    QPoint initialPoint,finalPoint;
    QRect drawingRect;
    QColor penColor;
    QList<QPoint> *coordinates;
    TBModel *tbModel;
    drawableComponent *component;
    lineComponent *line;
    rectangleComponent *rectangle;
    ellipseComponent *ellipse;
    eraseComponent *eraser;
    freehandComponent *freehand;
    imageComponent *image;
    PageInformation *info;
    QList<Undo *> *undoList;
    QList<Redo *> *redoList;

    bool isPressed=false;
    bool undoClick=false;
    bool wasCleared=false;
    bool redoClick=false;
    int lineType=0;
    int sheetTypeVar=0;
    int sheetBackgroundVar = 0;
    int colorFrameVar = 0;
    int sheetFrameVar = 0;
    int sheetReviewVar = 0;
    int mouseMoved = 0;
    bool isClickedInDrawingRange(QPoint point);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};
#endif // TEACHINGBOARD_H

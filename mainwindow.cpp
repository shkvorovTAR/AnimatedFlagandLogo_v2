#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::gray, Qt::SolidPattern));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    timer->start(1000/60);

    drawScene();
}

void MainWindow::timerTick()
{
    drawScene();
}

void MainWindow::drawScene()
{
    scene->clear();
    drawFlag();
    drawLogo();

}

void MainWindow::drawFlag()
{
    static bool needStop = false;

    scene->addRect(flagXPos, flagYPos, FLAG_WIDTH, FLAG_PART_HEIGHT, Qt::NoPen, QBrush(QColor("#0073cf")));
    scene->addRect(flagXPos, flagYPos + FLAG_PART_HEIGHT, FLAG_WIDTH, FLAG_PART_HEIGHT, Qt::NoPen, QBrush(Qt::black));
    scene->addRect(flagXPos, flagYPos + FLAG_PART_HEIGHT * 2, FLAG_WIDTH, FLAG_PART_HEIGHT, Qt::NoPen, QBrush(Qt::white));

    if(needStop) {
        timer->stop();
        return;
    }

    flagXPos += FLAG_DIFF * flagXDir;
    if(flagXDir > 0 && (flagXPos + FLAG_WIDTH >= SCENE_WIDTH))
    {
        flagXDir = -1;
    }
    else if(flagXDir < 0 && flagXPos<= 0) {
        flagXDir = 1;
    }

    flagYPos += FLAG_DIFF * flagYDir;
    if(flagYDir > 0 && (flagYPos + FLAG_HEIGHT >= SCENE_HEIGHT))
    {
        flagYDir = -1;
    }
    else if(flagYDir < 0 && flagYPos<= 0) {
        flagYDir = 1;
    }

}

void MainWindow::drawLogo()
{
    QPainterPath path = QPainterPath(QPointF(LOGO_OFFSET_X, LOGO_OFFSET_Y));
    path.lineTo(LOGO_OFFSET_X, LOGO_OFFSET_Y + 110);
    path.lineTo(LOGO_OFFSET_X-26, LOGO_OFFSET_Y + 110);
    path.lineTo(LOGO_OFFSET_X-26, LOGO_OFFSET_Y + 12);
    path.closeSubpath();
    scene->addPath(path, currentLogoPen, currentLogoBrush);

    scene->addEllipse(LOGO_OFFSET_X + 9, LOGO_OFFSET_Y - 3, 52, 52, currentLogoPen, currentLogoBrush);
    scene->addEllipse(LOGO_OFFSET_X + 9, LOGO_OFFSET_Y - 3 +52 +9, 52, 52, currentLogoPen, currentLogoBrush);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_clicked()
{
    currentLogoBrush = LOGO_BRUSH_1;
    currentLogoPen = LOGO_PEN_1;
}

void MainWindow::on_radioButton_2_clicked()
{
    currentLogoBrush = LOGO_BRUSH_2;
    currentLogoPen = LOGO_PEN_2;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    const int SCENE_WIDTH = 500;
    const int SCENE_HEIGHT = 400;

    const int FLAG_WIDTH = 165;
    const int FLAG_HEIGHT = 105;
    const int FLAG_PART_HEIGHT = FLAG_HEIGHT / 3;
    const int FLAG_DIFF = 5;

    const QColor LOGO_COLOR_1 = QColor("#0072ce");
    const QBrush LOGO_BRUSH_1 = QBrush(LOGO_COLOR_1);
    const QPen LOGO_PEN_1 = QPen(LOGO_COLOR_1);

    const QBrush LOGO_BRUSH_2 = QBrush(Qt::white);
    const QPen LOGO_PEN_2 = QPen(LOGO_BRUSH_1, 4, Qt::DotLine);

    const int LOGO_OFFSET_X = 250;
    const int LOGO_OFFSET_Y = 170;

    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QTimer *timer;

    QBrush currentLogoBrush = LOGO_BRUSH_1;
    QPen currentLogoPen = LOGO_PEN_1;

    int flagXPos = 0;
    int flagXDir = -1;
    int flagYPos = 0;
    int flagYDir = -1;

    void drawScene();
    void drawFlag();
    void drawLogo();

private slots:
    void timerTick();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
};

#endif // MAINWINDOW_H

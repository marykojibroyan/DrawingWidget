#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class DrawingWidget;
}
QT_END_NAMESPACE

class DrawingWidget : public QMainWindow
{
    Q_OBJECT

public:
    DrawingWidget(QWidget *parent = nullptr);
    ~DrawingWidget();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QVector<QRect> rectangles;
    QVector<QLine> lines;
    QPoint startPoint;
    QPoint endPoint;
    bool drawingLine;
    bool drawingRect;

private:
    Ui::DrawingWidget *ui;
};
#endif // DRAWINGWIDGET_H

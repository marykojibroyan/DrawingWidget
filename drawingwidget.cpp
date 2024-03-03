#include "drawingwidget.h"
#include "ui_drawingwidget.h"
#include <QPainter>

DrawingWidget::DrawingWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DrawingWidget)
{
    ui->setupUi(this);
}

void DrawingWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Draw previously drawn shapes
    for (const auto& rect : rectangles)
        painter.drawRect(rect);
    for (const auto& line : lines)
        painter.drawLine(line);

    // Draw the current shape being drawn
    if (drawingRect)
        painter.drawRect(QRect(startPoint, endPoint));
    else if (drawingLine)
        painter.drawLine(startPoint, endPoint);
}
void DrawingWidget::mousePressEvent(QMouseEvent *event) {
    startPoint = event->pos();
}

void DrawingWidget::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        endPoint = event->pos();
        update(); // Trigger repaint to update the drawn shape in real-time
    }
}

void DrawingWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if (drawingRect) {
            QRect rect(startPoint, endPoint);
            rectangles.push_back(rect.normalized()); // Store normalized rectangle
        } else if (drawingLine) {
            lines.push_back(QLine(startPoint, endPoint)); // Store line
        }
        update(); // Trigger repaint to draw the stored shape
    }
}

DrawingWidget::~DrawingWidget()
{
    delete ui;
}

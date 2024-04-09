#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickWidget>

#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// private slots:
    // void quickViewStatusChanged(QQuickView::Status);
    // void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);

private:
    Ui::MainWindow *ui;
    QQuickWidget *quick_widget_;
    Model model_;
};
#endif // MAINWINDOW_H

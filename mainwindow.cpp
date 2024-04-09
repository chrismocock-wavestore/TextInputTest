#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLineEdit>
#include <QQmlContext>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    quick_widget_(new QQuickWidget)
{
    ui->setupUi(this);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    quick_widget_->setSource(QUrl(QStringLiteral("qrc:/TextInputTest/MainWindow.qml")));
    quick_widget_->show();

    layout->addWidget(quick_widget_);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::quickViewStatusChanged(QQuickView::Status status)
// {
//     if (status == QQuickView::Error) {
//         QStringList errors;
//         const auto viewErrors = quick_view_->errors();
//         for (const QQmlError &error : viewErrors)
//             errors.append(error.toString());
//         statusBar()->showMessage(errors.join(QStringLiteral(", ")));
//     }
// }

// void MainWindow::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
// {
//     statusBar()->showMessage(message);
// }

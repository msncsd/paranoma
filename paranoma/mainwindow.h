#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QGLWidget>
#include <QVBoxLayout>
#include "glviewwidget.h"

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_conBtn_clicked();

    void on_addBtn_clicked();

    void on_frameList_itemClicked(QListWidgetItem *item);

    void on_clearAllBtn_clicked();

    void on_siftBtn_clicked();

    void on_selectBtn_clicked();

private:
    Ui::MainWindow *ui;
    QGLWidget * qglw;
    GLViewWidget* glview;
    QVBoxLayout *lay;
};

#endif // MAINWINDOW_H

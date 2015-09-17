#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QGLWidget>
#include <QVBoxLayout>
#include <QVector>
#include "glviewwidget.h"
#include "frame.h"

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

    void handleButton();

    void moveScrollBarToBottom(int min, int max);

    void on_selectBtn_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QGLWidget * qglw;
    GLViewWidget* glview;
    QVBoxLayout *lay;
    QVector<Frame> frameList;
};

#endif // MAINWINDOW_H

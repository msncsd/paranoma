#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
//#include <QListWidgetItem>

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
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QLabel>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_conBtn_clicked()
{
    qDebug() <<"cliced connect button";
    //QMessageBox::information(this,tr("Information"),tr("Can see the Frames' Connections"));
}

//Add Button Click Event
void MainWindow::on_addBtn_clicked()
{
    // 1.Open File dialog
    //   파일 다이얼로그를 열고 file path 를 얻는다
    QString filepath = QFileDialog::getOpenFileName(
                this,
                tr("Add Images"),
                "C://", //===파일 다이얼로그가 열리는 위치.. 임시로 아래 위치를 이용함
                //"C://Users//godori//img//",
                "All files(*.*);;Image File(*.png);;Image File(*.jpg);;Image File(*.bmp)"
                );

    // 2. get filepath and Set Image and Label
    //    불러온 파일의 패스로 preview 라벨에 이미지를 셋팅하고 path 라벨로 파일 패스 확인
    if(!filepath.isEmpty())
    {
        // 파일 처리 작업
        QImage image(filepath);     // 파일 패스로 이미지 생성
        QFile f(filepath);          // 파일 패스로 파일 f 생성
        QFileInfo  fileinfo(f.fileName());      // 파일 f 로 파일정보 생성
        QString filename(fileinfo.fileName());  // 파일정보에서 파일 이름 얻기

        // ui에 반영
        ui->preview->setPixmap(QPixmap::fromImage(image)); // 프리뷰 이미지 셋팅
        ui->frameList->addItem(filename);   // 파일이름 리스트에 추가
        ui->path->setText(filepath);        // 파일 패스 확인
        qDebug() <<"added filepath : "+filepath;

    }

    //QMessageBox::information(this,tr("File Name"),filename);

}



void MainWindow::on_frameList_itemClicked(QListWidgetItem *item)
{
   qDebug()<<"item clicked :"+ui->frameList->currentItem()->text();
   //ui->frameList->currentItem()->

}

void MainWindow::on_clearAllBtn_clicked()
{
    //ui->preview->clear();
    ui->preview->setText("no image");
    ui->frameList->clear();
}


// 셀렉트 버튼 클릭시 발생하는 이벤트 (전체중에 부분 선택)
void MainWindow::on_selectBtn_clicked()
{

}

// 시프트 모듈 테스트 버튼 클릭시 발생 이벤트
void MainWindow::on_siftBtn_clicked()
{

}


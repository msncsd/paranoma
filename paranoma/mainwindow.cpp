#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGLWidget"
#include "framelabel.h"
#include "frame.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QLabel>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>
#include <QGLWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QWidget>
#include <QPalette>
#include <QObject>
#include <QScrollBar>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   // ** Add custom glwidget
   glview = new GLViewWidget();
   ui->panoViewer->addWidget(glview);

   // ** Add scroll layout contents
   lay = new QVBoxLayout(this);
   ui->preview->setText("no image");

   //** Change Backrgoud of Widget
//   QPalette Pal(palette());
//   Pal.setColor(QPalette::Background, Qt::black);
//   ui->scrollArea->setAutoFillBackground(true);
//   ui->scrollArea->setPalette(Pal);

   //** scroll bar down always
   QScrollBar* scrollbar = ui->scrollArea->verticalScrollBar();
   QObject::connect(scrollbar, SIGNAL(rangeChanged(int,int)), this, SLOT(moveScrollBarToBottom(int, int)));

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
                //"C://", //===파일 다이얼로그가 열리는 위치.. 임시로 아래 위치를 이용함
                "C://Users//",
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

        // 새 프레임 생성 및 정보 저장
        Frame fm;
        fm.setFilePath(filepath);
        fm.setFileName(filename);

        // 새 프레임을 프레임리스트에 추가
        frameList.push_back(fm);
        for(int i = 0;i<frameList.size();i++){
            // 이제까지 만든 프레임 정보
            qDebug() <<"frameList["<<i<<"] name : "<<frameList[i].getFileName();
            qDebug() <<"frameList["<<i<<"] path : "<<frameList[i].getFilePath();
        }

        // ui에 반영
        ui->preview->setPixmap(QPixmap::fromImage(image)); // 프리뷰 이미지 셋팅
        ui->frameList->addItem(filename);   // 파일이름 리스트에 추가
        ui->path->setText(filepath);        // 파일 패스 확인
        qDebug() <<"added filepath : "+filepath;


        // (임시)리스트에 버튼을 추가
        QPushButton *btn = new QPushButton();
        btn->setFlat(true);

        QPixmap *mypix = new QPixmap();
        *mypix = QPixmap::fromImage(image);

        frameLabel *flabel = new frameLabel();
        flabel->setPixmap(*mypix);
        flabel->setFixedWidth(160);
        flabel->setFixedHeight(80);
        flabel->setScaledContents(true);
        lay->addWidget(flabel);
        ui->scrollAreaWidgetContents->setLayout(lay);

        //toggle mode
         //QPushButton *toggleButton;
         //ui->selectBtn->setCheckable( true );

        // button ver. (클릭 되지만 크기조절이 안됨)
        /*
        QPixmap pixmap;
        pixmap = QPixmap::fromImage(image);
        QPalette palette;
        QPushButton *button= new QPushButton(this);
        palette.setBrush(button->backgroundRole(), QBrush(pixmap));
        button->setFlat(true);
        button->setAutoFillBackground(true);
        button->setFixedHeight(60); // tGeometry();
        button->setPalette(palette);
        lay->addWidget(button);
         ui->scrollAreaWidgetContents->setLayout(lay);
        */

        //QVBoxLayout frameThumb = new QVBoxLayout(this);

       // QLabel namelabel(filename);//= new QLabel(filename);
      //  QWidget *item = new QWidget();
      //  item->add


        //lay->addItem(flabel);

       // lay->addWidget(namelabel);
        //lay->addItem(namelabel);



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
    QImage image(frameList[0].getFilePath());

    QPixmap *mypix = new QPixmap();
     *mypix = QPixmap::fromImage(image);

//            QPainter p(&pic);
//            QBrush b(QColor(0,0,0,128)); // adjust color and alpha to taste
//            p.setBrush(b);
//            p.drawRect(0, 0, 200, 200);

//            QPixmap pix(":/your/fancy/png/here");

        QPainter painter(mypix);
        QBrush b(QColor(255,255,255,128));
        painter.setBrush(b);
        painter.drawLine(0,0,500,500);

        b.setColor(QColor(255,0,0,128));
        painter.setBrush(b);
        painter.drawRect(30,30,500,500);

       //p->drawLine(pix.rect().topLeft(),pix.rect().bottomRig ht());

            ui->preview->setPixmap(*mypix);
//flabel->setPixmap(*mypix);
            //.show();
       //l.show();

}
void MainWindow::handleButton(){

}


// with scroll bar down always
void MainWindow::moveScrollBarToBottom(int min, int max)
{
    Q_UNUSED(min);
    ui->scrollArea->verticalScrollBar()->setValue(max);
}

void MainWindow::on_selectBtn_toggled(bool checked)
{

}

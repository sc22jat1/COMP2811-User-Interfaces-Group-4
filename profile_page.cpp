// profile_page.cpp
#include "profile_page.h"
#include "ui_profile_page.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>

ProfilePage::ProfilePage( QWidget *parent) : QDialog(parent), ui(new Ui::ProfilePage) {
    ui->setupUi(this);

    // set the slot function
    connect(ui->Play_Button_1, &QPushButton::clicked, this, &ProfilePage::on_Play_Button_1_Clicked);
    connect(ui->Play_Button_2, &QPushButton::clicked, this, &ProfilePage::on_Play_Button_2_Clicked);

    // connector to change image for user
    connect(ui->Tool_to_change_img, SIGNAL(clicked()), this, SLOT(on_Tool_to_change_img_clicked()));
}

ProfilePage::~ProfilePage() {
    delete ui;
}

void ProfilePage::on_Tool_to_change_img_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "Select Image", QDir::homePath(), "Images (*.png *.jpg *.jpeg)");

    if (!imagePath.isEmpty())
    {
        QPixmap newPixmap(imagePath);
        ui->Profile_img_appearance->setPixmap(newPixmap.scaled(ui->Profile_img_appearance->size(), Qt::KeepAspectRatio));
    }

    else
    {
        QMessageBox::information(this, "Image not selected", "No image selected or canceled");
    }

    
}

// Home button
void ProfilePage::on_Homebutton_clicked() {
    
    hide(); // hide current page
   
}

void ProfilePage::on_Play_Button_1_Clicked()
{
    QString videoPath = QFileDialog::getOpenFileName(this, "Open Video", QDir::homePath(), "Videos (*.mp4 *.avi *.mkv)");

    if (!videoPath.isEmpty()) {
        QMediaPlayer *mediaPlayer = new QMediaPlayer(this);
        QVideoWidget *videoWidget = new QVideoWidget(this);

        QVBoxLayout *layout = new QVBoxLayout(ui->video_1);
        layout->addWidget(videoWidget);

        mediaPlayer->setVideoOutput(videoWidget);
        mediaPlayer->setMedia(QUrl::fromLocalFile(videoPath));
        mediaPlayer->play();
    }
}



void ProfilePage::on_Play_Button_2_Clicked()
{
    QString videoPath = QFileDialog::getOpenFileName(this, "Open Video", QDir::homePath(), "Videos (*.mp4 *.avi *.mkv)");

    if (!videoPath.isEmpty()) {
        QMediaPlayer *mediaPlayer = new QMediaPlayer(this);
        QVideoWidget *videoWidget = new QVideoWidget(this);

        QVBoxLayout *layout = new QVBoxLayout(ui->video_2);
        layout->addWidget(videoWidget);

        mediaPlayer->setVideoOutput(videoWidget);
        mediaPlayer->setMedia(QUrl::fromLocalFile(videoPath));
        mediaPlayer->play();
    }
}








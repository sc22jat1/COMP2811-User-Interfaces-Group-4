#include "video_recorder_page.h"
#include <QDebug>
#include <QUrl>

VideoRecorderPage::VideoRecorderPage(QWidget *parent) : QWidget(parent) {
    topLayout = new QVBoxLayout(this);
    setWindowTitle("Video Recorder");
    setMinimumSize(400, 340);

    camera = new QCamera(this);
    viewfinder = new QCameraViewfinder(this);
    camera->setViewfinder(viewfinder);

    mediaRecorder = new QMediaRecorder(camera);
    camera->setCaptureMode(QCamera::CaptureVideo);

    camera->start();

    if (!camera->isAvailable()) {
        qDebug() << "Camera not available";
    } else {
        qDebug() << "Camera is available";
    }

    topLayout->addWidget(viewfinder);

    qDebug() << "Viewfinder added to layout";

    recordButton = new QPushButton("Record", this);
    stopButton = new QPushButton("Stop", this);

    connect(recordButton, &QPushButton::clicked, this, &VideoRecorderPage::startRecording);
    connect(stopButton, &QPushButton::clicked, this, &VideoRecorderPage::stopRecording);

    topLayout->addWidget(recordButton);
    topLayout->addWidget(stopButton);
}

void VideoRecorderPage::startRecording() {
    qDebug() << "Recording Start";
    QString fileName = "video.mp4"; // Change this to your desired file name
    QString videoFilePath = "C:/Users/lucky/Pictures/video.mp4";
    mediaRecorder->setOutputLocation(QUrl::fromLocalFile(videoFilePath));
    // mediaRecorder->setVideoSettings(camera->supportedViewfinderSettings().at(0)); // You might want to set appropriate video settings
    mediaRecorder->isAvailable();
    mediaRecorder->record();
    qDebug() << "Recording state: " << mediaRecorder->state();
}

void VideoRecorderPage::stopRecording() {
    mediaRecorder->stop();
    qDebug() << "Recording state: " << mediaRecorder->state();
}


#ifndef VIDEO_RECORDER_PAGE_H
#define VIDEO_RECORDER_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCamera>
#include <QCameraViewfinder>
#include <QMediaRecorder>

class VideoRecorderPage : public QWidget {
    Q_OBJECT

public:
    VideoRecorderPage(QWidget *parent = nullptr);

private slots:
    void startRecording();
    void stopRecording();

private:
    QVBoxLayout *topLayout;
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QMediaRecorder *mediaRecorder;
    QPushButton *recordButton;
    QPushButton *stopButton;
};

#endif // VIDEO_RECORDER_PAGE_H

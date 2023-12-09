#ifndef THE_PLAYER_H
#define THE_PLAYER_H

#include <QMediaPlayer>
#include <QMediaContent>
#include <QVideoWidget>
#include <QUrl>
#include <vector>
#include "the_button.h"

class ThePlayer : public QMediaPlayer
{
    Q_OBJECT

public:
    ThePlayer(QObject *parent = nullptr);

    void setContent(std::vector<TheButton *> *b, std::vector<TheButtonInfo> *i);
    void shuffle();
    void jumpTo(TheButtonInfo *button);

public slots:
    void playStateChanged(QMediaPlayer::State ms);
    void playPauseToggle(); // New function for play/pause toggle
    void toggleSound(); // Declaration for toggleSound

private:
    std::vector<TheButton *> *buttons;
    std::vector<TheButtonInfo> *infos;
    int updateCount;
};

#endif // THE_PLAYER_H

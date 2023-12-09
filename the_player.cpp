#include "the_player.h"
#include <QDebug>
#include <cstdlib>

ThePlayer::ThePlayer(QObject *parent)
    : QMediaPlayer(parent), buttons(nullptr), infos(nullptr), updateCount(0)
{
    connect(this, &QMediaPlayer::stateChanged, this, &ThePlayer::playStateChanged);
}

void ThePlayer::setContent(std::vector<TheButton *> *b, std::vector<TheButtonInfo> *i)
{
    buttons = b;
    infos = i;
    jumpTo(buttons->at(0)->info);
}

void ThePlayer::shuffle()
{
    TheButtonInfo *i = &infos->at(rand() % infos->size());
    buttons->at(updateCount++ % buttons->size())->init(i);
}

void ThePlayer::playStateChanged(QMediaPlayer::State ms)
{
    switch (ms)
    {
    case QMediaPlayer::State::StoppedState:
        play(); // starting playing again...
        break;
    default:
        break;
    }
}

void ThePlayer::jumpTo(TheButtonInfo *button)
{
    setMedia(*button->url);
    setMuted(true);
    play();
}

void ThePlayer::playPauseToggle()
{
    if (state() == QMediaPlayer::PlayingState)
    {
        pause();
    }
    else if (state() == QMediaPlayer::PausedState)
    {
        play();
    }
}

void ThePlayer::toggleSound()
{
    setMuted(!isMuted()); // Toggle the mute state
}

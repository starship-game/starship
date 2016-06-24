#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "player.h"
#include "score.h"
#include "health.h"
#include "bottun.h"
#include "level.h"
#include <QObject>

class Game:public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent = 0);
    QGraphicsScene *scene;
    Score *score;
    Player *player;
    Health *health;
    Button * play;
    Level *level;
    void menu();
    void gameOver();
public slots:
    void start();
};

#endif // GAME_H

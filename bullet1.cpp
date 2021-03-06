#include "bullet1.h"
#include <QTimer>
#include <QList>
#include <QDebug>
#include "game.h"
#include "spaceship.h"
#include "award1.h"
#include "award2.h"
#include <stdlib.h>
#include <typeinfo>

extern Spaceship * ship;
extern Game * game;

Bullet1::Bullet1(QGraphicsItem *parent):Bullet(parent)
{
    power1=5;
    setPixmap(QPixmap(":/pic/bullet2.png"));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet1::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Spaceship)){
            //if(this->power1 == ship->getpower()){
                game->score->increase();
                int random_numbetr= rand()%3;
                if(random_numbetr ==0){
                }
                else if(random_numbetr == 1){
                    Award1 * award1 = new Award1();
                    award1->setPos(x(),y());
                    scene()->addItem(award1);
                }
                else if(random_numbetr == 2){
                    Award2 * award2 = new Award2();
                    award2->setPos(x(),y());
                    scene()->addItem(award2);
                }
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
            //}
            //else if(this->power1 != ship->getpower()){
                scene()->removeItem(this);
                delete this;
                //ship->setpower(power1);
                //qDebug()<<power1;
                //return;
            //}
            /*scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];*/

            return;
        }
    }
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

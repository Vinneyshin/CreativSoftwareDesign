#include "minimal_fighter.h"

MinimalFighter::MinimalFighter(int _hp, int _power) {
    mHp = _hp;
    mPower = _power;
    mStatus = Alive;
}

void MinimalFighter::setHp(int _hp) {
    mHp = _hp;
}
void MinimalFighter::setStatus(FighterStatus _status) {
    mStatus = _status;
}
void MinimalFighter::setPower(int _power) {
    mPower = _power;
}


   
void MinimalFighter::hit(MinimalFighter *_enemy) {
    MinimalFighter* you = this;
    if ( _enemy->hp() - you->power() <= 0 )
        _enemy -> setStatus(Dead);
    
    if ( you->hp() - _enemy->power() <= 0 )
        you -> setStatus(Dead);

    _enemy->setHp(_enemy->hp() - you->power());
    you->setHp(you->hp() - _enemy->power());
}

void MinimalFighter::attack(MinimalFighter *_target) {
    MinimalFighter* you = this;

    if ( _target->hp() - you->power() <= 0 )
        _target -> setStatus(Dead);

        _target->setHp(_target->hp() - you->power());

        you -> setPower(0);
}

void MinimalFighter::fight(MinimalFighter *_enemy) {
    MinimalFighter* you = this;
    
    while (you -> status() == Alive && _enemy -> status() == Alive)
        you -> hit (_enemy);
}
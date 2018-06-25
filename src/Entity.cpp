/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:24:58 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/24 05:03:10 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

// ------------------------------Constructors------------------------------
Entity::Entity() {
    setAlive(false);
}
Entity::Entity(Entity const & obj) {
    *this = obj;
}

// ------------------------------Destructors-------------------------------
Entity::~Entity() {
}

// -------------------------------Operators--------------------------------
Entity &        Entity::operator=(Entity const & obj) {
    this->_alive = obj.getAlive();
    return (*this);
}

// --------------------------------Getters---------------------------------
bool            Entity::getAlive() const {
    return (_alive);
}
int             Entity::getCoordX() const {
    return (_x);
}
int             Entity::getCoordY() const {
    return (_y);
}
int             Entity::getMaxX() const {
    return (_xMax);
}
int             Entity::getMaxY() const {
    return (_yMax);
}
char            Entity::getSkin() const {
    return (_skin);
}

// --------------------------------Setters---------------------------------
void            Entity::setAlive(bool alive) {
    _alive = alive;
}
void            Entity::setCoordX(int x) {
    _x = x;
}
void            Entity::setCoordY(int y) {
    _y = y;
}
void            Entity::setMaxX(int xMax) {
    _xMax = xMax;
}
void            Entity::setMaxY(int yMax) {
    _yMax = yMax;
}
void            Entity::setSkin(char skin) {
    _skin = skin;
}

// --------------------------------Metods----------------------------------
void            Entity::setStart(int maxX, int maxY, int enem) {
    (void)maxX;
    (void)maxY;
    (void)enem;
}

// -------------------------------Collision--------------------------------


// ---------------------------------Moves----------------------------------
void            Entity::moveUp() {
    if (_y > 0) {
        _y--;
    }
}
void            Entity::moveDown() {
    if (_y < _yMax - 1) {
        _y++;
    }
}
void            Entity::moveRight() {
    if (_x < _xMax - 1) 
        _x++;
}
void            Entity::moveLeft() {
    if (_x > 0) {
        _x--;
    }
}

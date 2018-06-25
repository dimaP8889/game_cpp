/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 05:57:53 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/24 21:37:57 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

// ------------------------------Constructors------------------------------

Enemy::Enemy() {
	this->_alive = false;
	this->_y = 0;
	this->_skin = 'V';
}

Enemy::Enemy(Enemy const & obj) {

	*this = obj;
}

// ------------------------------Destructors-------------------------------

Enemy::~Enemy() {

}

// -------------------------------Operators--------------------------------

Enemy &		Enemy::operator=(Enemy const & obj) {

	_x = obj.getCoordX();
	_y = obj.getCoordY();
	_alive = obj.getAlive();
	return (*this);
}

void		Enemy::newEnemy(int const winX, int const winY) {
	this->_xMax = winX;
	this->_yMax = winY;
	this->_alive = true;
	this->_x = rand() % this->_xMax;
	this->_y = 0;
}
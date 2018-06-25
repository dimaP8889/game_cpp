/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:33:00 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/24 20:53:11 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bullet.hpp"
#include "Ship.hpp"

Ship::Ship() {
	return ;
}

Ship::Ship(Ship const & copy) {
	
	*this = copy;
}

Ship &		Ship::operator=(Ship const & copy) {

	_x = copy.getCoordX();
	_y = copy.getCoordY();
	_xMax = copy.getMaxX();
	_yMax = copy.getMaxY();
	return (*this);
}

Ship::Ship(int const winX, int const winY) {
	this->_xMax = winX;
	this->_yMax = winY;
	this->_y = winY - 1;
	this->_x = winX / 2;
	this->_alive = true;
	this->_skin = '^';
	this->_bullets = new Bullet[this->_yMax];
}


Ship::~Ship() {

}

Bullet* Ship::getBullets(void) const {
	return (this->_bullets);
}

void	Ship::fire(int y, int x) {
	if (!y)
		return ;
	for (int i = 0; i < this->_yMax; i++)
		if (!(this->_bullets[i].getAlive())) {
			this->_bullets[i].setAlive(true);
			this->_bullets[i].setCoordY(y);
			this->_bullets[i].setCoordX(x);
			return ;
		}
}

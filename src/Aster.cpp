// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Aster.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 21:27:05 by ypikul            #+#    #+#             //
//   Updated: 2018/06/24 21:27:06 by ypikul           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Aster.hpp"

// ------------------------------Constructors------------------------------

Aster::Aster() {
	this->_alive = false;
	this->_y = 0;
	this->_skin = '.';
}

Aster::Aster(Aster const & obj) {

	*this = obj;
}

// ------------------------------Destructors-------------------------------

Aster::~Aster() {

}

// -------------------------------Operators--------------------------------

Aster &		Aster::operator=(Aster const & obj) {

	_x = obj.getCoordX();
	_y = obj.getCoordY();
	_alive = obj.getAlive();
	return (*this);
}

void		Aster::newAster(int const winX, int const winY) {
	this->_xMax = winX;
	this->_yMax = winY;
	this->_alive = true;
	this->_x = rand() % this->_xMax;
	this->_y = 0;
}
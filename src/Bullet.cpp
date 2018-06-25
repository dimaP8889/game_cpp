/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 04:26:18 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/24 05:02:49 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

// ------------------------------Constructors------------------------------

Bullet::Bullet(void) {
	setAlive(false);
	setSkin('*');
}

Bullet::Bullet		(Bullet const & copy) {
	*this = copy;
}

// ------------------------------Destructors-------------------------------

Bullet::~Bullet() {
	return ;
}

// -------------------------------Operators--------------------------------

Bullet &		Bullet::operator=(Bullet const & obj) {
	_x = obj.getCoordX();
	_y = obj.getCoordY();
	_alive = obj.getAlive();
	return (*this);
}


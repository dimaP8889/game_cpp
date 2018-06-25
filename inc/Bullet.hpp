/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 04:26:36 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/24 05:40:32 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_H
# define BULLET_CLASS_H

#include "Entity.hpp"

class Bullet : public Entity {
private:
public:
	Bullet();
	Bullet(Bullet const & copy);
	~Bullet();

	Bullet &		operator=(Bullet const & obj);
};

#endif

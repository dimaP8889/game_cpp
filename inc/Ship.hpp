/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 02:44:28 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/24 20:53:33 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_HPP
# define SHIP_HPP

# include "Bullet.hpp"
# include "Entity.hpp"

class Ship : public Entity {
private:
	Bullet *_bullets;
public:
	Ship(void);
	Ship(int const winX, int const winY);
	Ship(Ship const & copy);
	~Ship(void);

	Bullet	*getBullets() const;
	void	fire(int y, int x);

	Ship &        operator=(Ship const & obj);
};

#endif

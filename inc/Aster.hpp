// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Aster.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 21:26:35 by ypikul            #+#    #+#             //
//   Updated: 2018/06/24 21:26:35 by ypikul           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASTER_HPP
# define ASTER_HPP


# include "Entity.hpp"

class Aster : public Entity
{
public:
	Aster();
	Aster(Aster const & copy);
	~Aster();
	
	Aster &		operator=(Aster const & copy);
	void		newAster(int const winX, int const winY);

};

#endif
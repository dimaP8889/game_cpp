/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:38:19 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/24 21:14:02 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <time.h>

int		main(void)
{
	Game game;

	srand(time(0));
	game.play();
	return (0);
}
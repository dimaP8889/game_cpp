/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:16:49 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/24 22:00:11 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "Ship.hpp"
# include "Aster.hpp"
# include "Enemy.hpp"
# include <ncurses.h>

class Game {
private:
	WINDOW	*_win;
	int		_winX;
	int		_winY;
	WINDOW	*_panel;
	int		_panelX;
	int		_panelY;
	WINDOW	*_game;
	int		_gameX;
	int		_gameY;

	Ship	*_ship;
	Enemy	*_enemies;
	Aster	*_aster;

public:
	Game(void);
	Game(Game const & copy);
	~Game(void);

	int		score;
	int		lives;
	int		counter;

	WINDOW	*getWindow(void);
	void	play(void);
	int		getX(void);
	int		getY(void);
	void	moveAll(void);
	void	printAll(void);
	void	addEnemy(void);
	void	addAster(void);
	void	checkCollision(void);
	Game &	operator=(Game const & copy);
};

#endif

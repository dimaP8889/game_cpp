/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:16:19 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/24 22:03:42 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CPP
# define GAME_CPP

#include "Enemy.hpp"
#include "Ship.hpp"
#include "Game.hpp"
#include <ncurses.h>
#include <ctime>
#include <unistd.h>

Game::Game (Game const & copy) {

	*this = copy;
}

Game &	Game::operator=(Game const & obj) {

	//Soory nothing here
	(void)obj;
	return (*this);
}

Game::Game(void) {
	this->_win = initscr();
	this->_winX = getmaxx(this->_win);
	this->_winY = getmaxy(this->_win);
	cbreak();
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	noecho();
	curs_set(0);
	box(this->_win, 0, 0);
	refresh();
	this->_panelX = this->_winX;
	this->_panelY = this->_winY * 0.2;
	this->_panel = newwin(this->_panelY, this->_winX, this->_winY - this->_panelY, this->_winX - this->_panelX);
	box(this->_panel, 0, 0);
	wrefresh(this->_panel);
	this->_gameX = this->_winX - 1 - 1;
	this->_gameY = this->_winY - this->_panelY - 1;
	this->_game = newwin(this->_gameY, this->_gameX, 1, 1);
	keypad(this->_game, true);
	// mvwprintw(_game, 1, 0, "y: %i : x: %i", this->_gameY, this->_gameX);
	wrefresh(this->_game);
	this->_aster = new Aster[150];
	this->_enemies = new Enemy[42];
	this->_ship = new Ship(this->_gameX, this->_gameY);
	nodelay(this->_game, true);

	this->score = 0;
	this->lives = 3;
	this->counter = 0;
}

Game::~Game(void) {
	endwin();
}

WINDOW	*Game::getWindow(void) {
	return (this->_win);
}

int		Game::getX(void) {
	return (this->_winX);
}

int		Game::getY(void) {
	return (this->_winY);
}

void	Game::addEnemy(void) {
	for (int i = 0; i < 42; i++)
	{
		if (this->_enemies[i].getAlive() && this->_enemies[i].getCoordY() == this->_gameY - 1) {
			this->_enemies[i].setAlive(false);
		}
	}
	for (int i = 0; i < 42; i++)
		if (!(this->_enemies[i].getAlive())) {
			this->_enemies[i].newEnemy(this->_gameX, this->_gameY);
			return ;
		}
}

void	Game::addAster(void) {
	for (int i = 0; i < 150; i++)
	{
		if (this->_aster[i].getAlive() && this->_aster[i].getCoordY() == this->_gameY - 1) {
			this->_aster[i].setAlive(false);
		}
	}
	if (this->counter == 3) {
		for (int i = 0; i < 150; i++)
			if (!(this->_aster[i].getAlive())) {
				this->_aster[i].newAster(this->_gameX, this->_gameY);
				return ;
			}
	}
}

void	Game::checkCollision(void) {
	for (int i = 0; i < this->_gameY; i++) {
		if (this->_ship->getBullets()[i].getAlive()) {
			for (int j = 0; j < 42; j++) {
				if (this->_enemies[j].getAlive() && _enemies[j].getCoordY() == _ship->getBullets()[i].getCoordY() && \
					_enemies[j].getCoordX() == _ship->getBullets()[i].getCoordX()) {
					this->_enemies[j].setAlive(false);
					_ship->getBullets()[i].setAlive(false);
					this->score += 10;
				}
			}
		}
	}
	for (int i = 0; i < 42; i++) {
		if (this->_enemies[i].getAlive() && _enemies[i].getCoordY() == _ship->getCoordY() && \
			_enemies[i].getCoordX() == _ship->getCoordX()) {
			this->lives -= 1;
			this->_enemies[i].setAlive(false);
			this->score += 10;
		}
	}
}

void	Game::moveAll(void) {

	for (int i = 0; i < this->_gameY; i++)
		if (this->_ship->getBullets()[i].getAlive() && !(_ship->getBullets()[i].getCoordY())) {
			_ship->getBullets()[i].setAlive(false);
		}
	for (int i = 0; i < this->_gameY; i++) {
		if (this->_ship->getBullets()[i].getAlive())
			this->_ship->getBullets()[i].moveUp();
	}
	checkCollision();
	for (int i = 0; i < 42; i++) {
		if (this->_enemies[i].getAlive())
			this->_enemies[i].moveDown();;
	}
	checkCollision();

	if (this->counter == 3) {
		for (int i = 0; i < 150; i++) {
			if (this->_aster[i].getAlive())
				this->_aster[i].moveDown();;
		}
	}	
}

void	Game::printAll(void) {
	wclear(this->_game);
	wbkgd(this->_panel, COLOR_PAIR(2));
	wattron(this->_game, COLOR_PAIR(1));
	for (int i = 0; i < this->_gameY; i++) {
		if (this->_ship->getBullets()[i].getAlive())
			mvwprintw(_game, _ship->getBullets()[i].getCoordY(), _ship->getBullets()[i].getCoordX(), "%c", _ship->getBullets()[i].getSkin());
	}
	wattroff(this->_game, COLOR_PAIR(1));
	wattron(this->_game, COLOR_PAIR(4));
	for (int i = 0; i < 42; i++) {
		if (this->_enemies[i].getAlive())
			mvwprintw(_game, _enemies[i].getCoordY(), _enemies[i].getCoordX(), "%c", _enemies[i].getSkin());
	}
	wattroff(this->_game, COLOR_PAIR(4));

	wattron(this->_game, COLOR_PAIR(3));
	for (int i = 0; i < 150; i++) {
		if (this->_aster[i].getAlive())
			mvwprintw(_game, _aster[i].getCoordY(), _aster[i].getCoordX(), "%c", _aster[i].getSkin());
	}
	wattroff(this->_game, COLOR_PAIR(3));

	wattron(this->_game, COLOR_PAIR(1));
	mvwprintw(_game, _ship->getCoordY(), _ship->getCoordX() - 1, "<");
	mvwprintw(_game, _ship->getCoordY(), _ship->getCoordX(), "%c", _ship->getSkin());
	mvwprintw(_game, _ship->getCoordY(), _ship->getCoordX() + 1, ">");
	wattroff(this->_game, COLOR_PAIR(1));

	mvwprintw(this->_panel, this->_panelY / 2, this->_panelX / 7, "SCORE: %i", score);
	if (this->lives == 3)
		mvwprintw(this->_panel, this->_panelY / 2, this->_panelX - this->_panelX / 5, "LIVES: <3 <3 <3");
	else if (this->lives == 2)
		mvwprintw(this->_panel, this->_panelY / 2, this->_panelX - this->_panelX / 5, "LIVES: <3 <3   ");
	else if (this->lives == 1)
		mvwprintw(this->_panel, this->_panelY / 2, this->_panelX - this->_panelX / 5, "LIVES: <3      ");
	else
		mvwprintw(this->_panel, this->_panelY / 2, this->_panelX - this->_panelX / 5, "LIVES: NOT FOUND");
	wrefresh(this->_panel);
}

void	Game::play(void) {
	clock_t	t1 = 0;
	clock_t	t2 = 0;
	int		flag = 0;
	bool	exit = false;
	int		c;

	while (!exit && this->score < 420 && this->lives > 0) {
		t1 = clock() / (CLOCKS_PER_SEC / 20);
		if (t1 > t2)
		{
			this->counter += 1;
			t2 = clock() / (CLOCKS_PER_SEC / 20);
			c = wgetch(this->_game);
			switch(c) {
				case KEY_UP: {
					this->_ship->moveUp();
					break;
				}
				case KEY_DOWN: {
					this->_ship->moveDown();
					break;
				}
				case KEY_LEFT: {
					this->_ship->moveLeft();
					this->_ship->moveLeft();
					break;
				}
				case KEY_RIGHT: {
					this->_ship->moveRight();
					this->_ship->moveRight();
					break;
				}
				case 'q': {
					if (!flag)
						flag = 1;
					else
						flag = 0;
					break;
				}
				case ' ': {
					if (!flag)
						this->_ship->fire(this->_ship->getCoordY(), this->_ship->getCoordX());
					break;
				}
				case 27: {
					exit = true;
					break;
				}
			}
			if (flag)
				this->_ship->fire(this->_ship->getCoordY(), this->_ship->getCoordX());
			addEnemy();
			addAster();
			moveAll();
			printAll();
			flushinp();
			if (this->counter > 2)
				this->counter = 0;

		}
	}
	if (this->lives < 1) {
		nodelay(this->_game, false);
		wclear(this->_game);
		mvwprintw(this->_game, this->_gameY / 2, this->_gameX / 2 - 10, "YOU LOSE :(");
		while (wgetch(this->_game) != 27)
			;
	}
	if (this->score >= 420) {
		nodelay(this->_game, false);
		wclear(this->_game);
		mvwprintw(this->_game, this->_gameY / 2, this->_gameX / 2 - 10, "YOU WIN :)");
		while (wgetch(this->_game) != 27)
			;
	}
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:19:33 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/24 04:29:56 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <string>
# include <cstdio>
# include <stdlib.h>
# include <time.h>
# include <iostream>

class Entity { 
public:
    Entity();
    Entity(Entity const & copy);
    ~Entity();
    int             getCoordX() const;
    int             getCoordY() const;
    bool            getAlive() const;
    int             getMaxY() const;
    int             getMaxX() const;
    char            getSkin() const;
    void            setCoordX(int x);
    void            setCoordY(int y);
    void            setAlive(bool alive);
    void            setMaxY(int yMax);
    void            setMaxX(int xMax);
    void            setSkin(char skin);
    void            moveUp();
    void            moveDown();
    void            moveLeft();
    void            moveRight();
    Entity &        operator=(Entity const & obj);
    virtual void    setStart(int maxX, int maxY, int enem);
    void			setBullets(Entity * bullet, Entity * player);
protected:
    int     _x;
    int     _y;
    bool    _alive;
    int     _xMax;
    int     _yMax;
    char    _skin;
};
#endif

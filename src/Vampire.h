#pragma once

#include "Rectangle.h"

class Game;

class Vampire : public Rectangle
{
public:
    Vampire(Game* game, sf::Vector2f position);
    virtual ~Vampire() {}

    void update(float deltaTime);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setIsKilled(bool isKilled) { m_isKilled = isKilled; }
    bool isKilled() { return m_isKilled; }

private:
	float	m_health;
    Game*	m_pGame;
    bool	m_isKilled = false;
	int		v_counter;
};

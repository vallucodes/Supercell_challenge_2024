#include "Weapon.h"
#include <iostream>

Weapon::Weapon() : Rectangle(sf::Vector2f(0, 0))
{
    // setPosition(sf::Vector2f(ScreenWidth * 0.5f, ScreenHeight * 0.5f));
    setPosition(sf::Vector2f(0.0f, 0.0f));
    setOrigin(sf::Vector2f(0.0f, 0.0f));
    setColor(sf::Color::Red);
}

void Weapon::setActive(bool isActive)
{
    m_isActive = isActive;
    if (isActive)
    {
        setSize(sf::Vector2f(WeaponWidth, m_weaponHeight));
        m_timer = WeaponActiveTime;
    }
    else
    {
        setSize(sf::Vector2f(0.0f, 0.0f));
        m_timer = 0.0f;
    }
}

void Weapon::update(float deltaTime)
{
    if (m_isActive)
    {
        m_timer -= deltaTime;
        if (m_timer <= 0.0f)
        {
            setActive(false);
        }
    }
}

void Weapon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape graphicsRect(getSize());
    graphicsRect.setFillColor(getColor());
    graphicsRect.setPosition(getPosition());
	graphicsRect.setRotation(getRotation());
    target.draw(graphicsRect);
}

float Weapon::getTimer() {
	return m_timer;
}

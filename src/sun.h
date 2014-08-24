#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "planet.h"

struct Sun: public Asteroid
{
    bool isRedGiant;
    bool isBlackHole;

    Sun() {}
    Sun(float mass,
        const sf::Vector2f& initialPos);

    virtual void update(float dt);
    virtual void setMass(float newMass);

    void turnIntoRedGiant();
    void turnIntoBlackHole();

private:
    sf::CircleShape circle;
    float redGiantExpandFactor;
};


#pragma once

#include <vector>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "planet.h"
#include "sun.h"
#include "explosion.h"
#include "screen.h"
#include "popup_messages.h"

class GameScreen:
    public Screen
{
public:
    GameScreen(Game& game);
    
    virtual void handleInput();
    virtual void update(float dt);
    virtual void draw() const;

    ssize_t getPoints() const { return points; }

private:
    float screenShakeFactor;
    sf::Vector2f shakeOffset;

    Sun sun;
    sf::Vector2f planetMoveDir[2];
    PlanetSystem planets;
    std::vector<Asteroid> asteroids;
    std::vector<Explosion> explosions;

    ssize_t points;

    PopupMessages messages;
    float gameOverDelay;

    void onKeyPressed(const sf::Event& evt);
    void onKeyReleased(const sf::Event& evt);
    void onMouseMoved(const sf::Event& evt);

    void updateForces(const std::vector<Asteroid*> allObjects,
                      float dt);
    void shakeScreen(float factor);
    void gameOver();

    void handleCollision(Asteroid* first,
                         Asteroid* second,
                         const sf::Vector2f& collisionPos);
    void checkCollisions(const std::vector<Asteroid*> allObjects);
    void checkRopeCollisions();

    void spawnAsteroids(float dt);
    void removeOutOfBounds();

    void doUpdateStep(float dt);
    void updateShake(float dt);

    void addPoints(ssize_t delta,
                   const sf::Vector2f& source);
};


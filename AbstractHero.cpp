/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Serves as a base class for all types of heroes in the game.
 * December 1, 2024
 * */

#include "AbstractHero.h"

AbstractHero::AbstractHero(int health, int stamina, int strength, int agility)
        : m_health(health), m_stamina(stamina), m_strength(strength), m_agility(agility) {}

AbstractHero::~AbstractHero(){}

// Setters and Getters:
void AbstractHero::setHealth(int newHealth) {m_health = (newHealth < 0) ? 0 : newHealth;}
void AbstractHero::setStamina(int stamina) {m_stamina = (stamina < 0) ? 0 : stamina;}

int AbstractHero::getHealth() const { return m_health; }
int AbstractHero::getStamina() const { return m_stamina; }


// Adder & Remover:
void AbstractHero::addHealth(int health) { if (health > 0) { m_health += health;} }
void AbstractHero::removeHealth(int health) { m_health -= health; if (m_health < 0) m_health = 0; }




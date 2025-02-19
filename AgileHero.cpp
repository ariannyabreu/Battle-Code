/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Derived class with unique implementation of attack(), defend() and rest() methods.
 * December 1, 2024
 * */

#include "AgileHero.h"
#include <iostream>

AgileHero::AgileHero(int health, int stamina, int strength, int agility)
        : AbstractHero(health, stamina, strength, agility) {}

// AgileHero attacks = its strenght. Allows AgileHero to attack a target hero.
void AgileHero::attack(AbstractHero& target) {
    if (m_stamina >= 10) {
        int damage = m_strength;
        target.removeHealth(damage);
        m_stamina -= 5;
        std::cout << "Agile Hero attacks for " << damage << " damage." << std::endl;
    } else {
        std::cout << "Not enough stamina to attack." << std::endl;
    }
}

// Defends and regenerates health.
void AgileHero::defend() {
    std::cout << "Powerful defends, reducing damage, increasing health." << std::endl;
    m_health += 10;
}

// Recover stamina and health, and increases agility.
void AgileHero::rest() {
    std::cout << "Powerful Hero rests, increasing stamina."  << std::endl;
    addHealth(10);
    m_stamina += 15;
    m_agility += 2;
}

void AgileHero::printInfo() const {
    std::cout << "**** Agile Hero ****\nHealth: " << m_health
              << "\nStamina: " << m_stamina
              << "\nStrength: " << m_strength
              << "\nAgility: " << m_agility << std::endl;
}

bool AgileHero::compareHealth(const AbstractHero& other) const {
    return m_health > other.getHealth();
}
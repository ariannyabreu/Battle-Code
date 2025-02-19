/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Derived class with unique implementation of attack(), defend() and rest() methods.
 * December 1, 2024
 * */

#include <iostream>

#include "PowerfulHero.h"

// Calls the base class constructor to set attributes.
PowerfulHero::PowerfulHero(int health, int stamina, int strength, int agility)
    : AbstractHero(health, stamina, strength, agility){}

// Attacks a target hero by dealing double their strength in damage.
void PowerfulHero::attack(AbstractHero& target) {
    if (m_stamina >= 10) {
        int damage = m_strength * 2;
        target.removeHealth(damage);
        m_stamina -= 10;
        std::cout << "Powerful Hero attacks for " << damage << " damage." << std::endl;
    } else {
        std::cout << "Not enough stamina to attack." << std::endl;
    }
}

// Defends by regenerating a small amount of health.
void PowerfulHero::defend() {
    std::cout << "Powerful defends, reducing damage, increasing health." << std::endl;
    m_health += 5;
}

// Regain stamins and health.
void PowerfulHero::rest() {
    std::cout << "Powerful Hero rests, increasing stamina."  << std::endl;
    addHealth(15);
    m_stamina += 15;
}

// Current status of the hero.
void PowerfulHero::printInfo() const {
    std::cout << "*** Powerful Hero ***\nHealth: " << m_health
              << "\nStamina: " << m_stamina
              << "\nStrength: " << m_strength
              << "\nAgility: " << m_agility << std::endl;
}

// Return true if powerful hero's health is greater than the other hero's health.
bool PowerfulHero::compareHealth(const AbstractHero& other) const {
    return m_health > other.getHealth();
}
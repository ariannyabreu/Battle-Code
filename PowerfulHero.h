/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Derived class with unique implementation of attack(), defend() and rest() methods.
 * December 1, 2024
 * */

#ifndef PROJECT2_POWERFULHERO_H
#define PROJECT2_POWERFULHERO_H

#include "AbstractHero.h"

class PowerfulHero: public AbstractHero {
public:
    PowerfulHero(int health, int stamina, int strength, int agility);

    void attack(AbstractHero& target) override;
    void defend() override;
    void rest() override;
    void printInfo() const override;
    bool compareHealth(const AbstractHero& other) const override;

};


#endif //PROJECT2_POWERFULHERO_H

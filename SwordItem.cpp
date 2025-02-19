/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Concrete implementation of the AbstractItem class. Represents a sword that modifies a hero's
 * stats by increasing attack power while slightly reducing stamina.
 * December 1, 2024
 * */

#include "SwordItem.h"

// Initializes the swords name and description using the base class constructor.
SwordItem::SwordItem(const std::string& name, const std::string& description)
        : AbstractItem(name, description) {}

// Methods to return the stat modifier specific to the SwordItem:
int SwordItem::getAttackModifier() const {return 10;}

int SwordItem::getDefenseModifier() const {return 0;}

int SwordItem::getHealthModifier() const {return 0;}

int SwordItem::getStaminaModifier() const {return -5;}

// Implements the clone method to create a deep copy of the SwordItem. Use the copy constructor to create a new instance.
std::unique_ptr<AbstractItem> SwordItem::clone() const {
    return std::make_unique<SwordItem>(*this);
}

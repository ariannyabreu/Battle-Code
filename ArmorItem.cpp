/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Concrete implementation of the AbstractItem class. Represents an Armor that modifies a hero's
 * stats.
 * December 1, 2024
 * */

#include "ArmorItem.h"

// Initializes the Armor name and description using the base class constructor.
ArmorItem::ArmorItem(const std::string& name, const std::string& description)
        : AbstractItem(name, description) {}

// Methods to return the stat modifier specific to the item:
int ArmorItem::getAttackModifier() const {return 0;}

int ArmorItem::getDefenseModifier() const {return 15;}

int ArmorItem::getHealthModifier() const {return 10;}

int ArmorItem::getStaminaModifier() const {return -3;}

// Implements the clone method to create a deep copy of the item. Use the copy constructor to create a new instance.
std::unique_ptr<AbstractItem> ArmorItem::clone() const {
    return std::make_unique<ArmorItem>(*this);
}
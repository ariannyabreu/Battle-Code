/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Concrete implementation of the AbstractItem class. Represents a Shield that modifies a hero's
 * stats.
 * December 1, 2024
 * */
#include "ShieldItem.h"

// Initializes the item name and description using the base class constructor.
ShieldItem::ShieldItem(const std::string& name, const std::string& description)
        : AbstractItem(name, description) {}

// Methods to return the stat modifier specific to the item:
int ShieldItem::getAttackModifier() const {return 0;}

int ShieldItem::getDefenseModifier() const {return 20;}

int ShieldItem::getHealthModifier() const {return 5;}

int ShieldItem::getStaminaModifier() const {return -2;}

// Implements the clone method to create a deep copy of the item. Use the copy constructor to create a new instance.
std::unique_ptr<AbstractItem> ShieldItem::clone() const {
    return std::make_unique<ShieldItem>(*this);
}
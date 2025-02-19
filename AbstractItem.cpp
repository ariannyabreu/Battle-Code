/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Abstract base class representing items that can be equipped by a hero. Each item has a name,
 * description, and stat modifiers (attack, defense, health, stamina). The class supports deep copying through the
 * clone() method and requires derived classes to implement the stat modifier logic via pure virtual methods.
 * December 1, 2024
 * */

#include "AbstractItem.h"

AbstractItem::AbstractItem(const std::string& name, const std::string& description)
        : m_name(name), m_description(description) {}

AbstractItem::~AbstractItem() {}

// getters:
std::string AbstractItem::getName() const { return m_name;}
std::string AbstractItem::getDescription() const { return m_description;}


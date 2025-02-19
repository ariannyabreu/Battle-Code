/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: A derived class of AbstractHero that includes the ability to equip items which modify the
 * hero's attributes. It supports deep copying and move semantics for proper resource management and implements custom
 * logic for actions like attacking, defending, and resting, influenced by the equipped items.
 * December 1, 2024
 * */

#include "EquippedHero.h"
#include <iostream>

// Initializes attributes by calling base class constructot.
EquippedHero::EquippedHero(int health, int stamina, int strength, int agility)
        : AbstractHero(health, stamina, strength, agility) {}

// Copy constructor to create a deep copy of another EquippedHero.
EquippedHero::EquippedHero(const EquippedHero& other)
        // Call the base class default copy constructor that is implicitly created by compiler  to copy attributes.
        : AbstractHero(other) {
    // Deep copy the items. Each item in the source EquippedHero is cloned into the new one. This prevents shared ownership of items.
    for (const auto& item : other.m_items) {
        m_items.push_back(item->clone());
    }
}

// Copy assignment operator to handle assignment of one EquippedHero to another.
EquippedHero& EquippedHero::operator=(const EquippedHero& other) {
    // prevent self-assignment.
    if (this != &other) {
        // Copy base class attributes.
        AbstractHero::operator=(other);
        // Clear any existing items in destination.
        m_items.clear();
        // Deep copy the items.
        for (const auto& item : other.m_items) {
            m_items.push_back(item->clone());
        }
    }
    return *this;
}

// Move constructor to transfer ownership of data from another EquippedHero.
EquippedHero::EquippedHero(EquippedHero&& other) noexcept
        // Move base class attributes.
        : AbstractHero(std::move(other)),
          // Transfer ownership of items from source to a new one. Leave the source object in a valid but empty state.
          m_items(std::move(other.m_items)) {}

// Move Assignment Operator. Similar to Move constructor but for assignement =.
// Transfer ownership of resources and ensures the destination object is updated while the source left in valid state.
EquippedHero& EquippedHero::operator=(EquippedHero&& other) noexcept {
    if (this != &other) {
        AbstractHero::operator=(std::move(other));
        m_items = std::move(other.m_items);
    }
    return *this;
}

// Add an item to Hero inventory. Transfers ownership of the item since items are stored as unique_ptr.
void EquippedHero::addItem(std::unique_ptr<AbstractItem> item) {
    // Move item into the vector.
    m_items.push_back(std::move(item));
}

// Getter for equipped items. Returns a read-only reference to the vector of equipped items.
const std::vector<std::unique_ptr<AbstractItem>>& EquippedHero::getItems() const {
    return m_items;
}

// Calculates total attack damage by combining base strength and attack modifiers from items.
void EquippedHero::attack(AbstractHero& target) {
    int totalAttackModifier = 0;
    for (const auto& item : m_items) {
        totalAttackModifier += item->getAttackModifier();
    }

    int damage = m_strength + totalAttackModifier;
    if (m_stamina > 10) {
        target.removeHealth(damage);
        m_stamina -= 10;
        std::cout << "EquippedHero attacks for " << damage << " damage." << std::endl;
    } else {
        std::cout << "Not enough stamina to attack!" << std::endl;
    }
}

// Boosts health based on defense modifiers from item.
void EquippedHero::defend() {
    int totalDefenseModifier = 0;
    for (const auto& item : m_items) {
        // Sum defense modifiers.
        totalDefenseModifier += item->getDefenseModifier();
    }

    // SUm health recovery.
    int recovery = (5 + totalDefenseModifier);
    m_health += recovery;
    if (m_health > 100) {
        m_health = 100;
    }
    std::cout << "EquippedHero defends and gains " << recovery << " health." << std::endl;
}

// Recovers stamina based on item modifier.
void EquippedHero::rest() {
    int totalStaminaModifier = 0;
    for (const auto& item : m_items) {
        totalStaminaModifier += item->getStaminaModifier();
    }

    int recovery = 20 + totalStaminaModifier;
    // Avoid negative recovery.
    m_stamina += (recovery > 0 ? recovery : 0);
    // stamina cap.
    if (m_stamina > 50) {
        m_stamina = 50;
    }
    std::cout << "EquippedHero rests and regains " << recovery << " stamina." << std::endl;
}

// Print hero info
void EquippedHero::printInfo() const {
    std::cout << "*** Equipped Hero ***\nHealth: " << m_health
              << "\nStamina: " << m_stamina
              << "\nStrength: " << m_strength
              << "\nAgility: " << m_agility
              << "\nEquipped Items: " << std::endl;
    for (const auto& item : m_items) {
        std::cout << "- " << item->getName() << ": " << item->getDescription() << std::endl;
    }
}

// Compares the health of this hero with another hero.
bool EquippedHero::compareHealth(const AbstractHero& other) const {
    return m_health > other.getHealth();
}



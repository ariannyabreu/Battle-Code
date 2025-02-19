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

#ifndef PROJECT2_ABSTRACTITEM_H
#define PROJECT2_ABSTRACTITEM_H
#include <string>
#include <memory>

class AbstractItem {
public:
    // Initialize item name and description.
    AbstractItem(const std::string& name, const std::string& description);

    // Destroys derived objects.
    virtual ~AbstractItem();

    // Pure virtual method for deep copying derived item objects.
    virtual std::unique_ptr<AbstractItem> clone() const = 0;

    // getters:
    std::string getName() const;
    std::string getDescription() const;

    // Pure virtual methods for stats modifiers:
    virtual int getAttackModifier() const = 0;
    virtual int getDefenseModifier() const = 0;
    virtual int getHealthModifier() const = 0;
    virtual int getStaminaModifier() const = 0;

protected:
    std::string m_name;
    std::string  m_description;
};


#endif //PROJECT2_ABSTRACTITEM_H

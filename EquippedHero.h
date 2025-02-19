/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: A specialized type of AbstractHero that includes the ability to equip items which modify the
 * hero's attributes. . It supports deep copying and move semantics for proper resource management and implements custom
 * logic for actions like attacking, defending, and resting, influenced by the equipped items.
 * December 1, 2024
 * */

#ifndef PROJECT2_EQUIPPEDHERO_H
#define PROJECT2_EQUIPPEDHERO_H

#include <vector>
#include <memory>
#include "AbstractHero.h"
#include "AbstractItem.h"

class EquippedHero : public AbstractHero {
public:
    EquippedHero(int health, int stamina, int strength, int agility);


    EquippedHero(const EquippedHero& other);
    EquippedHero& operator=(const EquippedHero& other);
    EquippedHero(EquippedHero&& other) noexcept;
    EquippedHero& operator=(EquippedHero&& other) noexcept;

    void addItem(std::unique_ptr<AbstractItem> item);
    const std::vector<std::unique_ptr<AbstractItem>>& getItems() const;

    void attack(AbstractHero& target) override;
    void defend() override;
    void rest() override;
    void printInfo() const override;
    bool compareHealth(const AbstractHero& other) const override;

private:
    std::vector<std::unique_ptr<AbstractItem>> m_items;
};

#endif // PROJECT2_EQUIPPEDHERO_H



/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Concrete implementation of the AbstractItem class. Represents a Shield that modifies a hero's
 * stats.
 * December 1, 2024
 * */

#ifndef PROJECT2_SHIELDITEM_H
#define PROJECT2_SHIELDITEM_H
#include "AbstractItem.h"

class ShieldItem : public AbstractItem {
public:
    ShieldItem(const std::string& name, const std::string& description);

    // Override modifier methods
    int getAttackModifier() const override;
    int getDefenseModifier() const override;
    int getHealthModifier() const override;
    int getStaminaModifier() const override;

    std::unique_ptr<AbstractItem> clone() const override;

};


#endif //PROJECT2_SHIELDITEM_H

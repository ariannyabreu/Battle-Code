/*
 * Arianny Abreu-Gonzalez ID 00335875
 * C++ Programming CIS 240
 * Professor Michael Penta
 * Project 2 - Battle Code
 * Program Description: Concrete implementation of the AbstractItem class. Represents an Armor that modifies a hero's
 * stats.
 * December 1, 2024
 * */

#ifndef PROJECT2_ARMORITEM_H
#define PROJECT2_ARMORITEM_H

#include "AbstractItem.h"

class ArmorItem : public AbstractItem {
public:
    ArmorItem(const std::string& name, const std::string& description);

    int getAttackModifier() const override;
    int getDefenseModifier() const override;
    int getHealthModifier() const override;
    int getStaminaModifier() const override;
    std::unique_ptr<AbstractItem> clone() const override;

};


#endif //PROJECT2_ARMORITEM_H

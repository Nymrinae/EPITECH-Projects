/*
** EPITECH PROJECT, 2018
** LittleHand.cpp
** File description:
** Exersice 1 - Can I have some more?
*/

#include "LittleHand.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted, 
                              FruitBox &lemons,
                              FruitBox &bananas,
                              FruitBox &limes)
{
    FruitBox box(unsorted.nbFruits());
    Fruit *fruit;

    while ((fruit = unsorted.pickFruit())) {
        if (fruit->getName() == "lemon") {
            if (!lemons.putFruit(fruit))
                box.putFruit(fruit);
        } else if (fruit->getName() == "banana") {
            if (!bananas.putFruit(fruit))
                box.putFruit(fruit);
        } else if (fruit->getName() == "lime") {
            if (!limes.putFruit(fruit))
                box.putFruit(fruit);
        } else 
            box.putFruit(fruit);
    }

    while ((fruit = box.pickFruit()))
        unsorted.putFruit(fruit);
}
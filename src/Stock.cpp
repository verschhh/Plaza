/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Stock.cpp
*/

#include "../include/Stock.hpp"

Stock::Stock(void) {
    for (int i = 0; i != 9; i++) {
        ingredients.push_back(5);
    }
}

Stock::~Stock(void) {

}

void Stock::displayStock(void) {
    for (int i = 0; i != 9; i++) {
        std::cout << "There is " << ingredients.at(i) << " " << IngredintName[i].second << "\n";
    }
    return;
}

void Stock::refillStock(void) {
    for (int i = 0; i != 9; i++) {
        ingredients.at(i) += 1;
    }
}

int Stock::checkIngredients(int *listIngredient) {
    for (int i = 0; listIngredient[i] != End; i++)
        if (ingredients.at(listIngredient[i]) == 0)
            return -1;
    return 0;
}

int Stock::checkPizza(int pizza) {
    if (pizza == Margarita) {
        int listIngredient[] = {Dough, Tomato, Gruyere, End};
        return checkIngredients(listIngredient);
    }
    if (pizza == Regina) {
        int listIngredient[] = {Dough, Tomato, Gruyere, Ham, Mushrooms, End};
        return checkIngredients(listIngredient);
    }
    if (pizza == Americana) {
        int listIngredient[] = {Dough, Tomato, Gruyere, Steak, End};
        return checkIngredients(listIngredient);
    }
    if (pizza == Fantasia) {
        int listIngredient[] = {Dough, Tomato, Eggplant, GoatCheese, ChiefLove, End};
        return checkIngredients(listIngredient);
    }
    return -1;
}

void Stock::consumeIngredient(int pizza) {
    --ingredients.at(Dough);
    --ingredients.at(Tomato);

    if (pizza == Margarita)
        --ingredients.at(Gruyere);
    if (pizza == Regina) {
        --ingredients.at(Ham);
        --ingredients.at(Mushrooms);
    }
    if (pizza == Americana)
        --ingredients.at(Steak);
    if (pizza == Fantasia) {
        --ingredients.at(Eggplant);
        --ingredients.at(GoatCheese);
        --ingredients.at(ChiefLove);
    }
}

int Stock::cookPizza(int pizza) {
    if (checkPizza(pizza) == -1)
        return 84;
    consumeIngredient(pizza);
    return 0;
}
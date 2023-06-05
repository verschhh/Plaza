/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Stock.hpp
*/

#pragma once

#include "Plazza.hpp"


enum {
    End = 84
};

class Stock {
    public:
        Stock();
        ~Stock();

    std::vector<int> ingredients;

    void displayStock(void);
    void refillStock(void);
    int checkPizza(int pizza);
    int checkIngredients(int *ingredient);
    int cookPizza(int pizza);
    void consumeIngredient(int pizza);
};

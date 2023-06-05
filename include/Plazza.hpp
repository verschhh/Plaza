/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** plazza.hpp
*/

#pragma once

#include <utility>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

enum {
    Regina,
    Margarita,
    Americana,
    Fantasia
};

enum {
    Dough,
    Tomato,
    Gruyere,
    Ham,
    Mushrooms,
    Steak,
    Eggplant,
    GoatCheese,
    ChiefLove
};

enum {
    S,
    M,
    L,
    XL,
    XXL
};

typedef struct order_s {
    int type;
    int size;
} order_t;

typedef struct kitchen_status_s {
    int id;
    int nbPizza;
    int nbIngredients;
    int ingredients;
} kitchen_status_t;

typedef struct data_s {
    bool running;
    order_t oders;
    kitchen_status_t kitchenStatus;
} data_t;

static std::pair<int, const char*> IngredintName[] =
{
    {0, "dough"},
    {1, "tomato"},
    {2, "gruyere"},
    {3, "ham"},
    {4, "mushrooms"},
    {5, "steak"},
    {6, "eggplant"},
    {7, "goat cheese"},
    {8, "chief love"}
};

static std::pair<int, const char*> PizzaName[] =
{
    {0, "Regine"},
    {1, "Margarita"},
    {2, "Americana"},
    {3, "Fantasia"}
};

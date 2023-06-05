/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Pizza.hpp
*/

#pragma once

class Pizza {
    public:
        Pizza(int, int);
        ~Pizza();

        int type;
        int size;
};

enum PizzaType
{
    Regina = 1 ,
    Margarita = 2 ,
    Americana = 4 ,
    Fantasia = 8
};
enum PizzaSize
{
    S = 1 ,
    M = 2 ,
    L = 4 ,
    XL = 8 ,
    XXL = 16
};
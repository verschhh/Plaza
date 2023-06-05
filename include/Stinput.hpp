/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Parser.hpp
*/

#pragma once

#include "Plazza.hpp"
#include <limits>
#include <algorithm>
#include <cctype>

template<typename Type>
    Type getInput() {
        Type input;
        std::cout << "> ";
        std::getline(std::cin, input);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Invalid input");
        }
        return input;
    }

class Stinput {
    public:
        Stinput();
        ~Stinput();

        std::vector<std::string> pizzaType;
        std::vector<std::string> pizzaSize;
        std::vector<int> pizzaNumber;

        void readStinput();
        int checkContent(const std::string&);
        bool checkNumber(std::string);
        bool checkSize(std::string);
        bool checkPizza(std::string);
};

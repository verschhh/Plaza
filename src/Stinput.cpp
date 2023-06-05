/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Parser.cpp
*/

#include "../include/Stinput.hpp"

Stinput::Stinput() {
}

Stinput::~Stinput() {
}

bool Stinput::checkPizza(std::string namePizza) {
    std::transform(namePizza.begin(), namePizza.end(), namePizza.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    if (namePizza == "regina" || namePizza == "margarita" ||
        namePizza == "americana" || namePizza == "fantasia") {
            pizzaType.push_back(namePizza);
            return true;
        }
    std::cout << "Invalid type of pizza" << std::endl;
    return false;
}

bool Stinput::checkSize(std::string sizePizza) {
    std::transform(sizePizza.begin(), sizePizza.end(), sizePizza.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    if (sizePizza == "s" || sizePizza == "m"
        || sizePizza == "l" || sizePizza == "xl"
            || sizePizza == "xxl") {
        pizzaSize.push_back(sizePizza);
        return true;
    }
    std::cout << "Invalid size of pizza" << std::endl;
    return false;
}

bool Stinput::checkNumber(std::string numberPizza) {
    if (numberPizza[0] != 'x')
        return false;
    std::string remainingPart = numberPizza.substr(1);

    try {
        int number = std::stoi(remainingPart);
        if (number > 0) {
            pizzaNumber.push_back(number);
            return true;
        }
    } catch (const std::exception&) {
        std::cout << "Format is : x + number of pizza you want" << std::endl;
        return false;
    }
    return false;
}

int Stinput::checkContent(const std::string& item) {
    int index = 0;
    typedef bool (Stinput::*CheckFunction)(std::string);
    CheckFunction functions[3] = {&Stinput::checkPizza, &Stinput::checkSize, &Stinput::checkNumber};

    std::istringstream iss(item);
    std::string sub_item;
    while (iss >> sub_item) {
        if (index > 2) {
            std::cout << "Too many arguments to create a pizza" << std::endl;
            return 84;
        }
         if (!(this->*functions[index])(sub_item)) {
            return 84;
        }
        index++;
    }
    if (index != 3) {
        std::cout << "Not Enough Arguments to create a pizza" << std::endl;
        return 84;
    }
    return 0;
}

void Stinput::readStinput() {
    try {
        std::string inputValue = getInput<std::string>();
        std::vector<std::string> items;
        std::istringstream iss(inputValue);
        std::string item;
        while (std::getline(iss, item, ';')) {
            item.erase(0, item.find_first_not_of(' '));
            items.push_back(item);
        }
        for (const std::string& item : items) {
            checkContent(item);
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
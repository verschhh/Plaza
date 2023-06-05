/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** main.cpp
*/

#include "include/Reception.hpp"

int check_args(int ac, char **av) {
    float argOne = 0;
    if (ac != 4) {
        std::cout << "USAGE: ./plazza [multiplier] [cooks] [time]" << std::endl;
        return 84;
    }
    if (std::stof(av[1]) <= 0 || atoi(av[2]) <= 0 || atoi(av[3]) <= 0) {
        std::cout << "USAGE: ./plazza [multiplier (float) ] [cooks(int)] [time(int)]" << std::endl;
        return 84;
    }
    return 0;
}

int help(char **av, int ac) {
    if (ac != 2)
        return 0;
    if (std::string(av[1]) == "-h") {
        std::cout << "USAGE: ./plazza [multiplier] [cooks] [time]" << std::endl;
        std::cout << "\t- multiplier: time in milliseconds, used by the kitchen to cook pizzas" << std::endl;
        std::cout << "\t- cooks: number of cooks per kitchen" << std::endl;
        std::cout << "\t- time: time in seconds, used by the kitchen stock to replace ingredients" << std::endl;
        return 0;
    }
    return 0;
}

int main(int ac, char **av) {
    Reception *reception = NULL;
    help(av, ac);
    if (check_args(ac, av) == 84)
        return 84;
    reception = new Reception(std::stof(av[1]), atoi(av[2]), atoi(av[3]));
    std::cout << "edeed";
    reception->run();
    return 0;
}

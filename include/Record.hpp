/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Record.hpp
*/

#pragma once
#include <fstream>
#include "Plazza.hpp"

class Record {
    public:
        Record();
        ~Record();

        std::ofstream fd;

        void writeFile(const char*);
};

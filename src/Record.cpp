/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Record.cpp
*/

#include "../include/Record.hpp"

Record::Record() {
    fd.open("log.txt", std::ios::trunc);
    if (!fd.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
}

Record::~Record() {
    fd.close();
}

void Record::writeFile(const char* str) {
    if (fd.is_open()) {
       fd << str << "\n";
       if (fd.fail()) {
           throw std::runtime_error("Failed to write to file");
       }
       fd.flush();
    } else {
        throw std::runtime_error("File is not open");
    }
}
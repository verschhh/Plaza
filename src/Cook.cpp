/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook.cpp
*/

#include "../include/Cook.hpp"

Cook::Cook(void) {
    status = Free;
}

Cook::~Cook(void) {
}

void Cook::upadate_status(int new_status) {
    status = new_status;
}

int Cook::check_status(void) {
    return status;
}

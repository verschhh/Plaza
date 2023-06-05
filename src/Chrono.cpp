/*
** EPITECH PROJECT, 2022
** Plaza
** File description:
** Chrono.cpp
*/

#include "../include/Chrono.hpp"

Chrono::Chrono() {
    _start = 0;
    _end = 0;
    _elapsed = 0;
}

Chrono::~Chrono() {
}

void Chrono::startChrono(void) {
    time(&_start);
}

void Chrono::resetChrono(void) {
    time(&_start);
    time(&_end);
}

double Chrono::getElapsedTime(void) {
    time(&_end);
    _elapsed = difftime(_end, _start);
    return _elapsed;
}
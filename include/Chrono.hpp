/*
** EPITECH PROJECT, 2022
** Plaza
** File description:
** Chrono.hpp
*/

#pragma once

#include <ctime>

class Chrono {
    public:
        Chrono();
        ~Chrono();

        void startChrono(void);
        void resetChrono(void);
        double getElapsedTime(void);

    private:
        time_t _start;
        time_t _end;
        double _elapsed;
};
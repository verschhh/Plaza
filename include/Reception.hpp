/*
** EPITECH PROJECT, 2023
** Plaza
** File description:
** Reception
*/

#pragma once

#include <vector>
#include "Kitchen.hpp"
#include "../include/Pipe.hpp"

typedef struct childData_s {
    Stock stock;
    pid_t pid;
} childData_t;

class Reception {
    public:
        Reception(double multiplier, int nb_cook, int time);
        ~Reception();
        void run();
        void leave(int ret);
        int checkCtrlD();
        std::vector<childData_t> _childs;

        double _mult;
        int _nbCook;
        int _time;
        bool _run;
        Pipe *_ipc;
        int _nbKitchen;
        std::string _pipeName;
        
    private:
};

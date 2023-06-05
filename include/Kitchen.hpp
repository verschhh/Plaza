/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Kitchen.hpp
*/

#pragma once

#include "Stock.hpp"
#include "Cook.hpp"
#include "Chrono.hpp"
#include "Stinput.hpp"
#include "Record.hpp"
#include "Pipe.hpp"
#include <vector>
#include <future>
#include <thread>
#include <functional>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdio.h>
#include <mutex>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>


class Kitchen {
    public:
        Kitchen(int arg_cook, Pipe *ipc, double mult,int time);
        ~Kitchen();

        int status;
        int nbCook;
        Stock *stock;
        Record *record; // move it to the main class later
        Chrono *chrono;
        std::vector<Cook> cook;
        std::vector<std::string> orders;
        pthread_mutex_t mutex;
        Pipe *_ipc;
        double _mult;
        int _time;

        struct data {
            int idCook;
            int status;
            int pizza;
            int result;
            Pipe *ipc;
            double mult;
            int time;
            Chrono *chrono;
            pthread_mutex_t *mutex;
        };

        void updateStatus(int);
        int checkStatus(void);
        int cookPizza(int pizza);
        int createThread(void);
        data *createData(int idCook);
};

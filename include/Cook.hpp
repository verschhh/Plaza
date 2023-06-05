/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook.hpp
*/

#pragma once

enum {
    Free,
    Cooking,
    Full
};

class Cook {
    public:
        Cook();
        ~Cook();

        int status;

        void upadate_status(int new_status);
        int check_status(void);
        void *thread(void);
};

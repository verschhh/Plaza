/*
** EPITECH PROJECT, 2023
** Plaza
** File description:
** Pipe
*/

#pragma once

#include <string>

class Pipe {
    public:
        Pipe(std::string path): _path(std::string(path)) {createPipe();};
        ~Pipe() = default;

        void sendMsg(std::string msg);
        std::string getMsg();
        void createPipe();

        std::string _path;
};

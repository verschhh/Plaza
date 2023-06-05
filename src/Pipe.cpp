/*
** EPITECH PROJECT, 2023
** Plaza
** File description:
** Pipe
*/

#include "../include/Pipe.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void Pipe::createPipe()
{
    if (mkfifo(_path.c_str(), 0666) == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        exit(84);
    }
}

void Pipe::sendMsg(std::string msg)
{
    int fd = open(_path.c_str(), O_WRONLY);
    if (fd == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        exit(84);
    }
    write(fd, msg.c_str(), msg.size());
    close(fd);
}

std::string Pipe::getMsg()
{
    int fd = open(_path.c_str(), O_RDONLY);
    if (fd == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        exit(84);
    }
    char buffer[1024];
    int size = read(fd, buffer, 1024);
    if (size == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        exit(84);
    } else if (size == 0) {
        std::cerr << "Error: Pipe closed." << std::endl;
        exit(84);
    }
    close(fd);
    return std::string(buffer, size);
}
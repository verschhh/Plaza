/*
** EPITECH PROJECT, 2023
** Plaza
** File description:
** Reception
*/

#include "../include/Reception.hpp"
#include "../include/Plazza.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

Reception::Reception(double multiplier, int nb_cook, int time)
{
    _mult = multiplier;
    _nbCook = nb_cook;
    _time = time;
    _run = true;
    _nbKitchen = 0;
    _pipeName = "./test";
    std::cout << "rfdezfds";
    _ipc = new Pipe(_pipeName);

}

Reception::~Reception()
{
}

void Reception::run()
{
    std::string input = "";
    while (1) {
        printf(">");
        if (input == "add") {
            _childs.push_back({Stock(), fork()});
            if (_childs.at(_childs.size() - 1).pid == 0) {
                Kitchen kitchen(_nbCook, _ipc, _mult, _time);
                _ipc->sendMsg("kill " + std::to_string(getpid()) + ";");
                break;
            } else if (_childs.at(_childs.size() - 1).pid == -1) {
                std::cout << "Fork failed." << std::endl;
                leave(1);
            }
        }
        std::cout << "testtt";
        std::string msg = _ipc->getMsg();
        std::string s;
        std::cout << "testttt";
        while (getline(std::istringstream(msg), s, ';')) {
            if (s.find("kill") != std::string::npos) {
                std::cout << "Kill received" << std::endl;
                for (int i = 0; i < _childs.size(); i++) {
                    std::cout << "Kitchen PID: pute" <<s<< std::endl;
                    if (_childs.at(i).pid == std::stoi(std::string(s).substr(5))) {
                        std::cout << "Kitchen  killed" << _childs.size()  << std::endl;
                        if (_childs.size() == 1) {
                            leave(0);
                        } else {
                            _childs.erase(_childs.begin() + i);
                        }
                        std::cout << "Kitchen PID: " << _childs.at(i).pid << " killed" << std::endl;
                        _nbKitchen--;
                    }
                    std::cout << "sort";
                }
            } else if (s.find("KITCHEN_READY") != std::string::npos) {
                std::cout << "KITCHEN_READY" << std::endl;
                _ipc->sendMsg(std::to_string(Margarita) + " " + std::to_string(L) + "x3");
                _nbKitchen++;
            }
        }
        std::cin >> input;
        checkCtrlD();
    }
}

int Reception::checkCtrlD()
{
    if (std::cin.eof()) {
        leave(0);
    }
    return (0);
}

void Reception::leave(int ret)
{
    for (int i = 0; i < _childs.size(); i++) {
        kill(_childs.at(i).pid, SIGKILL);
    }
    unlink(_pipeName.c_str());
    remove(_pipeName.c_str());
    exit(ret);
}
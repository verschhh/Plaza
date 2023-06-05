/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** kitchen.cpp
*/

#include "../include/Kitchen.hpp"

Kitchen::Kitchen(int arg_cook, Pipe *ipc, double mult, int time) {
    status = Free;
    stock = new Stock();
    record = new Record();
    pthread_mutex_init(&mutex, NULL);
    nbCook = arg_cook;
    for (int i = 0; i != arg_cook; i++) {
        cook.push_back(Cook());
    }
    this->_ipc = ipc;
    this->_mult = mult;
    this->_time = time;
    
    createThread();
}

Kitchen::~Kitchen(void) {

}

void Kitchen::updateStatus(int new_status) {
    status = new_status;
}

int Kitchen::checkStatus(void) {
    int status = 0;
    int full = 0;

    for (int i = 0; i != nbCook; i++) {
        status = cook[i].check_status();
        if (status == Free || status == Cooking)
            continue;
        else
            full++;
    }
    if (full == nbCook) {
        updateStatus(Full);
        return Full;
    }
    updateStatus(Free);
    return Free;
}

int Kitchen::cookPizza(int pizza) {
    if (checkStatus() == Full)
        return 84;
    if (stock->cookPizza(pizza) == 84) {
        return 84;
    }
    record->writeFile(PizzaName[pizza].second);
    return 0;
}

int which_pizza(int pizza) {
    if (pizza == 0)
        return 1;
    if (pizza == 1)
        return 2;
    if (pizza == 2)
        return 2;
    if (pizza == 3)
        return 2;
    return 84;
}

void *cookCooking(void *arg) {
    Kitchen::data *data = (Kitchen::data *)arg;
    int sleep_time = data->mult * which_pizza(data->pizza);
    Kitchen *kitchen = new Kitchen(1, NULL, 0, 0);
    data->status = 1;
    pthread_mutex_lock(data->mutex);
    sleep(sleep_time);
    kitchen->cookPizza(data->pizza);
    pthread_mutex_unlock(data->mutex);
    data->result = 1;
    return NULL;
}

Kitchen::data *Kitchen::createData(int idCook) {
    data *data = new Kitchen::data;
    data->mutex = &mutex;
    data->idCook = idCook;
    data->status = 0;
    data->pizza = 0;
    data->result = 0;
    data->ipc = _ipc;
    data->mult = _mult;
    data->time = _time;
    data->chrono = new Chrono();
    return data;
}

int Kitchen::createThread(void) {
    Chrono *chrono = new Chrono();
    data *data_t[nbCook];
    pthread_t cooks[nbCook];
    int once = 0;
    int rep = 0;

    for (int i = 0; i != nbCook; i++) {
        data_t[i] = createData(i);
        pthread_create(&cooks[i], NULL, &cookCooking, data_t[i]);
    }
    while (1) {
        printf("test");
        for (int i = 0; i != nbCook; i++) {
            if (data_t[i]->status == 0)
                pthread_join(cooks[i], NULL);
            if (data_t[i]->result == 1)
                _ipc->sendMsg("pizza fini;");
        }
        for (int i = 0; i != nbCook; i++) {
            if (data_t[i]->status == 0)
                rep++;
            if (rep == nbCook)
                chrono->startChrono();
        }
        if (chrono->getElapsedTime() >= 5) {
            return -1;
        }
        rep = 0;
        usleep(10000);
    }
    return 0;
}

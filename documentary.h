//
// Created by dahil on 27.10.2021.
//

#ifndef TASK_DOCUMENTARY_H
#define TASK_DOCUMENTARY_H
//------------------------------------------------------------------------------
// documentary.h - содержит описание документального фильма и его интерфейса.
//------------------------------------------------------------------------------
#include <cstdio>
#include "movie.h"
#include "rnd.h"

// Игровой фильм.
class Documentary : public Movie {
private:
    // Продолжительность.
    int minutes;
    // Имя.
    char name[10];
    // Дата выхода.
    int releaseDate;
public:
    // Вывод параметров документального фильма в файл.
    bool Out(FILE *file) override;
    // Ввод параметров документального фильма из файла.
    int In(FILE *file) override;
    // Ввод случайных параметров документального фильма.
    bool InRnd() override;
    // Подсчет сравнительного параметра.
    double ComparisonParam() override;
};

#endif //TASK_DOCUMENTARY_H

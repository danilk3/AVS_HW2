//
// Created by dahil on 27.10.2021.
//

#ifndef TASK_FICTION_H
#define TASK_FICTION_H
//------------------------------------------------------------------------------
// fiction.h - содержит описание игрового фильма и его интерфейса.
//------------------------------------------------------------------------------
#include <cstdio>
#include "movie.h"
#include "rnd.h"

// Игровой фильм.
class Fiction : public Movie {
private:
    // Дата выхода.
    int releaseDate;
    // Имя.
    char name[10];
    // Режисер.
    char director[10];
public:
    // Вывод параметров игрового фильма в файл.
    bool Out(FILE *file) override;
    // Ввод параметров игрового фильма из файла.
    int In(FILE *file) override;
    // Ввод случайных параметров игрового фильма.
    bool InRnd() override;
    // Подсчет сравнительного параметра.
    double ComparisonParam() override;
};

#endif //TASK_FICTION_H

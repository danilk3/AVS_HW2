//
// Created by dahil on 27.10.2021.
//

#ifndef TASK_CARTOON_H
#define TASK_CARTOON_H

//------------------------------------------------------------------------------
// cartoon.h - содержит описание мультфильма и его интерфейса.
//------------------------------------------------------------------------------
#include <cstdio>
#include "movie.h"
#include "rnd.h"

// Мультфильм.
class Cartoon : public Movie {
private:
    // Путь создания.
    enum way {
        DRAWED = 0,
        PUPPET = 1,
        PLASTIC = 2,
    };
    // Название.
    char name[10];
    // Дата выхода.
    int releaseDate;
    // Путь создания.
    way wayToCreate;
public:
    // Вывод параметров мультфильма в файл.
    bool Out(FILE *file) override;
    // Ввод параметров мультфильма из файла.
    int In(FILE *file) override;
    // Ввод случайных параметров мультфильма.
    bool InRnd() override;
    // Подсчет сравнительного параметра.
    double ComparisonParam() override;
};

#endif //TASK_CARTOON_H

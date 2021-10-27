//
// Created by dahil on 27.10.2021.
//
//------------------------------------------------------------------------------
// documentary.cpp - содержит функции обработки документального фильма.
//------------------------------------------------------------------------------
#include "documentary.h"
#include <cstring>

//------------------------------------------------------------------------------
// Вывод параметров документального фильма в файл.
bool Documentary::Out(FILE *file) {
    fprintf(file, "It is Documentary:\n"
                  "-name: %s,\n"
                  "-releaseDate: %d,\n"
                  "-minutes: %d,\n"
                  "-function result: %lf\n\n", name, releaseDate, minutes, ComparisonParam());
    return true;
}

//------------------------------------------------------------------------------
// Ввод случайных параметров документального фильма.
bool Documentary::InRnd() {
    RandName(name, 10);
    releaseDate = RandNumber(2021);
    minutes = RandNumber(1000);
    return true;
}

//------------------------------------------------------------------------------
// Ввод параметров документального фильма из файла.
int Documentary::In(FILE *file) {
    char buffer1[10], buffer2[100], buffer3[100];
    if (fscanf(file, "%s%s%s", buffer1, buffer2, buffer3) == EOF) {
        return 2;
    }
    if ((((releaseDate = atoi(buffer2)) < 0) || ((releaseDate = atoi(buffer2)) > 2021))) {
        return 0;
    }
    if ((((minutes = atoi(buffer3)) < 0) || ((releaseDate = atoi(buffer3)) > 1000))) {
        return 0;
    }
    strcpy(name, buffer1);
    return 1;
}

//------------------------------------------------------------------------------
// Подсчет сравнительного параметра.
double Documentary::ComparisonParam() {
    return releaseDate / (sizeof(name) / sizeof(name[0]));
}

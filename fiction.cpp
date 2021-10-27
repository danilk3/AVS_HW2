//
// Created by dahil on 27.10.2021.
//
//------------------------------------------------------------------------------
// fiction.cpp - содержит функции обработки игрового фильма.
//------------------------------------------------------------------------------
#include "fiction.h"
#include <cstring>
//------------------------------------------------------------------------------
// Вывод параметров игрового фильма в файл.
bool Fiction::Out(FILE *file) {
    fprintf(file, "It is Fiction:\n"
                  "-name: %s,\n"
                  "-director: %s,\n"
                  "-releaseDate: %d,\n"
                  "-function result: %lf\n\n", name, director, releaseDate,ComparisonParam());
    return true;
}
//------------------------------------------------------------------------------
// Ввод случайных параметров игрового фильма.
bool Fiction::InRnd() {
    RandName(name, 10);
    RandName(director, 10);
    releaseDate = RandNumber(2021);
    return true;
}
//------------------------------------------------------------------------------
// Ввод параметров игрового фильма из файла.
int Fiction::In(FILE *file) {
    char buffer1[10], buffer2[100], buffer3[10];
    if (fscanf(file, "%s%s%s", buffer1, buffer2, buffer3) == EOF) {
        return 2;
    }
    if ((((releaseDate = atoi(buffer2)) < 0) || ((releaseDate = atoi(buffer2)) > 2021))){
        return 0;
    }
    strcpy (name, buffer1);
    strcpy (director, buffer3);
    return 1;
}
//------------------------------------------------------------------------------
// Подсчет сравнительного параметра.
double Fiction::ComparisonParam() {
    return releaseDate / (sizeof(name) / sizeof(name[0]));
}

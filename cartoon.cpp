//
// Created by dahil on 27.10.2021.
//
//------------------------------------------------------------------------------
// cartoon.cpp - содержит функции обработки мультфильма.
//------------------------------------------------------------------------------
#include "cartoon.h"
#include <cstring>

//------------------------------------------------------------------------------
// Вывод параметров мультфильма в файл.
bool Cartoon::Out(FILE *file) {
    fprintf(file, "It is Cartoon:\n"
                  "-name: %s,\n"
                  "-releaseDate: %d,\n"
                  "-wayToCreate: %d,\n"
                  "-function result: %lf\n\n", name, releaseDate, (int) wayToCreate, ComparisonParam());
    return true;
}

//------------------------------------------------------------------------------
// Ввод случайных мультфильма.
bool Cartoon::InRnd() {
    RandName(name, 10);
    releaseDate = RandNumber(2021);
    wayToCreate = (way)RandNumber(3);
    return true;
}

//------------------------------------------------------------------------------
// Ввод параметров мультфильма из файла.
int Cartoon::In(FILE *file) {
    char buffer1[10], buffer2[100], buffer3[100];
    int number = 0;
    if (fscanf(file, "%s%s%s", buffer1, buffer2, buffer3) == EOF) {
        return 2;
    }
    if ((((number = atoi(buffer3)) < 0) || ((number = atoi(buffer3)) > 2))) {
        return 0;
    }
    if ((((releaseDate = atoi(buffer2)) < 0) || ((releaseDate = atoi(buffer2)) > 2021))) {
        return 0;
    }
    strcpy(name, buffer1);
    wayToCreate = (way)number;
    return 1;
}

//------------------------------------------------------------------------------
// Подсчет сравнительного параметра.
double Cartoon::ComparisonParam() {
    return releaseDate / (sizeof(name) / sizeof(name[0]));
}

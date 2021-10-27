//
// Created by dahil on 27.10.2021.
//
//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------
#include "container.h"

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (отчистка памяти).
void Container::Clear() {
    for (int i = 0; i < length; ++i) {
        delete data[i];
    }
    delete data;
    length = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока.
void Container::In(FILE *file, const int *size) {
    int result, movie_type;
    while (length < *size) {
        result = 1;
        if (fscanf(file, "%d", &movie_type) == EOF) {
            return;
        }
        switch (movie_type) {
            case 1:
                data[length] = new Fiction();
                break;
            case 2:
                data[length] = new Cartoon();
                break;
            case 3:
                data[length] = new Documentary();
                break;
            default:
                result = 0;
        }
        result = (result) ? data[length]->In(file) : 0;

        if (result == 1) {
            length++;
        } else if (result == 2) {
            return;
        } else {
            delete data[length];
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера.
void Container::InRnd(int size) {
    printf("Start random filling: \n");
    while (length < size) {
        switch (rand() % 3) {
            case 0:
                data[length] = new Fiction();
                break;
            case 1:
                data[length] = new Cartoon();
                break;
            case 2:
                data[length] = new Documentary();
                break;
        }
        data[length++]->InRnd();
    }
    printf("End random filling.\n");
}

//------------------------------------------------------------------------------
// Инициализация контейнера.
void Container::Init(int *size) {
    printf("Start init: \n");
    data = new Movie *[*size];
    length = 0;
    printf("End init\n");
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный файл.
void Container::Out(FILE *fp) {
    fprintf(fp, "Container contains %d elements.\n", length);
    for (int i = 0; i < length; i++) {
        fprintf(fp, "%d: ", i);
        data[i]->Out(fp);
    }
}

//------------------------------------------------------------------------------
// Меняем местами элементы.
template<typename T>
void swap(T &a, T &b) {
    T temp(std::move(a));
    a = std::move(b);
    b = std::move(temp);
}

// Сортировка.
void Container::ShakerSort() {
    printf("Start shaker sorting: \n");
    int left, right, i;
    left = 0;
    right = n - 1;
    while (left <= right) {
        for (i = right; i >= left; i--) {
            if (data[i - 1] > data[i]) {
                swap(data[i - 1], data[i]);
            }
        }
        left++;
        for (i = left; i <= right; i++) {
            if (data[i - 1] > data[i]) {
                swap(data[i - 1], data[i]);
            }
        }
        right--;
        printf("End shaker sorting.\n");
    }
}
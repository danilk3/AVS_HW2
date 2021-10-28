//------------------------------------------------------------------------------
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------
#include "container.h"

#include <cstring>   // для функций strcmp
#include <ctime>     // для функций time()
#include <sys/stat.h> // Для функций stat

// Названия папок, в которые будут записываться результаты работы программ.
const char test[100] = "..//Tests/", res[100] = "..//Results/";

void errMessage1() {
    printf("Incorrect command line!\n  "
           "Waited:\n     "
           "command -f infile outfile01 outfile02\n");
    printf("  Or:\n     "
           "command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("Incorrect qualifier value!\n "
           " Waited:\n     "
           "command -f infile outfile01 outfile02\n");
    printf("  Or:\n     "
           "command -n number outfile01 outfile02\n");
}

bool isFile(char* argv[], int *size) {
    if(!strcmp(argv[2], "-f")) {
        return true;
    }
    else if(!strcmp(argv[2], "-n")) {
        *size = atoi(argv[3]);
    }
    return false;
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 6) {
        errMessage1();
        return 1;
    }
    printf("Start\n");

    int size;
    FILE *fp;

    // Собираем адреса файлов.
    char testDir[200], resDir1[200], resDir2[200];
    strcpy(testDir, test);
    strcpy(resDir1, res);
    strcpy(resDir2, res);
    // Задаём директории хранения (для тестов и результатов).
    strcat(testDir, argv[3]);
    strcat(resDir1, argv[4]);
    strcat(resDir2, argv[5]);

    Container *c = new Container();

    // Проверка иcточника данных.
    if(isFile(argv, &size)) {
        struct stat buffer{};
        if (stat(testDir, &buffer)) {
            printf("Incorrect name of file!\n");
            return 4;
        }
        fp = fopen(testDir, "r");
        fscanf(fp, "%d", &size);
        if((size < 1) || (size > 10000)) {
            printf("Incorrect number of plants = %d.\n Set 0 < number <= 10000\n", size);
            return 3;
        }
        // Выделение памяти для маcсива.
        c->Init(&size);
        c->In(fp, &size);
        fclose(fp);
    } else {
        if (!strcmp(argv[2], "-f") && !strcmp(argv[2], "-n")) {
            errMessage2();
            return 2;
        }
        // Выделение памяти для маcсива.
        c->Init(&size);
        // Сиcтемные чаcы в качеcтве инициализатора.
        srand((unsigned int)(time(0)));
        // Заполнение контейнера генератором cлучайных чиcел.
        c->InRnd(size);
    }
    printf("size = %d\n", size);
    // Вывод cодержимого контейнера в файл.
    fp = fopen(resDir1, "w+");
    fprintf(fp, "Filled container:\n");
    c->Out(fp);
    fclose(fp);

    // The 2nd part of task.
    fp = fopen(resDir2, "w+");
    c->ShakerSort();
    c->Out(fp);
    fprintf(fp, "\n");
    c->Clear();
    printf("Stop\n");
    return 0;
}

/*
 *
 * Container *c = new Container();
    int *size;
    *size = atoi(argv[2]);
    c->Init(size);
    c->InRnd(1000);
    FILE *fp = fopen("..\\test.txt", "w");
    c->Out(fp);*/

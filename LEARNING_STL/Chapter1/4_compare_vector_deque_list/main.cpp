#include <QCoreApplication>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <algorithm>
#include <QElapsedTimer>
#include <stdlib.h>

/* цель:
 * сравнение функций вектора, листа и двухсторонней очереди (вставка, удаление, доступ)
 * обозначение отличий между этими контейнерами
 */

template<typename T>
void memoryAnalyzer(int sz) {
    // создангие контейнера
    T cont;

    // добавление первого элемента и сохранение его адреса
    cont.push_back(-1);
    int* originalStart = &(*cont.begin());

    // цикл анализа
    for (int i = 0; i < sz; i++) {
        // сохранение адресса первого элемента
        int* start = &(*cont.begin());
        // обход по всем элементам контейнера
        for (auto& i : cont) {
            // адрес последнего элемента
            int * lastItem = &i;
            // относительно первого элемента
            int startOffset = lastItem - start;
            // относительно инициализации контейнера
            int originalStartOffset = lastItem - originalStart;
            // вывод значений
            std::cout << "Offset from original start: " << originalStartOffset
                      << "\tOffset from start: " << startOffset
                      << "\tContent: " << i
                      << "\n";
        }
        // добавление нового элемента в контейнер
        cont.push_back(i);
        std::cout << "\n";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //HEADER
    std::cout << "CHAPTER 1 : LESSON 4 : COMPARE CONTAINERS VECTOR, LIST, DEQUE\n";

    // Сравнение по памяти
    std::cout << "Vector memory usage:\n";
    memoryAnalyzer<std::vector<int> >(10);

    std::cout << "List memory usage:\n";
    memoryAnalyzer<std::list<int> >(10);

    std::cout << "Deque memory usage:\n";
    memoryAnalyzer<std::deque<int> >(10);



    // Сравнение по времени выполнения


    return a.exec();
}


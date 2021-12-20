#include <QCoreApplication>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <stdlib.h>
#include <QElapsedTimer>


/* цель:
 * сравнение вектора, листа и двухсторонней очереди (вставка, удаление, доступ) с точки зрения затрат времени
 * обозначение отличий между этими контейнерами
 *
 * вывод:
 * 1) скорость push_back    d >> v > l
 * 2) скорость pop_back     d = v >> l
 * 3) скорость push_front   d >> l
 * 4) скорость pop_front    d >> l
 * 5) скорость insert       l > d >> v
 * 6) скорость erase        l > d >> v
 * 7) скорость direct access    v >> d
 * 8) скорость iterator access  d = v = l
 *
 */

// добавление и удаление большого количества элементов в конец
template<typename T>
void timeAnalPushBack(int sz) {
    // создание контейнера
    T cont;

    // запуск таймера
    QElapsedTimer t;
    t.start();

    // push_back
    for (int i = 0; i < sz; i++) {
        cont.push_back(i);
    }
    std::cout << "push_back time for " << sz << " elements: " << t.elapsed() << " ms\n";

    // pop_back
    t.start();
    for (int i = 0; i < sz; i++) {
        cont.pop_back();
    }
    std::cout << "pop_back time for " << sz << " elements: " << t.elapsed() << " ms\n";
}

// добавление и удаление большого количества элементов в начало
template<typename T>
void timeAnalPushFront(int sz) {
    // создание контейнера
    T cont;

    // запуск таймера
    QElapsedTimer t;
    t.start();

    // push_front
    for (int i = 0; i < sz; i++) {
        cont.push_front(i);
    }
    std::cout << "push_front time for " << sz << " elements: " << t.elapsed() << " ms\n";

    // pop_front
    t.start();
    for (int i = 0; i < sz; i++) {
        cont.pop_front();
    }
    std::cout << "pop_front time for " << sz << " elements: " << t.elapsed() << " ms\n";
}

// добавление и удаление большого количества элементов в середину
template<typename T>
void timeAnalInsert(int sz) {
    // создание контейнера
    T cont;

    // инициализация контейнера
    cont.push_back(-1);
    cont.push_back(-2);

    // создание итератора
    typename T::iterator it;

    // запуск таймера
    QElapsedTimer t;
    t.start();

    // insert
    for (int i = 0; i < sz; i++) {
        it = cont.begin();
        it++;
        cont.insert(it, i);
    }
    std::cout << "insert time for " << sz << " elements: " << t.elapsed() << " ms\n";

    // erase
    t.start();
    for (int i = 0; i < sz; i++) {
        it = cont.begin();
        it++;
        cont.erase(it);
    }
    std::cout << "erase time for " << sz << " elements: " << t.elapsed() << " ms\n";
}

// доступ прямой
template<typename T>
void timeAnalAccessDir(int sz) {
    // создание контейнера
    T cont;

    // заполнение
    for (int i = 0; i < sz; i++) {
        cont.push_back(i);
    }

    // запуск таймера
    QElapsedTimer t;
    t.start();
    for (int i = 0; i < sz; i++) {
            if (cont[i] == 0) {}
    }
    std::cout << "direct access time for " << sz << " elements: " << t.elapsed() << " ms\n";
}

// доступ по итератору
template<typename T>
void timeAnalAccessIt(int sz) {
    // создание контейнера
    T cont;

    // заполнение
    for (int i = 0; i < sz; i++) {
        cont.push_back(i);
    }

    // запуск таймера
    QElapsedTimer t;
    t.start();
    for (auto& i : cont) {
        if (i == 0) {}
    }
    std::cout << "iterator access time for " << sz << " elements: " << t.elapsed() << " ms\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //HEADER
    std::cout << "CHAPTER 1 : LESSON 5 : COMPARE CONTAINERS VECTOR, LIST, DEQUE (time)\n";

    // количество элементов для анализа
    int ANAL_SIZE_PUSH = 1000000,
            ANAL_SIZE_INSERT = 10000000,
            ANAL_SIZE_ACCESS = 10000000;

    // анализ vector
    std::cout << "Vector times:\n";
    timeAnalPushBack<std::vector<int> >(ANAL_SIZE_PUSH);
    std::cout << "no push_front for vector\n";
    std::cout << "no pop_front for vector\n";
    timeAnalInsert<std::vector<int> >(ANAL_SIZE_INSERT/100);
    timeAnalAccessDir<std::vector<int> >(ANAL_SIZE_ACCESS);
    timeAnalAccessIt<std::vector<int> >(ANAL_SIZE_ACCESS);
    std::cout << "\n";

    // анализ list
    std::cout << "List times:\n";
    timeAnalPushBack<std::list<int> >(ANAL_SIZE_PUSH);
    timeAnalPushFront<std::list<int> >(ANAL_SIZE_PUSH);
    timeAnalInsert<std::list<int> >(ANAL_SIZE_INSERT);
    std::cout << "no direct access for list\n";
    timeAnalAccessIt<std::list<int> >(ANAL_SIZE_ACCESS);
    std::cout << "\n";

    // анализ deque
    std::cout << "Deque times:\n";
    timeAnalPushBack<std::deque<int> >(ANAL_SIZE_PUSH);
    timeAnalPushFront<std::deque<int> >(ANAL_SIZE_PUSH);
    timeAnalInsert<std::deque<int> >(ANAL_SIZE_INSERT);
    timeAnalAccessDir<std::deque<int> >(ANAL_SIZE_ACCESS);
    timeAnalAccessIt<std::deque<int> >(ANAL_SIZE_ACCESS);
    std::cout << "\n";


    return a.exec();
}


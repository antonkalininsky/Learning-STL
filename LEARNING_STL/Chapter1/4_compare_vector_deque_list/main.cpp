#include <QCoreApplication>
#include <vector>
#include <list>
#include <deque>
#include <iostream>

/* цель:
 * сравнение вектора, листа и двухсторонней очереди (вставка, удаление, доступ) с точки зрения организации памяти
 * обозначение отличий между этими контейнерами
 *
 * вывод:
 * контейнеры по разному организуют память
 * 1) вектор хранит информацию непрерывно, если размер памяти не позволяет добавить новый элемент в вектор,
 * то вектор находит новую область памяти в которую может поместиться и перемещается туда полностью
 * 2) лист хранит информацию разбросанно, каждый новый элемент может находится в новой области памяти,
 * каждый элемент листа знает о своих соседях
 * 3) двухстороняя очередь использует смешанный механизм, она хранит информацию набором непрерывных блоков памяти,
 * блоки памяти могут располагаться разбросанно в памяти, каждый блок памяти знает о своем соседе
 */

// шаблонная функция для анализа использования памяти контейнером
template<typename T>
void memoryAnalyzer(int sz) {
    // создание контейнера
    T cont;

    // добавление первого элемента и сохранение его адреса
    cont.push_back(0);
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
                      << "     Offset from start: " << startOffset
                      << "     Content: " << i
                      << "\n";
        }
        // добавление нового элемента в контейнер
        cont.push_back(i + 1);
        std::cout << "\n";
    }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //HEADER
    std::cout << "CHAPTER 1 : LESSON 4 : COMPARE CONTAINERS VECTOR, LIST, DEQUE (memory)\n";

    // анализ вектора
    std::cout << "Vector memory usage:\n";
    memoryAnalyzer<std::vector<int> >(10);

    // анализ листа
    std::cout << "List memory usage:\n";
    memoryAnalyzer<std::list<int> >(10);

    // анализ двухсторонней очереди
    std::cout << "Deque memory usage:\n";
    // доработанный вариант функции memoryAnalyzer для особенностей работы deque
    std::deque<int> cont;
    // добавление первого элемента и сохранение его адреса
    cont.push_back(0);
    int* originalStart = &(*cont.begin());
    // цикл заполнения
    for (int i = 0; i < 3000; i++) {
        cont.push_back(i + 1);
    }
    // позиция последнего элемента
    int* start = &(*cont.begin());
    // начальное отклонение (i - 1)
    int startOffset_i = 0;
    for (auto& i : cont) {
        // адрес последнего элемента
        int * lastItem = &i;
        // относительно первого элемента
        int startOffset = lastItem - start;
        // относительно инициализации контейнера
        int originalStartOffset = lastItem - originalStart;
        // вывод значений если адреса в памяти не соседние
        if (startOffset_i != startOffset - 1) {
            std::cout << "Offset from original start: " << originalStartOffset
                      << "     Offset from start: " << startOffset
                      << "     Content: " << i
                      << "\n";
        }
        startOffset_i = startOffset;
    }

    return a.exec();
}


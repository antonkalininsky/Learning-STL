#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
//#include <stdlib.h>
#include <algorithm>

using namespace std;

/* цель:
 * базовая работа с сортировкой контейнеров
 *
 * вывод:
 * 1) сортировка работает
 * 2) итераторы должны быть в восходящем порядке
 * 3) сортировка может быть частичная
 * 4) лист не может быть сортирован этим алгоритмом
 */

template <typename T>
void showContainer(T c) {
    for (int i = 0; i < c.size(); i++) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";
}

void showList(const std::list<int> &l) {
    std::list<int>::const_iterator it;
    for (it = l.begin(); it != l.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void showMas(int *m, int sz) {
    for (int i = 0; i < sz; i++) {
        std::cout << *(m + i) << " ";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // HEADER
    cout << "CHAPTER 1 : LESSON 6 : SORT CONTAINERS\n";

    // MASSIVE
    cout << "Massive (partly)\n";
    int arrSz = 5;
    int mas[arrSz] = {5, 2, 6, 3, 9};
    // show init
    cout << "Initial massive: ";
    showMas(mas, arrSz);
    // the sorting
    sort(mas + 1, mas + 4);
    // show final
    cout << "Massive after sorting: ";
    showMas(mas, arrSz);
    cout << "\n";

    // VECTOR
    cout << "Vector\n";
    vector<int> vec = {5, 4, 3, 2, 1};
    // show init
    cout << "Initial vector: ";
    showContainer(vec);
    // the sorting
    sort(vec.begin(), vec.end());
    // sort(vec.end(), vec.begin()); ERROR!!! порядок итераторов сначала первый, потом второй
    // show final
    cout << "Vector after sorting: ";
    showContainer(vec);
    cout << "\n";

    // DEQUE
    cout << "Deque\n";
    deque<int> deq = {15, 10, 14, 11, -999};
    // show init
    cout << "Initial deque: ";
    showContainer(deq);
    // the sorting
    sort(deq.begin(), deq.end());
    // show final
    cout << "Deque after sorting: ";
    showContainer(deq);
    cout << "\n";

    // LIST
    cout << "List cannot be sorted via sort()\n";

    return a.exec();
}


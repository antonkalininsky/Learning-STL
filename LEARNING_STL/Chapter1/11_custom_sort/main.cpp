/* цель:
 * сортировка по пользовательским правилам
 *
 * вывод:
 * возможно использование кастомных пользовательских функций для использования в алгоритме сортировки
 */

#include <QCoreApplication>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void showContainer(T c) {
    for (int i = 0; i < c.size(); i++) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";
}

bool compFoo(int x, int y) {
    return x % 10 > y % 10;
}

bool compFoo2 (int x, int y) {
    return (x % 100 - x % 10) / 10 > (y % 100 - y % 10) / 10;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // HEADER
    cout << "CHAPTER 1 : LESSON 11 : CUSTOM SORT CONTAINERS\n";

    // создание начального вектора
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(rand() % 100);
    }
    cout << "Initial vector: ";
    showContainer(v);

    // сортировка 1
    sort(v.begin(), v.end(), compFoo);

    // отсортированный вектор функцией 1
    cout << "Sorted vector 1: ";
    showContainer(v);

    // сортировка 2
    sort(v.begin(), v.end(), compFoo2);

    // отсортированный вектор функцией 1
    cout << "Sorted vector 2: ";
    showContainer(v);

    return a.exec();
}


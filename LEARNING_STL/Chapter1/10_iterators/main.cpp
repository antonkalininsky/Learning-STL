/* цель:
 * ознакомление с итераторами
 * 1) функции
 * 2) методы
 * 3) типы итераторов
 *
 * вывод:
 * 1) существуют различные итераторы: обычные, константные, реверсивные, константные реверсивные
 * обычные предоставляют запись и чтение
 * константные предоставляют только чтение
 * реверсивные позволяют получать доступ к контейнеру с конца
 *
 * 2) различные операции с итераторами
 * it++ инкремент
 * it-- декремент
 * it+= it-= задание относительной позиции
 * == =< итд сравнение итераторов
 *
 * 3) различные функции
 * distance - расстояние между итераторами
 * next(it, off) prev(it, off) - возвращает новый итератор на основе старого + сдвиг
 *
 * обычные итераторы
 * cont.begin()
 * cont.end()
 *
 * константные итераторы
 * cont.cbegin()
 * cont.cend()
 *
 * реверсивные итераторы
 * cont.rbegin()
 * cont.rend()
 *
 * константные реверсивные итераторы
 * cont.crbegin()
 * cont.crend()
 *
 */

#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <typename T>
void showContainer(T c) {
    for (int i = 0; i < c.size(); i++) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // создание начального вектора
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    cout << "Initial vector: ";
    showContainer(v);
    cout << "\n";

    // создание итератора чтения/записи
    vector<int>::iterator it1;
    cout << "Iterator created\n";
    // end
    it1 = v.end();
    cout << "end of container: " << *it1 << "\n";
    // access
    it1--;
    cout << "--: " << *it1 << "     ";
    it1 -= 2;
    cout << "-2: " << *it1 << "     ";
    it1++;
    cout << "++: " << *it1 << "\n";
    // begin
    it1 = v.begin();
    cout << "begin of container: " << *it1 << "\n";
    // advance
    advance(it1, 3);
    cout << "advance 3 times: " << *it1 << "\n";
    // advance
    it1 = v.end();
    advance(it1, -3);
    cout << "advance -3 times: " << *it1 << "\n";
    // distance
    cout << "distance to end: " << distance(it1, v.end()) << "\n";
    // next and prev
    cout << "next 2 times: " << *next(it1, 2) << "     ";
    cout << "prev 1 time: " << *prev(it1, 1) << "     ";
    cout << "iterator: " << *it1 << "\n";
    // изменение
    *it1 = 69;
    cout << "iterator value is updated\nvector:";
    showContainer(v);

    // два итератора
    vector<int>::iterator it2;
    cout << "\nIterator 2 created\n";
    it2 = v.begin();
    cout << "iterator 1: " << *it1 << "     ";
    cout << "iterator 2: " << *it2 << "\n";
    if (it1 == it2) {
        cout << "i1 == it2\n";
    } else {
        cout << "i1 != it2\n";
    }
    if (it1 > it2) {
        cout << "i1 > it2\n";
    } else {
        cout << "i1 <= it2\n";
    }
    cout << "it1 - it2: " << it1 - it2 << "\n";
    cout << "it2 - it1: " << it2 - it1 << "\n";
    cout << "\n";

    // константный итератор
    cout << "Accessing vector via const_iterator: ";
    vector<int>::const_iterator it3;
    for (it3 = v.begin(); it3 != v.end(); it3++) {
        //*it3 = 3333; // can't do
        cout << *it3 << " ";
    }
    cout << "\n";

    // реверсивный итератор
    cout << "Accessing vector via reverse_iterator: ";
    vector<int>::reverse_iterator it4;
    for (it4 = v.rbegin(); it4 != v.rend(); it4++) {
        cout << *it4 << " ";
    }
    cout << "\n";

    return a.exec();
}


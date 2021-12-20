#include <QCoreApplication>
#include <vector>
#include <list>
#include <deque>
#include <iostream>


/* цель:
 * изучение базовых функций вектора, листа и двухсторонней очереди (вставка, удаление, доступ)
 * обозначение отличий между этими контейнерами
 *
 * вывод:
 * 1) были рассмотрены следующие последовательные контейнеры: лист, вектор, двухстороняя очередь
 * 2) рассмотренные функции: вставка и удаление в конце, вставка и удаление в начале, вставка и удаление в середине, доступ
 * 3) вектор не может вставлять и удалять элементы в начале
 * 4) нельзя обращаться к элементам листа произвольно (a[]), необходимо организовывать доступ через разименовывание итераторов
 * 5) изменение листа привело к изменению порядка и позиции элементов листа, необходимо переинициализировать итераторы в таком случае
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

// работа с вектором
void vectorPractice() {
    std::cout << "Working with vector\n";
    std::vector<int> v;
    // вставка элементов вектора производится в конце контейнера
    std::cout << "creating and filling vector with some numbers: ";
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    showContainer(v);
    // удаление элементов вектора производится в конце контейнера
    std::cout << "delete last element from vector: ";
    v.pop_back();
    showContainer(v);
    // вставлять и удалять элементы из начала вектора нельзя
    std::cout << "can't push and pop front element of vector\n";
    // вставка элемента в середине вектора
    std::cout << "insert number in the middle of vector: ";
    v.insert(v.begin() + 1, 9);
    showContainer(v);
    // удаление элемента из середины вектора
    std::cout << "delete number from the middle of vector: ";
    v.erase(v.begin() + 1);
    showContainer(v);
    std::cout << "\n";
}

// работа с листом
void listPractice() {
    std::cout << "Working with list\n";
    std::list<int> l;
    // вставка элементов листа в конце контейнера
    std::cout << "creating and filling list with some numbers: ";
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    showList(l);
    // удаление элементов листа в конце контейнера
    std::cout << "delete last element from list: ";
    l.pop_back();
    showList(l);
    // вставка элементов листа в начале контейнера
    std::cout << "creating and filling list with some numbers: ";
    l.push_front(4);
    l.push_front(5);
    l.push_front(6);
    showList(l);
    // удаление элементов листа в начале контейнера
    std::cout << "delete last element from list: ";
    l.pop_front();
    showList(l);
    // вставка элемента в середине листа
    std::cout << "insert number in the middle of list: ";
    std::list<int>::iterator it = l.begin();
    it++;
    l.insert(it, 9);
    showList(l);
    // удаление элемента из середины листа
    std::cout << "delete number from the middle of list: ";
    it = l.begin();
    it++;
    l.erase(it);
    showList(l);
    std::cout << "\n";
}

// работа с двухсторонней очередью
void dequePractice() {
    std::cout << "Working with deque\n";
    std::deque<int> d;
    // вставка элементов в конце очереди
    std::cout << "creating and filling deque with some numbers: ";
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    showContainer(d);
    // удаление элементов в конце очереди
    std::cout << "delete last element from deque: ";
    d.pop_back();
    showContainer(d);
    // вставка элементов в начале очереди
    std::cout << "creating and filling deque with some numbers: ";
    d.push_front(4);
    d.push_front(5);
    d.push_front(6);
    showContainer(d);
    // удаление элементов в начале очереди
    std::cout << "delete last element from deque: ";
    d.pop_front();
    showContainer(d);
    // вставка элемента в середине очереди
    std::cout << "insert number in the middle of deque: ";
    d.insert(d.begin() + 1, 9);
    showContainer(d);
    // удаление элемента из середины очереди
    std::cout << "delete number from the middle of deque: ";
    d.erase(d.begin() + 1);
    showContainer(d);
    std::cout << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //HEADER
    std::cout << "CHAPTER 1 : LESSON 3 : BASIC WORK WITH VECTOR, LIST, DEQUE\n";

    vectorPractice();
    listPractice();
    dequePractice();

    return a.exec();
}


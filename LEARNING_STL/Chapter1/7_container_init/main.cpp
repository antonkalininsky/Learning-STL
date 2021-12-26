#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

/* цель:
 * Способы инициализации контейнеров
 *
 * вывод:
 * 1)
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
    cout << "CHAPTER 1 : LESSON 7 : INIT CONTAINERS\n\n";

    // ARRAY
    // v1
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Init array v1: ";
    showMas(arr, 5);
    // v2
    int arr1[5] = {1, 2};
    cout << "Init array v2: ";
    showMas(arr1, 5);
    cout << "\n";

    // VECTOR
    // v1
    vector<int> vec = {3, 2, 1};
    cout << "Init vector v1: ";
    showContainer(vec);
    // v2
    vector<int> vec2(arr, arr + 2);
    cout << "Init vector v2: ";
    showContainer(vec2);
    // v3
    vector<int> vec3(5, 1);
    cout << "Init vector v3: ";
    showContainer(vec3);
    // v4
    vector<int> vec4(3);
    cout << "Init vector v4: ";
    showContainer(vec4);
    // v5
    vector<int> vec5(vec.begin(), vec.end());
    cout << "Init vector v5: ";
    showContainer(vec5);
    cout << "\n";

    // DEQUE
    // v1
    deque<int> deq = {3, 2, 1};
    cout << "Init deque v1: ";
    showContainer(deq);
    // v2
    deque<int> deq2(arr, arr + 2);
    cout << "Init deque v2: ";
    showContainer(deq2);
    // v3
    deque<int> deq3(5, 1);
    cout << "Init deque v3: ";
    showContainer(deq3);
    // v4
    deque<int> deq4(3);
    cout << "Init deque v4: ";
    showContainer(deq4);
    // v5
    deque<int> deq5(deq.begin(), deq.end() - 1);
    cout << "Init deque v5: ";
    showContainer(deq5);
    // v6
    deque<int> deq6(vec.begin() + 1, vec.end());
    cout << "Init deque v6: ";
    showContainer(deq6);
    cout << "\n";

    // LIST
    // v1
    list<int> ll = {1, 2, 1};
    cout << "Init list v1: ";
    showList(ll);
    // v2
    list<int> ll2(arr, arr + 2);
    cout << "Init list v2: ";
    showList(ll2);
    // v3
    list<int> ll3(5, 1);
    cout << "Init list v3: ";
    showList(ll3);
    // v4
    list<int> ll4(3);
    cout << "Init list v4: ";
    showList(ll4);
    // v5
    list<int> ll5(ll.begin(), ll.end());
    cout << "Init list v5: ";
    showList(ll5);
    // v6
    list<int> ll6(deq6.begin(), deq6.end());
    cout << "Init list v6: ";
    showList(ll6);
    cout << "\n";

    return a.exec();
}


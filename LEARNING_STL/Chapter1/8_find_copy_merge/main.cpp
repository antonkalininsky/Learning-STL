#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

/* цель:
 * алгоритмы find, copy, merge
 *
 * вывод:
 * 1) find работает как надо
 * 2) copy необходимо копировать размер не больше конечного
 * 3) copy может использовать любой размер в режиме ставки
 * 4) merge - аналогично copy
 */

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

    // HEADER
    cout << "CHAPTER 1 : LESSON 8 : FIND COPY MERGE\n\n";

    vector<int> A = {1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9};
    cout << "vector A: ";
    showContainer(A);

    vector<int> B = {2, 4, 6, 8, 10};
    cout << "vector B: ";
    showContainer(B);
    cout << "\n";

    // FIND
    vector<int>::iterator it1 = find(A.begin(), A.end(), 6);
    cout << "number 6 in A ";
    if (it1 == A.end()) {
        cout << "not found!";
    } else {
        cout << "found! ";
        if (it1 == A.begin()) {
            cout << "it is first element";
        } else {
            cout << "prev element: " << *--it1;
        }
    }
    cout << "\n";

    vector<int>::iterator it2 = find(B.begin(), B.end(), 1);
    cout << "number 1 in B ";
    if (it2 == B.end()) {
        cout << "not found!";
    } else {
        cout << "found! ";
        if (it2 == B.begin()) {
            cout << "it is first element";
        } else {
            cout << "prev element: " << *--it2;
        }
    }
    cout << "\n\n";

    // COPY
    vector<int> C(B.begin(), B.end());
    cout << "vector C: ";
    showContainer(C);
    cout << "copy first two elements of A into end C: ";
    copy(A.begin(), A.begin() + 2, C.begin());
    showContainer(C);

    // COPY INSERTER
    cout << "copy whole A into end C (inserter): ";
    copy(A.begin(), A.end(), inserter(C, C.begin()));
    showContainer(C);
    cout << "\n";

    // MEGRE
    vector<int> E(4);
    cout << "vector E has 4 zero elements\n";
    cout << "merge first two elements of A and B into E: ";
    merge(A.begin(), A.begin() + 2, B.begin(), B.begin() + 2, E.begin());
    showContainer(E);


    // MEGRE INSERTER
    vector<int> D;
    cout << "vector D is empty\n";
    cout << "merge A and B into D (inserter): ";
    merge(A.begin(), A.end(), B.begin(), B.end(), inserter(D, D.begin()));
    showContainer(D);





    return a.exec();
}


#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/* цель:
 * алгоритмы find, copy, merge для кастомной структуры
 *
 * вывод:
 * 1) find работает как надо
 * 2) copy необходимо копировать размер не больше конечного
 * 3) copy может использовать любой размер в режиме вставки
 * 4) merge - аналогично copy
 */

struct human {
    int year;
    int ID;
    char name[30];
    bool operator< (const human &h) const {
        return ID < h.ID;
    }
    bool operator== (const human &h) const {
        return ID == h.ID;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // HEADER
    cout << "CHAPTER 1 : LESSON 9 : FIND COPY MERGE CUSTOM\n\n";

    human gr1[2] = {{15, 2, "A"},
                  {3, 4, "B"}};
    human gr2[3] = {{37, 5, "C"},
                  {13, 8, "D"},
                  {25, 3, "E"}};
    human gr3[5], *p;

    cout << "group 1:\n";
    for (p = gr1; p != gr1 + 2; p++) {
        cout << p->ID << " " << p->name << " " << p->year << endl;
    }
    cout << "\n";

    cout << "group 2:\n";
    for (p = gr2; p != gr2 + 3; p++) {
        cout << p->ID << " " << p->name << " " << p->year << endl;
    }
    cout << "\n";

    merge(gr1, gr1 + 2, gr2, gr2 + 3, gr3);

    // merge
    cout << "merged group 3:\n";
    for (p = gr3; p != gr3 + 5; p++) {
        cout << p->ID << " " << p->name << " " << p->year << endl;
    }
    cout << "\n";

    // copy
    human gr4[2];
    copy(gr2, gr2 + 2, gr4);
    cout << "Copy first two elements of group 2 to new group:\n";
    for (p = gr4; p != gr4 + 2; p++) {
        cout << p->ID << " " << p->name << " " << p->year << endl;
    }
    cout << "\n";


    // find
    human h = {0, 2, "0"};
    cout << "Find element with ID = 2 in group 3:\n";
    p = find(gr3, gr3 + 5, h);
    if ( p == gr3 + 5 ) {
        cout << "not found!\n";
    } else {
        cout << p->ID << " " << p->name << " " << p->year << endl;
    }



    return a.exec();
}


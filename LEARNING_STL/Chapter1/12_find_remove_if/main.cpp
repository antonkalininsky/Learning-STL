/* информация:
 * find_if - поиск в контейнере с использованием предиката
 * remove - удаление элемента контейнера
 * remove_if - удаление элемента контейнера с использованием предиката
 * при использовании последних двух функций не меняется размер контейнера, остается старый мусор в "несжатой" части контейнера
 * данные функции возвращают указатель на новый конец контейнера
 *
 *
 */

#include <QCoreApplication>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

template <typename T>
void showContainer(T c) {
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << "\n";
}

class find5 {
public:
    bool operator()(int x) {
        if (x >= 5) {
            return true;
        }
        return false;
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    deque<int> d;
    for (int i = 0; i < 10; i++) {
        d.push_back(i);
    }
    cout << "Initial deque: ";
    showContainer(d);

    cout << "Searching for x>=5...\n";
    auto i = find_if(d.begin(), d.end(), find5());
    if (i != d.end()) {
        cout << "found element: " << *i;
    } else {
        cout << "element not found";
    }
    cout << "\n\n";

    cout << "removing x == 5\n";
    auto newEnd = remove(d.begin(), d.end(), 5);
    showContainer(d);
    cout << "new end is: " << *newEnd << "\n";
    cout << "erase from newEnd to old end\n";
    d.erase(newEnd, d.end());
    showContainer(d);
    cout << "\n";

    cout << "removing x >= 5\n";
    newEnd = remove_if(d.begin(), d.end(), find5());
    showContainer(d);
    cout << "new end is: " << *newEnd << "\n";
    cout << "erase from newEnd to old end\n";
    d.erase(newEnd, d.end());
    showContainer(d);
    cout << "\n";




    return a.exec();
}


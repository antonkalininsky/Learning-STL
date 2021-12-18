#include <QCoreApplication>
#include <iostream>

/* пример из книги
 *
 *  шаблонная функция
 *  template <class T>
 *  T f(T x) {
 *       T x2 = 2 * x;
 *       return x2 + ( x * x + 1) / x2;
 *  }
 *
 *  int main() {
 *      cout << f(5.0) << endl << f(5) << endl;
 *  }
 */

// шаблонная функция которая ищет нули в контейнере
template <typename T>
bool ContainerZeroDetector (T c, int sz) {
    for (int i = 0; i < sz ; i++) {
        if (c[i] == 0) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //HEADER
    std::cout << "CHAPTER 1 : LESSON 1 : TEMPLATES\n";

    // array
    int sz = 3;
    int arr[sz] = {0, 1, 2};
    std::cout << "arr (0, 1, 2) ";
    if (ContainerZeroDetector(arr, sz)) {
        std::cout << "has zeros!\n";
    } else {
        std::cout << "doesn't have zeros!\n";
    }

    // vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::cout << "vec (1, 2, 3) ";
    if (ContainerZeroDetector(vec, vec.size())) {
        std::cout << "has zeros!\n";
    } else {
        std::cout << "doesn't have zeros!\n";
    }

    std::cout << "\n\n";



    return a.exec();
}


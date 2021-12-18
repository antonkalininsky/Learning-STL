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
 *
 * шаблонный класс
 *  template <class T>
 *  class Pair {
 *  public:
 *      Pair (T x1, T y1): x(x1), y(y1) {}
 *      void showQ();
 *  private:
 *      T x, y;
 *  };
 *
 *  template <class T>
 *  void Pair<T>::showQ() {
 *      cout << x/y << endl;
 *  }
 *
 *  int main() {
 *      Pair<double> a(37.0, 5.0);
 *      Pair<int> u(37, 5);
 *      a.showQ();
 *      u.showQ();
 *      return 0;
 *  }
 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    return a.exec();
}


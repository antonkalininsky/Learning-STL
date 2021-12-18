#include <QCoreApplication>
#include <iostream>

/* пример из книги
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

// ОСОБЕННОСТИ КОМПИЛЯТОРА
// реализация и объявления темплейтных классов должны быть в одном файле
template <class T>
class DigitsCounter {
public:
    DigitsCounter(T num, int dig);
    int getCou() const;

private:
    int cou;

};

template <class T>
DigitsCounter<T>::DigitsCounter(T num, int dig) {
    // inits
    cou = 0;
    // digits to count: 1,2,3,4,5,6,7,8,9
    if (dig == 0 || dig > 9) {
        return;
    }
    // vector of digits
    std::vector<int> digits;
    // whole part
    int buf = (int)(num);
    for (;;) {
        digits.push_back(buf % 10);
        buf /= 10;
        if (buf == 0) {
            break;
        }
    }
    // mantisa part
    double buf2 = num - (int)(num);
    for (;;) {
        buf2 -= (int)(buf2);
        buf2 *= 10;
        if ((int)(buf2) == 0) {
            break;
        }
        digits.push_back((int)(buf2));
    }
    // count digits
    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] == dig) {
            cou++;
        }
    }
}

template <class T>
int DigitsCounter<T>::getCou() const {
    return cou;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //HEADER
    std::cout << "CHAPTER 1 : LESSON 2 : TEMPLATES CLASS\n";

    DigitsCounter<int> x(454454477, 4);
    std::cout << "number (454454477) has (4) " << x.getCou() << " times.\n";

    DigitsCounter<double> y(454.454477, 5);
    std::cout << "number (454.454477) has (5) " << y.getCou() << " times.\n";

    std::cout << "\n\n";
    return a.exec();
}


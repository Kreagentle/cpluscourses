#### Задание по программированию: Тесты для класса Rational ####


Класс _Rational_ представляет собой рациональное число и имеет следующий интерфейс
```objectivec
class Rational {
public:
  Rational();
  Rational(int numerator, int denominator);

  int Numerator() const;
  int Denominator() const;
};
```
Список требований, предъявляемых к реализации интерфейса класса _Rational_:

1. Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
2. При конструировании объекта класса _Rational_ с параметрами p и q должно выполняться сокращение дроби p/q.
3. Если дробь p/q отрицательная, то объект _Rational(p, q)_ должен иметь отрицательный числитель и положительный знаменатель.
4. Если дробь p/q положительная, то объект _Rational(p, q)_ должен иметь положительные числитель и знаменатель (обратите внимание на случай _Rational(-2, -3)_).
5. Если числитель дроби равен нулю, то знаменатель должен быть равен 1.

Разработайте набор юнит-тестов, которые будут проверять корректность реализации класса _Rational_. **Тестировать случай, когда знаменатель равен нулю, не надо**.
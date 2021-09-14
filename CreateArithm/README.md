#### Задание по программированию: Построение арифметического выражения ####


#### Часть 1 ####
Реализуйте построение арифметического выражения согласно следующей схеме:

* изначально есть выражение, состоящее из некоторого целого числа *x*;
* на каждом шаге к текущему выражению применяется некоторая операция: прибавление числа, вычитание числа, умножение на число или деление на число; перед применением операции выражение всегда должно быть заключено в скобки.

##### Пример #####
Изначально есть число 8, соответствующее выражение:
```commandline
8
```
К нему применяется операция умножения на 3, получается выражение
```commandline
(8) * 3
```
Затем вычитается 6:
```commandline
((8) * 3) - 6
```
Наконец, происходит деление на 1; итоговое выражение:
```commandline
(((8) * 3) - 6) / 1
```

##### Формат ввода #####
В первой строке содержится исходное целое число *x*. Во второй строке содержится целое неотрицательное число *N*— количество операций. В каждой из следующих *N* строк содержится очередная операция:
* прибавление числа *a*: **+ a**;
* либо вычитание числа *b*: **- b**;
* либо умножение на число *c*: __* c__;
* либо деление на число *d*: **/ d**.

Количество операций может быть нулевым — в этом случае необходимо вывести исходное число.

##### Формат вывода #####
Выведите единственную строку — построенное арифметическое выражение.

Обратите внимание на расстановку пробелов вокруг символов:
* каждый символ бинарной операции (+, -, * или /) должен быть окружён ровно одним пробелом с каждой стороны: (8) * 3;
* символ унарного минуса (для отрицательных чисел) не нуждается в дополнительном пробеле: -5;
* скобки и числа не нуждаются в дополнительных пробелах.

##### Подсказка #####
Для преобразования числа к строке используйте функцию *to_string* из библиотеки *<string>*.

##### Пример #####
###### Ввод ######
```commandline
8
3
* 3
- 6
/ 1
```
###### Вывод ######
```commandline
(((8) * 3) - 6) / 1
```

#### Часть 2. Без лишних скобок ####
Модифицируйте решение предыдущей части так, чтобы предыдущее выражение обрамлялось скобками лишь при необходимости, то есть только в том случае, когда очередная операция имеет бо́льший приоритет, чем предыдущая.

##### Пример #####
###### Ввод ######
```commandline
8
3
* 3
- 6
/ 1
```
###### Вывод ######
```commandline
(8 * 3 - 6) / 1
```
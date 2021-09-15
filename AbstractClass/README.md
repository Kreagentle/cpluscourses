#### Тренировочное задание по программированию: Отправка уведомлений ####


В этой задаче вам нужно разработать классы *SmsNotifier* и *EmailNotifier*, отправляющие уведомления в виде SMS и *e-mail* соответственно, а также абстрактный базовый класс для них.

Вам даны функции *SendSms* и *SendEmail*, которые моделируют отправку SMS и *e-mail*.

```objectivec
void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);
```

Разработайте:

1. Абстрактный базовый класс *INotifier*, у которого будет один чисто виртуальный метод *void Notify(const string& message)*.
2. Класс *SmsNotifier*, который:
* является потомком класса *INotifier*;
* в конструкторе принимает один параметр типа string — номер телефона;
* переопределяет метод *Notify* и вызывает из него функцию *SendSms*.
3. Класс *EmailNotifier*, который;
* является потомком класса *INotifier*;
* в конструкторе принимает один параметр типа string — адрес электронной почты;
* переопределяет метод *Notify* и вызывает из него функцию *SendEmail*.
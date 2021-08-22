#include <iostream>
#include <string>

using namespace std;

#include "phone_number.h"

PhoneNumber::PhoneNumber(const string &international_number) {
      if (international_number[0] != '+') {
        throw invalid_argument(international_number);
      }
      int i = 1;
      if (international_number[i] == '-') {
          throw invalid_argument(international_number);
      }
      while (international_number[i] != '-') {
          if (i == international_number.size()) {
              throw invalid_argument(international_number);
          }
          country_code_ += international_number[i];
          i++;
      }
      i++;
      if (international_number[i] == '-') {
          throw invalid_argument(international_number);
      }
      while (international_number[i] != '-') {
          if (i == international_number.size()) {
              throw invalid_argument(international_number);
          }
          city_code_ += international_number[i];
          i++;
      }
      i++;
      if(i == international_number.size() - 1) {
          throw invalid_argument(international_number);
      }
      while (i != international_number.size()) {
          local_number_ += international_number[i];
          i++;
      }
};

string PhoneNumber::GetCountryCode() const {
      return country_code_;
  };

string PhoneNumber::GetCityCode() const {
      return city_code_;
};

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
};

string PhoneNumber::GetInternationalNumber() const {
      return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
  };


  /* Принимает строку в формате +XXX-YYY-ZZZZZZ
     Часть от '+' до первого '-' - это код страны.
     Часть между первым и вторым символами '-' - код города
     Всё, что идёт после второго символа '-' - местный номер.
     Код страны, код города и местный номер не должны быть пустыми.
     Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

     Примеры:
     * +7-495-111-22-33
     * +7-495-1112233
     * +323-22-460002
     * +1-2-coursera-cpp
     * 1-2-333 - некорректный номер - не начинается на '+'
     * +7-1233 - некорректный номер - есть только код страны и города
  */

/*int main() {
    PhoneNumber r("+-");
    cout << r.GetCountryCode() << "||" << r.GetCityCode() << "||" << r.GetLocalNumber() << "||" << r.GetInternationalNumber() << endl;
    return 0;
}
*/
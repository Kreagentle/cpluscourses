#include <iostream>
#include <set>
#include <map>
#include <algorithm> 
#include <exception> 

using namespace std;

class Date {
public:
  Date (int y, int m, int d) {
    year = y;
    month = m;
    day = d;
  };

  int GetYear() const {
    return year;
  };
  int GetMonth() const {
    return month;
  };
  int GetDay() const {
    return day;
  };

private: 
  int year;
  int month;
  int day;
};

void Convert(string &st, int size) {
  while (st.size() != size) {
    st = '0' + st;
  }
}

bool operator<(const Date& lhs, const Date& rhs) {
  if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() < rhs.GetDay()
  || lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() < rhs.GetMonth()
  || lhs.GetYear() < rhs.GetYear()) {
      return true;
    }
    return false;
};

bool operator==(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay()) {
      return true;
    }
    return false;
};

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
      mp[date].insert(event);
  };

  bool DeleteEvent(const Date& date, const string& event) {
    int j = 0;
    bool temp = false;
    for (string i : mp[date]) {
      if (i == event) {
        j++;
        temp = true;
        break;
      }
    } 
    if (temp)
      mp[date].erase(mp[date].find(event));
    if(mp[date].size() == 0) 
      mp.erase(date);
    return temp;
  };

  int DeleteDate(const Date& date) {
    if (mp.count(date) > 0) {
      int size = mp.at(date).size();
      mp.at(date).clear();
      mp.erase(date);
      return size;
    } else {
      return 0;
    }
  };

  void Find(const Date& date) const {
    for (auto [key, value]:mp) {
    if (key == date) {
      for (auto i:value) {
        cout << i << endl;
      }
    }
    }
  };
  
  void Print() const {
    for (auto [key, value]:mp) {
      string year = to_string(key.GetYear()), month = to_string(key.GetMonth()), day = to_string(key.GetDay());
      Convert(year, 4);
      Convert(month, 2);
      Convert(day, 2);
      for (auto i:value) {
        cout << year << "-" << month << "-" << day << " ";
        cout << i << endl;
      }
    }
  };

private:
  map<Date, set<string>> mp;
};

int ChangeStr(const string command, string& str, int i, char c) {
  if (c == ' ') {
    while (command[i] != c) {
      str += command[i];
      i++;
    }
    i++;
  } else {
    if (command[i] == c) {
      str += command[i];
      i++;
    }
    while (command[i] != c) {
      if (command[i] != '+') {
        str += command[i];
      }
      i++;
    }
    i++;
  }
    return i;
}

void ChangeStrEnd(const string command, string& str, int i) {
    while (i != command.size()) {
        str += command[i];
        i++;
    }
}

void Dates(string data, string &year, string &month, string &day) {
  int j = 0;
  if (data[data.size() - 1] < 0x30 || data[data.size() - 1] > 0x39) 
    throw logic_error("Wrong date format: " + data);
  j = ChangeStr(data, year, j, '-');
  for (auto x:year) {
    if (x < 0x30 || x > 0x39) {
      throw logic_error("Wrong date format: " + data);
    }
  }
  j = ChangeStr(data, month, j, '-');
  for (auto x:month) {
    if (x < 0x30 || x > 0x39) {
      if (x == '-' || x == '+') break;
      throw logic_error("Month value is invalid: " + month);
    }
  }
  if (stoi(month) > 12 || stoi(month) < 1)
      throw logic_error("Month value is invalid: " + month);
  ChangeStrEnd(data, day, j); 
  for (auto x:day) {
    if (day.size() == 0 || x < 0x30 || x > 0x39) {
      if (x == '-' || x == '+') break;
      throw logic_error("Day value is invalid: " + day);
    }
  }
  if (stoi(day) > 31 || stoi(day) < 1) 
    throw logic_error("Day value is invalid: " + day);
}

int main() {
  Database db;

  string command;
  while (getline(cin, command)) {
    try {
    if (command != "") {
    string year = "", month = "", day = "";
    string strok = "", data = "", event = "";

    int i = 0;
    if (count(command.begin(), command.end(), ' ') == 0) {
        ChangeStrEnd(command, strok, i); 
    } else if (count(command.begin(), command.end(), ' ') > 2) {
        int s = ChangeStr(command, strok, i, ' '); 
        while(!isalpha(command[s+1])) {
          data += command[s];
          s++;
        }
        throw logic_error("Wrong date format: " + data);
    } else if (count(command.begin(), command.end(), ' ') == 2) {
        i = ChangeStr(command, strok, i, ' ');
        i = ChangeStr(command, data, i, ' ');
        if ((data.find("---") != std::string::npos || count(data.begin(), data.end(), '-') < 2) && data.size() != 0) 
            throw logic_error("Wrong date format: " + data);
        ChangeStrEnd(command, event, i); 
        Dates(data, year, month, day);
    } else if (count(command.begin(), command.end(), ' ') == 1) {
        i = ChangeStr(command, strok, i, ' ');
        ChangeStrEnd(command, data, i); 
        if ((data.find("---") != std::string::npos || count(data.begin(), data.end(), '-') < 2) && data.size() != 0) 
          throw logic_error("Wrong date format: " + data);
        Dates(data, year, month, day);
    } 


    if (strok != "Add" && strok != "Del" && strok != "Find" && strok != "Print")
      throw logic_error("Unknown command: " + strok);

    if (strok == "Add") {
      if (data.size() == 0)
        throw logic_error("Wrong date format: " + data);
      Date dt = {stoi(year), stoi(month), stoi(day)};
      db.AddEvent(dt, event);
    } else if (strok == "Del") {
      Date dt = {stoi(year), stoi(month), stoi(day)};
      if (event != "") {
        if (db.DeleteEvent(dt, event)) {
            cout << "Deleted successfully" << endl;
        } else {
            cout << "Event not found" << endl;
        }
      } else {
        cout << "Deleted " << db.DeleteDate(dt) << " events" << endl;
      }
    } else if (strok == "Find") {
      Date dt = {stoi(year), stoi(month), stoi(day)};
      db.Find(dt);
    } else if (strok == "Print") {
      db.Print();
    }
  }
    } catch(exception& ex) {
      cout << ex.what() << endl;
      break;
    }
  }

  // system("pause");
  return 0;
}
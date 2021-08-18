#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  string s;
  is >> s;
  if (s == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;
    int sc = 0;
    is >> sc;
    q.stops.resize(sc);
    for (auto& stop : q.stops) {
      is >> stop;
    }
  } else if (s == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (s == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if (s == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }

  return is;
}

struct BusesForStopResponse {
    string stop;
    map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    map<string, vector<string>> temp = r.stops_to_buses;
    if (temp.count(r.stop) == 0) {
        os << "No stop" << endl;
      } else {
        for (const string& bus : temp[r.stop]) {
          os << bus << " ";
        }
        os << endl;
      }
  return os;
}

struct StopsForBusResponse {
  string bus;
  vector<pair<string, vector<string>>> stops_for_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if (r.stops_for_buses.empty()) {
    os << "No bus" << endl;
  } else {
    for (const auto& stop_and_buses : r.stops_for_buses) {
      os << "Stop " << stop_and_buses.first << ":";
      if (stop_and_buses.second.size() == 1) {
        os << " no interchange" << endl;
      } else {
        for (const auto& bus : stop_and_buses.second) {
          if (bus != r.bus) {
            os << " " << bus;
          }
        }
        os << endl;
      }
    }
  }
  return os;
}

struct AllBusesResponse {
  map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  map<string, vector<string>> bts = r.buses_to_stops;
    if (bts.empty()) {
        os << "No buses" << endl;
      } else {
        for (const auto& bus_item : bts) {
          os << "Bus " << bus_item.first << ": ";
          for (const string& stop : bus_item.second) {
            os << stop << " ";
          }
          os << endl;
        }
      }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus] = stops;
    for (const auto& stop : stops) {
      stops_to_buses[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      return {stop, stops_to_buses};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    vector<pair<string, vector<string>>> res;

    if (buses_to_stops.count(bus) > 0) {
      for (const auto& stop : buses_to_stops.at(bus)) {
        res.push_back({stop, stops_to_buses.at(stop)});
      }
    }
    return StopsForBusResponse{bus, res};
  }

  AllBusesResponse GetAllBuses() const {
    return {buses_to_stops};
  }

private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
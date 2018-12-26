#include "bus.h"




// overload opertor`s for users struct`s

ostream& operator << (ostream& os, const BusesForStopResponse& r) {

    if (r.buses.empty()) {
    os << "No stop" << endl;
  } else {
    for (const auto& bus : r.buses) {
      os<<" "<<"Bus #" <<bus.first<<"time: ";
      for(const auto& tim:bus.second)
      {
          os<<"/ "<<tim<<" /,";

      }
      os<<"_________"<<"\n";
      os<<"\n";
    }

    os << endl;
  }
  return os;

}



ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stops_for_buses.empty()) {
    os << "No bus" << endl;
  } else {
    for (const auto& stop_and_buses : r.stops_for_buses) {
      os << "Stop " << stop_and_buses.first  << ":";
      if (stop_and_buses.second.size() == 1) {
        os << " Без пересадки " << endl;
      } else {
        for (const auto& bus : stop_and_buses.second) {
          if (bus.first != r.bus) {
            os << " " << bus.first;
          }
        }
        os << endl;
      }
    }
  }
  return os;


}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if (r.buses_to_stops.empty()) {
    os << "No buses" << endl;
  } else {
    for (const auto& bus_and_stops : r.buses_to_stops) {
      os << "Bus " << bus_and_stops.first << ":";
      for (const auto& stop : bus_and_stops.second) {
        os << " " << stop.first;
      }
      os << endl;
    }
  }
  return os;
}

#pragma once
#include "bus.h"
#include <iterator>
#include <fstream>
#include <utility>
#ifndef BUS_MANAGER_H
#define BUS_MANAGER_H





class BusManager {
public:
    BusManager(ifstream& file);

 void AddBus(const string& bus, const vector<pair<string,vector<string>>>& stops);//this method add track and bus
 void AddB(ifstream& list);
  BusesForStopResponse GetBusesForStop(const string& stop) const ;//this method given bus`s for stop

  StopsForBusResponse GetStopsForBus(const string& bus) const ;//this method given stops for bus

  AllBusesResponse GetAllBuses() const ;//this methid given all bus

 //void Delete(string& buss,string& sto);//this function remove track


private:
   map<string, vector<pair<string,vector<string>>>> buses_to_stops;//vocabulary bus and his stops
    map<string, vector<pair<string,vector<string>>>> stops_to_buses;//vocabulary stop and his bus`s
};

#endif // BUS_MANAGER_H

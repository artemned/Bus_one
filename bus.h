#pragma once
#include<iostream>
#include<cassert>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct Query {

  string bus;
  string stop;
  string time;
  vector<string> time_bus;
  vector<pair<string,vector<string>>> stops;//hear will be stops and his time
};

struct BusesForStopResponse {
    vector<pair<string,vector<string>>> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) ;

struct StopsForBusResponse {

      string bus;
   vector<pair<string, vector<pair<string,vector<string>>>>> stops_for_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);


struct AllBusesResponse {
  map<string,vector<pair<string,vector<string>>>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) ;




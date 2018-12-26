#include "bus_manager.h"
#include <QtDebug>
#include <QString>




static size_t s=0;
static size_t si=0;

 BusManager::BusManager(ifstream& file )
 {
     this->AddB(file);

 }

void BusManager::AddBus(const string& bus, const vector<pair<string,vector<string>>>& stops) {


    /*

        ADDDDD!
                                                         */


    if(bus!="")
    {


    auto it_s=stops[0].first;//остановка
vector<pair<string,vector<string>>> buses;//bus and time
buses.push_back({bus,{stops[0].second}});
  //поиск нашего автобуса и его айди

static map<string,size_t> maps_unic;//словарь для хран автобуса и его айди
static map<string,size_t> maps_unic_one;


if(maps_unic_one.count(it_s))

{
   const auto G=maps_unic_one.find(it_s);

    if(buses_to_stops.count(bus)&&buses_to_stops.at(bus)[G->second].first!=it_s)
    {
           bool flag=false;
        for(auto& d:buses_to_stops.at(bus))
        {
            if(d.first==it_s)
           {  flag=true;
              for(auto& adds:stops[0].second)
                {
                       d.second.push_back(adds);
                }

            }

         }
        if(!flag){

          buses_to_stops.at(bus).push_back({it_s,{stops[0].second}});
         }

    }


    //qDebug()<< QString::fromStdString(buses_to_stops.at(bus)[G->second].first);
    // qDebug()<< QString::fromStdString(it_s);

    if(buses_to_stops.count(bus) && buses_to_stops.at(bus)[G->second].first==it_s)//если есть остановка и автобус
    {
       for(auto& tm:stops[0].second)
      {

         buses_to_stops.at(bus)[G->second].second.push_back(tm);

      }

     sort( buses_to_stops.at(bus)[G->second].second.begin(),//сортировка вектора который в паре//что бы не было повторов
      buses_to_stops.at(bus)[G->second].second.begin());

     buses_to_stops.at(bus)[G->second].second.erase(unique( buses_to_stops.at(bus)[G->second].second.begin(),
      buses_to_stops.at(bus)[G->second].second.end()), buses_to_stops.at(bus)[G->second].second.end());

    }
    if(!buses_to_stops.count(bus))
    {


        buses_to_stops[bus]=stops;


    }


 }

if(!buses_to_stops.count(bus))
   {
       buses_to_stops.insert(make_pair(bus,stops));
       maps_unic_one[it_s]=s;
        s++;
   }

if(buses_to_stops.count(bus)&&(!maps_unic_one.count(it_s)))
{
    buses_to_stops.at(bus).push_back({it_s,{stops[0].second}});
    maps_unic_one[it_s]=s;
    s++;

}


///////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////
  if(maps_unic.count(bus))
{

 auto F=maps_unic.find(bus);
 if(stops_to_buses.count(it_s) && stops_to_buses.at(it_s)[F->second].first!=bus)
 {

     bool flag=false;
  for(auto& d:stops_to_buses.at(it_s))
  {
      if(d.first==bus)
     {  flag=true;
        for(auto& adds:stops[0].second)
          {
                 d.second.push_back(adds);
          }

      }

   }
  if(!flag){

    stops_to_buses.at(it_s).push_back({bus,{stops[0].second}});
   }

 }

 if(stops_to_buses.count(it_s) && stops_to_buses.at(it_s)[F->second].first==bus)//если есть остановка и автобус
 {
    for(auto& t:stops[0].second)
   {

      stops_to_buses.at(it_s)[F->second].second.push_back(t);

   }

  sort( stops_to_buses.at(it_s)[F->second].second.begin(),//сортировка вектора который в паре//что бы не было повторов
   stops_to_buses.at(it_s)[F->second].second.begin());

  stops_to_buses.at(it_s)[F->second].second.erase(unique( stops_to_buses.at(it_s)[F->second].second.begin(),
   stops_to_buses.at(it_s)[F->second].second.end()), stops_to_buses.at(it_s)[F->second].second.end());

 }

 if(!stops_to_buses.count(it_s))
 {


     stops_to_buses[it_s]=buses;


 }


}/////////////////

   if(!stops_to_buses.count(it_s))
      {
         stops_to_buses.insert(make_pair(it_s,buses));
           maps_unic[bus]=si;
           si++;
      }


    if(stops_to_buses.count(it_s)&& (!maps_unic.count(bus)))
   {

       stops_to_buses.at(it_s).push_back({bus,{stops[0].second}});
       maps_unic[bus]=si;
       si++;

   }
///////////////////////////////////////////

buses.clear();

  }//bus!=0;
}
void BusManager::AddB(ifstream& list){


    if(list){
        string bus="";
        string stop="";
        string time="";

       while(!list.eof()){

      vector<string> times;
      vector<pair<string,vector<string>>> pa;
      times.clear();
       pa.clear();
       list>>ws>>bus;
       list>>stop;
      std::getline(list,time);
       times.push_back(std::move(time));
      pa.push_back({std::move(stop),std::move(times)});//если что поменять на тайм
       AddBus(std::move(bus),pa);
       bus="";
       times.clear();
        pa.clear();
       }

}

}

BusesForStopResponse BusManager:: GetBusesForStop(const string& stop) const {
    if (stops_to_buses.count(stop) == 0) {
      return BusesForStopResponse{vector<pair<string,vector<string>>>()};
    } else {
      return BusesForStopResponse{stops_to_buses.at(stop)};
    }
  }

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
     vector<pair<string,vector<pair<string,vector<string>>>>>result;
     for(const auto& lc:buses_to_stops)
     {
         qDebug()<<QString::fromStdString(lc.first);
     }
    if (buses_to_stops.count(bus)>0) {
      for (const auto& stop : buses_to_stops.at(bus)) {
         result.push_back(make_pair(stop.first,stops_to_buses.at(stop.first)));
      }
    }
    return StopsForBusResponse{bus, result};
  }

  AllBusesResponse BusManager:: GetAllBuses() const {
    return AllBusesResponse{buses_to_stops};
  }


/*
void BusManager::Delete(string& buss,string& sto)//this function remove track
  {

     auto it = stops_to_buses.find(sto);
     if(it!=stops_to_buses.end())
     {

         if(count(it->second.begin(),it->second.end(),buss))
         {
              const auto new_end=(remove(begin(it->second),end(it->second),buss));
              it->second.erase(new_end,end(it->second));
              it->second.shrink_to_fit();//doing to size

         }

     }
     auto it_two =buses_to_stops.find(buss);
     if(it_two!=buses_to_stops.end())
     {

         if(count(it_two->second.begin(),it_two->second.end(),sto))
         {
             const auto new_end=(remove(begin(it_two->second),end(it_two->second),sto));
             it_two->second.erase(new_end,end(it_two->second));
             it_two->second.shrink_to_fit();

         }

     }

}
*/

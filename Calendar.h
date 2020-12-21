#pragma once
#include <queue>
#include"Event.h"
struct Compare: public std::binary_function<Event*,Event*,bool> // struktura z operatorem sortujacym zdarzenia
{
  bool operator()(const Event* first,const Event* second) const;
};
class Calendar
{
public:
  Calendar()=default;
  void PlanningNewEvent(Event* newEvent); // dodaje nowe zdarzenie do kalendarza
  void CancelEvent(); // usuwa zdarzenie
  bool Empty();  // czy pusty kalendarz
  int size() const;
  Event* EventHandling(); // zdejmuje z kalendarza zdarzenie (obs³uga)
  ~Calendar()=default;
private:
  std::priority_queue<Event*, std::vector<Event*>, Compare> schedule;  // FIFO kolejka prioryretowa z komparatorem sortujacym rosnaco 
};
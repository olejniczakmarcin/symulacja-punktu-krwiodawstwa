#include <iostream>
#include "Calendar.h"
bool Compare::operator()(const Event* first,const Event* second) const
{
  if (first != nullptr && second != nullptr)
  {
    if (first->time() > second->time()) return true;
    if (first->time() < second->time()) return false;
    return false;
  }
}
int Calendar::size() const
{
  return schedule.size();
}
void Calendar::PlanningNewEvent(Event* _new) // dodajemy nowe zdarzenie
{
  schedule.push(_new);
}
void Calendar::CancelEvent() // usuwamy zdarzenie
{
  schedule.pop();
}
bool Calendar::Empty() // sprawdzamy czy brak zdarzen
{
  return schedule.empty();
}
Event* Calendar::EventHandling() // zdejmuje z kopca element z wkaznikiem na niego
{
  return schedule.top();
}
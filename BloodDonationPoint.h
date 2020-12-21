#pragma once
#include <queue>
#include "Monitor.h"
#include "Recipient.h"
#include "Generator.h"
#include "Calendar.h"
class Calendar;
class BloodDonationPoint
{
public:
  BloodDonationPoint();
  BloodDonationPoint(int seed,Calendar* calendar);
  ~BloodDonationPoint();
  Monitor *monitor; // wskaznik na obiekt monitor
  std::queue<Recipient*> queue_recipient;  // kolejka biorcow
  Generator* generate_random_;
  Calendar* planning;
  void Set_total_order(double i);
  double Total_order();
  void Set_emergency_order(double i);
  double Emergeny_order();
  double total_order;
  double emergency_order;
  double simulation_time_;
  bool mode_promotion_;
  int seed_;
  int liczba_pacjentow;
  bool during_order_; // zamowienie czy w trakcie nie wolno zamawiac kolejnego
};
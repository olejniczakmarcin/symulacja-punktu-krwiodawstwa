#pragma once
#include "Calendar.h"
#include "Utilization.h"
class BloodTransport : public Event
{
public: 
  BloodTransport(double time, int order,bool type_order,int r,int n);
  ~BloodTransport()=default;
  Event* execute( BloodDonationPoint *order,bool step_mode_);
  int unit_order_; // ilosc zamowionych jednostek
private:
  double e_time_;
  bool type_order_;
  int T1 = 300;
  double Z = 2000; //  czas zamowienia do odbioru tryb normalny
  double E = 600; // czas od wyslania do ofbioru awaryjny
  double EW = 0.1; // wariancja do zamowienia awaryjnego
  int Q = 12; // liczba awaryjnie zamawianych jednostek krwi;
  int R_; // liczba normalnie zamawianych jednostek
  int N_;
};
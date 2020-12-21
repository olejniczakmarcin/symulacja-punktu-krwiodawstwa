#pragma once
#include<list>
#include"BloodUnit.h"
class Monitor
{
public:
  Monitor();
  ~Monitor()=default;
  std::list<BloodUnit*> blood_unit; // wskanik na liste jednostek krwi
  int SetUtilizationUnit(int unit);
  int UtilizationUnit();
  int TotalUnitBlood();
  int SetTotalUnitBlood(int unit);
  BloodUnit* ReturnFirstUnit();
private:
  int total_unit_blood_;
  int utilization_blood_unit_;  // do wyliczenia ile procent krwi zutylizowano
  int current_status_; // aktualny stan krwi
  const int R = 20; // poziom przy ktorym zamawiamy N jednostek krwi
  const int N = 17; // zmienna odpowiadajaca za zamowienie odpowiedniej ilsoci krwi
};

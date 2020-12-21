#pragma once
#include "Generator.h"
#include "Utilization.h"
class NewDonor : public Event
{
public:
  NewDonor(double time, BloodUnit* newUnit,int r,int n);
  ~NewDonor();
  Event* execute(BloodDonationPoint* stan,bool step_mode_);
  bool Devotion;
  BloodUnit* him; // wskaznik na oddana jednostke krwi
private:
  double e_time_;
  double T2 = 500;
  int L = 800;
  int R_;
  int N_;
};
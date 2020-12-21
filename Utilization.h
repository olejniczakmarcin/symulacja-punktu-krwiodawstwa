#pragma once
#include "Calendar.h"
#include "NewRecipient.h"
#include "NewDonor.h"
class Utilization: public Event
{
public:
  Utilization(double time,int r,int n);
  ~Utilization()=default;
  Event* execute(BloodDonationPoint *delet,bool step_mode_);
private:
  double e_time_;
  int R_;
  int N_;
  double P = 300;
  double W = 0.19;
  double Z = 2000;
};
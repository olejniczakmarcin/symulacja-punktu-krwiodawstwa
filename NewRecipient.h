#pragma once
#include "Calendar.h"
#include "Generator.h"
#include "BloodTransport.h"
class NewRecipient:public Event
{
public:
  NewRecipient(double time,int blood_neded, int r,int n);
  ~NewRecipient() = default;
  Event* execute(BloodDonationPoint *point,bool step_mode_);
private:
  int R_;
  int N_;
  int blood_neded_;
  double e_time_;
  double P = 300;
  double W = 0.19;
  double EW = 0.1;
  double E = 600;
  int Q = 12;
  double Z = 2000;
};
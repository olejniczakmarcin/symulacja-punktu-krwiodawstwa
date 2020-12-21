#pragma once
#include "BloodDonationPoint.h"
class BloodDonationPoint;
class Event
{
public:
  Event(double time) :time_(time){}
  double time() const { return time_; } 
  virtual Event* execute(BloodDonationPoint * akt,bool step_mode_) = 0;
  double time_;
};
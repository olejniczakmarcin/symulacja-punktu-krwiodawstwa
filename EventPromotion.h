#pragma once
#include "Calendar.h"
#include "EndEventPromotion.h"
class EventPromotion :public Event
{
public:
  EventPromotion(double time);
  ~EventPromotion() = default;
  Event* execute(BloodDonationPoint *advent,bool step_mode_);
private:
  double e_time_;
  int TT = 7200;
};
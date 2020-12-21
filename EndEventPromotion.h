#pragma once
#include"EventPromotion.h"
#include "Calendar.h"
class EndEventPromotion:public Event
{
  public:
    EndEventPromotion(double time);
    ~EndEventPromotion() = default;
    Event* execute(BloodDonationPoint* point,bool step_mode_);
private:
  double e_time_;
};
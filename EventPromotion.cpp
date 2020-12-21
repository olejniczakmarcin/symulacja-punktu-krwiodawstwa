#include "EventPromotion.h"
#include <iostream>
EventPromotion::EventPromotion(double time) :Event(time), e_time_(time) {}
Event* EventPromotion::execute(BloodDonationPoint* point,bool step_mode_)
{
  point->mode_promotion_ = true;
  if (step_mode_)
  {
    std::cout << "Rozpoczaecie akcji promocyjnej czas rozpoczecia : " << time_ << std::endl;
    system("PAUSE");
  }
  return new EndEventPromotion(e_time_ + TT);
}
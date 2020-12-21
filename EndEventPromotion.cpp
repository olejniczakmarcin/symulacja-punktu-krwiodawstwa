#include "EndEventPromotion.h"
#include <iostream>
EndEventPromotion::EndEventPromotion(double time) :Event(time),e_time_(time){}
Event* EndEventPromotion::execute(BloodDonationPoint* point,bool step_mode_)
{
  point->mode_promotion_ = false;
  if (step_mode_)
  {
    std::cout << "Zakonczenie akcji promocyjnej: " << e_time_ << std::endl;
    system("PAUSE");
  }
  return new EventPromotion(e_time_ + point->generate_random_->UniformDistribution(20000.0, 22000.0));
}
#include <iostream>
#include "BloodTransport.h"
BloodTransport::BloodTransport(double time,int order,bool type_order,int r,int n): Event(time),unit_order_(order),type_order_(type_order_),e_time_(time),R_(r),N_(n){}
Event* BloodTransport::execute(BloodDonationPoint* point,bool step_mode_)
{
  if (type_order_==true)
  {
    int order_time = point->generate_random_->NormalDistributions(E, EW);
    point->Set_total_order(1);
    point->Set_emergency_order(1);
    if (step_mode_)
    {
      std::cout << "Zaplanowano zamowienie w trybie AWARYJNYM czas dostawy potrwa: " << order_time << std::endl;
      system("PAUSE");
    }
    BloodUnit* new_units = new BloodUnit(e_time_ + order_time, new Utilization(e_time_ + order_time + T1,R_,N_));
    for (int i = 0;i < unit_order_;i++)
    {
      point->monitor->blood_unit.push_back(new_units);
      point->monitor->SetTotalUnitBlood(1);
    }
    return new_units->utilize_blood_; 
  }
  else
  {
    int order_time = point->generate_random_->ExponentialDistributions(Z);
    point->Set_total_order(1);
    if (step_mode_)
    {
      std::cout << "Zaplanowano zamowienie w trybie NORMALNYM czas dostawy: " << order_time << std::endl;
      system("PAUSE");
    }
    BloodUnit* new_units = new BloodUnit(e_time_ + order_time+T1, new Utilization(e_time_ + order_time + T1,R_,N_));
    for (int i = 0;i < unit_order_;i++)
    {
      point->monitor->blood_unit.push_back(new_units);
      point->monitor->SetTotalUnitBlood(1);
    }
    return new_units->utilize_blood_;
  }
}
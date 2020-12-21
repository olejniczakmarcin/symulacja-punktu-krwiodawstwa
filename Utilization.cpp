#include <iostream>
#include "Utilization.h"
Utilization::Utilization(double time,int r,int n): Event(time),e_time_(time),R_(r),N_(n){}
Event* Utilization::execute(BloodDonationPoint * point,bool step_mode_)
{
  if (point->monitor->blood_unit.empty()!=true)
  {
    point->monitor->SetUtilizationUnit(1);
    point->monitor->blood_unit.pop_front();
    if (step_mode_)
    {
      std::cout << "Usunieto jenostke krwi z powodu przekroczenia jej czasu przydatnosi czas usuniecia to: " << point->simulation_time_ << std::endl;
      system("PAUSE");
    }
    int blood_neded_ = point->generate_random_->GeometricalDistributions(1 / W);
    return new NewRecipient(e_time_ + point->generate_random_->ExponentialDistributions(P), blood_neded_, R_, N_);
  }
  else
  {
    int time_normal_order = point->generate_random_->ExponentialDistributions(Z);
    return new BloodTransport(e_time_ + time_normal_order, N_, false, R_, N_);
  }
}
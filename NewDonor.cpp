#include <iostream>
#include "NewDonor.h"
NewDonor::NewDonor(double time, BloodUnit* newUnit,int r,int n) :Event(time), him(newUnit), e_time_(time),R_(r),N_(n) {}
Event* NewDonor::execute(BloodDonationPoint *point,bool step_mode_)
{
  BloodUnit* unit = new BloodUnit(e_time_+ T2, new Utilization(e_time_ + T2,R_,N_));
  point->monitor->blood_unit.push_back(unit);
  point->monitor->SetTotalUnitBlood(1);
  point->planning->PlanningNewEvent(unit->utilize_blood_);
  if (step_mode_)
  {
    std::cout << "Pojawienie sie nowego dawcy czas pojawienia: " << e_time_ << std::endl;
    system("PAUSE");
  }
  return new NewDonor(e_time_+ point->generate_random_->ExponentialDistributions(L), new BloodUnit(e_time_+ point->generate_random_->ExponentialDistributions(L)+ T2, new Utilization(e_time_ + point->generate_random_->ExponentialDistributions(L)+ T2,R_,N_)),R_,N_);
}
NewDonor::~NewDonor()
{
  him = nullptr;
  delete him;
}
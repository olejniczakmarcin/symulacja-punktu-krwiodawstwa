#include <iostream>
#include "NewRecipient.h"
NewRecipient::NewRecipient(double time,int blood_needed,int r,int n) :Event(time),e_time_(time),blood_neded_(blood_needed),R_(r),N_(n) { }

Event* NewRecipient::execute(BloodDonationPoint * point,bool step_mode_)
{
  if (point->monitor->blood_unit.size() < R_)
  {
    if (point->monitor->blood_unit.size() < blood_neded_)
    {
      int order_time = point->generate_random_->NormalDistributions(E, EW);
      point->during_order_ = true;
      return new BloodTransport(e_time_ + order_time, Q, true,R_,N_);
    }
    else
    {
      int time_normal_order = point->generate_random_->ExponentialDistributions(Z);
      return new BloodTransport(e_time_ + time_normal_order, N_, false,R_,N_);
    }
  }
  else
  {
    if (point->monitor->blood_unit.size() > blood_neded_)
    {
      point->queue_recipient.push(new Recipient(e_time_, blood_neded_));
      Recipient *tmp = point->queue_recipient.front();
      for (int i = 0;i < blood_neded_;i++)
      {
        point->monitor->blood_unit.pop_front();
      }
      point->liczba_pacjentow++;
      point->queue_recipient.pop();
      delete tmp;
      if (step_mode_)
      {
        std::cout << "zdarzenie nowy biorca pojawil sie  : " << e_time_ << std::endl;
        system("PAUSE");
      }
      return new NewRecipient(e_time_ + point->generate_random_->ExponentialDistributions(P), blood_neded_, R_, N_);
    }
    else
    {
      int order_time = point->generate_random_->NormalDistributions(E, EW);
      point->during_order_ = true;
      return new BloodTransport(e_time_ + order_time, Q, true, R_, N_);
    }
  }
}
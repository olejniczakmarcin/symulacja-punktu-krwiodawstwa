#include <iostream>
#include "BloodDonationPoint.h"
#include <queue>
BloodDonationPoint::BloodDonationPoint()
{
  monitor = new Monitor;
  simulation_time_ = 0;
  generate_random_ = new Generator(seed_);
  mode_promotion_ = false;
  total_order = 0;
  emergency_order = 0;
}
BloodDonationPoint::BloodDonationPoint(int seed, Calendar* calendar):seed_(seed)
{
  monitor = new Monitor;
  simulation_time_ = 0;
  generate_random_ = new Generator(seed_);
  mode_promotion_ = false;
  planning = calendar;
  total_order = 0;
  emergency_order = 0;
}
BloodDonationPoint::~BloodDonationPoint()
{
  monitor = nullptr;
  generate_random_ = nullptr;
  planning = nullptr;
  delete planning;
  delete monitor;
  delete generate_random_;
}
void BloodDonationPoint::Set_total_order(double i)
{
  total_order += i;
}
double BloodDonationPoint::Total_order()
{
  return total_order;
}
void BloodDonationPoint::Set_emergency_order(double i)
{
  emergency_order += i;
}
double BloodDonationPoint::Emergeny_order()
{
  return emergency_order;
}
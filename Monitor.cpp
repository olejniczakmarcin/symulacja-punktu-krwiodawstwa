#include <iostream>
#include "Monitor.h"
#include <list>
Monitor::Monitor()
{
  utilization_blood_unit_ = 0;
  total_unit_blood_ = 0;
  std::cout << " Uruchomiono monitor jednostek krwi" << std::endl;  
}
int Monitor::UtilizationUnit()
{
  return utilization_blood_unit_;
}
int Monitor::TotalUnitBlood()
{
  return total_unit_blood_;
}
int Monitor::SetTotalUnitBlood(int unit)
{
  return total_unit_blood_ += unit;
}
int Monitor::SetUtilizationUnit(int unit)
{
  return utilization_blood_unit_ += unit;
}
BloodUnit* Monitor::ReturnFirstUnit()
{
  return blood_unit.front();  // return reference of 1 unit blood
}
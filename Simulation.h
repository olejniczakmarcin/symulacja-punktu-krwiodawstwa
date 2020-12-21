#pragma once
#include"BloodDonationPoint.h"
#include"NewDonor.h"
#include "NewRecipient.h"
#include "Generator.h"
#include"EventPromotion.h"
#include "BloodTransport.h"
class Simulation
{
public:
  Simulation(bool mode, int number);
  void Run();
  ~Simulation() = default;
private:
  bool step_mode_;
  int number_of_simulation;
};
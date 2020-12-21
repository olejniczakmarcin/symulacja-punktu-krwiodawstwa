#include <iostream>
#include "Simulation.h"
int main()
{
  char Sign;
  bool StepMode;
  int NumberOfSimulation;
  std::cout << "Run simulations in step mode ? y/n : ";
  std::cin >> Sign;
  if (Sign == 'y' || Sign == 'Y') StepMode = true;
  else StepMode = false;
  std::cout << "Enter the number of simulations : ";
  std::cin >> NumberOfSimulation;
  if(NumberOfSimulation > 10)
  {
    std::cout << "Too much simulation. Max 12";
    NumberOfSimulation = 12;
  }
  Simulation*simul = new Simulation(StepMode, NumberOfSimulation);
  simul->Run();
  simul = nullptr;
  delete simul;
  system("PAUSE");
  return 0;
}
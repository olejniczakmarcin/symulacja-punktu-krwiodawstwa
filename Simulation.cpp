#include <iostream>
#include "Simulation.h"
using namespace std;
int R;
int N;
int recipient_max_;
int seed;
int T2 = 500;
double P = 300;
double W = 0.19;
double L = 800; 
double A = 0.08;
Simulation::Simulation(bool mode, int number)
{
  step_mode_ = mode;
  number_of_simulation = number;
}
void Simulation::Run()
{
  cout << "Wpisz liczbe jednostek krwi ponizej ktorej zostaje zlozone zamowienie normalne: " << endl;
  cin >> R;
  cout << "Rozmiar zamowienia zwyklego: " << endl;
  cin >> N;
  cout << "Wpisz liczbe pacjentow po ktorej symulacja sie zakonczy: " << endl;
  cin >> recipient_max_;
  cout << "Wprowadz ziarno" << endl;
  cin >> seed;

  Calendar *schedule = new Calendar;
  Generator* new_generate_ = new Generator(seed);
  BloodDonationPoint *point = new BloodDonationPoint(seed, schedule);

  Event* actual = nullptr;
  Event* neww = nullptr;

  int blood_neded_ = point->generate_random_->GeometricalDistributions(1 / W);
  schedule->PlanningNewEvent(new NewDonor(point->simulation_time_ + point->generate_random_->ExponentialDistributions(L), new BloodUnit(point->simulation_time_ + T2, new Utilization(point->simulation_time_ + T2,R,N)),R,N));
  schedule->PlanningNewEvent(new NewRecipient(point->simulation_time_ + point->generate_random_->ExponentialDistributions(P), blood_neded_,R,N));
  schedule->PlanningNewEvent(new EventPromotion(point->simulation_time_ + point->generate_random_->UniformDistribution(20000.0, 22000.0)));
  while (point->liczba_pacjentow<recipient_max_)
  {
    cout << point->simulation_time_ << endl;
    actual = schedule->EventHandling();
    point->simulation_time_ = actual->time_;
    neww = actual->execute(point, step_mode_);
    schedule->CancelEvent();
    schedule->PlanningNewEvent(neww);
  }
  std::cout << "ilosc zniczonej krwi w trakcie symulacji wyrazona w procentach: " << (100.0 * point->monitor->UtilizationUnit()) / point->monitor->TotalUnitBlood() << "%" << endl;
  std::cout << "stosunek awaryjnych zamowien do calkowitej liczby zamawainej krwi " << double((100.0 * double(point->Emergeny_order()) / double((point->Total_order() + point->Emergeny_order())))) << std::endl;
  delete schedule, point, new_generate_, actual, neww;
  schedule = nullptr;
  point = nullptr;
  new_generate_ = nullptr;
  actual = nullptr;
  neww = nullptr;
}
#include"Generator.h"
#include <math.h>
#include "iostream"
#include <fstream>
using namespace std;
Generator::Generator(double seed) :seed_(seed) {}
double Generator::UniformDistribution(int down, int up) // rownomierny
{ 
  double x = seed_;  
  int h = int(seed_ / Q1);
  x = A1 * (x - Q1 * h) - R1 * h;
  if (x < 0) x += M;
  seed_ = x;
  return (x / M) * (up - down) + down;
}
double Generator::ExponentialDistributions(double lambda)
{
  return -log(UniformDistribution(0, 1))*lambda;
}
double Generator::GeometricalDistributions(double P)
{
  double tmp = 0;
  while (UniformDistribution(0,1) > 1 / P)
    tmp++;
  return tmp + 1;
}
double Generator::NormalDistributions(const double mean, const double zm)
{
  return zm * sqrt(2) * pow(erf(2 * UniformDistribution(0, 1) - 1), -1) + mean;
}
void Generator::GenerateSeed(int volume_of_seed)
{
  std::ofstream file;
  file.open("ziarna.txt");   
  if (!file)     
    std::cout << "Nie udalo sie otworzy pliku ziarna.txt" << std::endl;   
  seed_ = 10000; // Generowanie ziaren i zapis do pliku    
  for (int i = 0; i < volume_of_seed; i++)
  { double x = seed_;     
    int h = static_cast<int>(x / Q1);     
    x = A1*(x - Q1*h) - R1*h;     
    if (x < 0) x += M;     
    seed_ = x;     
    file << seed_ << std::endl;   
  }   
  file << std::flush;   
  file.close(); 
}
void Generator::LoadSeed()
{
  array_seed_.reserve(size_of_probe);
  std::ifstream file;
  file.open("ziarna.txt");
  if (!file)
    std::cout << "Nie udalo sie otworzyc pliku ziarna.txt" << std::endl;
  double tmp;
  while (!file.eof())
  {
    file >> tmp; 
    array_seed_.push_back(tmp);
  }
  file.close();
}
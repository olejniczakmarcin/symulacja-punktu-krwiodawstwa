#pragma once
#include<vector>
#define M 2147483647.0
#define Q1 127773
#define R1 2836
#define A1 16807 
#define size_of_probe 100000
class Generator
{
public:
  Generator(double seed);
  ~Generator() { array_seed_.clear(); }
  double UniformDistribution(int down, int up);
  double ExponentialDistributions(double lambda);
  double GeometricalDistributions(double P);
  double NormalDistributions(const double mean, const double zm);
  void GenerateSeed(int seed);
  void LoadSeed();
  void UniformDistributionTest();
  void ExponentialDistributionsTest();
  void GeometricalDistributionsTest();
  void NormalDistributionsTest();
private:
  double seed_;
  std::vector<double> array_seed_;
};
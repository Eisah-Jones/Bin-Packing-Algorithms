#ifndef ALG_TOOLS_CPP
#define ALG_TOOLS_CPP

#include <vector>
#include <algorithm>
#include <math.h>
#include <random>
#include "project2.h"



double generate_uniform_random_double(std::mt19937& mt)
{
  std::uniform_real_distribution<double> dist(0.0, 1.0);
  return dist(mt);
}


std::vector<double> uniform_random_vector(int n, std::mt19937& mt)
{
  std::vector<double> result;
  for(int i = 0; i < n; i++)
  {
    double v = generate_uniform_random_double(mt);
    result.push_back(v);
  }
  return result;
}


double waste(const std::vector<double>& items, const std::vector<double>& bins)
{
  double result = bins.size();
  double bin_total = 0.0;
  for(double i : items)
    bin_total += i;
  return result - bin_total;
}

#endif

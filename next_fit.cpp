#include "project2.h"
#include "alg_tools.cpp"

#include <vector>
#include <random>

void next_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
  free_space.push_back(1.0);
  int binIdx = 0;
  for(int idx = 0; idx < items.size(); idx++)
  {
    double value = items[idx];
    if(value <= free_space[binIdx])
    {
      free_space[binIdx] -= value;
      assignment[idx] = binIdx;
    }
    else
    {
      free_space.push_back(1.0 - value);
      assignment[idx] = binIdx++;
    }
  }
}


//int main()
//{
//  int n = 1000;
//  std::random_device rd;
//  std::mt19937 gen(rd());
//  std::vector<double> vec = uniform_random_vector(n, gen);
//  std::vector<int> a(vec.size(), 0);
//  std::vector<double> fs;
//  next_fit(vec, a, fs);
//  printf("%f\n", waste(vec, fs));
//}



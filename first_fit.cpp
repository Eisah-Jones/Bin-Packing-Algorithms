
#include "project2.h"
#include "alg_tools.cpp"
#include "sort_tools.cpp"
#include "shell_sort.cpp"

#include <vector>
#include <random>


void first_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{ 
  free_space.push_back(1.0);
  for(int idx = 0; idx < items.size(); idx++)
  {
    bool new_bin = true;
    double value = items[idx];
    int binIdx;
    for(binIdx = 0; binIdx < free_space.size() && new_bin; binIdx++)
    {
      if(value <= free_space[binIdx])
      {
        free_space[binIdx] -= value;
        assignment[idx] = binIdx;
        new_bin = false;
      }
    }

    if(new_bin)
    {
      free_space.push_back(1.0 - value);
      assignment[idx] = binIdx+1;
    }
  }
}


void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
  std::vector<double> copy = items;
  std::vector<int> gaps = getGaps(10, 1);
  shell_sort(copy, gaps);
  return first_fit(copy, assignment, free_space);
}


//int main()
//{
//  int n = 1000;
//  std::random_device rd;
//  std::mt19937 gen(rd());
//  std::vector<double> vec = uniform_random_vector(n, gen);
//  std::vector<int> a(vec.size(), 0);
//  std::vector<double> fs;
//  first_fit(vec, a, fs);
//  printf("%f\n", waste(vec, fs));
//}





#include "project2.h"
#include "alg_tools.cpp"
#include "sort_tools.cpp"
#include "shell_sort.cpp"

#include <vector>
#include <random>


void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{ 
  for(int idx = 0; idx < items.size(); idx++)
  {
    double value = items[idx];
    double min_space = 2;
    int final_bin = -1;
    for(int binIdx = 0; binIdx < free_space.size(); binIdx++)
    {
      if(value <= free_space[binIdx] && free_space[binIdx] - value < min_space)
      {
        min_space = free_space[binIdx] - value;
        final_bin = binIdx;
      }
    }

    if(final_bin == -1)
    {
      free_space.push_back(1 - value);
      assignment[idx] = free_space.size()-1;
    }
    else
    {
      free_space[final_bin] -= value;
      assignment[idx] = final_bin;
    }
  }
}


void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
  std::vector<double> copy = items;
  std::vector<int> gaps = getGaps(10, 1);
  shell_sort(copy, gaps);
  return best_fit(copy, assignment, free_space);
}


//int main()
//{
//  int n = 1000;
//  std::random_device rd;
//  std::mt19937 gen(rd());
//  std::vector<double> vec = uniform_random_vector(n, gen);
//  std::vector<int> a(vec.size(), 0);
//  std::vector<double> fs;
//  best_fit(vec, a, fs);
//  printf("%f\n", waste(vec, fs));
//}





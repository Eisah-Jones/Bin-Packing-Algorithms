#ifndef SHELL_SORT_CPP
#define SHELL_SORT_CPP

#include "project2.h"

using namespace std;


void shell_sort(vector<double>& vec, const vector<int>& gaps)
{
  for(vector<int>::const_iterator g = gaps.begin(); g != gaps.end(); g++)
  {
    int gap = *g;
    for(int i = gap; i < vec.size(); i++)
    {
      double temp = vec[i];
      int j;
      for(j = i; j >= gap && vec[j-gap] <= temp; j -= gap)
      {
        vec[j] = vec[j - gap];
      }
      vec[j] = temp;
    }
  }
}

#endif


#ifndef SORT_TOOLS_CPP
#define SORT_TOOLS_CPP

#include <vector>
#include <algorithm>
#include <math.h>
#include <random>

using namespace std;

vector<int> getGaps(int n, int i)
{
  vector<int> result;
  int v;
  for(int i = 10; i > 0; i--)
  {
    if(i == 1)
      v = pow(2, i) - 1;
    else
      v = pow(4, i) + 3 * pow(2, i-1) + 1;
    
    result.push_back(v);
  }

  return result;
}


void vecSwap(vector<int>& v, int a, int b)
{
  int temp = v[a];
  v[b] = v[a];
  v[a] = temp;
}


#endif








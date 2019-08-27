#include <random>
#include <cstdio>
#include <vector>
#include <fstream>
#include "project2.h"
#include "alg_tools.cpp"
#include "sort_tools.cpp"
#include "next_fit.cpp"
#include "first_fit.cpp"
#include "best_fit.cpp"



void startWaste(std::string fn)
{
  std::ofstream f;
  f.open(fn.c_str(), ios::trunc);
  f << "funcname,n,waste\n";
  f.close();
}


void writeWaste(std::string fn, std::string funcname, int n, double w)
{
  std::ofstream f;
  f.open(fn.c_str(), ios::app);
  f << funcname << ',' << n << ',' << w << "\n";
  f.close();
}


void runAlgorithms(int numAlgs, int repetitions)
{
  std::string algorithms[] = {"Next", "First", "First_decreasing", "Best", "Best_decreasing"};
  
  std::string wasteFile = "data/waste.csv";
  startWaste(wasteFile);

  std::random_device rd;
  std::mt19937 mt(rd());

  for(int algIdx = 0; algIdx < numAlgs; algIdx++)
  {
    std::string a = algorithms[algIdx];
    printf("[Start] %s_fit Analysis\n", a.c_str());
    for(int vecLen = 2; vecLen <= 65537; vecLen *= 2)
    {
      printf("        n = %d\n", vecLen);
      int progress = 1;
      double total_waste = 0.0;
      for(int rep = 0; rep < repetitions; rep++, progress++)
      {
        printf("          Progress: %04d/%d runs\r", progress, repetitions);
        std::vector<double> v = uniform_random_vector(vecLen, mt);
        std::vector<int> a(v.size(), 0);
        std::vector<double> fs;
        switch(algIdx)
        {
          case 0:
            next_fit(v, a, fs);
            break;
          case 1:
            first_fit(v, a, fs);
            break;
          case 2:
            first_fit_decreasing(v, a, fs);
            break;
          case 3:
            best_fit(v, a, fs);
          case 4:
            best_fit_decreasing(v, a, fs);
        }
        total_waste += waste(v, fs);
      }
      printf("          Progress: %d/%d runs        \n\n", repetitions, repetitions);
      double avgWaste = total_waste/repetitions;
      writeWaste(wasteFile, a, vecLen, avgWaste);
    }
    printf("[  End] %s Sort Analysis\n", a.c_str());
  }
}



int main()
{
  printf("--------------------------------\n");
  printf("  Running Project 2 Test Bench\n");
  printf("   Programmed by: Eisah Jones\n");
  printf("         UC Irvine 2019\n");
  printf("--------------------------------\n");
  runAlgorithms(5, 100);
  return 1;
}

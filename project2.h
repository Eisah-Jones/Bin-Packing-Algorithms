#ifndef PROJECT2_H
#define PROJECT2_H

#include <vector>


// implement in next_fit.cpp
void next_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);

//implement in first_fit.cpp
void first_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);
void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);

// implement in best_fit.cpp
void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);
void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);

/* 
 * for all functions
 * params:
 *      items: the items to assign to bins
 *      assignment: the assignment of the ith item to the jth bin for all i items
 *      free space: the amount of space left in the jth bin for all j bins created
 * return:
 *      bins : bins with items created by algorithm
 *
 * example usage:
 *      std::vector<item_t> items; 
 *      ...populate items...
 *      std::vector<bin_t> bins;
 *      bins = next_fit(items)
 */

#endif

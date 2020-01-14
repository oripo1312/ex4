//
// Created by shmuelsuna on 13/01/2020.
//

#ifndef EX4__FILECACHEMANAGER_H_
#define EX4__FILECACHEMANAGER_H_

#include <map>
#include "CacheManager.h"

class FileCacheManager : public CacheManager<string, string> {
  map<string, string> problem_solution_map;//this map  is in ram, helps us fetch less times from files

 public:
  FileCacheManager();//CTOR



  void save(string problem, string solution);


  string getSolution(string problem);

  bool isThereASolution(string problem);
};
#endif //EX4__FILECACHEMANAGER_H_
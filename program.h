#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <chrono>
#include "sorting_algorithm.h"
#include "DataGenerator.h"

using namespace std;

#define ORDER_RANDOM 1 << 1
#define ORDER_NSORTED 1 << 2
#define ORDER_SORTED 1 << 3
#define ORDER_REVERSE 1 << 4

typedef void (*p_func1)(vector<type>&, ull&);
typedef void (*p_func2)(vector<type>&);

typedef int ArgValue;

void experimentMode(string sort_name);


// Name        : Knapsack.cpp  
  
#include <iostream>  
#include<cstdlib>  
#include"Knapsack.h"  
#include<fstream>  
#include <string>  
using namespace std;  
  
const char left='-';  
const char least='\\'; 
const char up='|';  
 
int** result;   //results
int *cost1;     //cost1_array
int *volume;    //The volume array  
int *cost;     //cost_array
int** result1;   //results1
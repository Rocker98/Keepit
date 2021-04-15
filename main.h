
#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

void getInput(string &);

//transformaition to set from string 
void Extract(string&, unordered_set<string>&);
//void outputVec(vector<string>& input);
void outputSet(unordered_set<string>&);

//enable/disable due to parameter. Make "word" and "word," tha same words
void ignoreDotsAndCommas(string&);

//to provide such error like "Hello,world", cause there are two words
void addSpacesWhereIsNeeded(string&);

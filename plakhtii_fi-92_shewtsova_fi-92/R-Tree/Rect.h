#pragma once
#include <iostream>

using namespace std;
class Rect
{
	pair<pair<int, int>, pair<int, int>> rect;
public:
	Rect(pair<int, int> lt, pair<int, int> rb);
};


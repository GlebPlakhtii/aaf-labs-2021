#include "Rect.h"

Rect::Rect(pair<int, int> lt, pair<int, int> rb)
{
	this->rect = pair<pair<int, int>, pair<int, int>>(lt, rb);
}

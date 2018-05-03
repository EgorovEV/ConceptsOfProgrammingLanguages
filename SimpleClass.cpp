
#include "SimpleClass.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

unsigned int Essence::class_amount = 0;

Essence::Essence()
{
	info = class_amount;

	++class_amount;
	cout << "construct essence number " << info << endl;
}

Essence::~Essence()
{
	--class_amount;
	cout << "destruct essence number " << info << endl;
}

void CallStack::WriteOne() {
	exc_events.emplace();
}

void CallStack::DeleteOne() {
	if (exc_events.empty())
		return;

	if (exc_events.size() != 0) {
		exc_events.top().~Essence();
	}
	exc_events.pop();
}

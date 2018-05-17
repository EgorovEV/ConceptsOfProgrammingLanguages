#pragma once

#include <stdio.h>
#include <stack>

class Essence {
public:
	Essence();
	~Essence();

	unsigned int get_info() { return info; }
	static unsigned int class_amount;
private:
	unsigned int info;
};

class CallStack {
public:
	void WriteOne();
	void DeleteOne();
	
private:
	unsigned int depth;
	std::stack<Essence> exc_events;
};
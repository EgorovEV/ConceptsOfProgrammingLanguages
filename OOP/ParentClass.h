#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <utility>

using namespace std;

#define VIRTUAL_CLASS(className)							\
struct className {											\
	unordered_map<string, function<void(int)> > vFuncTable; \
	string thisName = #className;							\
	className();											\
	int info;

#define DECLARE_METHOD(methodName, className)						\
	static void className::methodName(int info) {					\
		std::cout << #className << "::" << #methodName << " ";		\
		cout << "info = " << info << endl;							\
	}	

#define END };
			

#define CONSTRUCTOR(className)							\
className::className() {	

#define SETINFO(Number)		\
	this->info = Number;

#define LINK_METHOD(methodName)							\
	this->vFuncTable.emplace(#methodName, methodName); 

#define END_CONSTRUCTOR };


#define VIRTUAL_CALL(className_ptr, func_name)			\
(className_ptr->vFuncTable[#func_name])(className_ptr->info); 



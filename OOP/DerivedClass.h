#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <utility>

using namespace std;

#define VIRTUAL_CLASS_DERIVED(derived_class_name, base_class_name)	\
struct derived_class_name {											\
    unordered_map<string, function<void(int)>> vFuncTable;			\
	string thisName = #derived_class_name;							\
	derived_class_name();											\
	int info;

#define END_DERIVE };

#define DERIVED_CONSTRUCTOR(derived_class_name)		\
derived_class_name::derived_class_name() {			\


#define LINK_DERIVE_METHOD(derived_method_name)						\
	this->vFuncTable.emplace(#derived_method_name, derived_method_name); 


#define END_DERIVED_CONSTRUCTOR(derived_class_name, base_class_name)								\
	base_class_name base_class_obj;																	\
    for (auto i = base_class_obj.vFuncTable.begin(); i != base_class_obj.vFuncTable.end(); ++i) {   \
        if (this->vFuncTable.count(i->first) == 0) {                                                \
            this->vFuncTable.emplace(i->first, std::function<void(int)>(i->second));				\
        }																							\
    }																								\
};
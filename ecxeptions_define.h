#pragma once
#include <setjmp.h>
#include "SimpleClass.h"

#define BAD_FILE 0
#define DEVIDE_ZERO 1

jmp_buf jump_point[10];
int it = 0;
int current_exp = -1;
CallStack FuncCallHistory;

#define TRY(action) \
	if (current_exp != -1) exit(1); \
	FuncCallHistory.WriteOne(); \
	if (setjmp(jump_point[it++]) == 0 && current_exp == -1) { \
		action; \
		--it; \
		FuncCallHistory.DeleteOne(); \
	}

#define THROW(type_exception) \
	if (current_exp != -1 || it <= 0) exit(1); \
	current_exp = type_exception; \
	longjmp(jump_point[--it], 1); 

#define CATCH(type_exception, action) \
	else if (current_exp == type_exception) { \
		action; \
		current_exp = -1; \
	}

#define END \
	if (current_exp != -1) { \
		THROW(current_exp); \
}
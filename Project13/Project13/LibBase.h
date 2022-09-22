#ifndef __LIBBASE_H__
#define __LIBBASE_H__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

typedef enum
{
	EXPERIENCE = 0,
	FRESHER,
	INTERN
}t_EmployeeType;

typedef enum 
{ 
	EXIT_T = 0, 
	EXPERIENCE_T,
	FRESHER_T,
	INTERN_T
}type_t;

typedef enum
{
	NO = 0,
	YES
} YesOrNo_t;

typedef enum
{
	SHOW_ALL = 0,
	SHOW_EXPERIENCE,
	SHOW_INTERN,
	SHOW_FRESHER
} show_t;

#endif
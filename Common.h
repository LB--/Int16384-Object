// Include guard
#ifndef COMMON_H
#define COMMON_H

// Suppress the deprecated warnings for VC2005
#define _CRT_SECURE_NO_WARNINGS

// General includes
#include	"TemplateInc.h"

#include <windows.h>
#include <sstream>
#include <string>
//#include <ctime>
//#include <cstdlib>
using namespace std;

#include "MersenneTwister.h"
#include "ttmath\ttmath.h"
#include "StringConvert.hpp"

typedef ttmath::UInt<TTMATH_BITS(16384)> UInt16384;
typedef ttmath::Int<TTMATH_BITS(16384)> SInt16384;
typedef ttmath::Big<TTMATH_BITS(8192),TTMATH_BITS(8192)> BigFloat;

// Specific to this extension
#include	"Resource.h"
#include	"FlagsPrefs.h"
#include	"Information.h"
#include	"Data.h"

// rTemplate include
#include	"rTemplate.h"

// Globals and prototypes
extern HINSTANCE hInstLib;
extern short * conditionsInfos;
extern short * actionsInfos;
extern short * expressionsInfos;
extern long (WINAPI ** ConditionJumps)(LPRDATA rdPtr, long param1, long param2);
extern short (WINAPI ** ActionJumps)(LPRDATA rdPtr, long param1, long param2);
extern long (WINAPI ** ExpressionJumps)(LPRDATA rdPtr, long param);
extern PropData Properties[];
extern WORD DebugTree[];

// End include guard
#endif

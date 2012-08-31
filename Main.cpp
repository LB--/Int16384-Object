// ============================================================================
//
// This file contains the actions, conditions and expressions your object uses
// 
// ============================================================================

#include "Common.h"
#include "ParamHelp.h"

/* ******* Custom Function Definitions ******* */
	//Random Funstions
UInt16384 URandom(const UInt16384 &Min, const UInt16384 &Max) //Unsigned
{
	MTRand RandID;

	unsigned int Temp = RandID.randInt();
	UInt16384 Final = (UInt16384)Temp;

	//Generate seeds
	unsigned int Seeds[200];
	for(unsigned char i = 0; i < 200; i++)
	{
		Seeds[i] = RandID.randInt();
	}

	//Using the seeds, run a loop a whole lotta times, and use random to either add, subtract, multiply, or divide the Final result by one of the random numbers from a random position in the seeds array
	for(unsigned short i = 0; i < 1000; i++)
	{
		switch (RandID.randInt() % 4)
		{
		case 0:
			Final += Seeds[RandID.randInt() % 200];
			break;
		case 1:
			Final -= Seeds[RandID.randInt() % 200];
			break;
		case 2:
			Final *= Seeds[RandID.randInt() % 200];
			break;
		case 3:
			Final /= Seeds[RandID.randInt() % 200];
			break;
		}
	}

	//The final result should be within the bounds specified by the function parameters
	UInt16384 Range = 1;
	Range += Max;
	Range -= Min;
	Final %= Range;
	Final += Min;
	return(Final);
}

SInt16384 SRandom(const SInt16384 &Min, const SInt16384 &Max) //Signed
{
	MTRand RandID;

	unsigned int Temp = RandID.randInt();
	SInt16384 Final = (SInt16384)Temp;

	//Generate seeds
	unsigned int Seeds[200];
	for(unsigned char i = 0; i < 200; i++)
	{
		Seeds[i] = RandID.randInt();
	}

	//Using the seeds, run a loop a whole lotta times, and use random to either add, subtract, multiply, or divide the Final result by one of the random numbers from a random position in the seeds array
	for(unsigned short i = 0; i < 1000; i++)
	{
		switch (RandID.randInt() % 4)
		{
		case 0:
			Final += Seeds[RandID.randInt() % 200];
			break;
		case 1:
			Final -= Seeds[RandID.randInt() % 200];
			break;
		case 2:
			Final *= Seeds[RandID.randInt() % 200];
			break;
		case 3:
			Final /= Seeds[RandID.randInt() % 200];
			break;
		}
	}

	//The final result should be within the bounds specified by the function parameters
	SInt16384 Range = 1;
	Range += Max;
	Range -= Min;
	Final %= Range;
	Final += Min;
	return(Final);
}

BigFloat FRandom(const BigFloat &Min, const BigFloat &Max) //Float
{
	MTRand RandID;

	double Temp = RandID.rand(1.6e308);
	BigFloat Final = (BigFloat)Temp;

	//Generate seeds
	double Seeds[200];
	for(unsigned char i = 0; i < 200; i++)
	{
		Seeds[i] = RandID.rand(1.6e308);
	}

	//Using the seeds, run a loop a whole lotta times, and use random to either add, subtract, multiply, or divide the Final result by one of the random numbers from a random position in the seeds array
	for(unsigned short i = 0; i < 1000; i++)
	{
		switch (RandID.randInt() % 4)
		{
		case 0:
			Final += Seeds[RandID.randInt() % 200];
			break;
		case 1:
			Final -= Seeds[RandID.randInt() % 200];
			break;
		case 2:
			Final *= Seeds[RandID.randInt() % 200];
			break;
		case 3:
			Final /= Seeds[RandID.randInt() % 200];
			break;
		}
	}

	//The final result should be within the bounds specified by the function parameters
	BigFloat Range = 1;
	Range += Max;
	Range -= Min;
	/*Final %= Range;*/
	Final += Min;
	return(Final);
}

// ============================================================================
//
// CONDITIONS
// 
// ============================================================================



		/* ******* *******          ******* ******* *\
		|* ******* ******* UNSIGNED ******* ******* *|
		\* ******* *******          ******* ******* */
CONDITION(
	/* ID */			0,
	/* Name */			"Unsigned: %0 == %1",
	/* Flags */			EVFLAGS_ALWAYS|EVFLAGS_NOTABLE,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	UInt16384 NumA (StrParam());
	UInt16384 NumB (StrParam());
	
	return(NumA == NumB);
}

CONDITION(
	/* ID */			1,
	/* Name */			"Unsigned: %0 > %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	UInt16384 NumA (StrParam());
	UInt16384 NumB (StrParam());
	
	return(NumA > NumB);
}

CONDITION(
	/* ID */			2,
	/* Name */			"Unsigned: %0 >= %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	UInt16384 NumA (StrParam());
	UInt16384 NumB (StrParam());
	
	return(NumA >= NumB);
}

CONDITION(
	/* ID */			3,
	/* Name */			"Unsigned: %0 < %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	UInt16384 NumA (StrParam());
	UInt16384 NumB (StrParam());
	
	return(NumA < NumB);
}

CONDITION(
	/* ID */			4,
	/* Name */			"Unsigned: %0 <= %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	UInt16384 NumA (StrParam());
	UInt16384 NumB (StrParam());
	
	return(NumA <= NumB);
}



		/* ******* *******          ******* ******* *\
		|* ******* *******  SIGNED  ******* ******* *|
		\* ******* *******          ******* ******* */
CONDITION(
	/* ID */			5,
	/* Name */			"Signed: %0 == %1",
	/* Flags */			EVFLAGS_ALWAYS|EVFLAGS_NOTABLE,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	SInt16384 NumA (StrParam());
	SInt16384 NumB (StrParam());
	
	return(NumA == NumB);
}

CONDITION(
	/* ID */			6,
	/* Name */			"Signed: %0 > %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	SInt16384 NumA (StrParam());
	SInt16384 NumB (StrParam());
	
	return(NumA > NumB);
}

CONDITION(
	/* ID */			7,
	/* Name */			"Signed: %0 >= %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	SInt16384 NumA (StrParam());
	SInt16384 NumB (StrParam());
	
	return(NumA >= NumB);
}

CONDITION(
	/* ID */			8,
	/* Name */			"Signed: %0 < %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	SInt16384 NumA (StrParam());
	SInt16384 NumB (StrParam());
	
	return(NumA < NumB);
}

CONDITION(
	/* ID */			9,
	/* Name */			"Signed: %0 <= %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	SInt16384 NumA (StrParam());
	SInt16384 NumB (StrParam());
	
	return(NumA <= NumB);
}



		/* ******* *******           ******* ******* *\
		|* ******* *******   FLOAT   ******* ******* *|
		\* ******* *******           ******* ******* */
CONDITION(
	/* ID */			10,
	/* Name */			"Float: %0 == %1",
	/* Flags */			EVFLAGS_ALWAYS|EVFLAGS_NOTABLE,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	BigFloat NumA (StrParam());
	BigFloat NumB (StrParam());
	
	return(NumA == NumB);
}

CONDITION(
	/* ID */			11,
	/* Name */			"Float: %0 > %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	BigFloat NumA (StrParam());
	BigFloat NumB (StrParam());
	
	return(NumA > NumB);
}

CONDITION(
	/* ID */			12,
	/* Name */			"Float: %0 >= %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	BigFloat NumA (StrParam());
	BigFloat NumB (StrParam());
	
	return(NumA >= NumB);
}

CONDITION(
	/* ID */			13,
	/* Name */			"Float: %0 < %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	BigFloat NumA (StrParam());
	BigFloat NumB (StrParam());
	
	return(NumA < NumB);
}

CONDITION(
	/* ID */			14,
	/* Name */			"Float: %0 <= %1",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_EXPSTRING,"First number",PARAM_EXPSTRING,"Second number")
) {
	BigFloat NumA (StrParam());
	BigFloat NumB (StrParam());
	
	return(NumA <= NumB);
}

// ============================================================================
//
// ACTIONS
// 
// ============================================================================



		/* ******* *******          ******* ******* *\
		|* ******* ******* UNSIGNED ******* ******* *|
		\* ******* *******          ******* ******* */
ACTION(
	/* ID */			0,
	/* Name */			"Unsigned: Set Variable to %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Set to")
) {
	rdPtr->SuperUInt = StrParam();
}

ACTION(
	/* ID */			1,
	/* Name */			"Unsigned: Add %0 to Variable",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Add")
) {
	rdPtr->SuperUInt += StrParam();
}

ACTION(
	/* ID */			2,
	/* Name */			"Unsigned: Subtract %0 from Variable",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Subtract")
) {
	rdPtr->SuperUInt -= StrParam();
}

ACTION(
	/* ID */			3,
	/* Name */			"Unsigned: Multiply Variable by %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Multiply by")
) {
	rdPtr->SuperUInt *= StrParam();
}

ACTION(
	/* ID */			4,
	/* Name */			"Unsigned: Divide Variable by %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Divide by")
) {
	rdPtr->SuperUInt /= StrParam();
}

ACTION(
	/* ID */			5,
	/* Name */			"Unsigned: Raise Variable to the Power of %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Raise to the Power of")
) {
	rdPtr->SuperUInt.Pow(StrParam());
}

ACTION(
	/* ID */			6,
	/* Name */			"Unsigned: Set Variable to Variable mod %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to perform Modulus with")
) {
	rdPtr->SuperUInt %= StrParam();
}



		/* ******* *******          ******* ******* *\
		|* ******* *******  SIGNED  ******* ******* *|
		\* ******* *******          ******* ******* */
ACTION(
	/* ID */			7,
	/* Name */			"Signed: Set Variable to %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Set to")
) {
	rdPtr->SuperSInt = StrParam();
}

ACTION(
	/* ID */			8,
	/* Name */			"Signed: Add %0 to Variable",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Add")
) {
	rdPtr->SuperSInt += StrParam();
}

ACTION(
	/* ID */			9,
	/* Name */			"Signed: Subtract %0 from Variable",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Subtract")
) {
	rdPtr->SuperSInt -= StrParam();
}

ACTION(
	/* ID */			10,
	/* Name */			"Signed: Multiply Variable by %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Multiply by")
) {
	rdPtr->SuperSInt *= StrParam();
}

ACTION(
	/* ID */			11,
	/* Name */			"Signed: Divide Variable by %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Divide by")
) {
	rdPtr->SuperSInt /= StrParam();
}

ACTION(
	/* ID */			12,
	/* Name */			"Signed: Raise Variable to the Power of %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Raise to the Power of")
) {
	rdPtr->SuperSInt.Pow(StrParam());
}

ACTION(
	/* ID */			13,
	/* Name */			"Signed: Set Variable to Variable mod %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to perform Modulus with")
) {
	rdPtr->SuperSInt %= StrParam();
}



		/* ******* *******           ******* ******* *\
		|* ******* *******   FLOAT   ******* ******* *|
		\* ******* *******           ******* ******* */
ACTION(
	/* ID */			14,
	/* Name */			"Float: Set Variable to %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Set to")
) {
	rdPtr->SuperFloat = StrParam();
}

ACTION(
	/* ID */			15,
	/* Name */			"Float: Add %0 to Variable",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Add")
) {
	rdPtr->SuperFloat += StrParam();
}

ACTION(
	/* ID */			16,
	/* Name */			"Float: Subtract %0 from Variable",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Subtract")
) {
	rdPtr->SuperFloat -= StrParam();
}

ACTION(
	/* ID */			17,
	/* Name */			"Float: Multiply Variable by %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Multiply by")
) {
	rdPtr->SuperFloat *= StrParam();
}

ACTION(
	/* ID */			18,
	/* Name */			"Float: Divide Variable by %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Divide by")
) {
	rdPtr->SuperFloat /= StrParam();
}

ACTION(
	/* ID */			19,
	/* Name */			"Float: Raise Variable to the Power of %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to Raise to the Power of")
) {
	rdPtr->SuperFloat.Pow(StrParam());
}

ACTION(
	/* ID */			20,
	/* Name */			"Float: Set Variable to Variable mod %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Value to perform Modulus with")
) {
	rdPtr->SuperFloat.Mod(StrParam());
}

		/* ******* *******           ******* ******* *\
		|* ******* *******   BYTES   ******* ******* *|
		\* ******* *******           ******* ******* */
ACTION(
	/* ID */			21,
	/* Name */			"Unsigned: Set Byte %0 to %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_NUMBER,"Byte to Set (0 to 2047)",PARAM_NUMBER,"Value to Set to (0 to 255)")
) {
	unsigned long Byte = lParam();
	((unsigned char *) &(rdPtr->SuperUInt))[Byte % 2048] = unsigned char(lParam() % 256);
}

ACTION(
	/* ID */			22,
	/* Name */			"Unsigned: Set Integer %0 to %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_NUMBER,"Integer to Set (0 to 511)",PARAM_NUMBER,"Value to Set to (-2147483648 to 2147483647)")
) {
	unsigned long Int = lParam();
	((signed int *) &(rdPtr->SuperUInt))[Int % 512] = lParam();
}

/* ******* ******* ******* */

ACTION(
	/* ID */			23,
	/* Name */			"Signed: Set Byte %0 to %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_NUMBER,"Byte to Set (0 to 2047)",PARAM_NUMBER,"Value to Set to (0 to 255)")
) {
	unsigned long Byte = lParam();
	((unsigned char *) &(rdPtr->SuperSInt))[Byte % 2048] = unsigned char(lParam() % 256);
}

ACTION(
	/* ID */			24,
	/* Name */			"Signed: Set Integer %0 to %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_NUMBER,"Integer to Set (0 to 511)",PARAM_NUMBER,"Value to Set to (-2147483648 to 2147483647)")
) {
	unsigned long Int = lParam();
	((signed int *) &(rdPtr->SuperSInt))[Int % 512] = lParam();
}

/* ******* ******* ******* */

ACTION(
	/* ID */			25,
	/* Name */			"Float: Set Byte %0 to %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_NUMBER,"Byte to Set (0 to 2047)",PARAM_NUMBER,"Value to Set to (0 to 255)")
) {
	unsigned long Byte = lParam();
	((unsigned char *) &(rdPtr->SuperFloat))[Byte % 2048] = unsigned char(lParam() % 256);
}

ACTION(
	/* ID */			26,
	/* Name */			"Float: Set Integer %0 to %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_NUMBER,"Integer to Set (0 to 511)",PARAM_NUMBER,"Value to Set to (-2147483648 to 2147483647)")
) {
	unsigned long Int = lParam();
	((signed int *) &(rdPtr->SuperFloat))[Int % 512] = lParam();
}

// ============================================================================
//
// EXPRESSIONS
// 
// ============================================================================



		/* ******* *******          ******* ******* *\
		|* ******* ******* UNSIGNED ******* ******* *|
		\* ******* *******          ******* ******* */
EXPRESSION(
	/* ID */			0,
	/* Name */			"UVariable$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(0)
) {
	ReturnStringSafe(rdPtr->SuperUInt.ToString().c_str());
}

EXPRESSION(
	/* ID */			1,
	/* Name */			"UAdd$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt16384 A (EStrParam());
	UInt16384 B (EStrParam());
	A += B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			2,
	/* Name */			"USubtract$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt16384 A (EStrParam());
	UInt16384 B (EStrParam());
	A -= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			3,
	/* Name */			"UMultiply$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt16384 A (EStrParam());
	UInt16384 B (EStrParam());
	A *= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			4,
	/* Name */			"UDivide$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt16384 A (EStrParam());
	UInt16384 B (EStrParam());
	A /= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			5,
	/* Name */			"UPower$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt16384 A (EStrParam());
	UInt16384 B (EStrParam());
	A.Pow(B);
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			6,
	/* Name */			"UModulo$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt16384 A (EStrParam());
	UInt16384 B (EStrParam());
	A %= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			7,
	/* Name */			"URandom$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"Minimum",EXPPARAM_STRING,"Maximum")
) {
	UInt16384 MinVal (EStrParam());
	UInt16384 MaxVal (EStrParam());
	UInt16384 RandomResult = URandom(MinVal, MaxVal);
	ReturnStringSafe(RandomResult.ToString().c_str());
}



		/* ******* *******          ******* ******* *\
		|* ******* *******  SIGNED  ******* ******* *|
		\* ******* *******          ******* ******* */
EXPRESSION(
	/* ID */			8,
	/* Name */			"SVariable$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(0)
) {
	ReturnStringSafe(rdPtr->SuperSInt.ToString().c_str());
}

EXPRESSION(
	/* ID */			9,
	/* Name */			"SAdd$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt16384 A (EStrParam());
	SInt16384 B (EStrParam());
	A += B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			10,
	/* Name */			"SSubtract$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt16384 A (EStrParam());
	SInt16384 B (EStrParam());
	A -= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			11,
	/* Name */			"SMultiply$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt16384 A (EStrParam());
	SInt16384 B (EStrParam());
	A *= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			12,
	/* Name */			"SDivide$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt16384 A (EStrParam());
	SInt16384 B (EStrParam());
	A /= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			13,
	/* Name */			"SPower$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt16384 A (EStrParam());
	SInt16384 B (EStrParam());
	A.Pow(B);
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			14,
	/* Name */			"SModulo$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt16384 A (EStrParam());
	SInt16384 B (EStrParam());
	A %= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			15,
	/* Name */			"SRandom$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"Minimum",EXPPARAM_STRING,"Maximum")
) {
	SInt16384 MinVal (EStrParam());
	SInt16384 MaxVal (EStrParam());
	SInt16384 RandomResult = SRandom(MinVal, MaxVal);
	ReturnStringSafe(RandomResult.ToString().c_str());
}



		/* ******* *******           ******* ******* *\
		|* ******* *******   FLOAT   ******* ******* *|
		\* ******* *******           ******* ******* */
EXPRESSION(
	/* ID */			16,
	/* Name */			"FVariable$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(0)
) {
	ReturnStringSafe(rdPtr->SuperFloat.ToString().c_str());
}

EXPRESSION(
	/* ID */			17,
	/* Name */			"FAdd$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	BigFloat A (EStrParam());
	BigFloat B (EStrParam());
	A += B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			18,
	/* Name */			"FSubtract$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	BigFloat A (EStrParam());
	BigFloat B (EStrParam());
	A -= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			19,
	/* Name */			"FMultiply$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	BigFloat A (EStrParam());
	BigFloat B (EStrParam());
	A *= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			20,
	/* Name */			"FDivide$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	BigFloat A (EStrParam());
	BigFloat B (EStrParam());
	A /= B;
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			21,
	/* Name */			"FPower$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	BigFloat A (EStrParam());
	BigFloat B (EStrParam());
	A.Pow(B);
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			22,
	/* Name */			"FModulo$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	BigFloat A (EStrParam());
	BigFloat B (EStrParam());
	A.Mod(B);
	ReturnStringSafe(A.ToString().c_str());
}

EXPRESSION(
	/* ID */			23,
	/* Name */			"FRandom$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"Minimum",EXPPARAM_STRING,"Maximum")
) {
	BigFloat MinVal (EStrParam());
	BigFloat MaxVal (EStrParam());
	BigFloat RandomResult = FRandom(MinVal, MaxVal);
	ReturnStringSafe(RandomResult.ToString().c_str());
}

		/* ******* *******           ******* ******* *\
		|* ******* *******   BYTES   ******* ******* *|
		\* ******* *******           ******* ******* */
EXPRESSION(
	/* ID */			24,
	/* Name */			"UByte(",
	/* Flags */			0,
	/* Params */		(1,EXPPARAM_LONG,"Byte Position (0 to 2047)")
) {
	return( ((unsigned char *) &(rdPtr->SuperUInt))[xlParam() % 2048] );
}

EXPRESSION(
	/* ID */			25,
	/* Name */			"UInt(",
	/* Flags */			0,
	/* Params */		(1,EXPPARAM_LONG,"Int Position (0 to 511)")
) {
	return( ((signed int *) &(rdPtr->SuperUInt))[xlParam() % 512] );
}

/* ******* ******* ******* */

EXPRESSION(
	/* ID */			26,
	/* Name */			"SByte(",
	/* Flags */			0,
	/* Params */		(1,EXPPARAM_LONG,"Byte Position (0 to 2047)")
) {
	return( ((unsigned char *) &(rdPtr->SuperSInt))[xlParam() % 2048] );
}

EXPRESSION(
	/* ID */			27,
	/* Name */			"SInt(",
	/* Flags */			0,
	/* Params */		(1,EXPPARAM_LONG,"Int Position (0 to 511)")
) {
	return( ((signed int *) &(rdPtr->SuperSInt))[xlParam() % 512] );
}

/* ******* ******* ******* */

EXPRESSION(
	/* ID */			28,
	/* Name */			"FByte(",
	/* Flags */			0,
	/* Params */		(1,EXPPARAM_LONG,"Byte Position (0 to 2047)")
) {
	return( ((unsigned char *) &(rdPtr->SuperFloat))[xlParam() % 2048] );
}

EXPRESSION(
	/* ID */			29,
	/* Name */			"FInt(",
	/* Flags */			0,
	/* Params */		(1,EXPPARAM_LONG,"Int Position (0 to 511)")
) {
	return( ((signed int *) &(rdPtr->SuperFloat))[xlParam() % 512] );
}

/* ******* ******* ******* */

EXPRESSION(
	/* ID */			30,
	/* Name */			"UIntAddr(",
	/* Flags */			0,
	/* Params */		(0)
) {
	return( ((signed int) &(rdPtr->SuperUInt)) );
}

EXPRESSION(
	/* ID */			31,
	/* Name */			"SIntAddr(",
	/* Flags */			0,
	/* Params */		(0)
) {
	return( ((signed int) &(rdPtr->SuperSInt)) );
}

EXPRESSION(
	/* ID */			32,
	/* Name */			"FAddr(",
	/* Flags */			0,
	/* Params */		(0)
) {
	return( ((signed int) &(rdPtr->SuperFloat)) );
}
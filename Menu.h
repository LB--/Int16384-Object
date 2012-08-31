// --------------------------------
// Condition menu
// --------------------------------

#ifdef CONDITION_MENU

	SEPARATOR
	SUB_START("Unsigned")
		ITEM(0,"A == B")
		ITEM(1,"A > B")
		ITEM(2,"A >= B")
		ITEM(3,"A < B")
		ITEM(4,"A <= B")
	SUB_END
	SUB_START("Signed")
		ITEM(5,"A == B")
		ITEM(6,"A > B")
		ITEM(7,"A >= B")
		ITEM(8,"A < B")
		ITEM(9,"A <= B")
	SUB_END
	SEPARATOR
	SUB_START("Float")
		ITEM(10,"A == B")
		ITEM(11,"A > B")
		ITEM(12,"A >= B")
		ITEM(13,"A < B")
		ITEM(14,"A <= B")
	SUB_END

#endif

// --------------------------------
// Action menu
// --------------------------------

#ifdef ACTION_MENU

	SEPARATOR
	SUB_START("Unsigned")
		ITEM(0,"Set")
		SEPARATOR
		ITEM(1,"Add")
		ITEM(2,"Subtract")
		ITEM(3,"Multiply")
		ITEM(4,"Divide")
		ITEM(5,"Raise to Power")
		ITEM(6,"Perform Modulus")
	SUB_END
	SUB_START("Signed")
		ITEM(7,"Set")
		SEPARATOR
		ITEM(8,"Add")
		ITEM(9,"Subtract")
		ITEM(10,"Multiply")
		ITEM(11,"Divide")
		ITEM(12,"Raise to Power")
		ITEM(13,"Perform Modulus")
	SUB_END
	SEPARATOR
	SUB_START("Float")
		ITEM(14,"Set")
		SEPARATOR
		ITEM(15,"Add")
		ITEM(16,"Subtract")
		ITEM(17,"Multiply")
		ITEM(18,"Divide")
		ITEM(19,"Raise to Power")
		ITEM(20,"Perform Modulus")
	SUB_END
	SEPARATOR
	SUB_START("Advanced")
		SUB_START("Unsigned")
			ITEM(21,"Set Byte (Size 1, unsigned)")
			ITEM(22,"Set Integer (Size 4, signed)")
		SUB_END
		SUB_START("Signed")
			ITEM(23,"Set Byte (Size 1, unsigned)")
			ITEM(24,"Set Integer (Size 4, signed)")
		SUB_END
		SUB_START("Float")
			ITEM(25,"Set Byte (Size 1, unsigned)")
			ITEM(26,"Set Integer (Size 4, signed)")
		SUB_END
	SUB_END
	SEPARATOR

#endif


// --------------------------------
// Expression menu
// --------------------------------

#ifdef EXPRESSION_MENU

	SEPARATOR
	ITEM(0,"Get Unsigned Variable")
	SUB_START("Unsigned")
		ITEM(1,"A + B")
		ITEM(2,"A - B")
		ITEM(3,"A * B")
		ITEM(4,"A / B")
		ITEM(5,"A ^ B")
		ITEM(6,"A % B")
		SEPARATOR
		ITEM(7,"Random")
	SUB_END
	SEPARATOR
	ITEM(8,"Get Signed Variable")
	SUB_START("Signed")
		ITEM(9,"A + B")
		ITEM(10,"A - B")
		ITEM(11,"A * B")
		ITEM(12,"A / B")
		ITEM(13,"A ^ B")
		ITEM(14,"A % B")
		SEPARATOR
		ITEM(15,"Random")
	SUB_END
	SEPARATOR
	ITEM(16,"Get Float Variable")
	SUB_START("Float")
		ITEM(17,"A + B")
		ITEM(18,"A - B")
		ITEM(19,"A * B")
		ITEM(20,"A / B")
		ITEM(21,"A ^ B")
		ITEM(22,"A % B")
		SEPARATOR
		DISABLED(23,"Random")
	SUB_END
	SEPARATOR
	SUB_START("Advanced")
		SUB_START("Unsigned")
			ITEM(24,"Get Byte (Size 1, unsigned)")
			ITEM(25,"Get Integer (Size 4, signed)")
			ITEM(30,"Get Memory Address")
		SUB_END
		SUB_START("Signed")
			ITEM(26,"Get Byte (Size 1, unsigned)")
			ITEM(27,"Get Integer (Size 4, signed)")
			ITEM(31,"Get Memory Address")
		SUB_END
		SUB_START("Float")
			ITEM(28,"Get Byte (Size 1, unsigned)")
			ITEM(29,"Get Integer (Size 4, signed)")
			ITEM(32,"Get Memory Address")
		SUB_END
	SUB_END
	SEPARATOR

#endif
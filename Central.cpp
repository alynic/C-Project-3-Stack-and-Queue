

#include "Central.h"

ControlType :: ControlType()
{
	header = "-- CPSC 131: Lab#3: Postfix Interpretation --";
	end =  "\nNo more data to process.\n-- The End of CPSC 131 Lab#3 --\n\n";
	done = false;
}

void ControlType :: DisplayHeaders(ControlType& control, ofstream& outfile)
{
	if (!done)
	{
		cout << header;
		outfile << header;
		done = true;
	}
	else
	{
		cout << end;
		outfile << end;
	}

}

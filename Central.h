

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Class definition of ControlType
class ControlType
{
public:
	// Class Constructor
	ControlType();
	// Function that displays the headers
	void DisplayHeaders(ControlType& control, ofstream& outfile);


private:
	string header;		// Declares header as string; header = "-- CPSC 131: Lab#3: Postfix Interpretation --"
	string end;			// Declares end as string; end = "\nNo more data to process.\n-- The End of CPSC 131 Lab#3 --\n\n"
	bool done;			// Declares done as boolean; done = false
};
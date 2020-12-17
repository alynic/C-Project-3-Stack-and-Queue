

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Class definition of FullStack
class FullStack
{};
// Class definition of EmptyStack
class EmptyStack
{};

template <class ItemType>
class StackType
{
public:

	StackType();
	/*	Purpose:			Stack class constructor
		Precondition:		Stack has been initialized
		Postcondition:		Top, maxStack, and items are initialized
	*/

	bool IsEmpty() const;
	/*	Purpose:			Determines wheter the stack is empty
		Precondition:		Stack has been initialized
		Postcondition:		Function value = (stack is empty)
	*/

	bool IsFull() const;
	/*	Purpose:			Determines whether the stack is full
		Precondition:		Stack has been initialized
		Postcondition:		Function value = (stack is full)
	*/

	void Push(ItemType& Item, ofstream& outfile);
	/*	Purpose:			Adds newItem to the top of the stack
		Precondition:		Stack has been initialized
		Postcondition:		If (stack is full), exception FullStack is thrown,
							else newItem is at the top of the stack
	*/

	void Pop(ofstream& outfile);
	/*	Purpose:			Removes top item from the stack
		Precondition:		Stack has been initialized
		Postcondition:		If (stack is empty), exception EmptyStack is thrown,
							else top element has been removed from stack
	*/

	// Function that builds a stack
	void BuildStack(char& newItem, ofstream& outfile);
	// Function that runs calculations
	void Calc(char& newItem, ofstream& outfile);
	// Function that runs a special push
	void SpecialPush(char& newItem, ofstream& outfile);
	// Function that shows results / runs output
	void ShowResult(ofstream& outfile);

private:
	int top;			// Declares top as int; top = -1
	int maxStack;		// Declares maxStack as int; maxStack = 500
	ItemType *items;	// Declares contents of items as ItemType
	string col;			// Declares col as string; col = ": "
	string result;		// Delcares result as string; result = "\n\t\tResult: "
	char sp;			// Declares sp as char; sp = " "
	char par1;			// Declares par1 as char; par1 = '('
	char par2;			// Declares par2 as char; par2 = ')'
	string push;		// Declares push as string; push = "\n\t\tpush "
	string pop;			// Declares pop as string; pop = "\n\t\tpop "
	int left;			// Declares left as int; left = first number from left
	int right;			// Declares right as int; right = second number from left
	int answer;			// Declares answer as int; answer = operation done from left and right numbers
};
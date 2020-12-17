

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Class definition of FullQueue
class FullQueue
{};
// Class definition of EmptyQueue
class EmptyQueue
{};

// Dynamically linked implementation of Queue
template <class ItemType>			
struct NodeType						// The record type for nodes of Queue's
{
	ItemType info;					// Declares info of type ItemType
	NodeType<ItemType> *link;		// Pointer that points to the pointer node
};

template <class ItemType>
class QueueType
{
public:
	QueueType();
	/*	Purpose:			Queue class constructor
		Precondition:		Queue has been initialized
		Postcondition:		Both front and rear are initialized
	*/

	void MakeEmpty();
	/*	Purpose:			Initialized the queue to an empty state
		Precondition:		Queue has been initialized
		Postcondition:		Queue is empty
	*/

	bool IsEmpty() const;
	/*	Purpose:			Determines whether the queue is empty
		Precondition:		Queue has been initialized
		Postcondition:		If (queue is full), FullQueue exception is thrown,
							else newItem is at rear of queue
	*/

	bool IsFull() const;
	/*	Purpose:			Determine whether the queue is full
		Precondition:		Queue has been initialized
		Postcondition:		Function value = (queue is empty)
	*/

	void Enqueue(ItemType newItem);
	/*	Purpose:			Adds newItem to the rear of the queue
		Precondition:		Queue has been initialized
		Postcondition:		If (queue is full), FullQueue exception is thrown,
							else newItem is at rear of queue
	*/

	void Dequeue(ItemType& newItem);
	/*	Purpose:			Removes front item from the queue and returns it in item
		Precondition:		Queue has been intialized
		Postcondition:		If (queue is empty), EmptyQueue exception is thrown and item
							is undefined, else front element has been removed from queue
							and item is a copy of removed element
	*/

	// Function that runs BuildList
	void BuildList(char& newItem, int count, bool& complete, ifstream& infile, ofstream& outfile);
	// Function that runs PrintQueue
	void PrintQueue(ofstream& outfile);


	~QueueType();
	/* Purpose:			Class destructor
	   Precondition:	MakeEmpty function is initialized
	   Postcondition:	Deconstructor initialized
	*/

private:
	NodeType<ItemType> *front;		// Pointer to the front of the node
	NodeType<ItemType> *rear;		// Pointer to the rear of the node
	NodeType<ItemType> *current;	// Pointer to transverse the list
	string dash1;					// Couts the "-- "
	string dash2;					// Couts the " --"
	string input;					// Couts the "Input: "
	string QContents;				// Couts the "Contents of Queue: "
	string SContents;				// Couts the "Contents of Stack: "
	char sp;

};
       

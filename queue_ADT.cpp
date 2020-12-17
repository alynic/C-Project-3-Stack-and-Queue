

#ifndef queue_ADT_H
#define queue_ADT_H

#include "queue_ADT.h"

// Purpose: The implementation of Queue operations for class template QueueType
template <class ItemType>
QueueType <ItemType> :: QueueType()
{
	front = NULL;			// Sets front to null
	rear = NULL;			// Sets rear to null
	input = "Input: ";		// Sets input as a string
	sp = ' ';				// Sets sp as a string
	dash1 = "\n\n-- ";		// Sets dash1 as a string
	dash2 = " --\n";		// Sets dash2 as a string
	QContents = "\nContents of Queue: ";	// Sets QContents as a string
	SContents = "\nContents of Stack:";		// Sets SContents as a string

}

// Was commented in stack_ADT header
template <class ItemType>
// Makes the list empty
void QueueType <ItemType> :: MakeEmpty()
{
	NodeType <ItemType>	*temp;			// Point to temp
	while (front != NULL)				// While front is not equal to null
	{
		temp = front;					// Initialize temp to the front
		front = front->link;			// Advance front to the link node
		delete temp;					// Delete the temporary pointer
	}

	rear = NULL;						// Initialize rear to NULL

}

template<class ItemType>
// Returns true if the queue is empty; false otherwise
bool QueueType <ItemType> :: IsEmpty() const
{
  return (front == NULL);
}

template <class ItemType>
// Checks to see if list is full
bool QueueType <ItemType> :: IsFull() const
{
	NodeType <ItemType> *location;			// Points to the location of the node
	try
	{
		location = new NodeType <ItemType>;	// Set the node
		delete location;					// Delete the location node
		return false;						// Return false
	}
	catch (bad_alloc exception)
	{
		return true;
	}

}

template <class ItemType>
// Grabs from file and puts it into a list
void QueueType <ItemType> :: Enqueue(ItemType newItem)
{
	if(IsFull())
		throw FullQueue();
	else
	{
		NodeType <ItemType> *newNode;		// Variable used to point to a new node

		newNode = new NodeType <ItemType>;	// Create the node
		newNode->info = newItem;			// Store the info into newItem
		newNode->link = NULL;				// Initialize the link field to NULL
	
		if (rear == NULL)					// If initially the queue is empty
			front = newNode;	
		else								// Add newNode at the end
			rear->link = newNode;
		
		rear = newNode;
	}

}

template <class ItemType>
// Function that builds a list
void QueueType <ItemType> :: BuildList(char& newItem, int count, bool& complete,ifstream& infile, ofstream& outfile)
{
	cout << dash1 << count << dash2 << input;
	outfile << dash1 << count << dash2 << input;
	while(infile >> newItem && newItem != ';')
	{
		Enqueue(newItem);
		cout << newItem << sp;
		outfile << newItem << sp;
	}
	
	Enqueue(newItem);						// Stores ';' in the list
	cout << newItem;
	outfile << newItem;
	
	if (front->info == ';')
		complete = true;

}

template <class ItemType>
// Function that prints the list
void QueueType <ItemType> :: PrintQueue(ofstream& outfile)
{
	cout << QContents;
	outfile << QContents;

	current = front;	// Sets front to current
	while(current->link != NULL)
	{
		cout << current->info << sp;
		outfile << current->info << sp;
		current = current->link;
	}

	cout << current->info << SContents;
	outfile << current->info << SContents;

}

template <class ItemType>
// Function that dequeues the list
void QueueType <ItemType> :: Dequeue(ItemType& newItem)
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
	  NodeType <ItemType> *temp;

	  temp = front;				// Set temp to point to the front
	  newItem = front->info;		// Set item the info of the front node
	  front = front->link;		// Set front to the link node
		

	  if (front == NULL)		// If after deletion the queue is empty
		  rear = NULL;			// Set rear to NULL
	  
	  delete temp;				// Delete the first node.
  }

}

template <class ItemType>
// Dequeues QueueType
QueueType <ItemType> :: ~QueueType()
{
	// Runs function MakeEmpty
	MakeEmpty();
}

#endif
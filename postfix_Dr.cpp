

#include "queue_ADT.cpp"
#include "stack_ADT.cpp"
#include "Central.h"

int main()
{
	// Declares and opens postfix file
	ifstream infile;
	infile.open ("postfix.in");
	ofstream outfile;
	outfile.open ("postfix.out");

	// Declares variables
	char newItem;
	int count = 1;
	bool complete = false;
	
	// Declares variables
	ControlType control;
	StackType <char> stack;
	QueueType <char> que;

	// Declares variables
	ControlType();
	QueueType <char>();
	StackType <char>();
	

	control.DisplayHeaders(control, outfile);

	// while loop that runs while complete is true
	// Builds the list, prints the queue, dequeues list, then stacks the list
	while(!complete)
	{
		que.BuildList(newItem, count, complete, infile, outfile);
		if (complete)
			break;
		else
		{
			que.PrintQueue(outfile);

			while (!que.IsEmpty())
			{
				que.Dequeue(newItem);
				stack.BuildStack(newItem, outfile);
			}
			
			stack.ShowResult(outfile);
			count++;			

		}
	}

	control.DisplayHeaders(control, outfile);
	// Dequeues queue
	que.~QueueType();
	// Dequeues stack
	stack.~StackType();

	// Closes files
	infile.close();
	outfile.close();

	return 0;
}
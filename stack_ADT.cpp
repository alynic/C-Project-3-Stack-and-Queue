

#ifndef stack_ADT_H
#define stack_ADT_H

#include "stack_ADT.h"

template <class ItemType>
StackType <ItemType> :: StackType()
{
	// Declares variables
	maxStack = 500;
	top = -1;
	items = new ItemType[maxStack];
	sp = ' ';
	col = ": ";
	par1 = '(';
	par2 = ')';
	result = "\n\t\tResult: ";
	push = "\n\t\tpush ";
	pop = "\n\t\tpop ";
}

// Was commented in stack_ADT header
template <class ItemType>
bool StackType <ItemType> :: IsEmpty() const
{
	return (top == -1);
}

template <class ItemType>
bool StackType <ItemType> :: IsFull() const
{
	return (top == maxStack - 1);
}

template <class ItemType>
void StackType <ItemType> :: Push(ItemType& newItem, ofstream& outfile)
{
	if (IsFull())
		throw FullStack();
	top++;
	items[top] = newItem;
	cout << push << items[top] << col;
	outfile << push << items[top] << col;

	switch (newItem)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		cout << newItem << sp;
		outfile << newItem << sp;
		for (int index = (top - 1); index >= 0; index--)
		{
			int temp;
			temp = (items[index] - '0');
			cout << temp << sp;
			outfile << temp << sp;
		}
		break;
	default:
		for (int index = top; index >= 0; index--)
		{
			int temp;
			temp = (items[index] - '0');
			cout << temp << sp;
			outfile << temp << sp;
		}
		break;
	}

}

template <class ItemType>
void StackType <ItemType> :: Pop(ofstream& outfile)
{
	if (IsEmpty())
		throw EmptyStack();
	
	switch (items[top])
	{
	case '+':
	case '-':
	case '*':
	case '/':
		cout << pop << items[top] << col;
		outfile << pop << items[top] << col;
		for (int index = (top - 1); index >= 0; index--)
		{
			int temp;
			temp = (items[index] - '0');
			cout << temp << sp;
			outfile << temp << sp;
		}
		break;
	default:
		cout << pop << (items[top] - '0') << col;
		outfile << pop << (items[top] - '0') << col;
		for (int index = (top - 1); index >= 0; index--)
		{
			int temp;
			temp = (items[index] - '0');
			cout << temp << sp;
			outfile << temp << sp;
		}
		break;
	}
	top--;

}

template <class ItemType>
void StackType <ItemType> :: BuildStack(char& newItem, ofstream& outfile)
{
	switch (newItem)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		Push(newItem, outfile);
		Calc(newItem, outfile);
		break;
	case ';':
		break;
	default:
		Push(newItem, outfile);
		break;
	}
	
}

template <class ItemType>
void StackType <ItemType> :: Calc(char& newItem, ofstream& outfile)
{
	switch (newItem)
	{
	case '+':
		left = (items[top - 2] - '0');
		right = (items[top - 1] - '0');
		answer = left + right;
		break;
	case '-':
		left = (items[top - 2] - '0');
		right = (items[top - 1] - '0');
		answer = left - right;
		break;
	case '*':
		left = (items[top - 2] - '0');
		right = (items[top - 1] - '0');
		answer = left * right;
		break;
	case '/':
		left = (items[top - 2] - '0');
		right = (items[top - 1] - '0');
		answer = left / right;
		break;
	}
	
	for(int index = 0; index < 3; index++)
	{
		Pop(outfile);
	}

	SpecialPush(newItem, outfile);
}

template <class ItemType>
void StackType <ItemType> :: SpecialPush(char& newItem, ofstream& outfile)
{
	cout << push << par1 << left << sp << newItem << sp << right << par2 << col;
	outfile << push << par1 << left << sp << newItem << sp << right << par2 << col;

	newItem = (answer + '0');

	
	if (IsFull())
		throw FullStack();
	top++;
	items[top] = static_cast<int> (newItem);
	
	cout << answer;
	outfile << answer;
	for (int index = (top - 1); index >= 0; index--)
	{
		cout << sp << items[index];
		outfile << sp << items[index];
	}

}

template <class ItemType>
void StackType <ItemType> :: ShowResult(ofstream& outfile)
{

	cout << pop << answer << col;
	outfile << pop << answer << col;
	top--;
	cout << result << answer;
	outfile << result << answer;

}

#endif
/*
Stack is implemented using arrays with push, pop, top, print functions being defined
We are using a pointer tp to keep note of top of stack

TC - O(1) for each of push(), pop(), top()
   - O(n) for print() - since all elements will be printed
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define size 100

int arr[size];

//defining an empty stack
int tp=-1;

void push(int x)
{
	//if stack is full then we can not push elements
	if(tp==(size-1))
	{
		cout<<"Stack Overflow!"<<endl;
		return;
	}
	tp++;
	arr[tp]=x;
}

void pop()
{
	//is stack is empty then we can not pop elements
	if(tp==-1)
	{
		cout<<"Stack is empty!"<<endl;
		return;
	}
	//adjusting pointer to point to element below topmost element
	tp--;
}

int top()
{
	return arr[tp];
}

int print()
{
	cout<<"Stack is:";
	for(int i=tp;i>=0;i--)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	push(2);
	push(3);
	push(4);
	push(5);
	print();
	cout<<"After Popping:";
	pop();
	print();
	push(6);
	cout<<"After Pushing:";
	print();
}

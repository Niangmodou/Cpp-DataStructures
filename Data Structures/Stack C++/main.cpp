#include <iostream>
#include <ctime> 
#include "Stack.h"

using namespace std;

void generateNumbers(Queue<int> &queue);

int main(){
	Stack<int> myStack;

	cout << "Adding numbers from 1 - 100 in Queue ..." << endl << endl;

	generateNumbers(myStack);

	cout << "Elements Enqueued! " << endl << endl;

	cout << "Printing Results ... " << endl;

	cout << myStack();

	cout << endl << "RUN FINISHED; ";
	return 0;
}

void generateNumbers(Stack<int>& stack){

	srand(time(0)); 
    int randInt; 
    for(int index=0; index<20; index++){ 
        randInt = (rand()%100)+1; 
       	stack.push(randInt);
    }
}
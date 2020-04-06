#include <iostream>
#include <ctime> 
#include "Queue.h"

using namespace std;

void generateNumbers(Queue<int> &queue);

int main(){
	Queue<int> myQueue;

	cout << "Adding numbers from 1 - 100 in Queue ..." << endl << endl;

	generateNumbers(myQueue);

	cout << "Elements Enqueued! " << endl << endl;

	cout << "Printing Results ... " << endl;

	cout << myQueue;

	cout << endl << "RUN FINISHED; ";
	return 0;
}

void generateNumbers(Queue<int>& queue){

	srand(time(0)); 
    int randInt; 
    for(int index=0; index<20; index++){ 
        randInt = (rand()%100)+1; 
       	queue.enqueue(randInt);
    }
}

#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

int main(){
	ArrayMap map;

	cout << "Task 1: Inserting into map" << endl;
	cout << map << endl;
	map.insert(12345,"Modou");
	map.insert(91798,"Chris");
	map.insert(13579,"Travis Scott");
	map.insert(90173,"Juice Wrld");
	map.insert(90210,"Trav$ Scott");

	cout << "Task 2: Printing the map" << endl; 
	cout << map << endl;

	cout << "Task 3: Removing from the map" << endl;
	while(!map.empty()){
		cout << "Removing ..." << endl;
	}

	cout << "Task 4: Printing the map" << endl;
	cout << map << endl;


}
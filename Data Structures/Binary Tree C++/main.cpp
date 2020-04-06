#include <iostream>
#include "tree.h"

using namespace std;

int main(){

	BinaryTree tree;

}

long carParkingRoof(vector<long> cars, int k) {
    set<long> lengths; //stores the unique possible roof lengths
    sort(cars.begin(),cars.end());

    for(size_t i = 0; i < cars.size(); ++i){
        vector<int> subCars;
        for(int j = i; j < (k+i); ++j){
            subCars.push_back(cars[j]);
        }
        long roofLength = 1 + subCars[subCars.size()-1] - subCars[0];
        lengths.insert(roofLength);
    }

    return abs(*min_element(lengths.begin(),lengths.end()));
}
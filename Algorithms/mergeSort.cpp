#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>&);

vector<int> merge(vector<int>&,vector<int>&);

void printVector(const vector<int>&);

int main(){
	vector<int> myVec{2,3,7,5,1,9,0,10,11};
	cout << "Before Sort: "; 
	printVector(myVec);
	mergeSort(myVec);
	cout << "After Sort: ";
	printVector(myVec);
}

void printVector(const vector<int>& arr){
	for(int n : arr) cout << n << " ";
	cout << endl;
}

void mergeSort(vector<int>& arr){
	if(arr.size() <= 1) return;

	int mid = arr.size()/2;
	vector<int> left(arr.begin(),arr.begin()+mid);
	vector<int> right(arr.begin()+mid,arr.end());
	mergeSort(left);
	mergeSort(right);
	arr = merge(left,right);
}


vector<int> merge(vector<int>& left,vector<int>& right){
	vector<int> result;

	size_t l = 0;
	size_t r = 0;
 
	while(l < left.size() && r < right.size()){
		if(left[l] < right[r]){
			result.push_back(left[l]);
			l++;
		}else{
			result.push_back(right[r]);
			r++;
		}
	}

	while(l < left.size()){
		result.push_back(left[l]);
		l++;
	}

	while(r < right.size()){
		result.push_back(right[r]);
		r++;
	}

	return result;
}

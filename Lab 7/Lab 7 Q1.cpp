#include <iostream>
using namespace std; 

int search (int a[], int size, int y){
	int low = 0;
	int high = size-1; 
	
	while (low <=high){
		int mid = (low + high)/2;
		
		if (a[mid]==y)
		return mid;
		
		else if (a[mid]<y)
		low = mid+1;
		
		else 
		high = mid-1; 
	}
	
	return -1;
}

int main (){
	int size; 
	cout << "Enter array size: ";
	cin >> size; 
	
	int a[size];
	
	for (int i=0;i <size; i++){
		cout << "Enter element"<<i+1 <<": ";
		cin >> a[i];
	}
	
	int search_element;
	cout << "Enter element to search: ";
	cin >> search_element; 
	
	int result = search (a, size, search_element);
	
	if (result != -1)
	cout << "Element found at index "<<result <<endl;
	
	else 
	cout << "Element not found"<<endl; 
	return 0; 
}

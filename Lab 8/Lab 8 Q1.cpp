#include <iostream>
#include <string>
using namespace std; 

int trucanteKey (int key){
	return key / 100; 
}

int main () {
	const int SIZE =5;
	int keys [SIZE];
	int hashIndices[SIZE];
	
	for (int i = 0; i<SIZE; i++){
		cout << "Enter key "<<i+1 <<": ";
		cin >> keys[i];
		
		if (keys[i] < 1000 || keys[i]>9999){
			cout << "Input out of range"<<endl;
			i --;
			continue; 
		}
		
		hashIndices[i] = trucanteKey(keys[i]);
	}
	
	for (int i = 0; i <SIZE; i++){
		cout << "Key: "<<keys[i]<< " Has Index: "<<hashIndices[i]<<endl;
	}
	return 0;
}

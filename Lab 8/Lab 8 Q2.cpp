#include <iostream>
#include <string>
using namespace std; 

int calculateHashValue (string id){
	int portion1 = stoi(id.substr(0, 3));
	int portion2 = stoi(id.substr(3,3));
	int portion3 = stoi(id.substr(6,4));
	
	int hashValue = (portion1+ portion2+ portion3)%100;
	return hashValue; 
}

int main (){
	string studentId;
	cout << "Enter ID: ";
	cin >> studentId; 
	
	int hashValue = calculateHashValue (studentId);
	
	cout << "Hash Value "<<hashValue << endl;
	
	return 0;
}

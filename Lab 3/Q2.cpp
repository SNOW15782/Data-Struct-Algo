#include <iostream>
#include <stack>

using namespace std; 
int main (){
	
	stack<int> s;
	int input;
	//even number
	int evenCount = 0;
	//odd number 
	int oddCount = 0;
	
	cout << "Enter 10 numbers: ";
	for (int i = 0; i<10; i++){
		cin >> input;
		s.push(input);
	}
	
	cout << "Numbers entered are: ";
	//declare another char for stack 
	while (!s.empty()){
		
		int num = s.top();
		cout << num << " ";
		
		if (num % 2 == 0){
			evenCount++;
		}
		
		else {
			oddCount++; 
		}
		
		s.pop();
	}
	
	cout << "\nThere are " << evenCount << " even numbers and " << oddCount << " odd numbers. ";
	return 0;
}

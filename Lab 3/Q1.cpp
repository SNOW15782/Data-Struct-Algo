#include <iostream>
//to use stack
#include <stack>
#include <string>

using namespace std;

int main (){
	
	stack <char> s;
	string input;
	
	//key in input
	cout << "Key in five characters: ";
	getline (cin,input);
	
	//loop 
	//initialize 1 new char 
	for (char c:input){
		//insert stack 
		s.push(c);
	}
	
	cout <<"The reverse order is: ";
	//while loop that continues as long as the s is not empty
	while (!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	
	cout << endl; 
	
	return 0;
}

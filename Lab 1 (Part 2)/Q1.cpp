#include <iostream>
using namespace std; 

int main (){
	char op;
	int num1;
	int num2;
	
	cout << "Enter an Operator (+,-,*,/): ";
	cin >> op; 
	
	cout << "Enter two operands: ";
	cin >> num1 >>num2; 
	
	switch (op){
		case '+':
			cout << num1 << "+" << num2 << "=" <<num1+num2<<endl;
			break;
		
		case '-':
			cout << num1 << "-" << num2 << "=" <<num1-num2<<endl;
			break;
			
		case '*':
			cout << num1 << "*" << num2 << "=" <<num1*num2<<endl;
			break;
			
		case '/':
			cout << num1 << "/" << num2 << "=" <<num1/num2<<endl;
			break;
			
		default: 
		cout << "Invalid operator"<<endl; 
		break;
	}
	return 0; 
}

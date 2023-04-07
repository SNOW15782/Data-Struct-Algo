#include <iostream>
using namespace std; 

void passByReference (int& num){
num +=5;	
}

void passByValue (int num){
num +=5;
}

int main ()
{
int value1;
int value2; 

cout << "Enter value 1 :";
cin >> value1;

cout << "Enter value 2 :"; 
cin >> value2; 

passByReference (value1);
cout << "The effect of passing value1 by reference is: "<<value1 <<endl;



passByValue (value2);
cout << "The effect of passing value2 by value is: "<<value2 <<endl;

return 0; 

}

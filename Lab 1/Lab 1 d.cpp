//MUHAMAD ARIF BIN SALLEHUDDIN
//1211206128
// Online IDE - Code Editor, Compiler, Interpreter
#include<iostream>
using namespace std;
int SumDigit(int num);
int main()
{
    int n1, sum;
	cout<< "\n\n Recursion : Find the sum of digits of a number :\n";
	cout<< "-----------------------------------------------------\n";     
    cout<< " Input any number to find sum of digits: \n";
    cin>> n1;
     sum = SumDigit (n1);//call the function for calculation
     cout<<" The Sum of digits of " << n1 << " is " << sum;
     return 0;
}
int SumDigit (int n1)
{
    if(n1 == 0)
        return 0;
         
    return ((n1 % 10) + SumDigit (n1 / 10));//calling the function SumDigit itself
}


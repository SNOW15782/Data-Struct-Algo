//MUHAMAD ARIF BIN SALLEHUDDIN
//1211206128
#include <iostream>
using namespace std; 

int main ()
{
	
int num; 
//loop using do while loop 
do {
//ask user to input a number 
cout << "Type a number (0 to exit): "; 
cin >> num; 
if (num!= 0)
{
	// if number remainder got 2
	if (num%2 == 0)
	{
	 cout <<num << " is even"<<endl;
	}
	// else not remainder got 2
else {
	cout <<num << " is odd" <<endl;
}	
}
//num!=0 to exit the code sebab nanti karang infinite loop
}while (num!= 0);

cout << "Thank you.";
	return 0; 
}


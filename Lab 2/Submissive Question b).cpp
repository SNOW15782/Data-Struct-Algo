#include <iostream>
using namespace std; 

int main ()
{
	//Declare character pointer variable ptr and initialize it with a string 
	char *ptr = "Data Structure and Alogorithm";
	
	//output the chracter pointed by ptr which is 'D'
	cout << *ptr;
	
	//increment pointer by 5, so it point to the 6 element /character S
	ptr += 5;
	
	//output will be S
	cout << *ptr;
	
	//increment pointer by 14,after the current position so it point to A,
	cout << *(ptr+14)<<endl; 
return 0;	
}

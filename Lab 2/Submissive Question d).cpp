#include <iostream>
using namespace std; 

//global function take integer reference and an interger argument
void add(int &v1, int v2);


int main ()
{
	//declare integer with 4 elements
	int array[]={10,20,30,40};
	
	//declare two interger pointer variable x and y
	int *x, *y;
	//declare 2 integraible a and b and initialize to 2 and 4
	int a=2, b=4;
	
	//assign the address of the 1st element of the array to pointer x 
	x = array;
	// Compute the value of b by adding the value of the fourth element of the array to the value of the first element of the array plus 2
	b = *(x+3) + (*x+2);
	
	//output of b to the console 
	cout <<"b = "<<b<<endl;
	
	//address of b pointed to y 
	y = &b;
	
	// Assign the value of the memory location pointed to by y (which is b) plus 4 to the memory location pointed to by x (which is the first element of the array)
	*x = *y + 4; 
	
	//output the value of a to the console 
	cout <<array [0]<<endl;
	
	// Declare a reference variable c and initialize it to a
	int &c = a;
	
	// Assign the value of the second element of the array plus the value of b to the reference variable c
	c = x[1] + *y;
	cout << "a = "<<a<<endl;
	 // Call the add function with arguments c (which is a reference to a) and the third element of the array
	add (c, array[2]);
	
	// Output the value of the reference variable c to the console
	cout << "c = "<<c<<endl;
	
	// Output the value of the third element of the array (which was not modified by the previous statements) to the console
	cout << *(x+2)<<endl; 
	return 0;
}
// Define the add function, which takes an integer reference and an integer argument
void add (int &v1, int v2)
{
	// Add 2 to the value of the integer reference v1
	v1 = v1 + 2;
	// Add 2 to the value of the integer argument v2 (this statement has no effect outside of the function)
	v2 = v2 + 2; 
}

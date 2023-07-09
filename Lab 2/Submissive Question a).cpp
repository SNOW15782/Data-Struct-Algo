#include <iostream>
using namespace std; 

int main ()
{
	//initialize an array with 5 element 
	int arr[5] = {1,2,3,4,5};
	
	//initialize variable 
	int a, b, *ptr;
	
	//ptr to point to first element of arr
	ptr = arr;
	
	//Assign value of 1st element of arr to a after adding 10 to it
	a = *ptr + 10;
	
	//increment by 2, making it point to the third element of arr. so 10+2 = 12
	ptr += 2;
	
	//Assing value of 3rd element of arr to b after minus 5 from it. 5-3
	b = *ptr - 5;
	
	//output
	cout << *ptr << "\n" << a << "\n" << b << endl;
	return 0;
}

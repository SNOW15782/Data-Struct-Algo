#include <iostream>
using namespace std; 

int main ()
{
	//initialized variable 
	int *a,*b,*c,d,e;
	
	//asign d address to pointer a 
	a=&d;
	
	//assign 3+10 (13) to mememory located by a (which is the variable d)
	*a = 3+10;
	
	//Assign the address of variable e to pointer b
	b=&e;
	
	//assign a (which is 13) plus 3 to memory location point to b (which is the variable e)
	*b=*a+3;
	
	//pointer b to pointer c (so now both b and c point to variable e)
	c=b;
	
	//Assingm the value of memory location pointed to by c (which is the variable e) + the value of the memory location pointed by a (which is 13)
	d=*c + *a;
	
	// Assign the value of the memory location pointed to by c (which is the variable e) to the memory location pointed to by c
    // This changes the value of e to the sum of the value of the memory location pointed to by a (which is 13) and the original value of e (which is currently uninitialized)
	*c=*a+e;
	
	//output
	cout << *a << " "<<*b <<" "<<*c << " "<<d << " "<< e; 
	return 0;
}

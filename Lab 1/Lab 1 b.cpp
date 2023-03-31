//MUHAMAD ARIF BIN SALLEHUDDIN
//1211206128
#include <iostream>
using namespace std; 

int main ()
{
int a;
int b;
int c;
int d; 
cout << "Enter four intergers: "<<endl;
//input 4 numbers 
cin >> a >> b >> c >> d;

int max_num = a; 

if (b > max_num)
{
	max_num = b;
}

if (c > max_num) 
{
    max_num = c;
}

if (d > max_num) 
{
    max_num = d;
}

cout << "maximum number : "<<max_num<<endl;
return 0; 	
}

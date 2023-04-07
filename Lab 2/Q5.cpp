#include <iostream>
using namespace std; 

int main ()
{
	int i;
	int n;
	float sum, avg; 
	float *p; 

cout << "How many marks would you like to enter: ";
cin >> i;

p = new float [i];
for (n=0; n<i; n++)
{
	cout << "Enter marks "<< n+1 << ": ";
	cin >> p[n];
	sum += p[n];
}

cout << "You have entered: ";
for (n=0; n <i; n++)
{
	cout << p[n];
	if (n != i-1)
	{
	
	cout << ", "; 
}
}


avg = sum / i;

cout << "\nSum of marks is: "<<sum <<endl;
cout << "Average marks is: "<<avg <<endl; 

delete [] p;
return 0; 

}

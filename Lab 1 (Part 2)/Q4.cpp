#include <iostream>
using namespace std; 

void Sum (int arr[], int size){
	int sum=0;
	//loop sum of the number 
	for (int i=0; i<size; i++){
		sum += arr[i];
	}
	cout << "Sum of the numbers entered is : "<<sum<<endl;
}

int main ()
{
int arr[5];

cout << "Enter five numbers and the program will calculate sum of the number."<<endl;
for (int i =0; i<5; i++){
	cout << "Enter number "<<i+1 <<" : ";
	cin >> arr[i];
}

cout <<"You have entered: ";
for (int i = 0; i<5; i++){
	cout << arr[i];
	if (i<4){
		cout << ", ";
	}
}

cout << endl;
Sum(arr, 5);

return 0;
}

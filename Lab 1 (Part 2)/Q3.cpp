#include <iostream>
using namespace std;

int main (){
	
	int mark[5], sum = 0, i = 0;
	
	while (i<5){
		cout << "Enter mark: " ;
		cin >> mark[i];
		sum = sum + mark[i]; 
		i++;
	}
	
	double avg = sum / 5;
	cout <<"Mark average is: "<<avg<<endl; 
return 0;
}

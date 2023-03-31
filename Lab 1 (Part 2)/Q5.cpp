#include <iostream>
#include <string.h>
using namespace std; 

struct employee{
	string first_name;
	string last_name;
	string emp_num;
	int age; 
		
};

int main (){
	employee record; 
	
	cout << "First name: ";
	getline (cin, record.first_name);
	
	cout << "Last name: ";
	getline (cin, record.last_name);
	
	cout << "Employee number: "; 
	getline (cin,record.emp_num);
	
	cout << "Age: ";
	cin >> record.age;
	
	cout <<endl;
	
	cout <<"Hello "<<record.first_name<<endl;
	cout <<"Your Employee number "<<record.emp_num<<endl;
	cout <<"You are "<<record.age <<" years old"<<endl; 
	
	return 0;
}

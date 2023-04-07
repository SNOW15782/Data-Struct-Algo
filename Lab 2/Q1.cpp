#include <iostream>
using namespace std; 

struct employee {
	string name;
	float salary; 
		
};

int main ()
{
	int numEmployees; 
	
	cout << "Enter number of employees: ";
	cin >> numEmployees;
	
	//create dynamic array 
	
	employee* employees = new employee[numEmployees];
	
	//loop 
	
	for (int i=0; i <numEmployees; i++)
	{
		cout << "\nEmployee " << i+1 << endl;
		cout << "\tEnter name : ";
		cin >> employees[i].name;
		
		cout << "Enter Salary: ";
		cin >> employees[i].salary;
		
	}
	
	//print out the list of emplpyees 
	cout << endl << "Employees List: "<<endl;
	for (int i = 0; i <numEmployees; i++)
	{
		cout << "Name : " << employees[i].name<<endl;
		cout << "Salary : " << employees[i].salary << endl; 
	}

delete [] employees; 

return 0;

}



#include <iostream>
using namespace std; 

class BMI {
	private : 
	float height;
	float weight;
	float bmi;
	
	public: 
	BMI ()
	{
	height = 1.0;
	weight = 1.0; 	
	 } 
	 
	void set (float h, float w)
	{
		height = h;
		weight = w;
	}
	
	void calculate () 
	{
		bmi = weight / (height * height);
	}
	
	void display ()
	{
		cout << "Your bmi is : "<< bmi << endl; 
		//if else 
		
		if (bmi < 18.5)
		{
			cout << "You are underweight "<<endl;
		}
		else if (bmi >=18.5 && bmi <= 24.9)
		{	
			cout << "You are Normal" << endl; 
		}
		
		else if (bmi >=25.0 && bmi <= 29.9)
		{
			cout << "You are  Overweight" <<endl; 	
		}
		else {
			cout << "You are obese" <<endl;
		}
	}
	
};

int main ()
{
	float height; 
	float weight; 
	
	cout << "This program will calculate your body mass index."<<endl;
	cout << "Enter your height in meter (m) unit : ";
	cin >> height;
	
	cout << "Enter your weight in kilogram (kg) unit : ";
	cin >> weight;
	
	BMI bmi;
	bmi.set(height,weight);
	bmi.calculate();
	bmi.display(); 
}

#include <iostream>
using namespace std; 

class Box {
	public:
		float length; 
		float breadth;
		float height; 
		
		float getVolume ()
		{
			return length*breadth*height;
		}
};

int main ()
{
	Box box1;
	box1.length = 5.0;
	box1.breadth = 6.0;
	box1.height = 7.0;
	
	Box box2;
	box2.length = 10.0;
	box2.breadth = 12.0;
	box2.height = 13.0;
	
	cout << "volume of Box 1: "<<box1.getVolume()<<endl;
	cout << "volume of Box 2: "<<box2.getVolume()<<endl;
	
	return 0; 
}

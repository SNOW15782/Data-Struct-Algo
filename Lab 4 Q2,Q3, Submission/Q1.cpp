#include <iostream>
#include <string>
#include <queue>

using namespace std; 

struct Person {
	string name;
	int flavor;
};

class ADTqueue{
	private: 
	queue <Person> items; 
	
	public:
		bool is_empty(){
			return items.empty();
		}
		
		void enqueue(Person item){
			items.push(item);
		}
		
		Person dequeue(){
			Person item = items.front();
			items.pop();
			return item; 
		}
		
		int size(){
			return items.size();
		}
};

int main (){
	cout <<  "Do you know that the flavor of ice cream can reveal one's personality\n";
	
	Person p;
	ADTqueue q; 
	
	for (int i = 0; i < 2 ; i++){
	
	cout << "Enter name: ";
	getline(cin, p.name);
	
	cout << "Enter favourite: "<<endl;
	cout << "(1=chocolate 2=vanilla 3=strawberry 4=mixed flavor)"<<endl;
	cin >>  p.flavor;
	
	cin.ignore(); //ignore newline chacter left by cin
	q.enqueue(p);
	}
	
	while (!q.is_empty()){
		p = q.dequeue();
		string name = p.name;
		int flavor = p.flavor;
		string personality; 
		switch (flavor){
			case 1:
				personality = "Sensitive and often daydreaming about past and future."; 
				break; 
				
			case 2:
				personality = "Friendly, easygoing and has many friends.";
				break;
				
			case 3: 
				personality = "Affectionate, giving, loving and very understanding.";
				break;
				
			case 4:
				personality = "Negotiator and will do anything to avoid open conflict";
				break;
				
			default:
				personality = "Unknown personality";
				break; 
		}
		
		cout << name << "\t" << personality << endl; 
	}

return 0;
}

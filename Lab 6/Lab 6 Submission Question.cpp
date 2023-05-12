#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class ADTstack
{
    private:
        node *top;

    public:
        ADTstack()
        {
            top = NULL;
        }
        int empty()
        {
            if(top == NULL)
                return 1;
            else
                return 0;
        }
        void push(int num)
        {
            node *temp;
            temp = new node;
            temp->data = num;

            if(top == NULL)
            {
                top = temp;
                temp->next = NULL;
            }
            else
            {
                temp->next = top;
                top = temp;
            }
        }
        int pop()
        {
            int num=0;
            node *temp;

            if(!empty())
            {
                num = top->data;
                temp = top;
                top = top->next;
                delete temp;
                return num;
            }
            else
            {
                cout<<"Stack is Empty\n";
                return 0;
            }

        }
        void display()
        {
            node* temp = top;
            cout<<"Data in the stack : "<<endl;

            while(temp != NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};

int main()
{
    ADTstack st;

    int ans, number;

    cout<<"1 : Push"<<endl;
    cout<<"2 : Pop"<<endl;
    cout<<"3 : Exit"<<endl;

    int choice, value;

    do{
        cout<<"\nEnter Operation to perform: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter value to push: ";
            cin>>value;
            st.push(value);
        }
        else if(choice==2)
        {
            if(!st.empty())
            {
                cout<<"Number popped: "<<st.pop()<<endl; 
            }  
            else
            {
                st.pop();
            }
        }
        else if(choice==3)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }
    }while(choice!=3);

    st.display();

    system("pause");
    return 0;
}

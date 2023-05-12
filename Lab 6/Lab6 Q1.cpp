#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class ADTqueue
{
    private:
        node *front, *rear;

    public:
        ADTqueue()
        {
            front=NULL;
            rear=NULL;
        }
        int empty()
        {
            if(front==NULL)
                return 1;
            else
                return 0;
        }
        void append(int num)
        {
            if(rear!=NULL)
            {
                rear->next=new node;
                rear=rear->next;
                rear->data=num;
                rear->next=NULL;
            }
            else
            {
                front=rear=new node;
                front->data=num;
                front->next=NULL;
            }
        }
        int serve()
        {
            int num;

            if(!empty())
            {
                num=front->data;
                node *temp=front;
                front=front->next;
                delete temp;

                if(front==NULL)
                    rear=NULL;

                return num;
            }
            else
            {
                cout<<"Queue is empty";
                return 0;
            }

        }
        void traverse()
        {
            node *temp;
            temp=front;

            while(temp!=NULL)
            {
                cout<<temp->data <<" ";
                temp=temp->next;
            }
        }
};

int main()
{
    ADTqueue q;
    int n, num, sum=0;

    cout<<"How many integers you want to append into the queue? ";
    cin>>n;
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter integer "<<i+1<<" to the queue : ";
        cin>>num;
        q.append(num);
    }

    cout<<"\nThe integers that were append onto the queue are : \n";

    q.traverse();

    cout<<"\n\nThe sum of the integers is : "<<endl;

    while(!q.empty())
    {
        sum+=q.serve();
    }
    cout<<sum<<endl;

    system("pause");
    return 0;

}

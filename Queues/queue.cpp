//QUEUE & ITS IMPLEMENTATION USING ARRAYS
#include<iostream>
using namespace std;

#define MAX 50

class queue_array {
    int queue[MAX],rear,front;
    public:
        queue_array() {
            rear = -1;
            front = -1;
        }
    void insert();
    void del();
    void traverse();
    void peek();
};
void queue_array :: insert() {
    int item;
    if (rear==MAX-1) {
        cout<<"\nQueue overflow";
    }
    else {
        if(front==-1)
            front=0;
        cout<<"\nEnter the element : ";
        cin>>item;
        rear=rear+1;
        queue[rear]=item;
    }
}
void queue_array :: del() {
    int item;
    if (front == -1 || front > rear) {
        cout<<"\nQueue underflow";
    }
    else {
        cout<<"\nDeleted element is : "<<queue[front];
        front = front + 1;
    }
}
void queue_array :: traverse() {
    int i;
    if (front == -1 || front > rear) {
        cout<<"\nQueue is empty!";
    }
    else {
        cout<<"\nQueue is :\n";
        for (i=front; i<=rear; i++) {
            cout<<queue[i]<<" ";
        }
    }
}
void queue_array :: peek() {
    if (front == -1 || front > rear) {
        cout<<"\nQueue is empty!";
    }
    else {
        cout<<"\nelement at top is : "<<queue[front];
    }
}
int main() {
    int choice;
    char ch;
    queue_array ps;
    do
    {

        cout<<"\n1. insert";
        cout<<"\n2. del";
        cout<<"\n3. TRAVERSE";
        cout<<"\n4. PEEK";
        cout<<"\nEnter your Choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            ps.insert();
            break;

            case 2:
            ps.del();
            break;

            case 3:
            ps.traverse();
            break;

            case 4:
            ps.peek();
            break;

            default:
            cout<<"\n Error";
        }
        cout<<"\n\nPress (Y/y) to continue = ";
        cin>>ch;
    } while (ch == 'Y' || ch == 'y');

}

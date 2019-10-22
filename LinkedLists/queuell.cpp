//PROGRAM TO INPLEMENT QUEUE USING LINKED LISTS
#include<iostream>
#include<process.h>
#include<stdlib.h>
using namespace std;

class queuell {
  struct queue {
    int info;
    struct queue *link;
  };
  struct queue *front;  struct queue *rear;
  typedef struct queue *NODE;
  public :
    queuell() {
      front = NULL;
      rear = NULL;
    }
    void enqueue();
    void dqueue();
    void traverse();
};
void queuell :: enqueue() {
    NODE temp;
    temp=(NODE)new(struct queue);
    cout<<"\nEnter the number : ";
    cin>>temp->info;
    temp->link=NULL;
    if(rear!=NULL)
          rear->link=temp;
    rear=temp;
    if(front == NULL)
          front = rear;
}
void queuell :: dqueue() {
    if(front == NULL) {
        cout<<"\nEmpty queue!";
        rear = NULL;
    }
    else {
        cout<<"\nElement deleted : "<<front->info;
        if(front!=rear)
            front = front->link;
        else
            front = NULL;
    }
}
void queuell :: traverse() {
    if(front == NULL) {
        cout<<"\nEmpty queue!";
    }
    else {
        NODE temp=front;
        cout<<"\nElements are : ";
        while(temp != rear) {
          cout<<temp->info<<" ";
          temp=temp->link;
        };
        cout<<temp->info;
    }
}
int main() {
    int c;
    queuell o;
    while(1) {
      cout<<"\n1. INSERT";
      cout<<"\n2. DELETE";
      cout<<"\n3. TRAVERSE";
      cout<<"\n4. QUIT";
      cout<<"\nEnter your choice : ";
      cin>>c;
      switch(c) {
          case 1 : o.enqueue(); cout<<"-------------------";
                   break;
          case 2 : o.dqueue(); cout<<"\n-------------------";
                   break;
          case 3 : o.traverse(); cout<<"\n-------------------";
                   break;
          case 4 : cout<<"-------------------"; exit(1);
          default : cout<<"\nERROR!\n";
      }
    };
}

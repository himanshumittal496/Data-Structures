//PROGRAM TO IMPLEMENT STACKS USING LINKED LISTS
#include <iostream>
#include <process.h>
using namespace std;

class stackll {
  struct node {
    int info;
    struct node *link;
  };
  struct node *top;
  typedef struct node *NODE;
  public :
    stackll() {
      top=NULL;
    }
    void push();
    void pop();
    void traverse();
};
void stackll :: push() {
      NODE temp;
      int item;
      temp=(NODE)new(struct node);
      cout<<"\nEnter the element : ";
      cin>>item;
      temp->info=item;
      temp->link=top;
      top=temp;
}
void stackll :: pop() {
      if(top == NULL) {
        cout<<"\nEmpty stack!";
      }
      else {
        NODE temp = top;
        cout<<"\nPopped item is : "<<temp->info;
        top=top->link;
        temp->link=NULL;
        delete(temp);
      }
}
void stackll :: traverse() {
      if (top == NULL) {
        cout<<"\nEmpty stack!";
      }
      else {
        NODE temp = top;
        cout<<"\nStack elements are : \n";
        while(temp!=NULL) {
          cout<<"\n"<<temp->info;
          temp = temp->link;
        }
      }
}
int main() {
  int c;
  stackll o;
  cout<<"\n--------- STACK IMPLEMENTATION----------\n";
  while(1) {
    cout<<"\n1. PUSH";
    cout<<"\n2. POP";
    cout<<"\n3. TRAVERSE";
    cout<<"\n4. QUIT";
    cout<<"\n\nEnter your choice : ";
    cin>>c;
    switch(c) {
      case 1 : o.push(); cout<<"-------------------";
               break;
      case 2 : o.pop(); cout<<"\n-------------------";
               break;
      case 3 : o.traverse(); cout<<"\n-------------------";
               break;
      case 4 : cout<<"-------------------"; exit(1);
      default : cout<<"\nERROR!!!\n";
    }
  }
}

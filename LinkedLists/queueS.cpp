//PROGRAM TO IMPLEMENT QUEUE USING STACKS
#include<iostream>
#include<process.h>
using namespace std;

class queueS {
  struct stack {
    int info;
    struct stack *link;
  };
  struct stack *top;
  typedef struct stack *NODE;
  public :
  queueS() {
    top = NULL;
  }
    void push();
    void pop();
    void traverse();
};
void queueS :: push() {
    NODE temp;
    temp=(NODE)new(struct stack);
    temp->link=top;
    cout<<"\nEnter the element : ";
    top=temp;
    cin>>temp->info;

}
int main() {
    queueS o;
    o.push();
}

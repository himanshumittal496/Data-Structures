//STACK  &  ITS  IMPLEMENTATION  USING  ARRAYS

#include <iostream>
using namespace std;
#define MAXSIZE 100

class stack_array
{
    int stack[MAXSIZE];
    int top;
     public:
     stack_array()
     {
         top=-1;
     }
     void push();
     void pop();
     void traverse();
     void peek();
};
void stack_array::push()
{
    int item;
    if(top==MAXSIZE-1)
    {
        cout<<"\nThe Stack is Full";
    }
    else
    {
        cout<<"\nEnter the element to be Inserted = ";
        cin>>item;
        stack[++top]=item;
    }

}
void stack_array::pop()
{
    int item;
    if(top==-1)
        cout<<"\nThe Stack is Empty";
    else
    {
        item=stack[top--];
        cout<<"\nThe deleted item is = "<<item;
    }
}
void stack_array::traverse()
{
    int i;
    if(top==-1)
        cout<<"\nThe Stack is Empty";
        else
        {
            cout<<"\nThe element(s) in the stack(s) is/are...";
            for(i=top;i>=0;i--)
                cout<<"\n"<<stack[i];
        }
}
void stack_array::peek()
{
    if(top==-1)
        cout<<"\nThe Stack is Empty";
        else
        {
            cout<<"\nElement at Top is "<<stack[top];
        }
}

int main()
{
    int c;
    stack_array ps;
    while(1)
    {

        cout<<"\n1. PUSH";
        cout<<"\n2. POP";
        cout<<"\n3. TRAVERSE";
        cout<<"\n4. PEEK";
        cout<<"\n5. QUIT";
        cout<<"\nEnter your Choice : ";
        cin>>c;

        switch(c)
        {
            case 1:
            ps.push();
            break;

            case 2:
            ps.pop();
            break;

            case 3:
            ps.traverse();
            break;

            case 4:
            ps.peek();
            break;

            case 5:
            exit(0);

            default:
            cout<<"\n Error";
        }

    }

}

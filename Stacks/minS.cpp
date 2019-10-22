#include<iostream>
using namespace std;

class Stack
{
private:
    static const int max = 100;
    int arr[max];
public:
  int top;
    Stack() { top = -1; }
    bool isEmpty();
    bool isFull();
    int pop();
    void push(int x);
    void traverse();
};

bool Stack::isEmpty() {
    if(top == -1)
        return true;
    return false;
}

bool Stack::isFull() {
    if(top == max - 1)
        return true;
    return false;
}

int Stack::pop() {
    if(isEmpty()) {
        cout<<"Stack Underflow";
        abort();
    }
    int x = arr[top];
    top--;
    return x;
}

void Stack::push(int x) {
    if(isFull()) {
        cout<<"Stack Overflow";
        abort();
    }
    top++;
    arr[top] = x;
}
void Stack::traverse() {
    int i;
    if(top==-1)
        cout<<"\nThe Stack is Empty";
        else {
            cout<<"\nThe element are...";
            for(i=top;i>=0;i--)
                cout<<"\n"<<arr[i];
        }
}

class SpecialStack: public Stack {
    Stack min;
public:
    int pop();
    void push(int x);
    void getMin();
};

void SpecialStack::push(int x) {
    if(isEmpty()==true) {
        Stack::push(x);
        min.push(x);
    }
    else {
        Stack::push(x);
        int y = min.pop();
        min.push(y);
        if( x < y )
          min.push(x);
        else
          min.push(y);
    }
}
int SpecialStack::pop() {
    int x = Stack::pop();
    min.pop();
    return x;
}

void SpecialStack::getMin() {
    int x = min.pop();
    min.push(x);
    cout<<"\nMinimum element is : "<<x;
}

int main() {
    SpecialStack ps;
    int c,n;
    while(1) {

        cout<<"\n1. PUSH";
        cout<<"\n2. POP";
        cout<<"\n3. TRAVERSE";
        cout<<"\n4. GET MIN";
        cout<<"\n5. QUIT";
        cout<<"\n\nEnter your Choice : ";
        cin>>c;

        switch(c)
        {
            case 1:
            cout<<"\nEnter element tot be inserted : ";
            cin>>n;
            ps.push(n);
            cout<<"\n-------------------";
            break;

            case 2:
            ps.pop();
            cout<<"\n-------------------";
            break;

            case 3:
            ps.traverse();
            cout<<"\n-------------------";
            break;

            case 4:
            ps.getMin();
            cout<<"\n-------------------";
            break;

            case 5:
            cout<<"\n-------------------";
            exit(0);

            default:
            cout<<"\n Error";
        }

    }

    return 0;
}

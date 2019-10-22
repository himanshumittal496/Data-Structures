 //PROGRAM TO IMPLEMENT SINGLY LINKED LIST
#include<iostream>
using namespace std;

class ll {
    struct node {
        int info;
        struct  node *link;
    };
    struct node *start;
    public :
        ll() {
            start = NULL;
        }
    void create_list(int);
    void addAtBeg(int);
    void addAfter(int,int);
    void Delete();
    void Count();
    void Search(int);
    void Display();
    void Reverse();
};
void ll :: create_list(int data) {
    struct node *q,*temp;
    temp = (struct node *)new(struct node);
    temp->info = data;
    temp->link = NULL;

    if (start == NULL)
        start = temp;
    else {
        q = start;
        while(q->link!=NULL)
            q=q->link;
        q->link=temp;
    }
}
void ll :: addAtBeg(int data) {
    struct node *temp;
    temp =(struct node*)new(struct node);
    temp->info=data;
    temp->link=start;
    start=temp;
}
void ll :: addAfter(int data, int pos) {
    struct node *temp,*q;
    int i;
    q=start;
    for (i=0; i<pos-1; i++) {
        q=q->link;
        if(q==NULL) {
            cout<<"\nError";
        }
    }
    temp=(struct node*)new(struct node);
    temp->link=q->link;
    temp->info=data;
    q->link=temp;
}
void ll :: Delete() {
    struct node *temp,*q;
    int data;
    if(start==NULL) {
        cout<<"\nEmpty List!";
        return;
    } else {
    cout<<"\nEnter element for deletion : ";
    cin>>data;

    if(start->info==data) {
        temp = start;
        start=start->link;
        delete(temp);
        return;
    }
    q=start;
    while(q->link->link!=NULL) {
        if(q->link->info==data) {
            temp=q->link;
            q->link=temp->link;
            delete(temp);
            return;
        } q=q->link;
    }
    if(q->link->info==data) {
        temp=q->link;
        delete(temp);
        q->link=NULL;
        return;
    }
    cout<<"\n\nElement not found!"; }
}
void ll :: Display() {
    struct node *q;
    if(start==NULL) {
        cout<<"\nEmpty List!";
    }
    q=start;
    cout<<"\n\nList : ";
    while(q!=NULL) {
        cout<<q->info<<" ";
        q=q->link;
    }
}
void ll :: Count() {
    struct node *q=start;
    int c = 0;
    while(q!=NULL) {
        q=q->link;
        c++;
    }
    cout<<"\nNumber of elements : "<<c;
}
void ll :: Reverse() {
    return;
}
void ll :: Search(int data) {
    struct node *q=start;
    int pos=1;
    while(q!=NULL) {
        if(q->info==data) {
            cout<<"\n\nItem "<<data<<" found at position "<<pos;
            return;
        }
        q=q->link;
        pos++;
    };
    if(q==NULL)
        cout<<"\nItem not in list!";

}
int main() {
    int choice,m,position;
    ll o;
    cout<<"\n---------- LINKED LISTS ----------\n";
    while(1) {
        cout<<"\n1. Create List\n";
        cout<<"2; AA at beg\n";
        cout<<"3. Add after\n";
        cout<<"4. Delete\n";
        cout<<"5. Display\n";
        cout<<"6. Count\n";
        cout<<"7. Reverse\n";
        cout<<"8. Search\n";
        cout<<"9. Quit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice) {
        case 1:
                cout<<"\nEnter the element : ";
                cin>>m;
                o.create_list(m); cout<<"\n-------------------";

            break;
        case 2:
            cout<<"\nEnter the element : ";
            cin>>m;
            o.addAtBeg(m); cout<<"\n-------------------";
            break;
        case 3:
            cout<<"\nEnter the element : ";
            cin>>m;
            cout<<"\nEnter the position : ";
            cin>>position;
            o.addAfter(m,position); cout<<"\n-------------------";
            break;
        case 4:
            o.Delete(); cout<<"\n-------------------";
            break;
        case 5:
            o.Display(); cout<<"\n-------------------";
            break;
        case 6:
            o.Count(); cout<<"\n-------------------";
            break;
        case 7:
            o.Reverse(); cout<<"\n-------------------";
            break;
        case 8:
            cout<<"\nEnter the element to be searched : ";
            cin>>m;
            o.Search(m); cout<<"\n-------------------";
            break;
        case 9:
            cout<<"\n-------------------"; exit(0);
        default:
            cout<<"\nError!"; cout<<"\n-------------------";
        }
    }
}

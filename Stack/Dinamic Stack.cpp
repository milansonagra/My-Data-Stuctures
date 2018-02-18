#include<iostream>
#include<stdlib.h>
using namespace std;

//  STRUCTURE OF NODE
struct node
{
    int data;
    struct node *link;
};

//  DEFINE CLASS OF LINKED LIST
class LinkedList
{
    struct node *top=NULL;
    struct node *First=NULL;
public:
    void insertAtEnd(int);
    int deleteFromEnd();
    void show();
};

void LinkedList::insertAtEnd(int d)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));

    nn->data=d;
    nn->link=NULL;

    if(First==NULL)
    {
        First=top=nn;
    }
    else
    {
        top->link=nn;
        top=top->link;
    }

}
int LinkedList::deleteFromEnd()
{
    if(top!=NULL)
    {
        int r = top->data;

        struct node *NewTop=First;

        if(top==First)
        {
            free(top);
            top=First=NULL;
        }
        else if(top!=NULL)
        {
            while(NewTop->link!=top)
            {
                NewTop=NewTop->link;
            }
            free(top);
            top=NewTop;
            top->link=NULL;
        }
        else
        {
            cout<<"STACK IS EMPTY !"<<endl;
        }
        return r;
    }
    else
    {
        cout<<"STACK IS EMPTY !"<<endl;
        return NULL;
    }
}
void LinkedList::show()
{
    if(First==NULL)
    {
        cout<<"No element available to show."<<endl<<endl;
    }
    else
    {
        struct node *show=First;
        cout<<endl;
        while(show->link!=NULL)
        {
            cout<<"("<<show->data<<","<<show->link<<") "<<"--> ";
            show=show->link;
        }
        cout<<" ("<<show->data<<","<<show->link<<") "<<endl;
    }
}

class Stack
{
    LinkedList manage;
public:
    void push(int);
    int pop();
};

void Stack::push(int d)
{
    manage.insertAtEnd(d);
    manage.show();
}
int Stack::pop()
{
    int r = manage.deleteFromEnd();
    manage.show();

    return r;
}
int main()
{
    Stack A;
    A.push(1);
    A.push(2);
    A.push(5);
    A.push(3);
    A.push(4);
    cout<<"POP ELEMENT: "<<A.pop()<<endl;
    cout<<"POP ELEMENT: "<<A.pop()<<endl;
    cout<<"POP ELEMENT: "<<A.pop()<<endl;
    cout<<"POP ELEMENT: "<<A.pop()<<endl;
    cout<<"POP ELEMENT: "<<A.pop()<<endl;
    cout<<"POP ELEMENT: "<<A.pop()<<endl;
}

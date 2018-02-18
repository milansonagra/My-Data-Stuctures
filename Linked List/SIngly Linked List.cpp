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
    struct node *First=NULL;
    int numberOfNode=0;
public:
    void insertAtFirst(int);
    void insertAtEnd(int);
    void insertAfter(int,int);
    void deleteNode(int);
    void show();
};

//  DEFINATION OF ALL THE METHODS OF LINKED LIST

void LinkedList::insertAtFirst(int d)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));

    nn->data=d;

    if(First!=NULL)
    {
        nn->link=First;
        First=nn;
    }
    else
    {
        First=nn;
        nn->link=NULL;
    }

    numberOfNode++;
}
void LinkedList::insertAtEnd(int d)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));

    nn->data=d;
    nn->link=NULL;

    if(First==NULL)
    {
        First=nn;
    }
    else
    {
        struct node *inst=First;
        while(inst->link!=NULL)
        {
            inst=inst->link;
        }
        inst->link=nn;
    }
    numberOfNode++;
}
void LinkedList::insertAfter(int d,int At)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));

    nn->data=d;

    int flag=0;
    struct node *Find=First;
    if(First!=NULL)
    {
        while(Find->data!=At)
        {
            Find=Find->link;
            flag++;
        }

        if(flag<numberOfNode)
        {
            nn->link=Find->link;
            Find->link=nn;
            numberOfNode++;
        }
        else
        {
            cout<<"Node- "<<At<<" note found in Linked List !"<<endl<<endl;
        }
    }
    else
    {
        cout<<"No Node available ! Cann't insert in between."<<endl<<endl;
    }
}
void LinkedList::deleteNode(int d)
{
    struct node *Delete=First;
    struct node *BeforeDelete;

    int flag=0;
    if(First!=NULL)
    {
        while(Delete->data!=d)
        {
            BeforeDelete=Delete;
            Delete=Delete->link;
            flag++;
        }
        if(flag<numberOfNode)
        {
            BeforeDelete->link=Delete->link;
            Delete->link=NULL;
            free(Delete);
            numberOfNode--;
        }
        else
        {
            cout<<"Node- "<<d<<" not found in Linked List !"<<endl<<endl;
        }
    }
    else
    {
        cout<<"Linked List is empty !"<<endl<<endl;
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
        cout<<endl<<"\tNumber of node this Linked List have:"<<numberOfNode<<endl<<endl;
    }
}
int main()
{
    LinkedList A;

    A.show();
    A.deleteNode(5);
    A.insertAfter(85,5);
    A.insertAtFirst(5);
    A.insertAtEnd(10);
    A.insertAtEnd(20);
    A.insertAtEnd(30);
    A.insertAtEnd(40);
    A.insertAfter(25,20);
    A.show();
    A.deleteNode(25);
    A.show();
    A.insertAtFirst(0);
    A.show();
}

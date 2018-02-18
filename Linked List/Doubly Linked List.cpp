#include<iostream>
#include<stdlib.h>
using namespace std;


//  STRUCTURE OF NODE
struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};


//  DOUBLY LINKED LIST
class DoublyLinkedList
{
    struct node *First=NULL;
    int numberOfNode=0;
public:
    void insertAtFirst(int);
    void insertAtEnd(int);
    void insertAfter(int,int);
    void deleteNode(int);
    void showLeftToRight();
    void showRighToLeft();
};

//  DEFINATION OF ALL THE METHODS OF LINKED LIST

void DoublyLinkedList::insertAtFirst(int d)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));

    nn->data=d;

    if(First!=NULL)
    {
        nn->rptr=First;
        First->lptr=nn;
        nn->lptr=NULL;
        First=nn;
    }
    else
    {
        First=nn;
        nn->lptr=NULL;
        nn->rptr=NULL;
    }

    numberOfNode++;
}

void DoublyLinkedList::insertAtEnd(int d)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));

    nn->data=d;
    nn->rptr=NULL;

    if(First==NULL)
    {
        First=nn;
        nn->lptr=NULL;
    }
    else
    {
        struct node *inst=First;
        while(inst->rptr!=NULL)
        {
            inst=inst->rptr;
        }
        inst->rptr=nn;
        nn->lptr=inst;
    }
    numberOfNode++;
}
void DoublyLinkedList::insertAfter(int d,int At)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));

    nn->data=d;

    int flag=0;
    struct node *Find=First;
    if(First!=NULL)
    {
        while(Find->data!=At)
        {
            Find=Find->rptr;
            flag++;
        }

        if(flag<numberOfNode)
        {
            nn->rptr=Find->rptr;
            (Find->rptr)->lptr=nn;
            Find->rptr=nn;
            nn->lptr=Find;
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
void DoublyLinkedList::deleteNode(int d)
{
    struct node *Delete=First;
    struct node *BeforeDelete;

    int flag=0;
    if(First!=NULL)
    {
        while(Delete->data!=d)
        {
            BeforeDelete=Delete;
            Delete=Delete->rptr;
            flag++;
        }
        if(flag<numberOfNode)
        {
            BeforeDelete->rptr=Delete->rptr;
            (Delete->rptr)->lptr=BeforeDelete;
            Delete->rptr=NULL;
            Delete->lptr=NULL;
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
void DoublyLinkedList::showLeftToRight()
{
    if(First==NULL)
    {
        cout<<"No element available to show."<<endl<<endl;
    }
    else
    {
        struct node *show=First;

        cout<<"Left To Right:"<<endl;
        cout<<endl;
        while(show->rptr!=NULL)
        {
            cout<<"("<<show->lptr<<" |"<<show->data<<"| "<<show->rptr<<") "<<" <--> ";
            show=show->rptr;
        }
        cout<<"("<<show->lptr<<" |"<<show->data<<"| "<<show->rptr<<") "<<endl;
        cout<<endl<<"\tNumber of node this Linked List have:"<<numberOfNode<<endl<<endl;
    }
}
void DoublyLinkedList::showRighToLeft()
{
    if(First==NULL)
    {
        cout<<"No element available to show."<<endl<<endl;
    }
    else
    {
        struct node *show=First;

        cout<<"Right to Left:"<<endl;
        cout<<endl;
        while(show->rptr!=NULL)
        {
            show=show->rptr;
        }
        while(show->lptr!=NULL)
        {
            cout<<"("<<show->lptr<<" |"<<show->data<<"| "<<show->rptr<<") "<<" <--> ";
            show=show->lptr;
        }
        cout<<"("<<show->lptr<<" |"<<show->data<<"| "<<show->rptr<<") "<<endl;
        cout<<endl<<"\tNumber of node this Linked List have:"<<numberOfNode<<endl<<endl;
    }
}
int main()
{
    DoublyLinkedList A;

    A.showLeftToRight();
    A.showRighToLeft();
    A.deleteNode(5);
    A.insertAfter(90,5);
    A.insertAtFirst(5);
    A.insertAtEnd(10);
    A.insertAtEnd(20);
    A.insertAtEnd(30);
    A.insertAfter(25,20);
    A.showLeftToRight();
    A.showRighToLeft();
    A.deleteNode(25);
    A.showRighToLeft();

}

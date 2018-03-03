#include<iostream>
using namespace std;


/*
*
*       Singly Linked List
*
**/

//  STRUCTURE OF NODE
struct Node
{
    char data;
    struct Node *link;
};


//  DEFINE CLASS OF LINKED LIST
class LinkedList
{
    struct Node *First=NULL;
    int numberOfNode=0;
public:
    void insertAtFirst(char);
    void insertAtEnd(char);
    void insertAfter(char,char);
    void deleteNode(char);
    int deleteFromEnd();
    void show();
};

//  DEFINATION OF ALL THE METHODS OF LINKED LIST

void LinkedList::insertAtFirst(char d)
{
    struct Node *nn=(struct Node *)malloc(sizeof(struct Node));

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
void LinkedList::insertAtEnd(char d)
{
    struct Node *nn=(struct Node *)malloc(sizeof(struct Node));

    nn->data=d;
    nn->link=NULL;

    if(First==NULL)
    {
        First=nn;
    }
    else
    {
        struct Node *inst=First;
        while(inst->link!=NULL)
        {
            inst=inst->link;
        }
        inst->link=nn;
    }
    numberOfNode++;
}
void LinkedList::insertAfter(char d,char At)
{
    struct Node *nn=(struct Node *)malloc(sizeof(struct Node));

    nn->data=d;

    int flag=0;
    struct Node *Find=First;
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
void LinkedList::deleteNode(char d)
{
    struct Node *Delete=First;
    struct Node *BeforeDelete;

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
int LinkedList::deleteFromEnd()
{
    struct Node *Delete=First;
    struct Node *BeforeDelete;

    int r=0;
    if(First!=NULL)
    {
        while(Delete->link!=NULL)
        {
            BeforeDelete=Delete;
            Delete=Delete->link;
        }
        BeforeDelete->link=Delete->link;
        Delete->link=NULL;
        r=Delete->data;
        free(Delete);
        numberOfNode--;
    }
    else
    {
        cout<<"Linked List is empty !"<<endl<<endl;
    }
    return r;
}
void LinkedList::show()
{
    if(First==NULL)
    {
        cout<<"No element available to show."<<endl<<endl;
    }
    else
    {
        struct Node *show=First;
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

/*
*
*       Doubly Linked List
*
**/


//  STRUCTURE OF DNODE
struct DNode
{
    char data;
    struct DNode *lptr;
    struct DNode *rptr;
};


//  DOUBLY LINKED LIST
class DoublyLinkedList
{
    struct DNode *First=NULL;
    int numberOfNode=0;
public:
    void insertAtFirst(char);
    void insertAtEnd(char);
    void insertAfter(char,char);
    void deleteNode(char);
    void showLeftToRight();
    void showRighToLeft();
    char getLeft(char);
    char getRight(char);
};

//  DEFINATION OF ALL THE METHODS OF LINKED LIST

void DoublyLinkedList::insertAtFirst(char d)
{
    struct DNode *nn=(struct DNode *)malloc(sizeof(struct DNode));

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

void DoublyLinkedList::insertAtEnd(char d)
{
    struct DNode *nn=(struct DNode *)malloc(sizeof(struct DNode));

    nn->data=d;
    nn->rptr=NULL;

    if(First==NULL)
    {
        First=nn;
        nn->lptr=NULL;
    }
    else
    {
        struct DNode *inst=First;
        while(inst->rptr!=NULL)
        {
            inst=inst->rptr;
        }
        inst->rptr=nn;
        nn->lptr=inst;
    }
    numberOfNode++;
}
void DoublyLinkedList::insertAfter(char d,char At)
{
    struct DNode *nn=(struct DNode *)malloc(sizeof(struct DNode));

    nn->data=d;

    int flag=0;
    struct DNode *Find=First;
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
            cout<<"DNode- "<<At<<" note found in Linked List !"<<endl<<endl;
        }
    }
    else
    {
        cout<<"No DNode available ! Cann't insert in between."<<endl<<endl;
    }
}
void DoublyLinkedList::deleteNode(char d)
{
    struct DNode *Delete=First;
    struct DNode *BeforeDelete;

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
            numberOfNode--;
        }
        else
        {
            cout<<"DNode- "<<d<<" not found in Linked List !"<<endl<<endl;
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
        struct DNode *show=First;

        cout<<"Left To Right:"<<endl;
        cout<<endl;
        while(show->rptr!=NULL)
        {
            cout<<"("<<show->lptr<<" |"<<show->data<<"| "<<show->rptr<<") "<<" <--> ";
            show=show->rptr;
        }
        cout<<"("<<show->lptr<<" |"<<show->data<<"| "<<show->rptr<<") "<<endl;
        cout<<endl<<"\tNumber of DNode this Linked List have:"<<numberOfNode<<endl<<endl;
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
        struct DNode *show=First;

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
        cout<<endl<<"\tNumber of DNode this Linked List have:"<<numberOfNode<<endl<<endl;
    }
}
char DoublyLinkedList::getLeft(char d)
{
    char Ans;

    int flag=0;
    struct DNode *Find = First;

    if(Find!=NULL)
    {
        while(Find->data!=d)
        {
            flag++;
            Find=Find->rptr;
        }

        if(flag < numberOfNode  && Find->lptr!=NULL)
        {
            Ans=(Find->lptr)->data;
        }
        else
        {
            Ans=NULL;
        }
    }
    else
    {
        Ans=NULL;
    }

    return Ans;
}
char DoublyLinkedList::getRight(char d)
{
    char Ans;

    int flag=0;
    struct DNode *Find = First;

    if(Find!=NULL)
    {
        while(Find->data!=d)
        {
            flag++;
            Find=Find->rptr;
            if(flag>numberOfNode)
            {
                break;
            }
        }

        if(flag < numberOfNode && Find->rptr!=NULL)
        {
            Ans=(Find->rptr)->data;
        }
        else
        {
            Ans=NULL;
        }
    }
    else
    {
        Ans=NULL;
    }

    return Ans;
}

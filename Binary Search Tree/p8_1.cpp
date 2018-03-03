#include<iostream>
#include<stdlib.h>
#include"LinkedList.h"
using namespace std;

//  NODE
struct node
{
    char data;
    struct node *lptr=NULL;
    struct node *rptr=NULL;
};

class BST
{
    struct node *root=NULL;
    DoublyLinkedList InOrder;
public:
    node* getRoot();
    void Insert(char);
    void Insert(node *);
    void Delete(char);
    node* Search(char);
    void inOrder(struct node *);
    void PreOrder(struct node *);
    void PostOrder(struct node *);
    char getPredecessor(char);
    char getSuccessor(char);
};

//  ONLY TO USE ROOT OUTSIDE OF THE WORLD
 node* BST::getRoot()
{
    return root;
}

void BST::Insert(char d)
{
    struct node *inst = (struct node *)malloc(sizeof(struct node ));
    struct node *subroot = root;

    inst->data=d;
    inst->lptr=NULL;
    inst->rptr=NULL;

    if(root==NULL)
    {
        root=inst;
        root->lptr=NULL;
        root->rptr=NULL;
    }
    else
    {
        NEXTNODE:
            if(subroot->data > inst->data)
            {
                if(subroot->lptr==NULL)
                {
                    subroot->lptr=inst;
                }
                else
                {
                    subroot=subroot->lptr;
                    goto NEXTNODE;
                }
            }
            else
            {
                if(subroot->rptr==NULL)
                {
                    subroot->rptr=inst;
                }
                else
                {
                    subroot=subroot->rptr;
                    goto NEXTNODE;
                }
            }
    }
}
void BST::Insert(node *inst)
{
    if(inst==NULL)
    {
        return;
    }

    struct node *subroot = root;

    if(root==NULL)
    {
        root=inst;
        root->lptr=NULL;
        root->rptr=NULL;
    }
    else
    {
        NEXTNODE:
            if(subroot->data > inst->data)
            {
                if(subroot->lptr==NULL)
                {
                    subroot->lptr=inst;
                }
                else
                {
                    subroot=subroot->lptr;
                    goto NEXTNODE;
                }
            }
            else
            {
                if(subroot->rptr==NULL)
                {
                    subroot->rptr=inst;
                }
                else
                {
                    subroot=subroot->rptr;
                    goto NEXTNODE;
                }
            }
    }

}
struct node* BST::Search(char d)
{
    struct node *SearchNode = root;

    while(SearchNode->data!=d)
    {
        if(SearchNode->data > d)
        {
            if(SearchNode->lptr == NULL)
            {
                return NULL;
            }
            SearchNode = SearchNode->lptr;
        }
        else
        {
            if(SearchNode->rptr == NULL)
            {
                return NULL;
            }
            SearchNode = SearchNode->rptr;
        }
    }
    return SearchNode;
}
void BST::Delete(char d)
{
    struct node *Delete;

    if(root==NULL)
    {
        cout<<"Binary Search Tree is empty !"<<endl;
    }
    else
    {
        Delete=Search(d);

        if(Delete == NULL)
        {
            cout<<endl<<"No Element Found to delete !"<<endl;
        }
        else
        {
            node *Predecessor=Search(getPredecessor(Delete->data));

            if(Predecessor!=NULL)
            {
                node *tempRoot = Predecessor->lptr;

                Predecessor->lptr = Delete->lptr;
                Predecessor->rptr = Delete->rptr;

                Insert(tempRoot);

                cout<<endl<<"Element- "<<Delete->data<<" is delete !"<<endl;

                InOrder.deleteNode(Delete->data);
            }
        }
    }

    free(Delete);
}

//  TRAVERSAL TECHNIQUE
void BST::inOrder(struct node *r = NULL)
{
    if(r!=NULL)
    {
        inOrder(r->lptr);
        cout<<r->data<<" ";
        InOrder.insertAtEnd(r->data);       //  to get Predecessor & Successor
        inOrder(r->rptr);
    }
}
void BST::PreOrder(struct node *r = NULL)
{
    if(r!=NULL)
    {
        cout<<r->data<<" ";
        PreOrder(r->lptr);
        PreOrder(r->rptr);
    }
}
void BST::PostOrder(struct node *r = NULL)
{
    if(r!=NULL)
    {
        PostOrder(r->lptr);
        PostOrder(r->rptr);
        cout<<r->data<<" ";
    }
}

//      Predecessor and Successor
char BST::getPredecessor(char d)
{
    char p = InOrder.getLeft(d);
    if(p!=NULL)
    {
        return p;
    }
    else
    {
        cout<<endl<<"Can not get Predecessor !"<<endl;
    }
}
char BST::getSuccessor(char d)
{
    char p = InOrder.getRight(d);
    if(p!=NULL)
    {
        return p;
    }
    else
    {
        cout<<"Can not get Successor !";
    }
}

int main()
{
    BST A;
    A.Insert('M');
    A.Insert('I');
    A.Insert('L');
    A.Insert('A');
    A.Insert('N');

    cout<<"In-Order Traversal Technique:\t";
    A.inOrder(A.getRoot());
    cout<<endl;

    cout<<"Pre-Order Traversal Technique:\t";
    A.PreOrder(A.getRoot());
    cout<<endl;

    cout<<"Post-Order Traversal Technique:\t";
    A.PostOrder(A.getRoot());
    cout<<endl;

    cout<<endl;
    cout<<"Predecessor of 'M':\t"<<A.getPredecessor('M');

    cout<<endl;
    cout<<"Successor of 'M':\t"<<A.getSuccessor('M');

    A.Delete('L');

    cout<<endl<<endl;
    cout<<"In-Order Traversal Technique:\t";
    A.inOrder(A.getRoot());
    cout<<endl;

    BST S;
    S.Insert('S');
    S.Insert('A');
    S.Insert('G');
    S.Insert('A');
    S.Insert('R');

    cout<<"In-Order Traversal Technique:\t";
    S.inOrder(S.getRoot());
    cout<<endl;

    cout<<"Pre-Order Traversal Technique:\t";
    S.PreOrder(S.getRoot());
    cout<<endl;

    cout<<"Post-Order Traversal Technique:\t";
    S.PostOrder(S.getRoot());
    cout<<endl;

    cout<<endl<<endl;
    BST D;
    D.Insert('S');
    D.Insert('H');
    D.Insert('A');
    D.Insert('L');
    D.Insert('I');
    D.Insert('N');

      cout<<"In-Order Traversal Technique:\t";
    D.inOrder(D.getRoot());
    cout<<endl;

    cout<<"Pre-Order Traversal Technique:\t";
    D.PreOrder(D.getRoot());
    cout<<endl;

    cout<<"Post-Order Traversal Technique:\t";
    D.PostOrder(D.getRoot());
    cout<<endl;

    cout<<endl;
    cout<<"Predecessor of 'S':\t"<<A.getPredecessor('L');

    cout<<endl;
    cout<<"Successor of 'S':\t"<<A.getSuccessor('L');
}

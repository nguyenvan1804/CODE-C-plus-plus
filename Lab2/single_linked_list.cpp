#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void InitList(List &l)
{
    l.pHead = l.pTail = NULL;
}

Node *createNode(List &l, int x)
{
    Node *p = new Node;
    if (p == NULL) return NULL;
    else
    {
        p->data = x;
        p->next = NULL;
    }
    return p;
}

bool IsEmpty(List &l)
{
    if (l.pHead == NULL) return true;
    else return false;
}

void InsertHead(List &l, Node *p)
{
    if (IsEmpty(l)) l.pHead = l.pTail = p;
    else
    {
        p->next = l.pHead;
        l.pHead = p;
    }
}

void InsertTail(List &l, Node *p)
{
    if (IsEmpty(l)) l.pHead = l.pTail = p;
    else
    {
        l.pTail->next = p;
        l.pTail = p;
    }
}

void InsertAfterQ(List &l, Node *q, Node *p)
{
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if (q == l.pHead) InsertHead(l,p);
    }
    else InsertTail(l,p);
}

void InsertAtK(List &l, Node *p, int k)
{
    if (IsEmpty(l) || k<=1) InsertHead(l,p);
    else if (k>= n) InsertTail(l,p);
    else 
    {
        Node *q = new Node;
        Node *w = new Node;
        Node *r = l.pHead;
        int d=0;
        while(r!= NULL)
        {
            d++;
            q = r;
            if ( d == k) break;
            else r = r->next;
        }
        w = l.pHead;
        while(w->next != p)
        {
            w =w ->next;
        }
        w->next = p;
        p->next = r;
    }
}

int main()
{

}
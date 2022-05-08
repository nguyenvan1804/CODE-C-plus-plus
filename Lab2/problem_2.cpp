#include <iostream>
using namespace std;

struct Node
{
    int sm;
    int hs;
    Node *next;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void InitList(List &d)
{
    d.pHead = d.pTail = NULL;
}

Node *createNode(int h, int s)
{
    Node *p = new Node;
    if (!p) return NULL;
    p->sm = s;
    p->hs = h;
    p->next = NULL;
    return p;
}

void addTail(List &d, Node *p)
{
    if (d.pHead == NULL) d.pHead = d.pTail = p;
    else 
    {
        d.pTail->next = p;
        d.pTail = p;
    }
}

void Input(List &lst)
{
    int x,n;
    cout<<"Nhap bac cua da thuc:";
    cin>>n;
    for (int i=n; i>=0; i--)
    {
        cout<<"Nhap he so cua x^"<<i<<" = ";
        cin>>x;
        Node *p = createNode(x, i);
        addTail(lst,p);
    }
}



void addition(List &lst, List l1, List l2)
{
    Node *p = new Node;
    Node *q = new Node;
    if(l1.pHead->sm > l2.pHead->sm)
    {
        lst = l1;
        p = l2.pHead;
    }
    else
    {
        lst = l2;
        p = l1.pHead;
    }

    q = lst.pHead;
    while ( q->sm > p->sm) q = q->next;// tìm q sao cho q->sm == p->sm
    while(q != NULL)
    {
        q->hs += p->hs;
        p = p->next;
        q = q->next;
    }
}

void subtraction(List &l,List l1, List l2)
{
    for (Node *k = l2.pHead; k != NULL; k = k->next)
    {
        k->hs = k->hs*(-1);
    }
    addition(l,l1,l2);
}

void output(List &lst)
{
    Node *p = lst.pHead;
    while(p != lst.pTail)
    {
        if (p->hs) cout<<p->hs<<"x^"<<p->sm;
        p = p->next;
        if(p->hs)
		{
            if (p->hs > 0) cout<<"+";
            else cout<<" ";
        }
        if(p->sm == 0) cout<<p->hs; 
    }
}

int main()
{
    List l ,l1, l2;
    
    InitList(l);
    InitList(l1);
    InitList(l2);

    cout<<"Nhap da thuc P(x):"<<endl;
    Input(l1);
    cout<<"Nhap da thuc Q(x):"<<endl;
    Input(l2);

    cout<<"P(x): ";
    output(l1);
    cout<<endl;
    cout<<"Q(x): ";
    output(l2);
    Node *p = l1.pHead;
    Node *q = l2.pHead;

    subtraction(l,l1,l2);
    cout<<endl;
    cout<<"T(x): ";
    output(l);

    if (p->sm <= q->sm)
    {
        subtraction(l2,l1,l);
    }
    else
    {
        subtraction(l1,l,l2);
    }

    addition(l,l1,l2);
    cout<<endl;
    cout<<"R(x): ";
    output(l);

    return 0;
}
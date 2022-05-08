#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Node
{
    string name;
    int day, month, year;
    double math, physic, language, aver;
    Node *next;
};

struct LIST
{
    Node *pHead;
    Node *pTail;
};

void InitList(LIST &lst)
{
    lst.pHead = lst.pTail = NULL;
}

bool IsEmpty(LIST &lst)
{
    if (lst.pHead = NULL)
    {
        return true;
    }
    return false;
}

int count_years(LIST &lst, int years)
{
    int count = 0;
    for (Node *k = lst.pHead; k != NULL; k = k->next)
    {
        if (k->year == years)
        {
            count ++;
        }
    }
    return count;
} 

void name_check(LIST &lst, string name)
{
    int count = 0;
    for (Node *k = lst.pHead; k != NULL; k = k->next)
    {
        if(k->name == name) 
        {
            cout<<"List have name student"<<endl;
            count++;
            break;
        }
    }
    if (count == 0) cout<<"List no have name student"<<endl;
}

void delete_name(LIST &lst, string name)
{
    Node *p = lst.pHead;
    Node *preX = lst.pHead;
    while(p != NULL)
    {
        if (p->name == name)
        {
            Node *r = p;
            if (p == lst.pHead)
            {
                lst.pHead = lst.pHead->next;
                p = lst.pHead;
                preX = lst.pHead;
            }
            else
            {
                preX->next = p->next;
                p = p->next;
            }
            delete r;
            continue;
        }
        preX = p;
        p = p->next;
    }
}

void biggest_mark(LIST &lst)
{
    double max = 0;
    for(Node *k = lst.pHead; k != NULL; k=k->next)
    {
        k->aver = (k->math + k->physic + k->language)/3;
        if (k->aver >= max)
        {
            max = k->aver;           
        }        
    }
    for(Node *k = lst.pHead; k != NULL; k=k->next)
    {
        if (k->aver == max)
        {
            cout<<k->name<<" "<<k->day<<"/"<<k->month<<"/"<<k->year<<" "<<k->math<<" "<<k->physic<<" "<<k->language<<" "<<k->aver<<endl;
        }
    }
}

void math_less_5(LIST &lst)
{
    for(Node *k = lst.pHead; k != NULL; k=k->next)
    {
        if (k->math < 5)
        {
            cout<<k->name<<" "<<k->day<<"/"<<k->month<<"/"<<k->year<<" "<<k->math<<" "<<k->physic<<" "<<k->language<<endl;
        }        
    }
}

void Input_file(LIST &lst)
{
    Node *p = new Node;
    fstream myfile;
    myfile.open("problem_1.txt", ios::in);
    if (myfile.is_open())
    {
        while (getline(myfile,p->name))
        {
            cout<<p->name<<endl;
        }
        myfile.close();
    }
}

void Input(LIST &lst)
{
    string a;
    int b,c,d;
    double e,f,g;

    cout<<"Enter name:";
    getline(cin,a);
    cout<<"Enter day of birth: ";
    cin>>b;
    cout<<"Enter month of birth: ";
    cin>>c;
    cout<<"Enter year of birth: ";
    cin>>d;
    cout<<"Enter math mark: ";
    cin>>e;
    cout<<"Enter physic mark: ";
    cin>>f;
    cout<<"Enter language mark: ";
    cin>>g;

    Node *p = new Node;
    p->name = a;
    p->day = b;
    p->month = c;
    p->year = d;
    p->math = e;
    p->physic = f;
    p->language = g;
    p->next = NULL;

    if (lst.pHead == NULL)
    {
        lst.pHead = p;
        lst.pTail = p;
    }
    else
    {
        lst.pTail->next = p;
        lst.pTail = p;
    }
}

//hàm ghi thong tin 1 học sinh vào file
void writeFile(ofstream &fileOut, Node *p)
{
    fileOut<<p->name<<" "<<p->day<<"/"<<p->month<<"/"<<p->year<<" "<<p->math<<" "<<p->physic<<" "<<p->language<<endl;
}

void OutFile(LIST &lst)
{
    ofstream fileout;
    fileout.open("SinhVien.txt", ios::out);
    for (Node *k = lst.pHead; k != NULL; k = k->next)
    {
        writeFile(fileout, k);
        //fileout<<endl;
    }
    fileout.close();
}

void Output(LIST &lst)
{
    Node *p = lst.pHead;
    while(p != NULL)
    {
        cout<<p->name<<" "<<p->day<<"/"<<p->month<<"/"<<p->year<<" "<<p->math<<" "<<p->physic<<" "<<p->language<<endl;
        p = p->next;
    }
}

int main()
{
    LIST list;
    int n;
    cout<<"Enter numbers of student:";
    cin>>n;

    InitList(list);
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        Input(list);
        cin.ignore();
    }

    cout<<"Add a new student: "<<endl;
    Input(list);

    OutFile(list);

    cout<<"Xuat danh sach: "<<endl;
    Output(list);

    int years;
    cout<<"Enter year of birth: ";
    cin>>years;
    cout<<"Count the number of student in a given year of birth:"<<count_years(list,years)<<endl;

    string name;
    cin.ignore();
    cout<<"Enter name to check:";
    getline(cin,name);
    name_check(list,name);

    string name1;
    cout<<"Enter name to delete:";
    getline(cin,name1);
    delete_name(list,name1);
    cout<<"Xuat danh sach: "<<endl;
    Output(list);

    cout<<"Find student having the biggest average: "<<endl;
    biggest_mark(list);

    cout<<"List student have math mark less than 5:"<<endl;
    math_less_5(list);

    return 0;
}
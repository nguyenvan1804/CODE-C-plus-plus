#include <iostream>
using namespace std;

//khai báo cấu trúc của 1 cái node trong stack
struct node
{
    int data; //stack đang chứa các số nguyên 
    struct node *pNext; // con trỏ liên kết giữa các Node với nhau
};
typedef struct node NODE;

//khai báo cấu trúc của Stack
struct stack
{
    NODE *pTop; //dùng con trỏ đầu để quản lý Stack
};
typedef struct stack STACK;

//hàm khởi tạo stack
void createStack(STACK &s)
{
    s.pTop = NULL;
}

//hàm khởi tạo Node
NODE *createNode(int n)
{
    NODE *p = new NODE();
    if (p == NULL)
    {
        return NULL;
    }
    p->data = n;
    p->pNext = NULL;
    return p;
}

//kiểm tra stack có rỗng hay không
bool IsEmpty(STACK s)
{
    if (s.pTop == NULL)
    {
        return true;
    }
    return false;
}

//thêm đối tượng vào đầu stack(LIFO)
bool Push(STACK &s, NODE *p)
{
    if (p == NULL)
    {
        return false;
    }
    if (IsEmpty(s) == true)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
}

//lấy phtu đầu stack và hủy nó đi
bool Pop(STACK &s, int &x) // x là giá trị cần lấy trong Node
{
    if (IsEmpty(s) == true)
    {
        return false;
    }
    else 
    {
        NODE *p = s.pTop;// p là Node thế mạng để xíu nữa xóa nó đi
        x = p->data; // gán giá trị của Node đầu stack vào biến x
        s.pTop = s.pTop->pNext; 
        delete p;
    }
    return true;
}

// xem thông tin của phần tử đầu stack và không hủy nó
bool Top(STACK &s, int &x)
{
    if (IsEmpty(s) == true)
    {
        return false;
    }
    x = s.pTop->data;// lấy giá trị phần tử đầu stack ra để xem
    return true;
}

void Output(STACK s)
{
    while(IsEmpty(s) == false)
    {
        int x;
        Pop(s,x);
        cout<< x <<" ";
    }
}

void Input(STACK &s)
{   
    int luachon;
    while(true) 
    {
        system("cls");
        cout<<"1.Them phan tu vao stack."<<endl;
        cout<<"2.Xuat danh sach stack ra man hinh."<<endl;
        cout<<"3.Xuat phan tu dau tien cua ds stack."<<endl;
        cout<<"4.Ket thuc."<<endl;

        cout<<"Enter option: ";
        cin>>luachon;

        if (luachon == 1)
        {
            int x;
            cout<<"Enter element to add:";
            cin>>x;

            NODE *p = createNode(x);
            Push(s,p);
        }
        else if (luachon == 2)
            {
                Output(s);
                system("pause");
            }
        else if (luachon == 3)
            {
                int x;
                Top(s,x);
                cout<<"Phan tu nam dau stack la:"<<x<<endl;
                system("pause");
            }
        else 
        {
            break;
        }
    }
    
}

int main()
{
    STACK s;
    createStack(s);
    Input(s);
    system("pause");
    return 0;
}
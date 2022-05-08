#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

void kiem_tra_ngoac()
{
    string s;
    cin>>s;
    stack<char> st;

    for(char a:s)
    {
        if(a == '(')
        {
            st.push(a);
        }
        else
        {
            if(st.empty())
            {
                cout<<"Invalid"<<endl;
                return;
            }
            else st.pop();
        }
    }
    if (st.empty()) cout<<"Valid"<<endl;
    else cout<<"Invalid"<<endl;
}

int main()
{
    kiem_tra_ngoac();
    return 0;
}


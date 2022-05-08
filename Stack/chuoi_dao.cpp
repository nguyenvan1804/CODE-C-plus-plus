#include <bits/stdc++.h>
#include <stack>
using namespace std;

//problem_1
/*int main()
{
    string s;
    cout<<"Enter s:";
    getline(cin,s);
    stringstream ss(s);
    string token;
    stack<string> st;

    while(ss >> token) //toán tử có thể phân tách các chuỗi 
                       //bằng dấu cách nhưng không được bằng dấu phẩy
    {
        st.push(token);
    }

    while( !st.empty() )
    {
        cout<<st.top()<< " ";
        st.pop();
    }

    return 0;

}*/

//problem_2
int main()
{
    char s[50];
    cout<<"Enter s:";
    cin.getline(s,50);
    stack<char> st;

    int i = 0;
    while(s[i] != ' ')
    {1
        st.push(s[i]);
    }

    while( !st.empty())
    {
        cout<<st.top();
        st.pop();
    }

    return 0;
}
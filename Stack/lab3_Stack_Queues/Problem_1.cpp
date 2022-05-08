#include<iostream>
#include<stack>
using namespace std;

//trả về mức độ ưu tiên của các toán tử
int uuTien(char c)
{
    if ( c=='(') return 0;
    if ( c=='+' || c=='-') return 1;
    if ( c=='*' || c=='/' || c=='%') return 2;
    if ( c=='^') return 3;
}

//chuyển từ trung tố sang hậu tố
void hauTo(string str)
{
    stack<char> s;
    int i = 0;
    string str1 = "";
    while(i<str.length())
    {
        char c = str.at(i);
        if(c != ' ')
        {
            if (c - '0' >= 0 && c - '0' <= 9 || isalpha(c)) str1+=c;
            else{
                cout<<str1<<" ";
                str1 = "";
                if (c == '(') s.push(c);
                else {
                    if (c == ')') 
                    {
                        while(s.top() != '(')
                        {
                            cout<<s.top();
                            s.pop();
                        }
                        s.pop();
                    }
                    else {
                        while(!s.empty() && uuTien(c) <= uuTien(s.top()))
                        {
                            cout<<s.top();
                            s.pop();
                        }
                        s.push(c);
                    }
                }
            }
        }
        i++;
    }
    if(str1 != " ") cout<<str1<<" ";
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}

//compute the postfix expression
int value_postfix(string s)
{
    stack<int> st;
    int i = 0, c1;
    while(i<s.length())
    {
        if (s[i] == '+' || s[i] =='-' || s[i] =='*' || s[i] =='/')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if (s[i] == '+') c1 = a+b;
            else if (s[i] == '-') c1 = a-b;
            else if (s[i] == '*') c1 = a*b;
            else if (s[i] == '/') c1 = a/b;
        }
        else
        {
            st.push((int)(s[i]-'0'));
        }
        i++;
    }
    return c1;
}

int main()
{
    string str;
    cout<<"Enter str: ";
    getline(cin,str);
    hauTo(str);

    cout<<endl;
    string str1;
    cout<<"Enter str1: ";
    getline(cin,str1);
    value_postfix(str1);

    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;

    stack<int> st;
    while(n != 0)
    {
        st.push(n % 2);
        n = n/2;
    }

    while(!st.empty())
    {
        cout<< st.top();
        st.pop();
    }
}
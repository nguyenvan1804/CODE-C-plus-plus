#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout<< st.top() <<endl; //lấy phần tử ở đỉnh 
    st.pop();
    cout<< st.top() <<endl;
    if (st.empty())
    {
        cout<<"Empty !";
    }

    return 0;
}

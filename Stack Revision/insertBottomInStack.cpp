#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &s, int ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtBottom(s, ele);
    s.push(top);
    return;
};

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int top = s.top();
    s.pop();

    reverse(s);
    insertAtBottom(s,top);
    return;
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int ele = 100;
    insertAtBottom(s, ele);
    cout << s.top() << endl;
    reverse(s);
    cout << s.top() << endl;
    return 0;
}
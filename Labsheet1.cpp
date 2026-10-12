#include <bits/stdc++.h>
using namespace std;

const int MAX = 100; // maximum size of the stack
int stk[MAX];        // the array
int top = -1;        // -1 means the stack is empty

void push(int x)
{
    if (top == MAX - 1)
    {
        cout << "Stack is full\n";
        return;
    }
    stk[++top] = x; // move top up, then store the value
    cout << x << " pushed\n";
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << stk[top--] << " popped\n"; // print value, then move top down
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--)
        cout << stk[i] << " ";
    cout << "\n";
}

int main()
{
    int choice, x;
    while (true)
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> x;
            push(x);
        }
        else if (choice == 2)
            pop();
        else if (choice == 3)
            display();
        else
            break;
    }
    return 0;
}
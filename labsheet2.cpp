#include <bits/stdc++.h>
using namespace std;

const int MAX = 100; // maximum size of the queue
int q[MAX];          // the array
int front = 0;       // index of the first element
int rear = -1;       // index of the last element (-1 means empty)

void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        cout << "Queue is full\n";
        return;
    }
    q[++rear] = x; // move rear forward, then store the value
    cout << x << " enqueued\n";
}

void dequeue()
{
    if (front > rear)
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << q[front++] << " dequeued\n"; // print value, then move front forward
    if (front > rear)
    { // queue became empty, so reset
        front = 0;
        rear = -1;
    }
}

void display()
{
    if (front > rear)
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue (front to rear): ";
    for (int i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << "\n";
}

int main()
{
    int choice, x;
    while (true)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> x;
            enqueue(x);
        }
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            display();
        else
            break;
    }
    return 0;
}
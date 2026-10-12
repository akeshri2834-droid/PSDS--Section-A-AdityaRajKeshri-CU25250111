#include <bits/stdc++.h>
using namespace std;

struct Task
{
    string name;
    int pri;
};

// ---------- heap (min or max) ----------
class Heap
{
    Task h[100];
    int n = 0;
    bool isMin;

    // true if a should be above b in the heap
    bool better(Task &a, Task &b)
    {
        return isMin ? a.pri < b.pri : a.pri > b.pri;
    }

    void up(int i)
    { // move a new element up
        while (i > 0)
        {
            int p = (i - 1) / 2; // parent index
            if (!better(h[i], h[p]))
                break;
            swap(h[i], h[p]);
            i = p;
        }
    }

    void down(int i)
    { // move an element down
        while (true)
        {
            int l = 2 * i + 1, r = 2 * i + 2, best = i;
            if (l < n && better(h[l], h[best]))
                best = l;
            if (r < n && better(h[r], h[best]))
                best = r;
            if (best == i)
                break;
            swap(h[i], h[best]);
            i = best;
        }
    }

public:
    Heap(bool minHeap) : isMin(minHeap) {}

    bool empty() { return n == 0; }

    void push(Task t)
    {
        if (n == 100)
        {
            cout << "Queue is full\n";
            return;
        }
        h[n] = t;
        up(n++);
    }

    Task top() { return h[0]; }

    Task pop()
    {
        Task t = h[0];
        h[0] = h[--n]; // last element goes to the root
        down(0);
        return t;
    }
};

// ---------- priority queue using the heap ----------
int main()
{
    int type;
    cout << "1. Min priority (smallest number first)\n"
         << "2. Max priority (largest number first)\nChoose: ";
    cin >> type;
    Heap pq(type == 1);

    int choice;
    while (true)
    {
        cout << "\n1. Insert\n2. Serve\n3. Peek\n4. Exit\nEnter choice: ";
        if (!(cin >> choice) || choice == 4)
            break;

        if (choice == 1)
        {
            Task t;
            cout << "Enter name and priority: ";
            cin >> t.name >> t.pri;
            pq.push(t);
        }
        else if (choice == 2)
        {
            if (pq.empty())
                cout << "Queue is empty\n";
            else
            {
                Task t = pq.pop();
                cout << "Served: " << t.name << " (priority " << t.pri << ")\n";
            }
        }
        else if (choice == 3)
        {
            if (pq.empty())
                cout << "Queue is empty\n";
            else
            {
                Task t = pq.top();
                cout << "Next: " << t.name << " (priority " << t.pri << ")\n";
            }
        }
    }
    return 0;
}
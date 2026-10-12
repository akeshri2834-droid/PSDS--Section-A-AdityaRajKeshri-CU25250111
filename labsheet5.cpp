#include <bits/stdc++.h>
using namespace std;

// ---------- custom operator stack ----------
const int MAX = 100;
char stk[MAX];
int top = -1;

void push(char c) { stk[++top] = c; }
char pop() { return stk[top--]; }
char peek() { return stk[top]; }
bool isEmpty() { return top == -1; }

// ---------- operator priority ----------
int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0; // '(' has the lowest priority
}

// ---------- infix to postfix ----------
string toPostfix(string exp)
{
    string out = "";
    for (char c : exp)
    {
        if (c == ' ')
            continue; // ignore spaces

        if (isalnum(c)) // operand: send straight to output
            out += c;
        else if (c == '(') // opening bracket: push
            push(c);
        else if (c == ')')
        { // closing bracket: pop until '('
            while (!isEmpty() && peek() != '(')
                out += pop();
            pop(); // remove the '('
        }
        else
        { // operator
            while (!isEmpty() &&
                   (prec(peek()) > prec(c) ||
                    (prec(peek()) == prec(c) && c != '^')))
                out += pop();
            push(c);
        }
    }
    while (!isEmpty()) // empty the stack
        out += pop();
    return out;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string exp;
        cin >> exp;
        top = -1; // reset the stack
        cout << toPostfix(exp) << "\n";
    }
    return 0;
}
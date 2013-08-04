/*
 * SPOJ: Transform the expression
 * Category: Simple data structures
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string infix;
        cin >> infix;

        stack<string> s;
        string op1, op2, optr,t;

        for (int i = 0; i < infix.size(); i++) {
            char ch = infix[i];
            switch(ch) {
                case '(': 
                    t = ch;
                    s.push(t);
                    break;
                case ')':
                    op2 = s.top();
                    s.pop();
                    optr = s.top();
                    s.pop();
                    op1 = s.top();
                    s.pop();
                    s.pop();
                    s.push(op1 + op2 + optr);
                    break;
                default:
                    t = ch;
                    s.push(t);
                    break;

            }
        }
        cout<<s.top()<<endl;
    }

    return 0;
}

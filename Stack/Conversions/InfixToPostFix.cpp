#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
        return true;

    return false;
}

string infixToPostfix(string infix_exp)
{
    unordered_map<char, int> mpp;
    mpp['('] = 5;
    // mpp[')'] = 5;
    mpp['^'] = 4;
    mpp['*'] = 3;
    mpp['/'] = 3;
    mpp['+'] = 2;
    mpp['-'] = 2;
    stack<char> st;
    string res = "";
    int n = infix_exp.size();

    for (int i = 0; i < n; i++)
    {

        char currChar = infix_exp[i];

        if (currChar == '(')
        {
            st.push(currChar);
        }
        else if (currChar == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }

            st.pop();

           
        }
        else if (isOperator(currChar))

        {
          
            while (!st.empty() && mpp[currChar] <= mpp[st.top()] && st.top()!='(') // imp line
            {

                cout << st.top() << "  ";
                res += st.top();
                st.pop();
            }

            
              
            st.push(currChar);
        }
        else
        {

           
            res += currChar;
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

  

    return res;
}

int main()
{
    
    string infix_Exp = "x^y/(5*z)+2";
    string ans = infixToPostfix(infix_Exp);
    cout << endl;
    cout << " prefix exp is -> " << ans;
}

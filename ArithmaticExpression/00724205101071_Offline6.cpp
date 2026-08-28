#include<bits/stdc++.h>
using namespace std;

int priority(char s)
{
    if(s == '^')
    {
        return 10;
    }
    if(s == '*' || s == '/')
    {
        return 5;
    }
    if(s == '+' || s == '-')
    {
        return 2;
    }
    else
        return -1;
}

string infixToPostfix(string infix)
{
    stack<char> S;
    string postfix = "";
    for(int i =0; i<infix.size(); i++)
    {
        char symbol = infix[i];
        if(symbol == ' ')
            continue;
        if(isdigit(symbol))
        {
            while(i < infix.size() && isdigit(infix[i]))
            {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--;
        }
        else if(symbol == '(')
        {
            S.push(symbol);
        }
        else if(symbol == ')')
        {
            while(!S.empty() && S.top() != '(')
            {
                postfix = postfix + S.top();
                S.pop();
            }
            S.pop();
        }
        else
        {
            while(!S.empty() && priority(S.top()) >= priority(symbol))
            {
                postfix = postfix + S.top();
                S.pop();
            }
            S.push(symbol);
        }
    }
    while(!S.empty())
    {
        postfix = postfix + S.top();
        S.pop();
    }
    return postfix;
}
int evaluatePostfix(string s){
    stack<int> st;
    int i;

    for(i = 0; i < s.length(); ++i){
        if(s[i] == ' ')
            continue;

        else if(isdigit(s[i])){
            int num = 0;

            while(isdigit(s[i])){
                num = (num * 10) + (int)(s[i] - '0');
                i++;
            }

            i--;
            st.push(num);
        }

        else{
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            switch(s[i]){
                case '+':
                    st.push(b + a);
                    break;

                case '-':
                    st.push(b - a);
                    break;

                case '*':
                    st.push(b * a);
                    break;

                case '/':
                    st.push(b / a);
                    break;

                case '^':
                    st.push(pow(b, a));
                    break;

                default:
                    cout << "Invalid operator" << endl;
                    return -1;
            }
        }
    }

    return st.top();
}
int main()
{
    string infix = "(12 + 34) * 56 - 78 / 9";

    string postfix = infixToPostfix(infix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;

    return 0;
}

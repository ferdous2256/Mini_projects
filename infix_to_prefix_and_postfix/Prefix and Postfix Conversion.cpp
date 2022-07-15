#include<iostream>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;
string POSTFIX(string);
string PREFIX(string);
double EVALUATE_POSTFIX(string);
double EVALUATE_PREFIX(string);


int main()
{
    string infix,prefix,postfix;
    cout<<"Input the INFIX Expression: ";
    cin>>infix;
    prefix=PREFIX(infix);
    postfix=POSTFIX(infix);
    cout<<endl<<endl<<"The PREFIX Expression is: "<<prefix;
    cout<<endl<<endl<<"The POSTFIX Expression is: "<<postfix;
    cout<<endl<<endl<<"The PREFIX Evaluation result is: "<<EVALUATE_PREFIX(prefix);
    cout<<endl<<endl<<"The POSTFIX Evaluation result is: "<<EVALUATE_POSTFIX(postfix)<<endl<<endl;
}


double EVALUATE_PREFIX(string prefix)
{
    double result,a,b;
    stack<double> r;
    for(int i=prefix.length()-1;i>=0;i--)
    {
        switch(prefix[i])
        {
        case '+':
            a=r.top();
            r.pop();
            b=r.top();
            r.pop();
            result=a+b;
            r.push(result);
            break;
        case '-':
            a=r.top();
            r.pop();
            b=r.top();
            r.pop();
            result=a-b;
            r.push(result);
            break;
        case '*':
            a=r.top();
            r.pop();
            b=r.top();
            r.pop();
            result=a*b;
            r.push(result);
            break;
        case '/':
            a=r.top();
            r.pop();
            b=r.top();
            r.pop();
            result=a/b;
            r.push(result);
            break;
        case '^':
            a=r.top();
            r.pop();
            b=r.top();
            r.pop();
            result=pow(a,b);
            r.push(result);
            break;
        default:
            r.push(prefix[i]-'0');
            break;
        }
    }
    return r.top();
}

double EVALUATE_POSTFIX(string postfix)
{
    double result,a,b;
    stack<double> r;
    for(int i=0;i<postfix.length();i++)
    {
        switch(postfix[i])
        {
        case '+':
            b=r.top();
            r.pop();
            a=r.top();
            r.pop();
            result=a+b;
            r.push(result);
            break;
        case '-':
            b=r.top();
            r.pop();
            a=r.top();
            r.pop();
            result=a-b;
            r.push(result);
            break;
        case '*':
            b=r.top();
            r.pop();
            a=r.top();
            r.pop();
            result=a*b;
            r.push(result);
            break;
        case '/':
            b=r.top();
            r.pop();
            a=r.top();
            r.pop();
            result=a/b;
            r.push(result);
            break;
        case '^':
            b=r.top();
            r.pop();
            a=r.top();
            r.pop();
            result=pow(a,b);
            r.push(result);
            break;
        default:
            r.push(postfix[i]-'0');
            break;
        }
    }
    return r.top();
}

string PREFIX(string infix)
{
    string r,prefix;
    for(int i=infix.length()-1;i>=0;i--)
    {
        if(infix[i]==')')
            r+='(';
        else if(infix[i]=='(')
            r+=')';
        else
            r+=infix[i];
    }
    stack<char> s;
    int p=0;
    for(int i=0;i<r.length();i++)
    {
        switch(r[i])
        {
        case '+':
            while(p>1)
            {
                prefix+=s.top();
                s.pop();
                if(s.empty())
                    p=0;
                else if(s.top()=='+'||s.top()=='-')
                    p=1;
                else if(s.top()=='*'||s.top()=='/')
                    p=2;
                else if(s.top()=='^')
                    p=3;
                else
                    p=0;
            }
            s.push(r[i]);
            p=1;
            break;
        case '-':
            while(p>1)
            {
                prefix+=s.top();
                s.pop();
                if(s.empty())
                    p=0;
                else if(s.top()=='+'||s.top()=='-')
                    p=1;
                else if(s.top()=='*'||s.top()=='/')
                    p=2;
                else if(s.top()=='^')
                    p=3;
                else
                    p=0;
            }
            s.push(r[i]);
            p=1;
            break;
        case '*':
            while(p>2)
            {
                prefix+=s.top();
                s.pop();
                if(s.empty())
                    p=0;
                else if(s.top()=='+'||s.top()=='-')
                    p=1;
                else if(s.top()=='*'||s.top()=='/')
                    p=2;
                else if(s.top()=='^')
                    p=3;
                else
                    p=0;
            }
            s.push(r[i]);
            p=2;
            break;
        case '/':
            while(p>2)
            {
                prefix+=s.top();
                s.pop();
                if(s.empty())
                    p=0;
                else if(s.top()=='+'||s.top()=='-')
                    p=1;
                else if(s.top()=='*'||s.top()=='/')
                    p=2;
                else if(s.top()=='^')
                    p=3;
                else
                    p=0;
            }
            s.push(r[i]);
            p=2;
            break;
        case '^':
            s.push(r[i]);
            p=3;
            break;
        case '(':
            s.push(r[i]);
            p=0;
            break;
        case ')':
            while(s.top()!='(')
            {
                prefix+=s.top();
                s.pop();
            }
            s.pop();
            if(s.empty())
                p=0;
            else if(s.top()=='+'||s.top()=='-')
                p=1;
            else if(s.top()=='*'||s.top()=='/')
                p=2;
            else if(s.top()=='^')
                p=3;
            else
                p=0;
            break;
        default:
            prefix+=r[i];
            break;
        }
    }
    while(!s.empty())
    {
        prefix+=s.top();
        s.pop();
    }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

string POSTFIX(string infix)
{
    string postfix;
    stack<char> s;
    int p=0;
    for(int i=0;i<infix.length();i++)
    {
        switch(infix[i])
        {
        case '+':
            while(p>=1)
            {
                postfix+=s.top();
                s.pop();
                if(s.empty())
                    p=0;
                else if(s.top()=='+'||s.top()=='-')
                    p=1;
                else if(s.top()=='*'||s.top()=='/')
                    p=2;
                else if(s.top()=='^')
                    p=3;
                else
                    p=0;
            }
            s.push(infix[i]);
            p=1;
            break;
        case '-':
            while(p>=1)
            {
                postfix+=s.top();
                s.pop();
                if(s.empty())
                    p=0;
                else if(s.top()=='+'||s.top()=='-')
                    p=1;
                else if(s.top()=='*'||s.top()=='/')
                    p=2;
                else if(s.top()=='^')
                    p=3;
                else
                    p=0;
            }
            s.push(infix[i]);
            p=1;
            break;
        case '*':
            while(p>=2)
            {
                postfix+=s.top();
                s.pop();
                if(s.empty())
                    p=0;
                else if(s.top()=='+'||s.top()=='-')
                    p=1;
                else if(s.top()=='*'||s.top()=='/')
                    p=2;
                else if(s.top()=='^')
                    p=3;
                else
                    p=0;
            }
            s.push(infix[i]);
            p=2;
            break;
        case '/':
            while(p>=2)
            {
                postfix+=s.top();
                s.pop();
                if(s.empty())
                    p=0;
                else if(s.top()=='+'||s.top()=='-')
                    p=1;
                else if(s.top()=='*'||s.top()=='/')
                    p=2;
                else if(s.top()=='^')
                    p=3;
                else
                    p=0;
            }
            s.push(infix[i]);
            p=2;
            break;
        case '^':
            s.push(infix[i]);
            p=3;
            break;
        case '(':
            s.push(infix[i]);
            p=0;
            break;
        case ')':
            while(s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
            if(s.empty())
                p=0;
            else if(s.top()=='+'||s.top()=='-')
                p=1;
            else if(s.top()=='*'||s.top()=='/')
                p=2;
            else if(s.top()=='^')
                p=3;
            else
                p=0;
            break;
        default:
            postfix+=infix[i];
            break;
        }
    }
    while(!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}




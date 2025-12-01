#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,p;
    string s,t;
    cin>>n>>m>>s;
    p=s.find('I');
    while(m--)
    {
        cin>>t;
        if(t=="delete")
        {
            if(s.length()==p+1) continue;
            else s.erase(p+1,1);
        }
        else if(t=="backspace")
        {
            if(p-1>=0&&p+1<s.length()&&s[p-1]=='('&&s[p+1]==')')
            {
                s.erase(p-1,1);
                s.erase(p,1);
                p--;
            }
            else
            {
                if(p-1>=0)
                {
                    s.erase(p-1,1);
                    p--;
                }
            }
        }
        else if(t=="<-") 
        {
            if(p-1>=0) 
            {
                swap(s[p],s[p-1]);
                p--;
            }
        }
        else if(t=="->")
        {
            if(p+1<s.length())
            {
                swap(s[p],s[p+1]);
                p++;
            }
        }
    }
    cout<<s;
}
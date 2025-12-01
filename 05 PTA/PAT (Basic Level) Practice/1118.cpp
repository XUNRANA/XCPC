#include <bits/stdc++.h>
using namespace std;
string p[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void solve()
{
    string s;
    cin>>s;
    if(s.size()==1)
    {
        cout<<s;
        return ;
    }
    for(int i=0;i<10;i++) 
    if(s==p[i]) 
    {
        cout<<i;
        return ;
    }
    if(s.substr(0,4)=="sqrt")
    {
        int x=stoi(s.substr(4));
        cout<<sqrt(x);
        return ;  
    }
    
    for(int i=0;i<s.size();i++)
    {
        if(!isdigit(s[i]))
        {
            int x=stoi(s.substr(0,i));
            int y=stoi(s.substr(i+1));
            // cout<<x<<" "<<y<<"?\n";
            // cout<<s[i]<<"?\n";
            if(s[i]=='+')
            {
                cout<<x+y;
            }
            else if(s[i]=='-')
            {
                cout<<x-y;

            }
            else if(s[i]=='*')
            {
                cout<<x*y;

            }
            else if(s[i]=='/')
            {
                cout<<x/y;

            }
            else if(s[i]=='%')
            {
                cout<<x%y;
            }
            else if(s[i]=='^')
            {
                int r=1;
                while(y--) r*=x;
                cout<<r;
            }
            return  ;
        }
    }
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=11;
	// cin>>T;
	while(T--) solve(); 
}

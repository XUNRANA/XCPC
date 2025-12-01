#include <bits/stdc++.h>
using namespace std;


char a[]={'O','B','A','F','G','K','M'};

void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    if(s1[0]==s2[0]) 
    {
        if(s1[1]==s2[1]) cout<<"same\n";
        else if(s1[1]<s2[1]) cout<<"hotter\n";
        else cout<<"cooler\n";
    }
    else 
    {
        int c1=0,c2=0;
        for(int i=0;i<7;i++) 
        {
            if(s1[0]==a[i]) c1=i;
            if(s2[0]==a[i]) c2=i;
        }
        
        if(c1<c2) cout<<"hotter\n";
        else cout<<"cooler\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}


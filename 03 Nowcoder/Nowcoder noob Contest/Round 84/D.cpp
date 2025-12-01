#include <bits/stdc++.h>
using namespace std;
int n,q,w,l,r,i;
string s;
int main() 
{
    cin>>n>>q>>s;
    s="0"+s+"0";
    while(i++<=n) if(s[i]!=s[i+1]) w++;
    while(q--)
    {
        cin>>l>>r;
        cout<<(w-(s[l-1]!=s[l])-(s[r]!=s[r+1])+(s[l]!=s[r+1])+(s[l-1]!=s[r]))/2<<'\n';   
    }
} 
#include <bits/stdc++.h>
using namespace std;
int n;
string dfs(string s,int l)
{
    if(l>=n) return s;
    char cp=s[l];
    for(int i=0;i<3;i++)
    {
        if(cp!='?'&&cp-'0'!=i) continue;
        s[l]=char(i+'0');
        if(l>0&&s[l]==s[l-1]) continue;
        if(l>=2)
        {   
            int sum=((s[l-2]-'0')&1)+((s[l-1]-'0')&1)+((s[l]-'0')&1);
            if(sum&1) continue;
        }
        string res=dfs(s,l+1);
        if(res!="null") return res;
    }
    return "null";
}
void solve()
{
    string s,res; 
    cin>>s;
    n=s.size();
    res=dfs(s,0);
    if(res=="null") cout<<"-1\n";
    else cout<<res<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

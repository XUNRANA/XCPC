#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=2*n;i+=2)
    {
        char t[100];
        scanf("%s",t);
        if(i==1) cout<<"{";
        
        if((i/2)%2==0) printf("{\\color{%s}{\"%c\\underline{%c}\"}}",t,s[i],s[i+1]);
        else printf("{\\color{%s}{\"\\underline{%c}%c\"}}",t,s[i],s[i+1]);
        
        if(i+1!=2*n) cout<<",";
        else cout<<"}";
    }
}

signed main()
{
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);cout.tie(0);
	int T=1;
// 	cin>>T;
	while(T--) solve();
}

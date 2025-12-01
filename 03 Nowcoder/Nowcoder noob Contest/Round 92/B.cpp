#include <bits/stdc++.h>
using namespace std;
int n,h,ans;
char a[6][4010];
void solve()
{
	cin>>n>>h;
	map<int,int>c;
    for(int i=1;i<=5;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char ch=a[i][j];
			cin>>ch;
			if(ch=='*') 
            {
                if((i==1&&a[2][j]=='#')||(i==5&&a[4][j]=='#')) c[2]++;
                else c[1]++;
            }
		}
	}
//	cout<<c[1]<<" "<<c[2]<<"\n";
	if(c[1]>h) ans=h;
	else 
	{
		ans=c[1];
		h-=c[1];
		ans+=min(h/2,c[2]);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
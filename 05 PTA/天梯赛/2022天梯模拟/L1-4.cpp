#include<bits/stdc++.h>
using namespace std;

string s1[]={"duo chi yu!","wan mei!","ni li hai!"};
string s2[]={"duo chi rou!","wan mei!","shao chi rou!"};
void solve()
{
	int n,a,b,c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		if(a)
		{
			if(b==130) cout<<s1[1]<<" ";
			else if(b<130) cout<<s1[0]<<" ";
			else cout<<s1[2]<<" ";
			
			if(c==27) cout<<s2[1]<<"\n";
			else if(c<27) cout<<s2[0]<<"\n";
			else cout<<s2[2]<<"\n";
		}
		else
		{
			if(b==129) cout<<s1[1]<<" ";
			else if(b<129) cout<<s1[0]<<" ";
			else cout<<s1[2]<<" ";
			
			if(c==25) cout<<s2[1]<<"\n";
			else if(c<25) cout<<s2[0]<<"\n";
			else cout<<s2[2]<<"\n";
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}



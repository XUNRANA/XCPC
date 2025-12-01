#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,a[100010],vt[100010],res=1,t,t1;
char s[100010][6];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	
    for(int i=1;i<=n;i++)
	{
		if(vt[i]) continue;
        t=i;
		while(!vt[t])
		{
			vt[t]=i;
			t=a[t];
		}
        
        if(vt[t]==i)
        {
            int cnt=0,c;
            for(int j=0;j<5;j++)
            {
                t1=t;
                c=j;
                do
                {
                    c=s[t1][c]-'A';
                    t1=a[t1];
                }while(t1!=t);
                if(c==j) cnt++;
            }
            res=res*cnt%P;
        }
	}
	cout<<res<<"\n";
} 

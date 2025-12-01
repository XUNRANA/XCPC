#include <bits/stdc++.h>
using namespace std;
int l,r;
int f(int x)
{
    int res=0;
    while(x)
    {
        res+=(x%10)*(x%10);
        x/=10;
    }
    return res;
}
int is(int x)
{
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
int a[100010];
int main()
{
	cin>>l>>r;
    vector<pair<int,int>>v;
	for(int i=l;i<=r;i++)
	{
		int j=i;
		set<int>s;
		s.insert(j);
        while(1)
        {
            j=f(j);
            a[j]=1;
            if(s.count(j)) break;
            if(j==1)
            {
            	int ans=s.size();
                if(is(i)) ans*=2;
                v.push_back({i,ans});
                break;
            }
            s.insert(j);
        }
	}
    for(auto i:v) if(!a[i.first]) cout<<i.first<<" "<<i.second<<"\n";
    if(v.empty()) cout<<"SAD\n";
}

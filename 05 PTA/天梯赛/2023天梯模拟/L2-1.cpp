#include <bits/stdc++.h>
using namespace std;
int c[1010];
void solve()
{
	int n,m,k;
	vector<int>a;//À…÷¶∏…
	stack<int>b;
	stack<int>h; 
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=n;i>=1;i--) b.push(c[i]);
	while(1)
	{
		if((int)a.size()==k)
		{
			int f=0;
			for(auto i:a) 
			{
				if(f) cout<<" ";
				cout<<i;
				f=1; 
			}
			cout<<"\n";
			a.clear();
		}
		
		if(a.empty())
		{
			if(!h.empty()) 
			{
				a.push_back(h.top());
				h.pop();
			}
			else if(!b.empty())
			{
				a.push_back(b.top());
				b.pop();
			}
			else break;
		}
		else
		{
            if(b.empty()&&!h.empty()&&h.top()>a.back())
            {
                int f=0;
                for(auto i:a) 
                {
                    if(f) cout<<" ";
                    cout<<i;
                    f=1; 
                }
                cout<<"\n";
                a.clear();
                continue;
            }
			if(!h.empty()&&h.top()<=a.back()) 
			{
				a.push_back(h.top());
				h.pop();
			}
			else if(!b.empty())
			{
				if(b.top()<=a.back())
				{
					a.push_back(b.top());
					b.pop();
				}
				else 
				{
					if((int)h.size()==m)
					{
						int f=0;
						for(auto i:a) 
						{
							if(f) cout<<" ";
							cout<<i;
							f=1; 
						}
						cout<<"\n";
						a.clear();
						continue;
					}
					else
					{	
						h.push(b.top());
						b.pop();
					}
				}
			}
			else break;
		}
	}
	if(a.size())
	{
		int f=0;
		for(auto i:a) 
		{
			if(f) cout<<" ";
			cout<<i;
			f=1; 
		}
		cout<<"\n";
	}
}	
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int T=1;
//	cin>>T;
	while(T--) solve();
}

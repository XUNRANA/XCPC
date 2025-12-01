#include <bits/stdc++.h>
using namespace std;


int n,m,k;
int a[1010];

void solve()
{
	cin>>n>>m>>k;
	stack<int>t;//推送器 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--) t.push(a[i]);
	stack<int>h;//盒子 
	vector<vector<int>>ans;
	vector<int>p;//松针 
	while(!h.empty()||!t.empty())
	{
		int x=0;//取松枝 
		if(p.empty())//空松干，随意取 
		{
			if(!h.empty())//盒子非空 
			{
				x=h.top();
				h.pop();
			}
			else if(!t.empty())//推送器非空 
			{
				x=t.top();
				t.pop();
			}
			p.push_back(x);//一定能放进去 
            if(p.size()==k)
            {
                ans.push_back(p);
                p.clear();
            }
		}
		else //非空，需要递减 
		{ 
			if(!h.empty()&&h.top()<=p.back())//盒子里可以取 
			{
				x=h.top();
				h.pop();
				p.push_back(x);
                if(p.size()==k)
        		{
        			ans.push_back(p);
        			p.clear();
        		}
			}
			else if(!t.empty())//盒子不能取，取推送器里的 
			{
				if(t.top()<=p.back())//取推送器里的 
				{
					x=t.top();
					t.pop();
					p.push_back(x);
                    if(p.size()==k)
            		{
            			ans.push_back(p);
            			p.clear();
            		}
				}
				else //推送器放盒子里 
				{
					
                    if(h.size()==m)
            		{
            			ans.push_back(p);
            			p.clear();
            			continue; 
            		}
            		else
            		{
	            		h.push(t.top());
						t.pop();
					}
				}	
			}
			else 
			{
				ans.push_back(p);
				p.clear();
			}
		}
		
		
	}
	
	if(p.size()) ans.push_back(p);
	
	for(auto i:ans)
	{
		int f=0;
		for(auto j:i) 
		{
			if(f) cout<<" ";
			cout<<j;
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


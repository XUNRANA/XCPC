#include<bits/stdc++.h>
using namespace std;
template<class code>inline code read(const code &a){
	code x=0;bool fg=0;
	char c=getchar();
	while(!isdigit(c)){
		fg|=(c=='-');
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return fg?-x:x;
}
char dd[1000005],a[1000005],b[1000005];
vector<int>zs[105];
void qk(int x){
	for(int i=0;i<=13;i++){
		while(!zs[i].empty()&&zs[i][zs[i].size()-1]>x)zs[i].pop_back();
	}
}
int mq,cnt,s1,s2;
void cl(int &s,char c){
	int bj=0;
		if(isdigit(c))bj=c-'0';
		else if(c=='J')bj=10;
		else if(c=='Q')bj=11;
		else if(c=='K')bj=12;
		if(bj<=9){
			if(zs[bj].empty()){
				mq++;
				zs[bj].emplace_back(mq);
			}else{
				int zd=zs[bj][zs[bj].size()-1],tag=0;
				if(!zs[11].empty()){
					int z=zs[11][zs[11].size()-1];
					if(z>zd){
						zs[11].pop_back();
						++mq;
						zs[bj].emplace_back(mq);
						tag=1;
					}
				}
				if(!tag){
					s+=mq-zd+2;
					mq=zd-1;
					qk(mq);
				}
			}
		}else{
			if(bj==10){
				int zd=1;
				if(!zs[11].empty()){
					zd=zs[11][zs[11].size()-1];
				}
				s+=mq-zd+2;
				mq=zd-1;
				qk(mq);
			}else if(bj==11){
				++mq;
				zs[11].emplace_back(mq);
			}else if(bj==12){
				if(!zs[11].empty()){
					zs[11].pop_back();
				}
				++mq;
				zs[12].emplace_back(mq);
			}
		}
}
void solve(){
	int n=read(n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	mq=0,s1=0,s2=0;
	for(int i=1;i<=n;i++){
		cl(s1,a[i]);
		cl(s2,b[i]);
	}
	for(int i=0;i<=13;i++)zs[i].clear();
	printf("%d %d\n",s1,s2);
}
int main(){
//	freopen("text.out","w",stdout);
	int t=read(t);
	while(t--)solve();
	return 0;
} 

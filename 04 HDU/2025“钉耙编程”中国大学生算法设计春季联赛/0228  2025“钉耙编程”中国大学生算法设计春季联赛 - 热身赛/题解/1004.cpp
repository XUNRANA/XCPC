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
bool check(long long a,long long b){
	if(a%b==0)return 1;
	if(b*2<=a)return 1;
	return !check(b,a-b);
}
long long ans=0,f[105];
void solve(){
	long long a=read(a);
	long long b=(a*0.618033988749894848);
	while(b>0&&!check(a,b))--b;
	while(b+1<a&&check(a,b+1))++b;
	ans^=(b+1);
}
int main(){

	int t;
	scanf("%d",&t);
	while(t--)solve();
	printf("%lld\n",ans);
	return 0;
} 

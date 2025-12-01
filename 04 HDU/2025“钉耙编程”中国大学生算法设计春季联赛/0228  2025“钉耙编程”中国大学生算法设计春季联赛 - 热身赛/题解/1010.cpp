#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	long long ans=0,su=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		su+=abs(x);
		ans+=su; 
	}
	printf("%lld\n",ans);
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
void test()
{
	//二分查找方法 
	vector<int>v;//必须是有序序列 
	for(int i=0;i<10;i++) v.push_back(i+1);
	bool ret=binary_search(v.begin(),v.end(),9);
	if(ret) cout<<"Find\n";
	else cout<<"Not Find\n";
}
int main()
{
	test();
} 

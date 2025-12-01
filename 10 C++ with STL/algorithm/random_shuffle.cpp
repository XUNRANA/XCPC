#include <bits/stdc++.h>
using namespace std;
void print(int a)
{
	cout<<a<<" ";
}
void test()
{
	vector<int>v;
	for(int i=0;i<10;i++) v.push_back(i+1);
	random_shuffle(v.begin(),v.end());
	for_each(v.begin(),v.end(),print);
}
int main()
{
	srand((unsigned int)time(NULL));
	test();
} 

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,id[100009],a[100009],b[100009],s[100009];
void add(int l,int r,int x)
{
	if(id[l]==id[r])
	{
		for(int i=l;i<=r;i++) 
		{
			a[i]+=x;
			s[id[l]]+=x;
		} 
		return ;
	}
	for(int i=id[l]+1;i<id[r];i++) 
	{
		b[i]+=x;
		s[i]+=sqrt(n)*x;
	}
	for(int i=l;id[i]==id[l];i++) 
	{
		a[i]+=x;
		s[id[l]]+=x;
	}
	for(int i=r;id[i]==id[r];i--) 
	{
		a[i]+=x;
		s[id[r]]+=x;
	}
	return ;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		id[i]=(i-1)/sqrt(n)+1;
		s[id[i]]+=a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		int l,r,op,c;
		cin>>op>>l>>r>>c;
		if(op==0) add(l,r,c);
		else cout<<a[r]+b[id[r]]<<endl;
	}
	return 0;
}

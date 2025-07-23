#include <bits/stdc++.h>
#define Maxn 5007
#define modp 998244353
int p[Maxn][Maxn];
int pre[Maxn];
int a,b,c;
int solve(int x,int y)
{
	int res=0;
	for (int k=0;k<=x&&k<=y;k++)
	{
		int del=pre[k];
		del=(1LL*del*p[x][k])%modp;
		del=(1LL*del*p[y][k])%modp;
		res=(res+del)%modp;
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	memset(p,0,sizeof(p));
	p[0][0]=1;
	for (int i=1;i<=5000;i++)
	{
		p[i][0]=1;
		for (int j=1;j<=i;j++)
			p[i][j]=(p[i-1][j-1]+p[i-1][j])%modp;
	}
	memset(pre,0,sizeof(pre));
	pre[0]=1;
	for (int i=1;i<=5000;i++)
		pre[i]=(1LL*pre[i-1]*i)%modp;
	int ans=1;
	ans=(1LL*ans*solve(a,b))%modp;
	ans=(1LL*ans*solve(b,c))%modp;
	ans=(1LL*ans*solve(a,c))%modp;
	printf("%d\n",ans);
	return 0;
}
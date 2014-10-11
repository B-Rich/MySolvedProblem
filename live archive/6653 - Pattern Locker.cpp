/*
*
* solved by Ahmed Kamal
*/
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<cstring>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<bitset>
#include<queue>
#include<utility>
#include<algorithm>
#include<functional>

using namespace std;

typedef long long int LL ;
#define vi vector<int> 
#define ii pair<int,int> 
#define vii vector< pair<int,int> > 
#define sc(x) scanf("%d",&x)
double const EPS = 2.22045e-016;
#define INF (1<<29)

#define ALL(v)              ((v).begin()), ((v).end())
#define SZ(v)               ((int)((v).size()))
#define CLR(v, d)           memset(v, d, sizeof(v))
#define REP(i, n)       for(int i=0;i<(int)(n);++i)
#define LOOP(i,b, n)        for(int i=(b);i<(int)(n);++i)

#define PB  push_back
typedef vector<double>    VD;
typedef vector<string>    VS;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
LL mod = 10000000000007;
int L,N,M;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t; sc(t);
    REP(ts,t){
    sc(L);sc(N);sc(M);
        L *=L;
        LL ans=0;

        LL h=L;
        int temp = L;
        REP(i,N-1){
          h*=--temp;
          h%=mod;
        }
         // printf("h %lld\n", h);
        REP(i,(M-N) +1 ){
           ans+= h;
           ans =ans% mod;
           h*=(--temp);
           h = h%mod;
       }
       printf("Case %d: %lld\n",ts+1,ans);
   }
   return 0; 
}

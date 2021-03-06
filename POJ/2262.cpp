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

#define ALL(v)        ((v).begin()), ((v).end())
#define SZ(v)       ((int)((v).size()))
#define CLR(v, d)     memset(v, d, sizeof(v))

#define REP(i, n)   for(int i=0;i<(int)(n);++i)
#define LOOP(i,b,n)   for(int i=(b);i<(int)(n);++i)

#define PB  push_back
typedef vector<double>    VD;
typedef vector<string>    VS;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

const int MaxN = 1000006;
bool isprime[MaxN];
vector<int> primes ;
void sieve () {
  CLR(isprime,true);
   for(int i = 2 ; i <= MaxN ; i++)
     if(isprime[i])
        for(int j = 2*i ; j <= MaxN ; j +=i)
              isprime[j] = false ;
for(int i = 2 ; i <= MaxN ; i++ )
  if(isprime[i])
    primes.push_back(i);
}


int main()
{
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      //freopen("output.txt", "w", stdout);
  #endif
  sieve();
  int pn = SZ(primes);
  int n;
  while(sc(n) != EOF && n != 0){
    int sq = n+1/2;
    int ans = -1;
    REP(i,pn){
      if(primes[i] > sq)
        break;
      if(isprime[n-primes[i] ]){
        ans = primes[i];
        break;
      }
    }
    if(ans  == -1)
      printf("Goldbach's conjecture is wrong.\n");
    else
      printf("%d = %d + %d\n",n,ans,n-ans );
  }
return 0; 
}

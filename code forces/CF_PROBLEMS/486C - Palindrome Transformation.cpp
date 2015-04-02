/*
*
* solved by Ahmed Kamal
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long int LL ;
#define vi vector<int> 
#define ii pair<int,int> 
#define vii vector< pair<int,int> > 

#define ALL(v)        ((v).begin()), ((v).end())
#define SZ(v)       ((int)((v).size()))
#define CLR(v, d)     memset(v, d, sizeof(v))
#define REP(i, n)   for(int i=0;i<(int)(n);++i)
#define LOOP(i,b, n)    for(int i=(b);i<(int)(n);++i)

#define SC(x) scanf("%d",&x)
#define DSC(x) int x; scanf("%d",&x)
#define DSC2(x,y) int x,y; scanf("%d %d",&x,&y)

#define PB  push_back
#define MP  make_pair
double const EPS = 2.22045e-016;
#define INF (1<<29)


typedef vector<double>    VD;
typedef vector<string>    VS;
void print_v(vi arr){
int n = SZ(arr);
  REP(i,n)
    if(i == n-1)
       printf("%d\n",arr[i] );
     else
      printf("%d ", arr[i]);
}

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }


int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
DSC2(n,p);
string s; cin>>s;
vi arr(n,0);
if(p > n/2){
  reverse(ALL(s));
  p = n-p+1;
}
p--;
// printf("%d\n",p );
REP(i,n/2){
  arr[i] = arr[n-i-1] = min((s[i] - s[n-i-1] + 26)%26,(s[n-i-1] - s[i] + 26)%26 );
}
// print_v(arr);
int a=p,aa=p , b=p,bb=p;
REP(i,n/2){
  if(arr[i] > 0 && i <= p){
    aa = i;
    break;
  }
}
for(int i = p-1; i>=0 ;i--){
  if(arr[i] > 0){
    a = i;
    break;
  }
}
LOOP(i,p,n/2){
  if(arr[i] > 0){
    b = i;
    break;
  }
}
for(int i = n/2-1; i>=p ;i--){
  if(arr[i] > 0){
    bb = i;
    break;
  }
}
 // printf("aa %d, a %d , b = %d , bb= %d\n",aa,a,b,bb );
int ans1=arr[p] ,ans2=arr[p];
int i =p+1;
while(i <= bb){
  ans1++;
  ans1 += arr[i];
  i++;
}
ans1+=bb-p;
i = p-1;
while(i >=aa ){
  ans1++;
  ans1+=arr[i];
  i--;
}
////////////////////
i =p-1;
while(i >= aa){
  ans2++;
  ans2 += arr[i];
  i--;
}
ans2+=p-aa;
i = p+1;
while(i <=bb ){
  ans2++;
  ans2+=arr[i];
  i++;
}
// printf("1 = %d , 2 = %d\n",ans1 , ans2 );
printf("%d\n",min(ans1,ans2) );
return 0; 
}

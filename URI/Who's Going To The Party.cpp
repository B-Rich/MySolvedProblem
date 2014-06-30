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

#define ALL(v)				((v).begin()), ((v).end())
#define SZ(v)				((int)((v).size()))
#define CLR(v, d)			memset(v, d, sizeof(v))
#define LOOP(i, n)		for(int i=0;i<(int)(n);++i)
#define LOOPP(i,b, n)		for(int i=(b);i<(int)(n);++i)

#define PB	push_back
typedef vector<double>    VD;
typedef vector<string>    VS;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
        int n;
        while(cin>>n && n!=0){
            vii pairs(n,ii(0,0));
            bool hash[1005];
            CLR(hash,false);
            scanf("\n");
            LOOP(i,n)
                scanf("(%d,%d) ",&pairs[i].first,&pairs[i].second);       
            int ch =1;
            hash[1]=true;
            while(ch >0){
                ch =0;
                LOOP(i,n){
                    if(hash[pairs[i].first] && !hash[pairs[i].second]){
                      hash[pairs[i].second]=true;
                      ch++;
                    }
                    else if( !hash[pairs[i].first] && hash[pairs[i].second]){
                      hash[pairs[i].first]=true;
                      ch++;
                    }
                }
            }
            int ans=0;
            LOOP(i,1002){
                if(hash[i])
                    ans++;
            }
            printf("%d\n",ans);
        
        }

return 0; 
}

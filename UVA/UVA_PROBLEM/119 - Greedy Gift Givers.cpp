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
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
        int n;
        int t=0;
        while(cin>>n){
            if(t++ > 0)
                printf("\n");
            VS names(n,"");
            map<string, int> mp;
            LOOP(i,n){
                cin>>names[i];
                mp[names[i]]=0;
            }
            LOOP(i,n){
                string name;int mony,num;
                cin>>name>>mony>>num;
                int b;
                if(mony !=0 && num !=0)
                 b= mony/num;                
                else
                    b=0;
                LOOP(i,num){
                    string temp;
                    cin>>temp;
                    mp[temp]+=b;
                }
                mp[name] -= (mony -(mony-num*b));
            }       
            
            LOOP(i,n)
                cout<<names[i]<<" "<<mp[names[i]]<<endl;
            
            
        }
        

return 0; 
}
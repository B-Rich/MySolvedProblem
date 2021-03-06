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
#include<stack>
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
double const Epsilon = 2.22045e-016;

#define ALL(v)				((v).begin()), ((v).end())
#define SZ(v)				((int)((v).size()))
#define CLR(v, d)			memset(v, d, sizeof(v))
#define LOOP(i, n)		for(int i=0;i<(int)(n);++i)

#define PB	push_back
typedef vector<double>    VD;
typedef vector<string>    VS;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int main()
{
  //  freopen("input.txt","r",stdin);
 //   freopen("output.txt","w",stdout);
int t;
string s;getline(cin,s);
stringstream ss;
ss<<s; ss>>t;
//sc(t);//scanf("\n");
LOOP(i,t){
stack<char> arr;
int p=0,k=0;
bool good =true;
getline(cin,s);
LOOP(i,SZ(s)){
	switch(s[i]){
	case '(' : arr.push(s[i]);
	  break;
	case '[' : arr.push(s[i]);
	  break;
	case ')' :
	   if(arr.empty() || arr.top() !='(' )
			good =false;
	   else
		   arr.pop();
	   break;
	case ']' :
		   if(arr.empty() || arr.top() !='[' )
				good =false;
		   else
			   arr.pop();
	  break;
	 }

}
if(!arr.empty())
	good=false;
if(good)
	printf("Yes\n");
else
	printf("No\n");

}


return 0;
}


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
//#define ii pair<int,int>
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

class TheMatrix {
public:
	int MaxArea(vector <string> arr) {
		int n=SZ(arr),m=SZ(arr[0]);
		int max_a =0;
		LOOP(i,n)
		  LOOP(j,m){
			int max_i=i;
					int max_j =m ;
			for (int ii = i; ii < n; ++ii) {
				for (int jj = j+1; jj < m; ++jj) {
					if(arr[ii][jj] == arr[ii][jj-1] && max_j > jj ){
						max_j = jj;
						break;
					}
				}
				if( ii<n-1 &&  arr[ii+1][j] == arr[ii][j] ){
						max_i = ii+1;
						break;
					}
				max_i++;


				int aria = (max_i-i)*(max_j-j);
				if(aria> max_a)
					max_a = aria;

			}
			int aria = (max_i-i)*(max_j-j);
			if(aria> max_a)
				max_a = aria;
		}
		return max_a;
	}

};

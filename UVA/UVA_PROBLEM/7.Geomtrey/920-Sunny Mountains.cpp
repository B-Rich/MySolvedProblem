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
double const EPS = 2.22045e-018;

#define ALL(v)				((v).begin()), ((v).end())
#define SZ(v)				((int)((v).size()))
#define CLR(v, d)			memset(v, d, sizeof(v))
#define LOOP(i, n)		for(int i=0;i<(int)(n);++i)

#define PB	push_back
typedef vector<double>    VD;
typedef vector<string>    VS;

// struct point_i { int x, y; };
// basic raw form, minimalist mode
struct point {
	double x, y;// whenever possible, work with point_i
point(int _x, int _y) { x = _x, y = _y; } // constructor (optional)
bool operator < (point other) const {// override ‘less than’ operator
if (x==other.x)// useful for sorting
   return y > other.y;// first criteria , by x-axis
return x > other.x;// second criteria, by y-axis
}
};
struct line { double a, b, c; };

bool areParallel(line l1, line l2) {// check coefficient a + b
return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areSame(line l1, line l2) {// also check coefficient c
return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }

bool areIntersect(line l1, line l2, point *p) {
if (areSame(l1, l2)) return false;// all points intersect
if (areParallel(l1, l2)) return false;// no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
p->x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
if (fabs(l1.b) > EPS)// special case: test for vertical line
p->y = - (l1.a * p->x + l1.c) / l1.b;// avoid division by zero
else
p->y = - (l2.a * p->x + l2.c) / l2.b;
return true; }

void pointsToLine(point p1, point p2, line *l) {
if (p1.x == p2.x) {
// vertical line is handled nicely here
l->a = 1.0;
l->b = 0.0;
l->c = -p1.x;
// default values
} else {
l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
l->b = 1.0;
l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
} }

void pointSlopeToLine(point p, double m, line *l) {
l->a = -m;
l->b = 1;
l->c = -((l->a * p.x) + (l->b * p.y)); }

double dist(point p1, point p2) {
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
return hypot(p1.x - p2.x, p1.y - p2.y); }
// Euclidean distance
// return double

int main()
{
 //  freopen("input.txt","r",stdin);
 //   freopen("output.txt","w",stdout);
int test;sc(test);
LOOP(ts,test)
{
	double ans=0.0;
	int n ;sc(n);
 vector<point> arr;
 arr.assign(n,point(0,0));

	LOOP(i,n){
		point p(0,0);
		cin>>p.x;cin>>p.y;
		arr[i]=p;
	}

	std::sort( arr.begin(),arr.end() );
	//reverse(ALL(arr));
	//int m_y=0;
	point p_y0(0,0),p_yn(arr[0].x,arr[0].y);
	for(int i =1; i<n ;i++)
	{
	 	line l1,l2;
	 pointsToLine( arr[i-1], arr[i], &l1);
    p_y0.x=0;      p_y0.y=p_yn.y;
   // p_yn.x=30001;     p_yn.y=m_y;
	 pointSlopeToLine(p_yn,0.0, &l2);

	 point des(0,0);
	 if(p_yn.y<arr[i].y && areIntersect( l1, l2, &des))
      ans+=dist(arr[i],des);

      if(arr[i].y > p_yn.y){
    	  p_yn.y=arr[i].y;
    	  p_yn.x=arr[i].x;
      }
	}
printf("%.2f\n",ans);
}


return 0;
}


// source : http://saketsaurabh.in/blog/2009/11/radius-of-a-sphere-inscribed-in-a-general-tetrahedron/
// 			http://en.wikipedia.org/wiki/Tetrahedron	
#include <bits/stdc++.h>
using namespace std;

typedef long long 		ll;
typedef list<int> 	li;
typedef vector<int> 	vi;
typedef vector<double> 	vd;
typedef vector<long long> 	vll;
typedef vector<bool> 	vb;
typedef pair<int,int> 	pii;
typedef vector<pair<int,int> > vpii;
typedef pair<double,double> 	pdd;
typedef vector<pair<double,double> > vpdd;

#define rep(i,n)    		for(int i=0;i<n;i++)
#define repi(i,k,n) 		for(int i=k;i<n;i++)
#define mp 				make_pair
#define pb			 	push_back
#define all(a) 			a.begin(),a.end()
#define imax  			numeric_limits<int>::max()
#define imin 			numeric_limits<int>::min()
#define dmax            numeric_limits<double>::max()
#define dmin            numeric_limits<double>::min()
class tetrahedron {
	double u,v,w,U,V,W ;
	public :
		tetrahedron ( double a=0,double b=0,double c=0,double d=0,double e=0,double f=0) {
			u = a ;
			v = b ;
			w = c ;
			U = d ;
			V = e ;
			W = f ;
		}
		double area_of_face ( double a,double b,double c) {
			double p = (a+b+c)/2;
			double area = sqrt(p*(p-a)*(p-b)*(p-c));
			return area;
		}
		double volume ( ) { // using heron formula given by Piero della Francesca
			double X = (w-U+v)*(U+v+w); 
			double x = (U-v+w)*(v-w+U);
			double Y = (u-V+w)*(V+w+u);
			double y = (V-w+u)*(w-u+V);
			double Z = (v-W+u)*(W+u+v);
			double z = (W-u+v)*(u-v+W);
			double a = sqrt(x*Y*Z);
			double b = sqrt(y*Z*X);
			double c = sqrt(z*X*Y);
			double d = sqrt(x*y*z);
			double vol = sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d)) / (192*u*v*w) ;
			return vol ;
			
/*			double Volume = 4*u*u*v*v*w*w;
			Volume -= u*u*pow(v*v+w*w-U*U,2);
			Volume -= v*v*pow(w*w+u*u-V*V,2);
			Volume -= w*w*pow(u*u+v*v-W*W,2);
			Volume += (v*v+w*w-U*U)*(w*w+u*u-V*V)*(u*u+v*v-W*W);
			Volume = sqrt(Volume);
			Volume /= 12;
			return Volume ;
*/		}
		double surface_area ( ) {  // sum of area of all the triangles of tetrahedron
			double area = area_of_face(u,v,W);
			area += area_of_face(W,V,U);	
			area += area_of_face(w,V,u);
			area += area_of_face(w,v,U);
			return area;
		}
		double radius() {
			double radius = (3*volume()) / surface_area();
			cout << volume() << " " << surface_area() << endl;
			return radius;
		}
};
int main() {
	int t;
	cin >> t;
	while(t--) {
		double u,v,w,U,V,W ;
		cin >> u >> v >> w >> W >> V >> U ;
		tetrahedron example(u,v,w,U,V,W);
		cout << example.radius() << endl;
	}
}



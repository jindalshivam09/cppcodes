#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;
#define MAX 10000000

class point {

	LL x,y;
	public:
		point(LL a=0,LL b=0) : x(a) , y(b) {}
		void read() {
		
			cin >> x >> y;
		}
		
		LL operator ^ (const point &a) const {
		
			return x * a.y - y * a.x;
		}

		int quadrant () const  {
		
			return y > 0 || y == 0 && x > 0;
		}
		
		point operator + (const point &a) const {
		
			return point(a.x+x , a.y+y);
		}
		
		bool operator < (const point &a) const{
		
			return x < a.x || x == a.x && y < a.y;
		}
		
		point operator - () const{
		
			return point(-x,-y);
		}
		
		bool operator == (const point &a) const {
		
			return x == a.x && y == a.y;
		}
};

bool less_angle (const point &a, const point &b) {

	int p = a.quadrant();
	int q = b.quadrant();
	if( p != q )
		return p > q;
	else
		return (a ^ b) > 0;
}
pair<point,LL> polyline[MAX];
point cordinates[151];

LL LLabs(LL a) {
	return a > 0 ? a : -a;
}
	
int main() {

	int n;
	cin >> n;
	
	for(int i=0;i<n;i++)
		cordinates[i].read();
		
	sort(cordinates,cordinates+n,less_angle);

	int count=0;
	
	for (int i=0;i<n;i++) {
	
		for(int j=i;j<n;j++) {
		
			LL area = cordinates[i]^cordinates[j];	
			point sum = cordinates[i] + cordinates[j];
			
			if (area < 0)
				break;	
			
			area = LLabs(area);		
			polyline[count++] = make_pair(sum,area);
			
			for (int k=j;k<n;k++) {
			
				sum = sum + cordinates[k];
				
				if ((cordinates[j]^cordinates[k]) < 0)
					break;
				
				if((cordinates[i]^sum)>=0)
					polyline[count++] = make_pair(sum , area + LLabs(cordinates[k]^sum));
			}
		}
	}
	
	sort(polyline , polyline + count ) ;
	int k=0,j=0;
	
	for(int i=0;i<count;i=j) {
	
		for( j=i; j<count&& polyline[i].first == polyline[j].first ;j++) ;
		
		polyline[k++] = polyline[j-1];
	}
	count = k;
	
	LL ans = 0;
	for (int i=0; i < count ; i++) {
	
		point sum = -polyline[i].first;
		
		int j =  lower_bound(polyline,polyline+count,make_pair(sum,-1LL)) - polyline;
		
		if( j < count && polyline[j].first == sum)
			ans = max( ans, polyline[i].second + polyline[j].second);
	}
	cout << ans/2 << "." << ans%2 * 5 << endl;
}

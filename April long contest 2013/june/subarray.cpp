#include<iostream>
#include<complex>
#include<vector>
using namespace std;
#define MAX 1000000000
#define PI 3.14159265358979323846


typedef long long ll;

// using FFT 

int rev(int k,int bit)
{
	int res=0;
	while(bit)
	{
		res<<=1;
		if(k&1)
		res++;
		k>>=1;
		bit--;
	}
	return res;
}
template<class T> vector< complex<double> > reverseBit (const vector<T> &poly) {
	ll size = poly.size(); 
	vector<complex<double> > res(size);
	int bits=0;
	int s = size;
	while(s) {
		bits++;
		s>>=1;
	}
	bits--;
	
	for(int k=0;k<size;k++) {
		res[rev(k,bits)]=complex<double>(poly[k]);
	}
	return res;
}

//------------ Fast Fourier Transformation-------------------------

template <class T> vector<complex<double> > FFT (const vector<T> &poly , ll size , bool flag) {
	
	vector< complex<double> > p = reverseBit(poly);
	int pos=0;
	int s = size;
	while(s) {
		pos++;
		s >>= 1;
	}
	pos--;
	for(int i=1 ; i<=pos ; i++) {
		ll m = 1 << i;
		complex<double> wn(cos((2*PI)/m), sin((2*PI)/m));
		if(!flag)
		 wn = complex<double>(cos((-2*PI)/m), sin((-2*PI)/m));
		
		for(int j=0 ; j<size ; j += m) {
			complex<double> w=1;
			
			for(int k=0 ; k<m/2 ; k++) {
				complex<double> t = w * p[j+k+m/2];
				complex<double> u = p[j+k];
				p[j+k] = u + t;
				p[j+k+m/2] = u - t;
				w = w*wn;		
			}
		}	
	}
	return p;
}

//------------Inverse FFT---------------------------

vector<double> inverseFFT (const vector<complex<double> > &poly, ll size) {
	vector<complex<double> > p = FFT(poly,size,false);
	vector<double> res(p.size());
	for(ll i=0 ; i<p.size() ; i++) {
		res[i] = (p[i].real())/size;
	}
	return res;
}

vector<double> operator * (vector<double> &poly1 ,vector<double> &poly2) {
	ll size1 = poly1.size() ;
	ll size2 = poly2.size();
	ll size = max(size1,size2);
	
	// find next power of 2 greater than size as resulting poly wil hace degreebound as sum of both poly's degreebound
	ll pos = 0;
	while(size) {
		pos++;
		size >>= 1;
	}
	pos++;
	size = 1<<(pos);
	
	poly1.resize(size,0);
	poly2.resize(size,0);
	
	vector< complex<double> >  p1 = FFT(poly1,poly1.size(),true); 
	vector< complex<double> >  p2 = FFT(poly2,poly2.size(),true);

	vector< complex<double> > mult(poly1.size());
	
	for(ll i=0 ; i<mult.size() ; i++) {
		mult[i] = p1[i] * p2[i];
	}	
	
	vector<double> res = inverseFFT(mult,mult.size());
	return res;
}

main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	int q;
	
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	
	if(n==1){
		cout << 0 << endl;
	}
	else {
		vector<ll> sum(n);
		sum[0] = arr[0];
		for(int i=1;i<n;i++) {
			sum[i] = arr[i] + sum[i-1];
		}
		//cout << arr[n] << endl;
		vector<double>  poly1,poly2;
		poly1.resize(sum[n-1]+1,0);
		poly2.resize(sum[n-1]+1,0);
		// creating polynomials        poly1[i] + poly2[j] - sum[n-1] = sum_subarray[j-i]   where j<i  

		for(int i=0;i<n;i++) {
			poly1[sum[i]] = 1;
			poly2[sum[n-1] - sum[i]] = 1;
		}
		
		poly2[sum[n-1]] = 1;
		
		vector<double> ans = poly1 * poly2;
		ll count = 0;
		for(ll i=sum[n-1]+1 ; i<ans.size() ; i++) {
			if(ans[i] > 0.000001)
			count++;
		}
		cout << count-1 << endl;
	}
	
}

#include<iostream>
#include<vector>
#include<set>
#include<complex>
#include<cstdlib>
#include<cstring>

using namespace std;
typedef long long ll;
#define PI 3.14159265358979323846

int rev(int i,int j)
{
	int res=0;
	while(j){
		res<<=1;
		if(i&1)
		res++;
		i>>=1;
		j--;
	}
	return res;
}

//------------ Fast Fourier Transformation-------------------------

vector<complex<double> > FFT (const vector<double> &poly ) {
	
	ll size = poly.size();
	vector<complex<double> > p(size);
	int bits=0;
	ll s = size;
	while(s) {
		bits++;
		s>>=1;
	}
	bits--;
	
	for(int k=0;k<size;k++) {
		p[rev(k,bits)]=complex<double>(poly[k]);
	}
	int pos=0;
	s = size;
	while(s) {
		pos++;
		s >>= 1;
	}
	pos--;
	for(int i=1 ; i<=pos ; i++) {
		ll m = 1 << i;
		complex<double> wn(cos((2*PI)/m), sin((2*PI)/m));		
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

vector<double> inverseFFT (const vector<complex<double> > &poly) {
	
	ll size = poly.size();
	vector<complex<double> > p(size);
	int bits=0;
	ll s = size;
	while(s) {
		bits++;
		s>>=1;
	}
	bits--;
	
	for(int k=0;k<size;k++) {
		p[rev(k,bits)]=poly[k];
	}
	int pos=0;
	s = size;
	while(s) {
		pos++;
		s >>= 1;
	}
	pos--;
	for(int i=1 ; i<=pos ; i++) {
		ll m = 1 << i;
		complex<double> wn(cos((-2*PI)/m), sin((-2*PI)/m));		
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
	vector<double> res(p.size());
	for(ll i=0 ; i<p.size() ; i++) {
		res[i] = (p[i].real())/size;
	}
	return res;
}


main() {
	int n;
	cin >> n;
	
	int arr[n];
	for(int i=0;i<n;i++) 
	cin >> arr[i];
	
	if(n==1) {
		cout << 0 << endl;
	}
				
	else if(n<2000) {
		
		
		set<ll> sums;
		for(int i=0;i<n;i++)
		{
			ll sum=0;
			for(int j=i;j<n;j++)
			{
				sum+=arr[j];
				sums.insert(sum);
			}
		}
		cout<<sums.size()-1<<endl;
	}
	else {
		
		ll sum[n];
		sum[0] = arr[0];
		for(int i=1;i<n;i++)
		sum[i] = sum[i-1] + arr[i];
		
		vector<double>  poly1,poly2;
		poly1.resize(sum[n-1]+1,0);
		poly2.resize(sum[n-1]+1,0);
		// creating polynomials        poly1[i] + poly2[j] - sum[n-1] = sum_subarray[j-i]   where j<i 
		for(int i=0;i<n;i++) {
			poly1[ sum[i] ] = 1;
			poly2[ sum[n-1] - sum[i] ] = 1;
		}
		
		//cout << poly1.size() << " ";
		poly2[sum[n-1]]=1;
		// find next power of 2 greater than size as resulting poly wil hace degreebound as sum of both poly's degreebound
		ll pos = 0;
		ll size = poly1.size();
		while(size) {
			pos++;
			size >>= 1;
		}
		pos++;
		size = 1<<(pos);
		
		poly1.resize(size,0);
		poly2.resize(size,0);
		//cout << poly1.size() << " ";
		vector<complex<double> > p1 = FFT(poly1);
		vector<complex<double> > p2 = FFT(poly2);
		
		//cout << p1.size() << " ";
		
		vector<complex<double> > mult(p1.size());
		
		for(int i=0;i<size;i++)
		mult[i] = p1[i] * p2[i];
		
		vector<double> ans = inverseFFT(mult);
		ll count = 0;
		for(ll i=sum[n-1]+1 ; i<ans.size() ; i++) {
			if(ans[i] > 0.000001)
			count++;
		}
		cout << count-1 << endl;
		
	}
}

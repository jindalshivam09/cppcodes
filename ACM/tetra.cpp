/*TETRA*/
#include<iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
 
int main() {
	int T;
	scanf("%d\n", &T);
	while (T--) {
		double u,U,v,V,w,W;
		double Volume;
		
		scanf("%lf %lf %lf %lf %lf %lf\n",&u,&v,&w,&W,&V,&U);
		//printf("%d %d %d %d %d %d\n",u,v,w,W,V,U);
		//printf("%lf %lf %lf %lf %lf %lf\n",u,v,w,W,V,U);
		
		Volume = 4*u*u*v*v*w*w;
		Volume -= u*u*pow(v*v+w*w-U*U,2);
		Volume -= v*v*pow(w*w+u*u-V*V,2);
		Volume -= w*w*pow(u*u+v*v-W*W,2);
		Volume += (v*v+w*w-U*U)*(w*w+u*u-V*V)*(u*u+v*v-W*W);
		Volume = sqrt(Volume);
		Volume /= 12;
		
		//printf ("volume : %lf\n", Volume);
		
		double s1 = (double) ((U + V + W) / 2);
		double s2 = (double) ((u + v + W) / 2);
		double s3 = (double) ((u + V + w) / 2);
		double s4 = (double) ((U + v + w) / 2);
		
		//printf("%lf %lf %lf %lf\n",s1,s2,s3,s4);
		
		double L1 = sqrt(s1*(s1-U)*(s1-V)*(s1-W));
		double L2 = sqrt(s2*(s2-u)*(s2-v)*(s2-W));
		double L3 = sqrt(s3*(s3-u)*(s3-V)*(s3-w));
		double L4 = sqrt(s4*(s4-U)*(s4-v)*(s4-w));
		
		//printf("%f %f %f %f\n",L1,L2,L3,L4);
		
		double R = (Volume*3)/(L1+L2+L3+L4);
		cout << Volume << " " << (L1+L2+L3+L4) << endl;
			
		printf ("%.4lf\n",R);
	}
	return 0;
}

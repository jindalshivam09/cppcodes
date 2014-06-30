#include<iostream>

using namespace std;

void swap(long &x,long &y) { long z =x; x=y; y=z; }

void max_heapify(long a[],int i,int n) { int l=2*i; int r=2*i+1; int largest;

if((l<=n)&& a[l]>a[i]) largest=l; else largest=i; if((r<=n) && a[largest]<a[r]) largest=r; if(largest!=i) { swap(a[largest],a[i]); //now mainting max heap property at the bottom heap of largest! max_heapify(a,largest,n); } }

void build_max_heap(long a[],int n) { int i; for(i=n/2;i>=1;i--) { max_heapify(a,i,n); } } void heap_sort(long a[],int n) { build_max_heap(a,n); int N=n; //printf("Swapping and replacing......\n"); for(int i=n;i>=2;i--) { swap(a[i],a[1]); n--;//excuding the last element from the heap cuz its the highest one in the available array max_heapify(a,1,n); } }

long a[100000];

int main() { int n,negs; long x,cost; cin>>n; for(int i=1;i<=n;i++) cin>>a[i]; cin>>x; heap_sort(a,n); negs=0; cost=0; a[0]=0; for(int i=1;i<=n;i++) { if(a[i]<0) negs++; else{ break; } } //if x lies within if(x <= negs) { cost = x*(-a[x]); for(int i=1;i<x;i++) { cost += (-a[i]+a[x]); } } else { for(int i=1;i<=negs;i++) { cost += (-a[i]); } } cout<<cost<<"\n"; }

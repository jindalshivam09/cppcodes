#include<iostream>
#include<vector>
#include<limits>
using namespace std;

#define MAX 100008
#define INFINITY  numeric_limits<int>::max()

vector<int> inferiors[MAX];		//store all the inferiors of a chef with index i
int			health[MAX],		//store the health of the chef
			array[MAX],			//make a array of chefs as acc to the dfs 
			beg[MAX],			//index of the first inferior of the chef
		 	last[MAX],			//index of the last inferior if the chef 
		 	alive_count[4*MAX],	//at each node of segment tree it store the total alive chefs which are desclastants of the node 
		 	min_health[4*MAX],	//it store the min_health of the chef who is the descendant of the node
		 	sickness[4*MAX];	//sickness value of all the inferiors of the node

int count;						// assign index to the chefs

// do dfs on the chefs to assign them numbers
void dfs (int superior) {

	array[count++] = superior;
	beg[superior] = count-1;
	
	int n = inferiors[superior].size();
	for(int i=0 ; i<n  ; i++) {
	
		dfs(inferiors[superior][i]);
	} 
	
	last[superior] = count-1;
}


// make a segment tree on the basis of the numbers assign to the chefs in dfs
void segment_tree (int superior , int left, int right ) {

	if (left == right) {
	
		min_health[superior] = health[array[left]];
		alive_count[superior] = 1;
		sickness[superior] = 0;
		return ;
	}
	
	int mid = (left+right)/2;
	
	segment_tree(superior*2,left,mid);
	segment_tree(superior*2+1,mid+1,right);
	
	alive_count[superior] = alive_count[superior*2] + alive_count[superior*2+1];
	sickness[superior] = 0;
	min_health[superior] = min( min_health[superior*2], min_health[superior*2+1] );
}

//to update the sickness value of the tree 
void update (int superior,int left,int right, int val, int ltree , int rtree) {

	if (ltree > right || rtree < left)
		return;
		
	if (left <= ltree && right >= rtree) {
	
		min_health[superior] -= val;
		sickness[superior] += val; 
		return;
	}
	
	if (sickness[superior]) {
	
		sickness[superior*2] += sickness[superior];
		sickness[superior*2+1] += sickness[superior];
		min_health[superior*2] -= sickness[superior];
		min_health[superior*2+1] -= sickness[superior];
		sickness[superior] = 0;
	}
 	
 	int mid = (ltree+rtree)/2;
 	update(superior*2,left,right,val,ltree,mid);
 	update(superior*2+1,left,right,val,mid+1,right);
 	
 	min_health[superior] = min( min_health[superior*2], min_health[superior*2+1] );
}

int query(int superior,int left, int right , int ltree, int rtree) {


//	cout << "processing queries\n";
//	cout << left << " " << right << " " << ltree << " " << rtree << lastl;
	
	if (ltree > right || rtree < left)
		return 0;
	
	if(ltree == rtree) {

		if(min_health[superior] > 0)
			return alive_count[superior];
		else {
	
			min_health[superior] = INFINITY;
			return alive_count[superior] = 0;	
		}
	}
	
	if (sickness[superior]) {
	
		sickness[superior*2] += sickness[superior];
		sickness[superior*2+1] += sickness[superior];
		min_health[superior*2] -= sickness[superior];
		min_health[superior*2+1] -= sickness[superior];
		sickness[superior] = 0;
	}	
		
	if (ltree >= left && rtree <= right) {
	
		if (min_health[superior] > 0)
			return alive_count[superior];
			
		else {
		
			int mid = (ltree+rtree)/2;
			query(superior*2,left,right,ltree,mid);
			query(superior*2+1,left,right,mid+1,rtree);

		 	min_health[superior] = min( min_health[superior*2], min_health[superior*2+1] );
			return alive_count[superior] = alive_count[superior*2] + alive_count[superior*2+1];	
		}
	}
	
	int mid = (ltree+rtree)/2;
	int lcount = query(superior*2,left,right,ltree,mid);
	int rcount = query(superior*2+1,left,right,mid+1,rtree);

 	min_health[superior] = min( min_health[superior*2], min_health[superior*2+1] );
	alive_count[superior] = alive_count[superior*2] + alive_count[superior*2+1];	
	
	return lcount+rcount;
}

int main() {

	int n;
	cin >> n;
	int a,b;
	
	for(int i=0 ; i<n ; i++) {
	
		cin >> a >> b;
		health[i+1] = a;
		inferiors[b].push_back(i+1);
	}
	// to assign numbers to the chefs in order of their superiors
	cout << count << endl;
	dfs(0);
	
	segment_tree(1,0,n);
	
	int q;
	cin >> q;
	while(q--) {
	
		int t;
		cin >> t;
		
		if(t==1) {
		
			int chef,val;
			cin >> chef >> val;
			update(1,beg[chef]+1,last[chef],val,0,n);
		}
		
		else {
		
			int chef;
			cin >> chef;
			cout << query(1,beg[chef]+1,last[chef],0,n) << endl;
		}
	}
}


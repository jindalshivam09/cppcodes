#include<bits/stdc++.h>
using namespace std;

class GCDLCMEasy {
	public :
		string possible(int n, vector<int> a, vector<int> b, vector<int> g, vector<int> l) {
			vector<int> arr(n) ;
			vector<pair<pair<int,int>,int> > pairs ;
			for(int i=0;i<a.size();i++) { 
					if(l[i] % g[i]) {
						return "Solution does not exist";
					}
					pairs.push_back( make_pair( make_pair(min(a[i],b[i]),max(a[i],b[i])), l[i]*g[i] )) ;
					pairs.push_back( make_pair( make_pair(max(a[i],b[i]),min(a[i],b[i])), l[i]*g[i] )) ;
			}
			sort(pairs.begin(),pairs.end()) ;
			bool flag = true ;
			for(int i=0;i<a.size()-1;i++) {
					if(pairs[i].first.first == pairs[i+1].first.first) {
						if(pairs[i].second % pairs[i+1].second && pairs[i+1].second % pairs[i].second) {
							flag = false ;
							break;
						}
						int index = lower_bound(pairs.begin(),pairs.end(),make_pair(make_pair(pairs[i].first.second,pairs[i+1].first.second),0)) - pairs.begin() ;
						if(index < a.size() && pairs[i].first.second == pairs[index].first.first && pairs[i+1].first.second == pairs[index].first.second) {
							int divide ;
							if(pairs[i].second > pairs[i+1].second) 
								divide = pairs[i].second / pairs[i+1].second ;
							else
								divide = pairs[i+1].second / pairs[i].second ;
							int y1 = divide*pairs[index].second ;
							int rooty1 = sqrt(y1);
							if(y1 == rooty1*rooty1) {
								if(pairs[index].second % rooty1 == 0) {
									arr[pairs[index].first.first] = rooty1, arr[pairs[index].first.second] = pairs[index].second/rooty1 ;
								}
								else {
									flag = false;
									break;
								}
							}
							else {
								flag = false;
								break;
							}
						}
					}
			}
			if(flag)
				return "Solution exists";
			else
				return "Solution does not exist" ;
		}
};

int main() {

}

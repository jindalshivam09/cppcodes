#include<bits/stdc++.h>
using namespace std;
#define MAX	1000000000
int n ;
typedef struct tree* ptrTree ;
struct tree {
	int val, ans, cnt, rval, lval, prior;
	ptrTree ltree, rtree;
	tree() {}
	tree(int val) {
		this->val = val;
		rval = lval = val;
		ans = cnt = 1;
		ltree = rtree = NULL ;
		prior = rand() % MAX + 1 ;
	}
};
ptrTree root ;

int getCnt(ptrTree t) {
	if(t==NULL)
		return 0;
	return t->cnt ;
}

int getAns(ptrTree t) {
	if(t==NULL)
		return 0;
	return t->ans ;
}

void updateCnt(ptrTree t) {
	if(t==NULL)
		return;
	t->cnt = getCnt(t->ltree) + getCnt(t->rtree) + 1 ;
	if(t->ltree)
		t->lval = t->ltree->lval ;
	else
		t->lval = t->val ;
	if(t->rtree)
		t->rval = t->rtree->rval ;
	else
		t->rval = t->val ;

	t->ans = getAns(t->ltree) + getAns(t->rtree) + 1;

	if(t->ltree && t->val == t->ltree->rval)
		t->ans -= 1;
	if(t->rtree && t->val == t->rtree->lval)	
		t->ans -= 1;
	return ;		
}

void split(ptrTree t, ptrTree &lchild, ptrTree &rchild, int key, int add=0) {
	if(t == NULL) {
		lchild = rchild = NULL ;
		return ;
	}
	int value = add + getCnt(t->ltree) ;
	if(key <= value) 
		split(t->ltree,lchild,t->ltree,key,add), rchild = t ;
	else
		split(t->rtree,t->rtree,rchild,key,value+1), lchild = t ;

	updateCnt(lchild) ;
	updateCnt(rchild) ;
}

void merge(ptrTree &t, ptrTree lchild, ptrTree rchild) {
//	updateCnt(lchild) ;
//	updateCnt(rchild) ;
	if(lchild == NULL || rchild == NULL) {
		t = lchild ? lchild : rchild ;
		return ;
	}
	if(lchild->prior > rchild->prior) 
		merge(lchild->rtree,lchild->rtree,rchild), t = lchild ;
	else
		merge(rchild->ltree,lchild,rchild->ltree), t = rchild ;

//	cout << "update" ;
	updateCnt(t) ; 
}

void insert(int val) {
	ptrTree node = new tree(val) ;
	merge(root,root,node) ;
}

void update(int a, int b) {
	ptrTree t1, t2, t3 ;
	split(root,t1,t2,b) ;
	split(t1,t1,t3,a-1) ;
	merge(root,t3,t1) ;
	merge(root,root,t2) ;
}

int retrieve(int a, int b) {
	ptrTree t1,t2,t3 ;
	split(root, t1, t2, b) ;
	split(t1,t1,t3,a-1) ;
//	cout << "splitted" ;
	int ans = getAns(t3) ;
	merge(root,t1,t3) ;
	merge(root,root,t2) ;
	return ans ;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		root = NULL;
		cin >> n ;
		int val ;
		for(int i=0;i<n;i++) {
			cin >> val;
			insert(val) ;
		}
//		cout << "intput taken\n" ;
		int q ;
		cin >> q ;

		while(q--) {
			int type,l,r ;
			cin >> type >> l >> r ;
			if(type == 1) {
				cout << retrieve(l,r) << endl;
			}
			else {
				update(l,r) ;
			}
		}
	}
}

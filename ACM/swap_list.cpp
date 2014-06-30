#include<cstdio>
#include<iostream>
using namespace std;

typedef struct n {
	int data;
	struct n *link;
} list;

list* create_list (int n) {
	int a;
	list *temp,*head = nullptr ,*pre;
	for (int i = 0 ; i < n ; i ++) {
		
		cin >> a ;
		temp = new list;
		temp -> data = a;
		temp -> link = NULL;
		if (!head) {
		
			pre = head = temp;
		}
		else {
		
			pre -> link = temp;
			pre = temp;
		}
	}
	
	return head;
}

void print_list(list *head) {

	list *temp = head;
	while(temp) {

		cout << temp -> data << " ";
		temp = temp->link;
	}
	cout << endl;
}

list* swap_list (list *node) {
	list *first = node , *second = node -> link , *pre = NULL,*temp;
	while (second && first ) {
		
		
		temp = second ;
		first -> link = temp -> link;
		second -> link = first ;
	
		if(!pre ) 		node = temp;
		else 			pre -> link = second;

		pre  = temp -> link;

		first = first -> link;
		
		if (first)		second = first -> link ;
		else 			second = nullptr ;
		
	}
	return node;
}

int main() {
	int n;
	cin >> n ;
	list *node = create_list(n);
	
	node  = swap_list(node); 
	print_list(node);
	
}

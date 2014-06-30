#include<iostream>
#include<cstdlib>
#define MAX 10
using namespace std;

typedef struct ds{
    int key;
    ds* link;
}list;

list* createList(int *arr,int n) {

    list *prev=NULL,*temp,*head= NULL;
    for(int i=0;i<n;i++) {
        temp = (list*)malloc(sizeof(list));
        if(!head) {
            temp->key = arr[i];
            temp->link = NULL;
            prev = head = temp;
        }
        else {
            temp->key = arr[i];
            temp->link = NULL;
            prev->link = temp;
            prev = temp;
        }
    }
    return head;
}

void printList(list *head) {

    list *temp;
    temp = head;
    while(temp) {
        cout << temp->key << " ";
        temp = temp->link;
    }
}

list* reverseList(list *head) {
    list *pre = NULL, *next = head->link , *temp = head;
    while(temp->link) {
     //   cout << "hi";
        //cout << temp->key << " "  << next->key << " ";
        //if(pre)
        //cout << pre->key << endl;
        temp->link = pre;
        pre = temp;
        temp = next;
        next = next->link;
    }
    temp->link = pre;
    head = temp;
}

main() {
    int n;
    cin >> n;
    int arr[MAX];
    for(int i=0;i<n;i++)
    cin >> arr[i];
    list *head = createList(arr,n);
    head = reverseList(head);
    printList(head);
}

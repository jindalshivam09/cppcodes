#ifndef __TREAP_H__
#define __TREAP_H__

typedef int KEY_TYPE;
typedef struct treap{
        KEY_TYPE key;
        int priority;
        struct treap* lchild;
        struct treap* rchild;
}treap;

treap* RR_Rotate(treap* k2);
treap* LL_Rotate(treap* k2);
int Randint();
int Randint(int a, int b);
treap* New_Node(KEY_TYPE key);
treap* Insert(KEY_TYPE key, treap* root);
void Delete_Recur(KEY_TYPE key, treap* &Root);
void Delete_Non_Recur(KEY_TYPE key, treap* &Root);
void InOrder(treap* root);

#endif

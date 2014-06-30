#include <iostream>
#include "treap.h"
#include <ctime>
#include <cstdio>
#include <bits/stdc++.h>

/* RR(Y rotates to the right):

        k2                   k1
       /  \                 /  \
      k1   Z     ==>       X   k2
     / \                      /  \
    X   Y                    Y    Z
*/
/*
 Return which the root pointer(at a higher level) should point to
 */
treap* RR_Rotate(treap* k2)
{
        treap* k1 = k2->lchild;
        k2->lchild = k1->rchild;
        k1->rchild = k2;
        return k1;
}

/* LL(Y rotates to the left):

        k2                       k1
       /  \                     /  \
      X    k1         ==>      k2   Z
          /  \                /  \
         Y    Z              X    Y
 */
treap* LL_Rotate(treap* k2)
{
        treap* k1 = k2->rchild;
        k2->rchild = k1->lchild;
        k1->lchild = k2;
        return k1;
}


/* remember to add: srand(time(NULL)); in main.cpp */
inline int Randint()
{
        return rand();
}

inline int Randint(int a, int b)
{
        return a + rand() % (b-a+1);
}

treap* New_Node(KEY_TYPE key)
{
        treap* p_node = (treap*)malloc(sizeof(treap));
        if(!p_node)
        {
                fprintf(stderr, "Out of memory!\n");
                exit(1);
        }
        p_node->key = key;
        /* Note: the range of priority is very important, actually */
        p_node->priority = Randint(0, 100);
        p_node->lchild = p_node->rchild = NULL;
        return p_node;
}


/* Recursive implementation of Insertion in treap */
treap* Insert(KEY_TYPE key, treap* root)
{
        treap* p_node = New_Node(key);
        if(!root)
                return (root = p_node);
        if(key <= root->key)
        {
                root->lchild = Insert(key, root->lchild);
                if(root->lchild->priority < root->priority)
                        root = RR_Rotate(root);
        }
        else
        {
                root->rchild = Insert(key, root->rchild);
                if(root->rchild->priority < root->priority)
                        root = LL_Rotate(root);
        }
        return root;
}

/* Recursive implementation of Delete() */
void Delete_Recur(KEY_TYPE key, treap* &root)
{
        if(!root)
        {
                printf("treap empty, delete failed!\n");
                return;
        }
        if(key < root->key)
                Delete_Recur(key, root->lchild);
        else if(key > root->key)
                Delete_Recur(key, root->rchild);
        else
        {
                if(!root->lchild || !root->rchild)
                {
                        treap* temp = root;
                        if(!root->lchild)
                                root = root->rchild;
                        else
                                root = root->lchild;
                        free(temp);
                }
                else
                {
                        if(root->lchild->priority < root->rchild->priority)
                        {
                                root = RR_Rotate(root);
                                Delete_Recur(key, root->rchild);
                        }
                        else
                        {
                                root = LL_Rotate(root);
                                Delete_Recur(key, root->lchild);
                        }
                }
        }
}

/* Non-recursive implementation of Delete() */
void Delete_Non_Recur(KEY_TYPE key, treap* &Root)
{
        treap* parent = NULL;
        treap* root = Root;
        if(!root)
        {
                printf("treap empty, delete failed!\n");
                return;
        }
        while(root)
        {
                if(key < root->key)
                {
                        parent = root;
                        root = root->lchild;
                }
                else if(key > root->key)
                {
                        parent = root;
                        root = root->rchild;
                }
                else // now root is the node we want to delete
                {
                        if(!root->lchild) // root's left child is empty
                        {
                                if(!parent)
                                        Root = root->rchild;
                                else
                                {
                                        if(parent->lchild == root)
                                                parent->lchild = root->rchild;
                                        else
                                                parent->rchild = root->rchild;
                                }
                        }
                        else if(!root->rchild) // root's left is non-empty, its right child is empty.
                        {
                                if(!parent)
                                        Root = root->lchild;
                                else
                                {
                                        if(parent->lchild == root)
                                                parent->lchild = root->lchild;
                                        else
                                                parent->rchild = root->lchild;
                                }
                        }
                        else /* root has two non-empty children, then using rotation to make it a 
                                        leaf node or a node with only one child. This is difference between
                                        BST delete and treap delete */
                        {
                                while(root->lchild && root->rchild)
                                {
                                        if(root->lchild->priority < root->rchild->priority)
                                        {
                                                if(!parent)
                                                {
                                                        Root = RR_Rotate(root);
                                                        parent = Root;
                                                }
                                                else
                                                {
                                                        if(parent->lchild == root)
                                                        {
                                                                parent->lchild = RR_Rotate(root);
                                                                parent = parent->lchild;
                                                        }
                                                        else
                                                        {
                                                                parent->rchild = RR_Rotate(root);
                                                                parent = parent->rchild;
                                                        }
                                                }
                                        }
                                        else
                                        {
                                                if(!parent)
                                                {
                                                        Root = LL_Rotate(root);
                                                        parent = Root;
                                                }
                                                else
                                                {
                                                        if(parent->lchild == root)
                                                        {
                                                                parent->lchild = LL_Rotate(root);
                                                                parent = parent->lchild;
                                                        }
                                                        else
                                                        {
                                                                parent->rchild = LL_Rotate(root);
                                                                parent = parent->rchild;
                                                        }
                                                }
                                        }
                                }
                                if(!root->lchild)
                                {
                                        if(parent->lchild == root)
                                                parent->lchild = root->rchild;
                                        else
                                                parent->rchild = root->rchild;
                                }
                                else // root->rchild == NULL
                                {
                                        if(parent->lchild == root)
                                                parent->lchild = root->lchild;
                                        else
                                                parent->rchild = root->lchild;
                                }
                        }
                        free(root);
                        return;
                }
        }
        printf("key doesn't exist, delete failed!\n");
}


void InOrder(treap* root)
{
        if(root)
        {
                InOrder(root->lchild);
                printf("key: %d | priority: %d ", root->key, root->priority);
                if(root->lchild)
                        printf(" | left child: %d ", root->lchild->key);
                if(root->rchild)
                        printf(" | right child: %d ", root->rchild->key);
                printf("\n");
                InOrder(root->rchild);
        }
}

int main(int argc, char* argv[])
{
        srand(time(NULL));
        treap* root = NULL;
//        int vector[] = {15,6,18,3,7,17,20,2,4,13,9};
//        const int length = sizeof(vector)/sizeof(int);
        for(int i = 0; i< 10;i++)
                root = Insert(i, root);
        
        printf("\nInOrder: \n");
        InOrder(root);

        int input;
        printf("\nplease input the value you want to delete: ");
        scanf("%d",&input);
        
        while(1)
        {
                Delete_Non_Recur(input, root);
                printf("\nAfter delete %u:\n",input);
                InOrder(root);
                printf("\nplease input another value you want to delete: ");
                scanf("%u",&input);
        }
        printf("\n");
        return 0;
}

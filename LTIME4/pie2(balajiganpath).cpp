//Coder: Balajiganapathi
#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

class Trie {
    public:
    int count;
    Trie *child[2];

    Trie() {
        child[0] = child[1] = NULL;
        count = 0;
    }

    void insert(int num, int bit) {
        ++count;
        if(bit < 0) return;
        int b = ((num & (1 << bit))? 1: 0);

        if(child[b] == NULL) child[b] = new Trie();
        child[b]->insert(num, bit - 1);
    }

    void remove(int num, int bit) {
        --count;
        if(bit < 0) return;
        int b = ((num & (1 << bit))? 1: 0);

        child[b]->remove(num, bit - 1);
    }

    int search(int num, int bit) {
        if(bit < 0) return 0;
        int b = ((num & (1 << bit))? 1: 0);
        if(child[1 - b] != NULL && child[1 - b]->count > 0) return ((1 << bit) | child[1 - b]->search(num, bit - 1));
        else return child[b]->search(num, bit - 1);
    }

    ~Trie() {
        for(int b = 0; b < 2; ++b) 
            if(child[b] != NULL)
                delete child[b];
    }
} * root;

int n;

int num[10004];
void brute() {
    int ans = 0;

    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            for(int k = j + 1; k < n; ++k)
                ans = max(ans, num[i] ^ num[j] ^ num[k]);

    printf("%d\n", ans);
}

void use_tries() {
    root = new Trie();
    int ans = 0;
    for(int i = 0; i < n; ++i) 
        root->insert(num[i], 30);
    
    for(int i = 0; i < n; ++i) {
        root->remove(num[i], 30);
        for(int j = i + 1; j < n - 1; ++j) {
            root->remove(num[j], 30);
            ans = max(ans, root->search(num[i] ^ num[j], 30));
            root->insert(num[j], 30);
        }
        //root->insert(num[i], 30); // Not needed!
    }

    printf("%d\n", ans);
    delete root;
} 

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", num + i);

        if(n <= 200) brute();
        else use_tries();
    }

	return 0;
}


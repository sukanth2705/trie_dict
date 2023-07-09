typedef struct  node1{
    char label;
    int  marker;
    struct node1* first_child;
    struct node1* next_sibling;
}trienode;
typedef struct node2{
    trienode*arr;
}trie;
trie trieinit();
int  triesearch(trie,char *);
void trieinsert(trie,char *);
void listall(trie);
trienode* create_node(char,int);

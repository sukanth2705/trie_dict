#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<trie.h>
trie trieinit(){
    trie t;
    trienode* n=(trienode*)malloc(sizeof(trienode));
    n->first_child=NULL;
    n->next_sibling=NULL;
    t.arr=n;
    return t;
}
trienode* create_node(char c,int m){
    trienode* t=(trienode*)malloc(sizeof(trienode));
    t->label=c;
    t->marker=m;
    t->first_child=NULL;
    t->next_sibling=NULL;
    return t;
}
int triesearch(trie t,char*str){
    int len=strlen(str);
    int index=0;
    trienode* n=t.arr->first_child;
    while(index<len){
        if(n==NULL){
            return 0;
        }
        if(n->label-'a'<str[index]-'a'){
            n=n->next_sibling;
        }
        else if(n->label-'a'==str[index]-'a'){
            if(index!=len-1){
                n=n->first_child;
            }
            index++;
        }
        else{
            return 0;
        }
    }
    return n->marker;
}
void trieinsert(trie t,char * str){
    int len=strlen(str);
    int index=0;
    trienode* prev=t.arr;
    trienode*n=t.arr->first_child;
    if(n==NULL){
        t.arr->first_child=create_node(str[0],0);
        n=t.arr->first_child;
    }
    int s=0;
    while(index<len){
        if(n==NULL){
            if(s==1){
                prev->next_sibling=create_node(str[index],0);
                n=prev->next_sibling;
            }
            else if(s==0){
                prev->first_child=create_node(str[index],0);
                n=prev->first_child;
            }
        }
        else if(n->label-'a'<str[index]-'a'){
            prev=n;
            n=n->next_sibling;
            s=1;
        }
        else if(n->label-'a'==str[index]-'a'){
            index++;
            prev=n;
            n=n->first_child;
            s=0;
        }
        else{
            if(prev->first_child==n){
                prev->first_child=create_node(str[index],0);
                prev->first_child->next_sibling=n;
                n=prev->first_child;
                s=0;
            }
            else{
                prev->next_sibling=create_node(str[index],0);
                prev->next_sibling->next_sibling=n;
                n=prev->next_sibling;
                s=1;
            }
        }
    }
    prev->marker=1;
    return ;
}
char *copy(char s[]){
    char *s2, *p1, *p2;
    s2 = (char *)malloc(50 * sizeof(char));
    p1 = s;
    p2 = s2;
    while (*p1 != '\0'){
       *p2 = *p1;
        p1++;
        p2++;
    }
    *p2 = '\0';
    return s2;
}
void r(trienode *node, char *due_str){
    if (node->marker==1){
        printf("%s\n", due_str);
    }
    if (node->first_child==NULL){
        return ;
    }
    trienode *iter = node->first_child;
    while (iter){
        char *new_due_str=copy(due_str);
        new_due_str[strlen(new_due_str)]='\0';
        new_due_str[strlen(new_due_str) + 1] = '\0';
        new_due_str[strlen(new_due_str)] = iter->label;
        r(iter, new_due_str);
        iter=iter->next_sibling;
        free(new_due_str);
    }
}
void listall(trie t){
    trienode *node = t.arr;
    char s[] = {'\0'};
    r(node, s);
    return;
}

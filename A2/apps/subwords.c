#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<trie.h>
#include<dicttype.h>
#include<dictload.h>
#include<dictutils.h>
int com(const void* a, const void* b){
    return (*(char*)a - *(char*)b);
}
int main(){
    dict d=loaddfltdict();
    char str[100001];
    printf("Enter string:");
    scanf("%s",str);
    int len=strlen(str);
    qsort(str,len,sizeof(str[0]),com);
    char prev=str[0];
    int size=0;
    int*distinct=NULL;
    for(int i=1;i<len;i++){
        if(str[i]!=prev){
            size++;
            if(distinct==NULL){
                distinct=(int*)malloc(sizeof(int));
                distinct[size-1]=i-1;
            }
            else{
                distinct=realloc(distinct,size*sizeof(int));
                distinct[size-1]=i-1;
            }
            prev=str[i];
        }
    }
    size++;
    if(distinct==NULL){
        distinct=(int*)malloc(sizeof(int));
    }
    else{
        distinct=realloc(distinct,size*sizeof(int));
    }
    distinct[size-1]=len-1;
    printf("Subwords are:\n");
    int cnt=0;
    for(int i=0;i<size;i++){
        char temp[len];
        temp[len-1]='\0';
        int index=0;
        for(int j=0;j<len;j++){
            if(j!=distinct[i]){
                temp[index]=str[j];
                index++;
            }
        }
        if(strcmp(temp,"")!=0){
            char**anagram=anagrams(d,temp);
            index=0;
            while(anagram[index]!=NULL){
                printf("%s\n",anagram[index]);
                index++;
            }
            if(index==0){
                cnt++;
            }
            free(anagram);
        }
        else{
            cnt++;
        }
    }
    if(size==cnt){
        printf("0 words found\n");
    }
    free(distinct);
    return 0;
}
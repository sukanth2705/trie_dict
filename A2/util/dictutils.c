#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<trie.h>
#include<dicttype.h>
#include<dictutils.h>
char* addbefore(dict d,char*str){
    char*ans=NULL;
    int len=0;
    int str_len=strlen(str);
    char*buff=(char*)malloc((str_len+2)*sizeof(char));
    for(int i=1;i<str_len+2;i++){
        buff[i]=str[i-1];
    }
    for(int i=0;i<26;i++){
        char c=('a'+i);
        buff[0]=c;
        if(triesearch(d,buff)==1){
            if(ans==NULL){
                len++;
                ans=(char*)malloc(sizeof(char));
                ans[len-1]=c;
            }
            else{
                len++;
                ans=realloc(ans,len*sizeof(char));
                ans[len-1]=c;
            }
        }
    }
    len++;
    if(ans==NULL){
        ans=(char*)malloc(sizeof(char));
    }
    else{
        ans=realloc(ans,len*sizeof(char));
    }
    ans[len-1]='\0';
    return ans;
}
char* addafter(dict d,char*str){
    char*ans=NULL;
    int len=0;
    int str_len=strlen(str);
    char*buff=(char*)malloc((str_len+2)*sizeof(char));
    buff[str_len+1]='\0';
    for(int i=0;i<str_len;i++){
        buff[i]=str[i];
    }
    for(int i=0;i<26;i++){
        char c=('a'+i);
        buff[str_len]=c;
        if(triesearch(d,buff)==1){
            if(ans==NULL){
                len++;
                ans=(char*)malloc(sizeof(char));
                ans[len-1]=c;
            }
            else{
                len++;
                ans=realloc(ans,len*sizeof(char));
                ans[len-1]=c;
            }
        }
    }
    len++;
    if(ans==NULL){
        ans=(char*)malloc(sizeof(char));
    }
    else{
        ans=realloc(ans,len*sizeof(char));
    }
    ans[len-1]='\0';
    return ans;
}
int compare(const void* a, const void* b){
    return (*(char*)a - *(char*)b);
}

void swap(char* a,char* b){
    char t=*a;
    *a=*b;
    *b=t;
}
int c(char *str,char first,int l,int h){
    int index=l;
    for (int i=l+1;i<=h;i++){
        if (str[i]>first&&str[i]<str[index]){
            index=i;
        }
    }
    return index;
}
char** anagrams(dict d,char* str){
    int len=strlen(str);
    int ans_len=1;
    char**ans=(char**)malloc(sizeof(char*));
    ans[0]=NULL;
    qsort(str,len,sizeof(str[0]),compare);
    int s=0;
    while(!s){
        if(triesearch(d,str)==1){
            ans_len++;
            ans=realloc(ans,ans_len*sizeof(char*));
            char*temp=(char*)malloc((len+1)*sizeof(str));
            strcpy(temp,str);
            ans[ans_len-1]=temp;
        }
        int i;
        for(i=len-2;i>=0;i--){
            if(str[i]<str[i+1]){
                break;
            }
        }
        if(i==-1){
            s=1;
        }
        else{
            int index=c(str,str[i],i+1,len-1);
            swap(&str[i],&str[index]);
            qsort(str+i+1,len-i-1,sizeof(str[0]),compare);
        }
    }
    ans[0]=ans[ans_len-1];
    ans[ans_len-1]=NULL;
    return ans;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<trie.h>
#include<dicttype.h>
#include<dictload.h>
#include<dictutils.h>
typedef struct node{
    int l;
    char *choice;
}new;
new recur(dict d,char* str){
    int len=strlen(str);
    char *a=addafter(d,str);
    char *b=addbefore(d,str);
    new n;
    new c;
    n.choice=(char*)malloc(3*sizeof(char));
    n.choice[2]='\0';
    if(strcmp(a,"")==0&&strcmp(b,"")==0){
        n.l=0;
        n.choice[0]='x';
        n.choice[1]='y';
        return n;
    }
    int max=0;
    int curr=0;
    char *temp=NULL;
    if(strcmp(a,"")!=0){
        temp=(char*)malloc((len+2)*sizeof(char));
        strcpy(temp,str);
        temp[len+1]='\0';
        for(int i=0;i<strlen(a);i++){
            temp[len]=a[i];
            c=recur(d,temp);
            curr=1+c.l;
            if(curr>max){
                n.l=curr;
                n.choice[1]='1';
                n.choice[0]=a[i];
                max=curr;
            }
            free(c.choice);
        }
    }
    free(temp);
    temp=NULL;
    if(strcmp(b,"")!=0){
        temp=(char*)malloc((len+2)*sizeof(char));
        strcpy(temp+1,str);
        for(int i=0;i<strlen(b);i++){
            temp[0]=b[i];
            c=recur(d,temp);
            curr=1+c.l;
            if(curr>max){
                n.l=curr;
                n.choice[1]='2';
                n.choice[0]=b[i];
                max=curr;
            }
            free(c.choice);
        }
    }
    free(temp);
    return n;
}
void print(dict d,char*str){
    printf("==>%s\n",str);
    int len=strlen(str);
    new temp=recur(d,str);
    if(temp.l==0){
        return ;
    }
    char*buff=(char*)malloc((len+2)*sizeof(char));
    if(temp.choice[1]=='1'){
        strcpy(buff,str);
        buff[len+1]='\0';
        buff[len]=temp.choice[0];
        print(d,buff);
    }
    else{
        strcpy(buff+1,str);
        buff[0]=temp.choice[0];
        print(d,buff);
    }
    free(buff);
    free(temp.choice);
}
int main(){
    dict d=loaddfltdict();
    char str[100001];
    printf("Enter string:");
    scanf("%s",str);
    if(triesearch(d,str)==0){
        printf("No maxchain.\n");
        return 0;
    }
    print(d,str);
    return 0;
}
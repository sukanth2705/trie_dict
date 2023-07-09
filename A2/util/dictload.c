#include<stdio.h>
#include<stdlib.h>
#include<trie.h>
#include<dicttype.h>
#include<dictload.h>
dict loaddfltdict(){
    dict d=trieinit();
    FILE* ptr=fopen("../dict/DFLT_DICT.txt","r");
    char *str=NULL;
    int len=0;
    char c;
    c=getc(ptr);
    while(c!=EOF){
        if(c!='\n'&&c!='\r'){
            len++;
            if(str==NULL){
                str=(char*)malloc(sizeof(char));
                str[len-1]=c;
            }
            else{
                str=realloc(str,len*sizeof(char));
                str[len-1]=c;
            }
        }
        else{
            if(str!=NULL){
                len++;
                str=realloc(str,len*sizeof(char));
                str[len-1]='\0';
                trieinsert(d,str);
                free(str);
            }
            str=NULL;
            len=0;
        }
        c=getc(ptr);
    }
    if(str!=NULL){
        len++;
        str=realloc(str,len*sizeof(char));
        str[len-1]='\0';
        trieinsert(d,str);
        free(str);
        str=NULL;
    }
    fclose(ptr);
    return d;
}
dict loaddict(char*fname){
    dict d=trieinit();
    FILE* ptr=fopen(fname,"r");
    char *str=NULL;
    int len=0;
    char c;
    c=getc(ptr);
    while(c!=EOF){
        if(c!='\n'&&c!='\r'){
            len++;
            if(str==NULL){
                str=(char*)malloc(sizeof(char));
                str[len-1]=c;
            }
            else{
                str=realloc(str,len*sizeof(char));
                str[len-1]=c;
            }
        }
        else{
            if(str!=NULL){
                len++;
                str=realloc(str,len*sizeof(char));
                str[len-1]='\0';
                trieinsert(d,str);
                free(str);
            }
            str=NULL;
            len=0;
        }
        c=getc(ptr);
    }
    if(str!=NULL){
        len++;
        str=realloc(str,len*sizeof(char));
        str[len-1]='\0';
        trieinsert(d,str);
        free(str);
        str=NULL;
    }
    fclose(ptr);
    return d;
}
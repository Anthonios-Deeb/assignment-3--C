#include <stdio.h>
#include "StrList.h"
#include <stdlib.h>
#include <string.h>
#define INITIAL_SIZE 10;

typedef struct _Node{
  char * str;
  struct _Node * next;
}node;

struct _StrList{
  node * head;
  node * tail;
};

node* Node_alloc(const char *str, node* next) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }
    
    new_node->str = (char*)malloc(strlen(str) + 1);
    if (new_node->str == NULL) {
        free(new_node);
        return NULL;
    }

    strcpy(new_node->str, str);
    
    new_node->next = next;
    
    return new_node;
}


StrList* StrList_alloc(){
  StrList * list= malloc(sizeof(StrList));
  list->head=NULL;
  list->tail=NULL;
  return list;
}

void StrList_free(StrList *StrList){
  if(StrList==NULL){
    return;
  }

  while(StrList->head!=NULL){
    node * temp=StrList->head;
    free(temp->str);
    StrList->head=temp->next;
    free(temp);
  }
  free(StrList);
}

size_t StrList_size(const StrList* StrList){
  if(StrList==NULL){
    return 0;
  }

  int size =0;
  node * temp=StrList->head;
  while(temp!=NULL){
    temp=temp->next;
    size++;
  }

  return size;
}

void StrList_insertLast(StrList* StrList,const char* data){
  if(StrList==NULL){
    return;
  }
  node *new_node=Node_alloc(data,NULL);
 
  if(StrList->head==NULL && StrList->tail==NULL){
    StrList->head=new_node;
    StrList->tail=new_node;
  }else {
    StrList->tail->next=new_node;
    StrList->tail=StrList->tail->next;
  }
}

void StrList_insertAt(StrList* strList,const char* data,int index){
  if(strList==NULL||index<0){
    return;
  }
  
  int count=0;
  node * temp=strList->head;      
  while(count!=index-1&&temp!=NULL){ 
    temp=temp->next;
    count++;
  }

  if(count!=index-1&&temp!=NULL)
    return;

  if(temp==NULL&&count==index-1){
    StrList_insertLast(strList,data);
    return;
  }

  node *new_node = Node_alloc(data,temp->next);
  temp->next=new_node;
}


char* StrList_firstData(const StrList* strList){
  if(strList==NULL){
    return " ";
  }
  return strList->head->str;
}


void StrList_print(const StrList* strList){
  if(strList==NULL){
    return;
  }

  node * temp=strList->head;
  while(temp!=NULL){
    printf("%s",temp->str);
    
    temp=temp->next;
    if(temp!=NULL){
      printf(" ");
    }

  }
}

void StrList_printAt(const StrList* strlist,int index){
  if(strlist==NULL){
    return;
  }

  int count=0;
  node * temp=strlist->head;
  while(count!=index&&temp!=NULL){
    temp=temp->next;
    count++;
  }

  if(count!=index||temp==NULL)
    return;

  printf("%s",temp->str);
}

int StrList_printLen(const StrList* strList){
  if(strList==NULL){
    return 0;
  }

  int amount=0;
  node * temp=strList->head;
  
  while(temp!=NULL){
    amount=amount+strlen(temp->str);
    temp=temp->next;
  }

  return amount;
}

int StrList_count(StrList* strList, const char* data){
  if(strList==NULL){
    return 0;
  }

  node * temp=strList->head;
  int amount=0;
  
  while(temp!=NULL){
    if(strcmp(temp->str,data)==0){
      amount++;
    }
    temp=temp->next;
  }

  return amount;
}

void StrList_remove(StrList* strList, const char* data){
  if(strList==NULL){
    return;
  }

  if(StrList_size(strList)==1&&strcmp(strList->head->str,data)==0){
    node * d=strList->head;
    free(d->str);
    free(d);
    strList->head=NULL;
    strList->tail=NULL;
    return;
  }

  if(strcmp(strList->head->str,data)==0){
    node * d=strList->head;
    strList->head=strList->head->next;
    free(d->str);
    free(d);
  }
  
  int index=1;
  node * temp=strList->head;
  while(temp->next!=NULL){
    if(strcmp(temp->next->str,data)==0){
      if(index+1==StrList_size(strList)){
        strList->tail=temp;
        node * d=temp->next;
        temp->next=NULL;
        free(d->str);
        free(d);
        return;
      }
      node * d=temp->next;
      temp->next=temp->next->next;
      free(d->str);
      free(d);
    }
    index++;
    temp=temp->next;
  }
}

void StrList_removeAt(StrList* strList, int index){
  if(strList==NULL){
    return;
  }

  if(index>StrList_size(strList)){
    return;
  }

  if(index==0){
    if(StrList_size(strList)==1){
      node * d=strList->head;
      free(d->str);
      free(d);
      strList->head=NULL;
      strList->tail=NULL;
      return;
    }

    node * d=strList->head;
    strList->head=d->next;
    free(d->str);
    free(d);
    return;
  }

  int count=0;
  node * temp=strList->head;
  while(count!=index-1&&temp!=NULL){ 
    temp=temp->next;
    count++;
  }

  if(count!=index-1&&temp!=NULL){
    return;
  }

  if(count+2==StrList_size(strList)){
    strList->tail=temp;
  }

  node * d=temp->next;
  temp->next=temp->next->next;
  free(d->str);
  free(d);
}

int StrList_isEqual(const StrList* strList1, const StrList* strList2){
  if(strList1==NULL&&strList2==NULL){
    return 1;
  }else if(strList1==NULL){
    return 0;
  }else if(strList2==NULL){
    return 0;
  }
  
  node * temp1=strList1->head;
  node * temp2=strList2->head;

  while (temp1!=NULL&&temp2!=NULL){
    if(strcmp(temp1->str,temp2->str)==0){
      return 0;
    }
    temp1=temp1->next;
    temp2=temp2->next;
  }

  return temp1==NULL&&temp2==NULL;
}

StrList* StrList_clone(const StrList* strList){
  if(strList==NULL){
    return NULL;
  }

  StrList * new_list= malloc(sizeof(StrList));
  new_list->head=NULL;

  node * clone_temp=new_list->head;
  node * temp=strList->head;

  while (temp!=NULL){
    clone_temp=Node_alloc(temp->str,temp->next);
    if(temp->next==NULL){
      new_list->tail=clone_temp;
    }
    temp=temp->next;
    clone_temp=clone_temp->next;
  }
  return new_list;
}

void StrList_reverse(StrList* strlist){
  if(strlist==NULL){
    return;
  }

  if(StrList_size(strlist)==1){
    return;
  }

  node * head=strlist->head;
  node * tail=strlist->tail;

  node * start=head;
  node * end=tail;

  while(strcmp(start->str,end->str)!=0&&start->next!=NULL){
    while (strcmp(start->next->str,end->str)!=0){
      start=start->next;
    }

    end->next=start;
    end=end->next;
    start=head;
  }

  head->next=NULL;
  node * temp=head;
  strlist->head=strlist->tail;
  strlist->tail=temp;
}

void findMinAndset(StrList* strlist,node* start){
  node * min=start;
  node * temp=start->next;
  
  while(temp!=NULL){
    if(strcmp(temp->str,min->str)<0){
      min=temp;
    }
    temp=temp->next;
  }

  char * t=start->str;
  start->str=min->str;
  min->str=t;
}

void StrList_sort(StrList* strlist){
  if(strlist==NULL){
    return;
  }

  node * start=strlist->head;

  while (start!=NULL){
    findMinAndset(strlist,start);
    start=start->next;
  }

}

int StrList_isSorted(StrList* strlist){
  if(strlist==NULL){
    return 0;
  }
  node * temp=strlist->head;
  while(temp->next!=NULL){
    if(strcmp(temp->str,temp->next->str)>0){
      return 0;
    }
    temp=temp->next;
  }
  return 1;
}
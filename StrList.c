#include "StrList.h"
#include <stdlib.h>
#include <string.h>
#define INITIAL_SIZE 10;

typedef struct{
  char * str;
  node next;
}* node;

struct _StrList{
  node head;
  node tail;
};

StrList* StrList_alloc(){
  StrList * list= malloc(sizeof(StrList));
  list->head=NULL;
  list->tail=NULL;
  return list;
}

void StrList_free(StrList* StrList){
  while(StrList->head!=NULL){
    node temp=StrList->head;
    StrList->head=temp->next;
    free(temp);
  }
  free(StrList);
}

size_t StrList_size(const StrList* StrList){
  int size =0;
  node temp=StrList->head;
  while(temp!=NULL){
    temp=StrList->head;
    size++;
  }
  return size;
}

void StrList_insertLast(StrList* StrList,const char* data){
  if(StrList->head==NULL||StrList->tail==NULL){
    StrList->head=malloc(sizeof(node));
    StrList->head->str=data;
    StrList->head->next=NULL;
    StrList->tail=StrList->head; 
  }else {
    StrList->tail->next=malloc(sizeof(node));
    StrList->tail->next->str=data;
    StrList->tail->next->next=NULL;
    StrList->tail=StrList->tail->next;
  }
}

void StrList_insertAt(StrList* strList,const char* data,int index){
  int count=0;
  node temp=strList->head;
  while(count!=index-1&&temp!=NULL){
    temp=temp->next;
    count++;
  }

  if(count!=index-1)
    return;

  if(temp==NULL){
    StrList_insertLast(strList,data);
    return;
  }

  node temp_next=temp->next;
  temp->next=malloc(sizeof(node));
  temp->next->str=data;
  temp->next->next=temp_next;
}


char* StrList_firstData(const StrList* strList){
  return strList->head->str;
}


void StrList_print(const StrList* strList){
  node temp=strList->head;
  while(temp!=NULL){
    printf('%s',temp->str);
    printf(' ');
    temp=temp->next;
  }
}

void StrList_printAt(const StrList* strlist,int index){
  int count=0;
  node temp=strlist->head;
  while(count!=index&&temp!=NULL){
    temp=temp->next;
    count++;
  }

  if(count!=index || temp==NULL)
    return;

  printf('%s',temp->str);
}

int StrList_printLen(const StrList* strList){
  int amount=0;
  node temp=strList->head;
  
  while(temp!=NULL){
    amount=amount+strlen(temp->str)+1;
    temp=temp->next;
  }

  return amount;
}

int StrList_count(StrList* strList, const char* data){
  node temp=strList->head;
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
  int index=0;
  node temp=strList->head;
  while(temp!=NULL){
    if(strcmp(temp->str,data)==0){
      temp->next=temp->next->next;
      free(temp->next);
    }
  }
}

void StrList_removeAt(StrList* strList, int index){
  int count=0;
  node temp=strList->head;
  while(count!=index-1&&temp!=NULL){
    temp=temp->next;
    count++;
  }

  if(count!=index-1||temp!=NULL){
    return;
  }
  temp->next=temp->next->next;
  free(temp->next);
}

int StrList_isEqual(const StrList* strList1, const StrList* strList2){
  node temp1=strList1->head;
  node temp2=strList2->head;

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
  StrList * new_list= malloc(sizeof(StrList));
  new_list->head=NULL;

  node clone_temp=new_list->head;
  node temp=strList->head;

  while (temp!=NULL){
    clone_temp->str = temp->str;
    if(temp->next==NULL){
      new_list->tail=clone_temp;
    }
    temp=temp->next;
    clone_temp=clone_temp->next;
  }
  StrList_free(strList);
  return new_list;
}

void StrList_reverse(StrList* strlist){
  node head=strlist->head;
  node tail=strlist->tail;

  node start=head;
  node end=tail;

  while(strcmp(start->str,end->str)!=0||start->next->next!=NULL){
    while (strcm(start->next->str,end->str)!=0||start->next->next!=NULL){
      start=start->next;
    }
    end->next=start;
    end=end->next;
    start->next=NULL;
    node start=head;
  }
  node temp=head;
  strlist->head=strlist->tail;
  strlist->tail=temp;
}

void findMinAndset(StrList* strlist,node start){
  node min=start;
  node temp=start->next;
  
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
  node start=strlist->head;

  while (start!=NULL){
    findMinAndset(strlist,start);
    start=start->next;
  }
}

int StrList_isSorted(StrList* strlist){
  node temp=strlist;
  while(temp->next!=NULL){
    if(strcmp(temp->str,temp->next->str)!=-1){
      return 0;
    }
    temp=temp->next;
  }
  return 1;
}
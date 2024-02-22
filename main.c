#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"

int main(){
  StrList * strlist=StrList_alloc();
  int count,i;
  char str[100];
  while(1){
    int x=0;
    scanf("%d",&x);
    switch (x){
    case 0:
      return 0;
    break;

    case 1:

      scanf("%d", &count);
      for(int i=0;i < count;i++){
        scanf("%s",str);
        StrList_insertLast(strlist,str);
      }

    break;
    
    case 2:
      scanf("%d",&i);
      scanf("%s",str);
      StrList_insertAt(strlist,str,i);
    break;

    case 3:
      StrList_print(strlist);
      printf("\n");
    break;

    case 4:
      printf("%zu",StrList_size(strlist));
      printf("\n");
    break;

    case 5:
      scanf("%d",&i);
      StrList_printAt(strlist,i);
      printf("\n");
    break;

    case 6:
       printf("%d",StrList_printLen(strlist));
       printf("\n");
    break;
     
    case 7:
      scanf("%s",str);
      printf("%d",StrList_count(strlist,str));
      printf("\n");
    break;

    case 8:
      scanf("%s",str);
      StrList_remove(strlist,str);
    break;

    case 9:
      scanf("%d",&i);
      StrList_removeAt(strlist,i);
    break;

    case 10:
      StrList_reverse(strlist);
    break;

    case 11:
      StrList_free(strlist);
    break;

    case 12:
      StrList_sort(strlist);
    break;

    case 13:
      if(StrList_isSorted(strlist)==1){
        printf("true");
      }else{
        printf("false");
      }
      printf("\n");
    break;

    default:
      break;
    }
  }
}
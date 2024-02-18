#include <stdio.h>
#include "StrList.h"

int main(){
  StrList * strlist=StrList_alloc();

  while(1){
    int x;
    scanf("%d",&x);
    switch (x){
    case 0:
      return 0;
    break;

    case 1:
      int i;
      char * str;
      scanf("%d",&i);
      for(int j=0;j<i;j++){
        scanf("%s",&str);
        StrList_insertLast(strlist,str);
      }
    break;
    
    case 2:
      int i;
      char * str;
      scanf("%s",&str);
      scanf("%d",&i);
      StrList_insertAt(strlist,str,i);
    break;

    case 3:
    StrList_print(strlist);
    break;

    case 4:
      printf(StrList_size(strlist));
    break;

    case 5:
      int i;
      scanf("%d",&i);
      StrList_printAt(strlist,i);
    break;

    case 6:
       printf(StrList_printLen(strlist));
    break;
     
    case 7:
      char * str;
      scanf("%s",&str);
      printf(StrList_count(strlist,str));
    break;

    case 8:
      char * str;
      scanf("%s",&str);
      StrList_remove(strlist,str);
    break;

    case 9:
      int i;
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
      StrList_isSorted(strlist);
    break;

    default:
      break;
    }
  }


}
// array.c
// cstl array 테스트 코드

#include <stdio.h>
#include "../include/array.h"

decl_array(myarr, int, 5);

int main() {

  myarr arr = make_myarr();
  int i;
    
  for (i = 0; i < arr.get_length(&arr); i++)
    arr.data[i] = i + 1;
  
  myarr_iterator iter; 
  myarr_iterator iter_end = myarr_end(&arr);
  
  for (iter = myarr_begin(&arr); myarr_iterator_equals(&iter, &iter_end) == 0; myarr_iterator_next(&iter))  
  {
    printf("%d\n", iter.get(&iter));
  }
  
}


#include "stringUtil.h"


int stringRangeCmp(char* str_one, char* str_two, int str_one_start_index, int cmp_size){
    
    for(int i = str_one_start_index, j = 0 ;  j < cmp_size ; i++, j++){
        if(str_one[i] != str_two[j]){ //mismatch
            return 0;
        }
    }

    //string match
    return 1;
}
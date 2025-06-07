#include "hamming.h"
#include <stdio.h>
#include <string.h>

int hamming(const char* str1, const char* str2){
    
    int distancia = 0;
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    if(len1 != len2){
        return -1;
    }
    
    for(size_t i = 0; i < len1; i++){
        if(str1[i] != str2[i]){
            distancia ++;
        }
    }
    
    return distancia;
}
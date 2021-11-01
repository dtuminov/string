#include "tests.h"
#include <assert.h>
#include <stdio.h>

void run_all_tests() { 
   assert(OK == test_strlen());
   assert(OK == test_strcpy());
   assert(OK == test_strchr());
   assert(OK == test_strdup());
   assert(OK == test_memcpy());
   assert(OK == test_strstr());
   assert(OK == test_memset());
   assert(OK == test_memchr());
} 

// test strlen

Errors test_strlen(){
    char* string = "Hello world";
    if(_strlen(string) != 11){
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_strcpy(){
    char * str1 = "Hello world";
    char * str2 = "Andrey is";
    if (_strcpy(str2, str1) != "Hello world"){
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_strchr(){
    char* string = "0abcd";
    char symbol = '0';
    if (_strchr(string, symbol) != string){
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_strdup(){
    char * str1 = "Hello world";
    if (_strdup(str1) == NULL) {
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    free(str1);
    return OK;
}

Errors test_memcpy(){
    char* str1 = "Hello   world";
    char* str2 = "goodbye";
    if (_memcpy(str1,str2, strlen(str2)+1) != "goodbye world") {
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_strstr(){
    char *str1 = "Hello world";
    char *str2 = "Hello";
    if (strstr(str1, str2) != "Hello"){
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_memset(){
    char * string = "Hello world";
    char symbol = '_';
    int n = 5;
    if (MYmemset(string, symbol,n) != "_____ world"){
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_memchr(){
    char * string = "0nrvnrv";
    char symbol = '0';
    int n = 4;
    if (MYmemchr(string, symbol, n) != string){
        printf("F*ck this sh*t I'm out\n");
        return error;
    } 
    return OK;
}
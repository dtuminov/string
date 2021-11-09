#include "tests.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// test strlen

Errors test_strlen(){
    char string[] = "Hello world";
    if(_strlen(string) != 11){
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_strcpy(){
    char str1[] = "He";
    char str2[] = "An";
    _strcpy(str2, str1);
    if (strcmp(str2, "He") != 0){
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_strchr(){
    char string[] = "0abcd";
    char symbol = '0';
    if (_strchr(string, symbol) != string){
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_strdup(){
    char  str1[] = "Hello world";
    char* str2 =__strdup((char*)str1);
    if (str2 == NULL) {
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    if(strcmp(str1,"Hello world") != 0){
        return error;
    }
    free(str2);
    return OK;
}

Errors test_memcpy(){
    char str1[] = "Hello   world";
    char str2[] = "goodbye";
    _memcpy(str1,str2, _strlen(str2)+1);
    if (strcmp(str1, "goodbye") != 0) {
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_strstr(){
    char str1[] = "Hello world";
    char str2[] = "Hello";
    _strstr(str1, str2);
    if (strcmp(str2, "Hello") != 0){
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_memset(){
    char string[] = "Hello world";
    char symbol = '_';
    int n = 5;
    _memset(string, symbol,n);
    if (strcmp(string, "_____ world") != 0){
        printf("F*ck this sh*t I'm out\n");
        return error;
    }
    return OK;
}

Errors test_memchr(){
    char  string[] = "0nrvnrv";
    char symbol = '0';
    int n = 4;
    if (_memchr(string, symbol, n) != string){
        printf("F*ck this sh*t I'm out\n");
        return error;
    } 
    return OK;
}

void run_all_tests() { 
    assert(OK == test_strlen());
    assert(OK == test_strchr());
    //assert(OK == test_strdup());
    assert(OK == test_memchr());
    assert(OK == test_memset());
    assert(OK == test_memcpy());
    assert(OK == test_strstr());
    assert(OK == test_strcpy());
    printf("OK");
} 
#ifndef PROJECT_H
#define PROJECT_H
/**
*\file header.h
*\brief functions prototype
*/

#include<stdio.h>
size_t _strlen(char * string );
char* _strcpy(char *dst, char *str);
char* __strdup (char *src);
void* _memcpy(void * destptr, void * srcptr, size_t num );
void* _memset(void * memptr, char val, size_t num );
void* _memchr(void *string, char symbol, size_t n);
char* _strchr(char * string, char symbol );
char * _strstr(char* source, char* value);
int _memcmp(char* str1, char* str2, size_t num);
#endif
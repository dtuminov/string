#ifndef PROJECT_H
#define PROJECT_H
/**
*\file header.h
*\brief functions prototype
*/

#include<stdio.h>
size_t _strlen(char * string );
char* _strcpy (char *dst, char *str);
char* _strdup (char *src);
void* _memcpy(void * destptr, void * srcptr, size_t num );
char* _strstr(char * string1, char * string2 );
void* _memset(void * memptr, char val, size_t num );
void* _memchr(void *string, char symbol, size_t n);
char* _strchr(char * string, char symbol );
#endif
/**
    \file source.c
    \brief functions realization
*/
#include "string.h"
#include <malloc.h>
#include <assert.h>

/**
 * \fn size_t strlen(char * string)
 * \brief finding lenght of string
 * \param string given string
 * \return length of this string
*/

size_t _strlen(char * string){
    if (string == NULL){
       return 0;
    }
    size_t lenght = 0;
    for(char* i = string; *i != '\0'; ++i){
        lenght++;
    }
    return lenght;
}

/**
 * \fn char *strcpy (char *dst, char *str)
 * \brief  copies given string to new
 * \param dts new string
 * \param str given string
*/

char* _strcpy (char *dst, char *str){
    if(_strlen(dst) < _strlen(str)) { return NULL; }
    size_t i = 0;
    for (; i < _strlen(str); i++){
        dst[i] = str[i];
    }
    dst[i+1] = '\0';
    return dst;
}

/**
 * \fn char * strchr(char * string, int symbol )
 * \brief find symbol in given string
 * \param string given string 
 * \param symbol given symbol
*/

char * _strchr(char * string, char symbol ){
    if(string == NULL) { return NULL; }
    while (*string != '\0') {
        if (*string == symbol) { return string; }
        string ++;
    }
    return NULL; 
}

/**
 * \fn char* strdup (char *src)
 * \brief creates a copy of the specified null-terminated string in the heap
 * \param src given string
*/

char* _strdup (char *src){
    if(src == NULL) { return NULL; }
    char *str = NULL;
    size_t lenght = _strlen(src);
    str = malloc(lenght + 1);
    _strcpy(str, src);
    return str;
}

/**
 *  \fn void * memchr( void *string, int symbol, size_t n)
 *  \brief  Функция memchr в num байтах блока памяти, адресуемого указателем memptr, ищет первое вхождение val (интерпретируется как не подписанный символ), и возвращает указатель на найденный символ. В Си эта функция определена так:
 *  \param string given srting
 *  \param symbol given int value wich we finging in string
 *  \param n count of bites
*/

void * _memchr( void *string, char symbol, size_t n){
    if(string == NULL) { return NULL; }
    char *p = string;
    while (n-- != 0)
    {
        if (symbol == *p++) {
			return (void *)(p - 1);
		}
    }
    return NULL;
}

/**
 *  \fn void * memcpy( void * destptr, void * srcptr, size_t num )
 *  \brief Функция memcpy копирует num байтов первого блока памяти, на который ссылается указатель srcptr, во второй блок памяти, на который ссылается указатель destptr.
 *  \param destptr first given string 
 *  \param srcptr second given string 
 *  \param num count of bites
*/

void * _memcpy( void * destptr, void * srcptr, size_t num ){
    if(destptr == NULL || srcptr == NULL ) { return NULL; }
    for (size_t i = 0; i < num; i++){
       ((char*)destptr)[i] = ((char*)srcptr)[i];
    }
    ((char*)destptr)[_strlen(destptr)+1] = '\0';
    return destptr;
}

/**
 *  \fn void * memset( void * memptr, int val, size_t num )
 *  \brief Функция memset заполняет num байтов блока памяти, через указатель memptr. Код заполняемого символа передаётся в функцию через параметр val.
 *  \param memptr  Указатель на блок памяти для заполнения.
 *  \param val val передается в виде целого числа, но функция заполняет блок памяти символом, преобразуя это число в символ.
 *  \param num Количество байт, которые необходимо заполнить указанным символом.
*/

void * _memset( void * memptr, char val, size_t num ){
    if (memptr == NULL) { return NULL; }
    for (size_t i = 0; i < num; i++)
    {
        ((char*)memptr)[i] = val;
    }
    return memptr;
}

/**
 * \fn char * strstr(char * string1, char * string2 ) 
 * \brief Функция ищет первое вхождение подстроки string2 в строке string1. Возвращает указатель на первое вхождение строки string2   в строку string1, или пустой указатель, если строка string2 не является частью строки string1. В данном поиске нуль-символ не  учитывается.
 * \param string1 first string parametr     
 * \param string2 second string parametr
*/

char * _strstr (char * string1, char * string2 ) {
    char * needle_ptr = NULL, * haystack_ptr = NULL;
    if (string1 == NULL || string2 == NULL) { return NULL; }
    while (*string1) {
        if (*string1 == *string2) {
            int trigger_out = 1;
            needle_ptr = string2;
            haystack_ptr = string1;
            while (*needle_ptr && *haystack_ptr) {
                trigger_out = trigger_out && (*needle_ptr == *haystack_ptr);
            }
            if (trigger_out) { return string1; }
        }
    ++string1;
    }
    return NULL;
}
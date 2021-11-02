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

char* __strdup (char *src){
    if(src == NULL) { return NULL; }
    size_t lenght = _strlen(src);
    char *str = calloc(sizeof(char), lenght + 1);
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
 * \fn int _memcmp(char* str1, char* str2, size_t num)
 * @brief Comparison of num elements of strings
 * @param str1 First string
 * @param str2 Second string
 * @param num
 * @return Numerical difference of characters in strings
 */
int _memcmp(char* str1, char* str2, size_t num) {
    if (str1 == NULL || str1 == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < num; i++) {
        if (str1[i] == str2[i]) {
            continue;
        } else if (str1[i] > str2[i]) {
            return (str1[i] - str2[i]);
        } else if (str1[i] < str2[i]) {
            return (str1[i] - str2[i]);
        }

        str1++;
        str2++;
    }
    return 0;
}

/**
 * \fn char * strstr(char * string1, char * string2 ) 
 * \brief Функция ищет первое вхождение подстроки string2 в строке string1. Возвращает указатель на первое вхождение строки string2   в строку string1, или пустой указатель, если строка string2 не является частью строки string1. В данном поиске нуль-символ не  учитывается.
 * \param string1 first string parametr     
 * \param string2 second string parametr
*/

char * _strstr (char* source, char* value) {
    size_t source_len, value_len;

    source_len = _strlen(source);
    value_len = _strlen(value);

    if (source == NULL || value == NULL) {
        return NULL;
    }

    if (value_len == 0) {
        return (char *) source;
    }

    while (source_len >= value_len) {
        source_len--;
        if (_memcmp(source, value, value_len) == 0) {
            return (char*) source;
        }
        source++;
    }
    return NULL;
}
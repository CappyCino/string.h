#include <stdio.h>

char* strchr_(char *str,int character);
int strlen_(char *string);
char* strcat_(char *destination,char *source);
char* strncat_(void * destination, void * source, size_t size); // Returns a pointer to the destination string
int strcmp_(const char * str1, const char * str2); // Return 0 if equal, 1 if str1 > str2, -1 if str1 < str2
int strncmp_(const char * str1, const char * str2, size_t size); // Return 0 if equal, 1 if str1 > str2, -1 if str1 < str2    size times
char* strcpy_(char * destination, char * source); //Returns: 	A char type pointer to the destination string.
char* strncpy_(char * destination, const char * source, size_t size); // Returns: A char type pointer to the destination string.
char* strpbrk_(char * str, char * search); //Returns: 	A char type pointer to the position of the first occurrence of any of the search characters, or NULL if none of the characters were found.
char* strstr_(const char *s1, const char *s2); // Returns: A pointer to the first occurrence of the substring s2 in the string s1, or NULL if s2 is not found in s1.

int main(){

    char arr[10] = "Hello" ;
    char arr2[20] = "World!";


    printf("***************STRCHR_****************\n");
    char *strchr_result = strchr_(arr, 'e');
    printf("strchr_ found 'e' in %s. Result:  %s\n",arr,strchr_result);
    char *strchr_result2 = strchr_(arr2,'r');
    printf("strchr_ found 'r' in %s. Result:  %s\n",arr2,strchr_result2);
    printf("*******************************\n");


    printf("***************STRLEN_****************\n");
    int len = strlen_(arr);
    printf("strlen_ of %s is: %d\n", arr, len);
    int len2 = strlen_(arr2);
    printf("strlen_ of %s is: %d\n", arr2, len2);
    printf("*******************************\n");


    printf("***************STRCAT_****************\n");
    char destination[30] = "Hello ";
    char *strcat_result = strcat_(destination, arr2);
    printf("strcat_ result for strcat_result pointer: %s\n", strcat_result);
    printf("Concatenated string which is destination: %s\n", destination);
    printf("*******************************\n");


    printf("***************STRNCAT_****************\n");
    char destination2[30] = "Hello ";
    char *strncat_result = strncat_(destination2, arr2, 3); // Append only first 3 characters of arr2
    printf("strncat_ result for strncat_result pointer: %s\n", strncat_result);
    printf("Concatenated string which is destination2: %s\n", destination2);
    printf("*******************************\n");


    printf("***************STRCMP_****************\n");
    int cmp_result = strcmp_(arr, arr2);
    if (cmp_result == 0) {
        printf("strcmp_ result: %s and %s are equal.\n", arr, arr2);
    } else if (cmp_result < 0) {
        printf("strcmp_ result: %s is less than %s.\n", arr, arr2);
    } else {
        printf("strcmp_ result: %s is greater than %s.\n", arr, arr2);
    }
    printf("*******************************\n");


    printf("***************STRNCMP_****************\n");
    int ncmp_result = strncmp_(arr, arr2, 3); // Compare first 3 characters
    if (ncmp_result == 0) {
        printf("strncmp_ result: First 3 characters of %s and %s are equal.\n", arr, arr2);
    } else if (ncmp_result < 0) {       
        printf("strncmp_ result: First 3 characters of %s are less than %s.\n", arr, arr2);
    } else {
        printf("strncmp_ result: First 3 characters of %s are greater than %s.\n", arr, arr2);
    }
    printf("*******************************\n");


    printf("***************STRCPY_****************\n");
    char destination3[30];
    char *strcpy_result = strcpy_(destination3, arr);
    printf("strcpy_ result for strcpy_result pointer: %s\n", strcpy_result);
    printf("Copied string which is destination3: %s\n", destination3);
    printf("*******************************\n");


    printf("***************STRNCPY_****************\n");
    char destination4[30];
    char *strncpy_result = strncpy_(destination4, arr2, 3); // Copy only first 3 characters
    printf("strncpy_ result for strncpy_result pointer: %s\n", strncpy_result);
    printf("Copied string which is destination4: %s\n", destination4);
    printf("*******************************\n");    


    printf("***************STRPBRK_****************\n");
    char search[] = "aeiou";
    char *strpbrk_result = strpbrk_(arr, search);
    if (strpbrk_result != NULL) {
        printf("strpbrk_ found a character from '%s' in '%s': %c\n", search, arr, *strpbrk_result);
    } else {
        printf("strpbrk_ did not find any characters from '%s' in '%s'.\n", search, arr);
    }
    char *strpbrk_result2 = strpbrk_(arr2, search);
    if (strpbrk_result2 != NULL) {
        printf("strpbrk_ found a character from '%s' in '%s': %c\n", search, arr2, *strpbrk_result2);
    } else {
        printf("strpbrk_ did not find any characters from '%s' in '%s'.\n", search, arr2);
    }
    printf("*******************************\n");


    printf("***************STRSTR_****************\n");
    char *strstr_result = strstr_(arr, "rain");
    if (strstr_result != NULL) {
        printf("strstr_ found 'rain' in '%s': %s\n", arr, strstr_result);
    } else {
        printf("strstr_ did not find 'rain' in '%s'.\n", arr);
    }
    char *strstr_result2 = strstr_(arr2, "Wor");
    if (strstr_result2 != NULL) {
        printf("strstr_ found 'Wor' in '%s': %s\n", arr2, strstr_result2);
    } else {
        printf("strstr_ did not find 'World' in '%s'.\n", arr2);
    }
    printf("*******************************\n");

    return 0; 
}


char* strchr_(char *str,int character){

    if(str == NULL) {return NULL;} // Check for NULL pointers
    while(*str != '\0'){
        if(*str == character){
            return str;
        }
        str++;
    }
    return NULL; // Character not found
}
    
int strlen_(char *string){
    int counter = 0;

    while(*string != '\0'){
        counter++;
        string++;
    }

    return counter;
}

char* strcat_(char *destination,char *source){
    char *destination_start = destination; // Save the start of destination for return

    while(*destination != '\0'){ // Find the end of destination string
        destination++;}

    while(*source != '\0'){ 

        *destination = *source; // Copy character from source to destination

        destination++;
        source++;}
        
        destination++; // Move to the next position in destination
       *destination = '\0'; // Null-terminate the destination string

        return destination_start; 
}

char* strncat_(void *destination, void *source, size_t size)
{
    if (destination == NULL || source == NULL)
        return NULL;

    // Cast to char* for actual operations
    char *dest = (char*)destination;
    const char *src = (const char*)source;
    char *dest_start = dest;

    // Move to the end of destination string
    while (*dest != '\0') {
        dest++;
    }

    // Append characters from source to destination (up to size)
    while (*src != '\0' && size > 0) {
        *dest = *src;
        dest++;
        src++;
        size--;
    }

    *dest = '\0'; // Null-terminate destination

    return dest_start;
}

int strcmp_(const char * str1, const char * str2){

    while(*str1 != '\0' && *str2 != '\0'){
        if(*str1 < *str2)
            return -1; // str1 is less than str2
        else if(*str1 > *str2)
            return 1; // str1 is greater than str2
        str1++;
        str2++;
    }

    // If we reach here, one or both strings ended
    if(*str1 == '\0' && *str2 == '\0')
        return 0; // Both strings are equal
    else if(*str1 == '\0')
        return -1; // str1 is less than str2
    else
        return 1; // str1 is greater than str2
}

int strncmp_(const char * str1, const char * str2, size_t size){

    while(size > 0 && *str1 != '\0' && *str2 != '\0'){
        if(*str1 < *str2)
            return -1; // str1 is less than str2
        else if(*str1 > *str2)
            return 1; // str1 is greater than str2
        str1++;
        str2++;
        size--;
    }

    // If we reach here, one or both strings ended or size limit reached
    if(size == 0 || (*str1 == '\0' && *str2 == '\0'))
        return 0; // Both strings are equal up to size
    else if(*str1 == '\0')
        return -1; // str1 is less than str2
    else
        return 1; // str1 is greater than str2
}

char* strcpy_(char *destination, char *source){
     
    char *destination_start = destination; // Save the start of destination for return

    if(destination == NULL || source == NULL) 
     return NULL; // Check for NULL pointers
    
    while(*source != '\0'){ // Copy characters from source to destination
        *destination = *source;
        destination++;
        source++;
    }

    if(destination == NULL)
     *destination = '\0'; // Null-terminate the destination string

    return destination_start; // Return the start of the destination string
}

char *strncpy_(char * destination, const char * source, size_t size){

    char *destination_start = destination; // Save the start of destination for return

    if(destination == NULL || source == NULL) {return NULL;} // Check for NULL pointers

    while(*source != '\0' && size > 0){ // Copy characters from source to destination
        *destination = *source;
        destination++;
        source++;
        size--;
    }
    if(destination == NULL)
        *destination = '\0';

    return destination_start; // Return the start of the destination string
}

char* strpbrk_(char *str, char *search){
    
    char *search_ptr = search;

    if(str == NULL || search == NULL) return NULL; // Check for NULL pointers

    while(*str != '\0') {
        search_ptr = search; // Reset search pointer for each character in str

        while(*search_ptr != '\0') {
            if(*str == *search_ptr) {
                return str; // Return pointer to the first occurrence
            }
            search_ptr++;
        }
        str++;
    }
    return NULL; // No characters found
}

char* strstr_(const char *s1, const char *s2){

    if (s1 == NULL || s2 == NULL) return NULL; // Check for NULL pointers

    const char *p1 = s1;
    const char *p2 = s2;

    while (*p1 != '\0') {
        const char *start = p1;
        p2 = s2;

        while (*p2 != '\0' && *start == *p2) {
            start++;
            p2++;
        }

        if (*p2 == '\0') { // If we reached the end of the substring
            return (char *)p1; // Return pointer to the first occurrence
        }
        p1++;
    }
    return NULL; // Substring not found
}
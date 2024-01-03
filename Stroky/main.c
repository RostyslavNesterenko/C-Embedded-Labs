#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 256

void reverse(char *str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void custom_itoa(unsigned int num, char *str) {
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
    } else {
        while (num != 0) {
            str[i++] = (num % 10) + '0';
            num /= 10;
        }
    }
    str[i] = '\0';
    reverse(str, i);
}

int main() {
    char input[MAX_LENGTH];
    char numberString[MAX_LENGTH];
    printf("Enter a string: ");
    if (fgets(input, MAX_LENGTH, stdin) != NULL) {
        char *ptr = input;
        while (*ptr) {
            if (isdigit((unsigned char)*ptr)) {
                char *start = ptr;
                while (isdigit((unsigned char)*ptr)) ptr++;
                strncpy(numberString, start, ptr - start);
                numberString[ptr - start] = '\0';
                unsigned int number = atoi(numberString);
                custom_itoa(number, numberString);
                printf("Number string: %s\n", numberString);
            } else {
                ptr++;
            }
        }
    }
    return 0;
}

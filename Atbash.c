// Atbash: A simple substitution cipher.

#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");
    char c;
    while((c = fgetc(fp)) != EOF) {
        if((c >= 'a' && c <= 'z') )
            printf("%c", 'z' - (c - 'a'));
        else if(c >= 'A' && c <= 'Z')
            printf("%c", 'Z' - (c - 'A'));
        else
            printf("%c", c);
    }
    return 0;
}

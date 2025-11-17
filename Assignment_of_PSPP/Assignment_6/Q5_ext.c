#include <stdio.h>
#include <string.h>
char *strchar(char *str, char c) {
    //char *p;
    //p = str;
   // if(c == '\0') {
     //   return NULL;
    //}
    int len = strlen(str);
    int i = 0;
    while(i < len + 1) {
        if(c == str[i]) {
            return &str[i];
        }
        i++;
    }
    return NULL;
}
int main(){
printf("%s\n", strchar("Abhijit", '\0'));
}

#include <stdio.h>
char *strconcat(char *dest, const char *src){
    int count = 0, count1 = 1;
    for(int i = 0; dest[i] != '\0'; i++){
        count++;
    }

    for(int i = 0; src[i] != '\0'; i++)
    count1++;
    int j = 0;
    for(int i = count; i < count + count1; i++){
        dest[i] = src[j++];
    }
    return dest;
}
int main(){
	char b[32] = "Sharwari", a[32] =" is one of my best friend";
printf("%s\n", strconcat(b, a));
}

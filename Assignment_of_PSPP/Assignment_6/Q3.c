#include <stdio.h>
char *stranybyte( char *s, const char *accept){
    int count1 = 1, count2 = 1;
    for(int i = 0; s[i] != '\0'; i++){
        count1++;
    }
    for(int i = 0; accept[i] != '\0'; i++){
        count2++;
    } char *p;
    for(int i = 0; i < count1; i++){
        for(int j = 0; j < count2; j++){
            if(s[i] == accept[j]){
               p = &s[i];
                return p;
            }
        }
    }
    return NULL;
}
int main(){
	printf("%s\n", stranybyte("abhijit","xiy") ? stranybyte("abhijit","xiy"): "");
	}

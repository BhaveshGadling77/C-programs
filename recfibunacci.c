#include <stdio.h>
void fibu(int n, int pre, int curr){
       int next = 0;
	if(n == 0)
		return;

	next = pre + curr;
	printf("%d ", next);
	return fibu(n - 1, curr, next);
}
int main(){
	fibu(6, 1, 0);
	return 0;

}

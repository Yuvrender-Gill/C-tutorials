#include <stdlib.h>
#include <stdio.h>

/*
*
*
*/
int main() {
	char phone[11];
	int number;
	
	scanf("%s %d", phone, &number);
	
	if ((1 <= number) && (number <= 9)){
		
		printf("%c\n", phone[number]);
			
	} else if (number == 0){
		printf("%s\n", phone);
	} else{
		printf("ERROR\n");
		return 1;
	}
	
	return 0;

}

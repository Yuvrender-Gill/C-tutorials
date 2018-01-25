#include <stdlib.h>
#include <stdio.h>

/*
*
*
*/
int main() {
        char phone[11];
        int number;
	int return_cvalue = 0;
	
        scanf("%s", phone);
	
	while(scanf("%d", &number ) != EOF){
        	if ((1 <= number) && (number <= 9)){

                	printf("%c\n", phone[number]);
			

        	} else if (number == 0){
                	printf("%s\n", phone);
			
        	} else{
                	printf("ERROR\n");
                	return_cvalue = 1;
        	}
		
	}

        return return_cvalue;

}

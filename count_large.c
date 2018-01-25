#include <stdio.h>
#include <stdlib.h>



/* Check permissions take two strings permissions and required_permissions.
* Both strings comprise the permissions of file format in unix  and comprise of chars 
* r, w,x and -. If permissions has atleat the required_permissions as subset it returns 0 
* otherwise return 1.  
*/
int check_permissions(char *permissions, char *required_permissions){
	
	for (int i = 0; i < 9; i++){
		if (required_permissions[i] != '-'){ 
        		if(permissions[i] != required_permissions[i]){
				return 1;	
			}
		
		}	
	}
	return 0;
}	
                           
           
/* Takes the input of ls -l command from the command line and returns the files which exceed the specified file size.
* 
*/     
int main(int argc, char** argv) {
    
    // String to read from the output
    char file[31];
    int file_count = 0;	

    // Checking the proper number of arguments to the program
    if (!(argc == 2 || argc == 3)) {
        fprintf(stderr, "USAGE: count_large size [permissions]\n");
        return 1;
    }

    // Get the given size
    int given_size = (int) strtod(argv[1], NULL);
      
	int count = 0;

    // Reading the Total # line
	scanf("%s", file);
	scanf("%s", file); 
    // A boolean to check conditions
	int checker = 0;
    // Reading the rest of ls -l output  
    while(scanf("%s", file) != EOF){
	    // Counter to know the place of reading the output
        count += 1;
        int curr_size;
        char permissions[11];
        
        //1. Check and store the permissions
        if (count % 9 == 1){ // Means we are at the permissions strings
            //Checking if the file is regular file
            if (file[0] != 'd') { //If file is not a directory
		        checker = 1; // If the file is not directory put the checker to be true
                for(int i = 0; i < 10; i++){
                    //Store the permissions of file as a string
                    permissions[i] = file[i];
                }
            }
        }
	if (checker){ //If file is not a directory then proceed further
            if (count % 9 == 5){ // Only true when the reading pointer is at the file size
                curr_size = (int) strtod(file, NULL);
                if (given_size < curr_size ){ //if the file size is larger than the specified limit
			        if (argc == 2){ //if only size is given then increment the file count
                            file_count += 1;
                    } else if (argc == 3){ // Otherwise check permissions condition and then increase the file count
                            if (!check_permissions(permissions + 1, argv[2])){
                                file_count += 1;
                            }
                    }
                }
            }   
        }
    }
	printf("%d\n",file_count);
    return 0;
}

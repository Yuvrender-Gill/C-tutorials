#include <stdio.h>
#include <stdlib.h>
 

int populate_array(int, int *);
int check_sin(int *);


int main(int argc, char **argv) {
    // TODO: Verify that command line arguments are valid.
    if (argc != 2){
        fprintf(stderr, "USAGE: validate_sin SIN\n");
        return 1;
    }

    int sin = (int) strtod(argv[1], NULL);
    int sin_array[9];
    int check = populate_array(sin, sin_array);
    // Check if the sin_array is populated correctly
    if (!check){
        //Validate the sin and print the message
        int validate_sin = check_sin(sin_array);
        if (!validate_sin){
            printf("Valid SIN\n");
        } else {
            printf("Invalid SIN\n");
        }
    } else {
    
        return 1;
    }


    // TODO: Parse arguments and then call the two helpers in sin_helpers.c
    // to verify the SIN given as a command line argument.
  
    return 0;
}

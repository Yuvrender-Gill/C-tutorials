

/*
 * Convert a 9 digit int to a 9 element int array.
 */
int populate_array(int sin, int *sin_array) {
     
    int store1 = sin;
    int store2 = sin;
    int num_digits = 0;
    

    // Calculating the number of  digits in the given sin 
    while (store1 > 0){
        store1 = (int) store1 / 10;
        num_digits += 1;
    }
    
    // Checking for a valid SIN number
    if (sin < 0 || num_digits != 9){
	
        return 1;
    } // If SIN digits are valid then populate the array with digits of the string. 
    else { 
        for (int i = 0; i < num_digits; i++){
     	    int dig = store2 % 10;
	    store2 = (int) store2 / 10;
	    sin_array[i] = dig;
            }
	   
    }
  
    return 0;
}


/* 
 * Return 0 (true) iff the given sin_array is a valid SIN. This function implements Luhn's Algorithm to verify 
 * that the given SIN is a valid Canadian SIN. The function takes an array of digits of SIN in reverse order. 
 * The function then multiplies all the odd indexed elements of sin_array and replaces with the corresponding 
 * elements of the array if resulting product is single digit or it sums the digits of product and then replaces
 * the corresponding element. The function returns 0 if the sum of all elemets of new array is divisible by 10
 * otherwise it returns 1.        
 */
int check_sin(int *sin_array) {
    
    int temp_array_sum = 0;
    int temp_array[9];
    // Making a copy of sin_array in temp_array
    for (int i = 0; i < 9; i++){
        temp_array[i] = sin_array[i];
    }
    // Implementing Luhn's Algorithm
    for (int i = 0; i < 9; i++){ 
        if ((i % 2) != 0){ //Putting condition on the odd indices
            int prod = sin_array[i] * 2;
	    if (prod > 9){ //If the product has two digits
	        int sum_prod = 0;
		while (prod > 0){ // Extracting the digits from the product
		    int dig = (prod % 10);
		    prod = (int) prod / 10;
		    sum_prod = sum_prod + dig;   
		} //Replacing the corresponding digit in SIN with the sum of digits of product
	    temp_array[i] = sum_prod;	
	    } else { // If the product is single digit then just replace the corresponding digit with product
		temp_array[i] = prod;
	    } //For even indices do nothing 	
        }
	temp_array_sum += temp_array[i];
	 
     }
	
    // Returning 1 or 0 depending in the sum of temp_array values 
    if (temp_array_sum % 10 == 0){
        return 0;
    } 				
    return 1;
}

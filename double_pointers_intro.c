int main() {

    int i = 81;
    int *pt = &i;
    int **pt_ptr = &pt;

    int *r= *pt_ptr;
    int k = *r;
   
    // We don't actually need the intermediate value r. 
    // We can dereference pt_ptr twice like this.
    int k1 = **pt_ptr;
  
    // We can even have triple pointers.
    int ***pt_ptr_ptr = &pt_ptr;
    int k2 = ***pt_ptr_ptr;
    printf("Value of i: %d\n", &i);
    printf("Value of pt: %d\n", &pt);
    printf("Value of pt_ptr: %d\n", &pt_ptr );
    printf("Value of r: %d\n", &r);
    printf("Value of k: %d\n", &k);
    printf("Value of k1: %d\n", &k1);
    printf("Value of pt_ptr_pt: %d\n", &pt_ptr_ptr);
    printf("Value of k2: %d\n", &k2);

    return 0;
}

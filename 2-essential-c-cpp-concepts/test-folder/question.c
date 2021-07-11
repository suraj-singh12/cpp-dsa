#include <stdio.h>
int main()
{

    unsigned int x[4][3]= { {1,2,3},
                            {4,5,6},
                            {7,8,9},
                            {10,11,12}
                          };
    printf("%u\n",x);
    
    printf("%u\n",x+1);   // see adding 1 to base address takes me to row 1 i.e. the row with {4,5,6} elements 
                          // that means we skipped how many elements? three elements i.e. 1,2,3 and int is 4 bytes in size here so answer would be (base_address + (4*3))
    printf("%u\n",*x);    // this is quite same as just writing x
                          // because it means x[0] which is basically the base_address of the array
    
    printf("%u\n",*(x+1));    // so this is equivalent to x[1] which is address of row 1 i.e. row with elements {4,5,6} so again answer would be (base_address + 4*3)
    
    printf("%u\n",*x+3);    // now this one, this is *x i.e. x[0] i.e. base address of array, this means we are at row 0 so adding 3 takes us 3 steps ahead in row 0
                          // so now we are at row {1,2,3} element 3
                          // so answer would be base_address + 4*3)
    
    printf("%u, %u, %u\n",x+3,*(x+3),*(x+2)+3); // ans is : address of x[3], address of x[3], address of x[2] + 4*3
                                                // 2000+(4*3)*3, 2000+(4*3)*3, 2000+(4*3)*2 + (4*3)
                                                // 2036, 2036, 2036
    return 0; 
}

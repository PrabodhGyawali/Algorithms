#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Returns string of bits representing number */
int get_max_bit_length(int decimal) {
    int bit_len = 0;
    while (pow(2, bit_len) - decimal < 0) 
    {
        bit_len++;
    }
    return bit_len;
}

/* Bit representation (MSB on left) of array */
int* get_bit_representation(int decimal) {
    int num = decimal;
    int bit_len = get_max_bit_length(decimal);
    printf("bit_len: %d\n", bit_len);
    int* bit_array = (int*)calloc(bit_len, sizeof(int));

    for (int i = bit_len; i > -1; i--)
    {
        double d = pow(2, i);
        if (i == 0) {printf("i:0 => d = %f\n", d);}
        printf("%f\n", d);
        if ((num - d) >= 0) {
            printf("num - d = %f\n", num - d);
            bit_array[bit_len - i] = 1;
            num -= d;
            printf("new_num = %d\n", num);
        }
        
    }
    return bit_array;
}

/* Ouput: integers > -1 of size n.
    nums[i+1] > nums[i]
    - result of bitwise AND of all elements is x
*/
long long minEnd(int n, int x) {
    int* nums = malloc(sizeof(int)*n);
    int binary[32];
    
    for (int i = 0; i < n; i++)
    {
        // Get bit representation of n


    }
    return nums[n];
}

int main() {
    int* bit_array = get_bit_representation(69);
    int bit_len = get_max_bit_length(69);
    for (int i = bit_len; i > 0; i--)
    {
        printf("%d", bit_array[i]);
    }
}
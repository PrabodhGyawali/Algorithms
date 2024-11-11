#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long binary_to_decimal(const char* binary) {
    long long decimal = 0;
    long long power = 1;
    int len = strlen(binary);
    
    // Process from right to left
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

long long decimal_to_binary(int decimal) {
	if (decimal == 0) {
		return 0;
	}

	long binary = 0;
	int place_value = 1;
	while (decimal > 0) {
		int rem = decimal % 2;
		binary += (rem * place_value);
		place_value *= 10;
		decimal /= 2;
	}

	return binary;
}

/* Ouput: integers > -1 of size n.
    nums[i+1] > nums[i]
    - result of bitwise AND of all elements is x
*/
long long minEnd(int n, int x) {
    long long* nums = malloc(sizeof(long long)*n);
    long long binary_x = decimal_to_binary(x);
	for (int i = 0; i < n; i++)
    {
        // Get bit representation of n
		nums[i] = decimal_to_binary(i);
		// Join this integer with binary_x
		nums[i] = nums[i] & binary_x;
		char binary_str[65];
		sprintf(binary_str, "%lld", nums[i]);
		nums[i] = binary_to_decimal(binary_str);
    }
	long long ans = nums[n-1];
	free(nums);
    return ans;
}

int main() {
	long long ans = minEnd(3, 4);
	printf("ans: %lld\n", ans);
	return 1;
}

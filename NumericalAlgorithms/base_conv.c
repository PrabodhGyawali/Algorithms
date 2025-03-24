#include <stdio.h>
#include <math.h>

int 
binary_to_decimal(int binary) {
	int decimal = 0;
	int i = 0;
	while (binary != 0) {
		int rem = binary % 10;
		decimal += rem * pow(2, i++);
		binary /= 10;
	}

	return decimal;
}

int
decimal_to_binary(int decimal) {
	if (decimal == 0) { return 0; }

	int binary = 0;
	int place_value = 1;

	while(decimal > 0) {
		int rem = decimal % 2;
		binary += (rem * place_value);
		place_value *= 10;
		printf("place_value: %d\n", place_value);
		decimal /= 2;
	}
	return binary;
}

int main(int argc, char* argv[]) {
	int binary = 10110;
	int decimal = binary_to_decimal(binary);
	printf("Binary: %d\nDecimal: %d\n", binary, decimal);

	int decimal2 = 69;
	int binary2 = decimal_to_binary(decimal2);
	printf("Decimal: %d\nBinary: %d\n", decimal2, binary2);
	return 0;
}


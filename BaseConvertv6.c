#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char inputnumber[64];
int inputbase;
int outputbase;
char outputs[36] = {'0','1','2','3','4','5','6','7','8','9',
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int main(){
	
	// retrieve original number and base from the user //
	
	printf("Please input a value (Capitalize all Letters): ");
	scanf("%s", inputnumber);
	
	printf("Please input the base: ");
	scanf("%d", &inputbase);
	
	
	// Convert to input number to base 10 //
	
    int find_value(char input){ //Converts Alphanumeric Characters to Base 10 Values
 	   int num_value;
	   	
	   for (num_value = 0; num_value <= 36; num_value++){
 		   if ((int)input == (int) outputs[num_value]){
 			   //printf("The numerical Value of the symbol is: %d\n", num_value);
			   return num_value;  
 		   }
 	   }
    }
	
	// My own power function //
	
	int power(int base, int expon){
		int i;
		int result = 1;
		for (i = 1; i <= expon; i++){
		result = result * base;	
		}
		return result;
	}
			
	// Initializes a new array with numerical values in reverse order //
	
	int convert_to_ten(char input_array[]){
	int i;
	int base_ten;
	int exponent = 0;
	int array_length = strlen(inputnumber);
	
	for (i = array_length - 1; i >= 0; i--){
		int multiple = power(inputbase, exponent);
		base_ten += (find_value(inputnumber[i]) * multiple);
		int test = find_value(inputnumber[i]);
		exponent += 1;
		}
		return base_ten;
	}
	int to_be_divided = convert_to_ten(inputnumber);
	printf("In base 10, the value is: %d\n", to_be_divided);
	
	printf("Please input the desired base: ");
	scanf("%d", &outputbase);
	
	int convert_to_base(int base_ten_number){
		int dividend = base_ten_number;
		int divisor = outputbase;
		int remain;
		char character;
		
		while (dividend != 1){
			remain = dividend%divisor;
			printf("Remainder becomes: %d\n", remain);
			character = outputs[remain];
			printf("The character value is: %s\n", character);
			dividend -= dividend/divisor;
			printf("Dividend becomes: %d\n", dividend);
		}
		printf("\n");
		return 0;
	}
	
	convert_to_base(to_be_divided);
}
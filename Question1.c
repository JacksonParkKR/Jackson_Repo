//solution by Jackson.
//Dec, 17, 2017.

//Question1. Treasure map
//There is two array, and each elements of array respectively. Those are for the map.
//When the elements convert by binary, it represents of the each rows of map.
//1 is blocked, 0 is empty. 
//By combining two array, get new array for representing a treasure map.
//To show the Prodo, convert 1 to #, 0 to whitespace.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int binaryConvert(int item);	//Decimal to binary
void perfectDecoder(int array1[], int array2[], int size);	//Decoder for array and print the treasure map.

int main(){
	int size;	//array size
	int i=0;
	int j=0;
	int boundary;	//This question implicits a tresure map is nxn matrix form. So need to check whether input data is in boundary or not.
	printf("what is the matrix size?\n");
	scanf("%d",&size);

	boundary = (pow(2,size))-1;	//get Max_boundary
	
	int Array[2][size];	//Two array.

	for(i=0; i<2; i++){
		for(j=0; j<size; j++){
			printf("put %d th element in array\n",j+1);
			scanf("%d",&Array[i][j]);
			if((Array[i][j])>boundary || (Array[i][j]) < 0){	//boundary checking.
				printf("out of boundary\n");
				exit(0);
			}
		}
	}
	perfectDecoder(Array[0],Array[1],size);
	return 0;
}

void perfectDecoder(int array1[], int array2[], int size){
	
	char cryptogarphArray[size][size];
	int i=0;
	int j=0;
	int calc;
	int breakedNum = 0;

	for(i=0;i<size;i++){		
		j=0;
		calc = binaryConvert(array1[i] | array2[i]);	//use bitwise OR, and convert decimal data to binary. 

		int firstDivide = pow(10,size-1);	//To break apart a multi-value to seperate.

		while(j<size){
			breakedNum=calc/firstDivide;	//breakedNum is 1 or 0.
			if(breakedNum == 1){	// 1 is blocked, so make it as #
				cryptogarphArray[i][j] = '#';

			}else{	//0 is empty, so whitespace.
				cryptogarphArray[i][j] = ' ';
			}
			calc = calc- breakedNum*firstDivide;
			firstDivide /=10;
			j++;
		}		
	}
	printf("Decoding complete\n");

	for(i=0;i<size;i++){	//To show the map to user
		for(j=0;j<size;j++){
			printf("%c",cryptogarphArray[i][j]);
		}
		printf("\n");	
	}

}
int binaryConvert(int item){	//converting decimal to binary. (Recursion function)
	if(item == 0){
		return 0;
	}else{
		return (item%2+10*binaryConvert(item/2));
	}
}

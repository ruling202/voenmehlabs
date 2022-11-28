#include <stdio.h>
#define SIX 6
#define TWENTY 20
void inc_array_elem_by_1(int intArray[]);
int main(void) {
	/*for (int i = 0; i < 10; i++)
	{
		char array[i];
		print("size of vla %i \n", sizeof(array));
	}*/
	int intArray[SIX] = { 22,19,37,56,18,40 };
	int offset;
	inc_array_elem_by_1(intArray);
	for (offset = 0; offset < SIX; offset++)
	{
		printf("intArray[%i] = %i \n", offset, intArray[offset]);
	}
	int house;
	int* addrOfHouse;
	addrOfHouse = &house;
	*addrOfHouse = 5;
	printf("house = %d\n", house);

	int firstInt =1, secondInt=2, tempInt;
	printf("first = %d, second = %d \n", firstInt, secondInt);
	int* anIntPtr;
	anIntPtr = &firstInt;
	tempInt = *anIntPtr;
	*anIntPtr = secondInt;
	secondInt = tempInt;
	printf("first = %d, second = %d\n", firstInt, secondInt);

	char aCode = 'A', bCode = 'B';
	char *aCodePtr = &aCode, *bCodePtr = &bCode, *tempCodePtr;
	printf("aCodePtr = %p , value = %c \n", aCodePtr, *aCodePtr);
	printf("bCodePtr = %p , value = %c  \n", bCodePtr, *bCodePtr);
	tempCodePtr = aCodePtr;
	aCodePtr = bCodePtr;
	bCodePtr = tempCodePtr;
	printf("aCodePtr = %p , value = %c \n", aCodePtr, *aCodePtr);
	printf("bCodePtr = %p , value = %c\n", bCodePtr, *bCodePtr);

	char stack[] = "1 2 3 4 5 6";
	size_t size_stack = sizeof(stack) - 1;
	char* pstack = stack;
	for (int offset = size_stack; offset >= 0; offset--)
	{
		printf("%c", pstack[offset]);
	}
	printf("\n%s\n", pstack);

	char charValue = 'A', * ptrChar = &charValue,
	**ptrPtrChar = &ptrChar;
	charValue = 'B';
	*ptrChar = 'C';
	**ptrPtrChar = 'D';

	char A[] = "ABCDEFGH";
	char* pA = A;
	printf("%c\n", *pA);
	pA++;
	printf("%c\n", *pA);
	pA+=2;
	printf("%c\n", *pA);

	char testString[TWENTY], *pointrChar = testString;
	for (int id = 0; id < TWENTY; id++) {
		*pointrChar = getchar();
		pointrChar++;
	}
	pointrChar = testString + (TWENTY - 1);
	for (int id = 0; id < TWENTY; id++) {
		putchar(*pointrChar);
		pointrChar--;
	}
	
}
void inc_array_elem_by_1(int intArray[]) {
	for (int offset = 0; offset < SIX; offset++) {
		intArray[offset]++;
	}
}
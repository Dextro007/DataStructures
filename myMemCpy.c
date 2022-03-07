/*
 * Prbm : write your own function that takes the data and source block of memeory and copies it to 	    the other 
 **/

#include<stdio.h>
#include<strin.h>

void memcpy_custom( void* source, void *dest, size_t n){
	char *schar = (char *)source;
	char *dchar = (char *)dest;
	for(int i = 0; i<n; i++){
		dchar[i] = schar[i];
	}
	return;
}

int main(){
	char srcChar[] = {"Function is working fine"};
	char dest[100];
	memcpy_custom(srcChar, dest, strlen(srcChar)+1);
	printf("Value copied in dest %s \n", dest);


	int srcInt[] = {10, 20, 30,40};
	int destInt[5];
	int n = sizeof(srcInt)/sizeof(srcInt[0]);
	memcpy_custom(srcInt, destInt, n);
	printf("Values in destination memory \n");
	for( int i = 0; i< n; i++){
		printf( "%d ", destInt[i]);
	}
	return 0;
}
		



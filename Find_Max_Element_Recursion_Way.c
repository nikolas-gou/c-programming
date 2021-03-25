//										FIND THE MAX ELEMENT WITH RECURSION AND NOT
//													

#include<stdio.h>
#include<stdlib.h>

#define random 1000//	RANDOM VALUES

//	FUNCTIONS

int serial_max(int *, int);//	SERIAL WAY FOR FIND MAX ELEMENT
int rec_max(int *, int);//		RECURSION WAY FOR FIND MAX ELEMENT


    int main() {
    	int *T;//	DYNAMIC ARRAY
    	int  i, N;//	POINTER OF ARRAY, SIZE OF ARRAY

    	printf("\nGIVE THE SIZE OF ARRAY : ");
    	scanf("%d", &N);
    	
    	T = (int *)malloc(N * sizeof(int));// ALLOCATE SPACE
    	
    	for(i = 0; i < N; i++) 
    		if((rand() % random) % 2 == 0) //	POSSITIVE VALUES
    			T[i] = rand() % random;
    		else						  //	NEGATIVE VALUES
   			    T[i] = -1 * rand() % random;
    		
		printf("\nTHE RECURSION WAY FOUND MAX ELEMENT : %d", rec_max(T, N));
		printf("\nTHE SERIAL WAY FOUND MAX ELEMENT    : %d", serial_max(T, N));
		
		free(T);
		return 0;
	}
	
//	FUNCTIONS

int rec_max(int *T, int N) {//  PARAMETERS : ARRAY AND SIZE OF ARRAY
	
	if(N == 1) // IF THE ARRAY HAS ONLY ONE ELEMENT THEN THE MAX ELEMENT IS FIRST "T[0]" 
		return T[0];
	
	if(T[N - 1] > rec_max(T, N-1))
		return T[N - 1];
}

int serial_max(int *T, int N) {//  PARAMETERS : ARRAY AND SIZE OF ARRAY
    int i, max = 0;
    
    for(i = 1; i < N; i++) {
        if(T[max] < T[i]) {// THE SERIAL WAY
            max = i;
        }
    }
    return T[max];
}

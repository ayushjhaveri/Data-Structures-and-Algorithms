#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
} 	


int* readData(char * fileName){

	FILE *fptr;
	if((fptr = fopen(fileName,"r")) == NULL){
		printf("Error Opening File");
		return NULL;
	}
	int size;
	fscanf(fptr,"%d\n",&size);
	int *values;
	values =(int*) malloc(sizeof(int)*size);
	char a[3];
	
	int i = size ;
	while(i--){
		 fscanf(fptr,"%2s %d\n",a,&(values[size-i-1])) ;
	}
	
	return values;
}


KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey){

	int sz = hiKey - loKey + 1 ;
	int* temp = (int*) malloc(sizeof(int)*sz) ;
	
	for(int i=0 ; i<sz ; i++) 
		temp[i] = 0;
		
	int keysz = 0 ;
	
	for(int i=0 ; i<lsSize ;i++){
		if(!temp[Ls[i] - loKey]){
			temp[Ls[i] - loKey] = 1;
			keysz++;
			}
	}
			
	KeyStruct keys = (KeyStruct)malloc(sizeof(struct keyStruct));
	int j = 0;
	keys->keysSize = keysz ;
	keys->Keys = (int*) malloc(sizeof(int)*(keys->keysSize)) ;
	for(int i=0 ; i<sz ; i++){
		if(temp[i]){
			keys->Keys[j] = loKey + i ;
			j++ ;
		}
	}
	
	return keys ;

}`

int part2Loc(int* Ls, int lo, int hi, int piv)
{
	int l,r ;
	l = lo ;
	r = hi ;
	while(l<r){
		while(Ls[l] <= piv)
			l++ ;
		while(Ls[r] > piv)
			r-- ;
		if(l<r){
			int temp = Ls[l] ;
			Ls[l] = Ls[r] ;
			Ls[r] = temp ;
		}
	}
	
	return 0 ;
}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey)
{
	KeyStruct keys = (KeyStruct)malloc(sizeof(*keys)) ;
	keys = extractKeys(Ls,size,loKey,hiKey) ;
	
	for(int i = 0 ; i<keys->keysSize ; i++){
		part2Loc(Ls,0,size-1,keys->Keys[i]) ;
	}

}		
	





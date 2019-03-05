#include<stdio.h>
#include<stdlib.h>

typedef struct{
	long long int card_number;
	char bank_code[5], first_name[5], last_name[5];
	int expiry_month, expiry_year;
}Credit;

Credit *credit_arr; 
void insertionSort(int count);
void insertInOrder(int count);





int main(int argc, char **argv){
	
	FILE *fptr;
	if ((fptr = fopen(argv[1],"r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
		
	credit_arr = (Credit*) malloc(sizeof (Credit)*10);
	int capacity=10, count=0;
	
	Credit temp;
	while(fscanf(fptr,"\"%llu,%[^,],%u/%u,%[^,],%[^\"]\"\n", &temp.card_number,temp.bank_code,&temp.expiry_month,&temp.expiry_year,temp.first_name,temp.last_name) != EOF){
		count++;
		if(count>capacity){
			capacity*=2;
			credit_arr = (Credit *)realloc(credit_arr,sizeof(Credit)*capacity);
		}
		
		credit_arr[count-1]=temp;
		//insertInOrder(count);
		
	
	}
	fclose(fptr);
	printf("\n");
	insertionSort(count);
	for(int i=0;i<count;i++){
		printf("%llu\n",credit_arr[i].card_number);
	}

	return 0;
}

void insertionSort(int count){
	
	
	if(count<=1)return;
	
	insertionSort(count-1);
	insertInOrder(count); 
	return;

}

void insertInOrder(int count){

	if(count<=1)return;
	
	Credit key= credit_arr[count-1];
	int j = count-2;
	
	while (j >= 0 && credit_arr[j].card_number > key.card_number) 
       { 
           credit_arr[j+1] = credit_arr[j]; 
           j = j-1; 
       } 
       credit_arr[j+1] = key; 
}




#include<stdio.h>

/*
Observations:
When the function returns all the local variables stored are removed and the address location points back at the initial value.
When a function calls itself, it has not returned yet, so it retains its address location until it returns.
*/

int bits=0;

int p(){
	if(bits>=10)return 0;
	int pilani=1;
	printf("p: %u\n",&pilani);
	bits++;
	p();
	

}

int g(){
	int goa=2;	
	printf("g: %u",&goa);
}

int h(){
	int hyd=3;
	printf("h: %u",&hyd);
}

int d(){
	int dub=4;
	printf("d: %u",&dub);
}

int main(){

	p();
	g();
	h();
	d();

}



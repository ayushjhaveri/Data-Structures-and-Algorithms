#include"merge.h"

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
	
	int i=0,j=0,k=0;
	while(i<sz1 && j<sz2){
		if(Ls1[i]->cgpa <= Ls2[j]->cgpa){
			Ls[k]=Ls1[i];
			i++;
		}else{
			Ls[k]=Ls2[j];
			j++;
		}
		k++;
	}

	while(i<sz1){
		Ls[k]=Ls1[i];
		i++;
		k++;
	}
	
	while(j<sz2){
		Ls[k]=Ls2[j];
		j++;
		k++;
	}

}

void mergeSort(Element Ls[],int p, int r){
	if (p<r){
		int q = p+(r-p)/2;
		Element Ls1[q-p+1],Ls2[r-q];
		for(int i=0;i<q-p+1;i++){
			Ls1[i]=Ls[i];
		}
		for(int j=0;j<r-q;j++){
			Ls2[j]=Ls[q-p+1+j];
		}
		mergeSort(Ls1, p,q);
		mergeSort(Ls2,q+1,r);
		merge(Ls1,q-p+1,Ls2,r-q,Ls);
	}

}

void iterMergeSort(Element Ls[],int p, int r){
	
	int size = r-p+1;
	for (int current_size=1 ; current_size<=size/2 ; current_size*=2){
		
		Element Ls1[current_size];
		Element Ls2[current_size];
		Element Ls3[current_size*2];
		
		int k=0;
		while(k<size){
			for(int i=0;i<current_size;i++){
				Ls1[i]=Ls[k];
				k++;
			}
			for(int j=0;j<current_size;j++){
				Ls2[j]=Ls[k];
				k++;
			}
			merge(Ls1,current_size,Ls2,current_size,Ls3);
			for(int i=k-1,j=current_size*2-1;i>k-1-current_size*2;i--,j--){
				Ls[i] = Ls3[j];
			}

		}
	
	}


}




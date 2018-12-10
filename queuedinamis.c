#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	int noMeja;
	char namaPemesan[100];
	int noPesanan;
	char pesanan[100];
}pengunjung;

//mendeklarasikan struktur elemen
typedef struct elm *alamatelmt;

typedef struct elm{
	pengunjung elmt;
	alamatelmt next;
}elemen;

//mendeklarasikan queue
typedef struct{
	elemen *first;
	elemen *last;
}queue;

void createEmpty(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;
}

int isEmpty(queue Q){
	int hasil = 0;
	if(Q.first == NULL){
		hasil= 1;
	}
	
	return hasil;
}

int countElement(queue Q){
	int hasil=0;
	
	if(Q.first!=NULL){
		elemen * elmt;
		elmt = Q.first;
		while(elmt!=NULL){
			hasil = hasil+1;
			elmt = elmt -> next;
		}
	}
	
	return hasil;
}

void add(int noMeja,char namaPemesan[],int noPesanan,char pesanan[] ,queue *Q){
	elemen *elmt;
 	elmt=(elemen *) malloc (sizeof(elemen));
 	
 	elmt->elmt.noMeja=noMeja;
 	strcpy(elmt->elmt.namaPemesan,namaPemesan);
 	elmt->elmt.noPesanan=noPesanan;
 	strcpy(elmt->elmt.pesanan,pesanan);
 	elmt->next=NULL;
 	if((*Q).first==NULL){
  		(*Q).first=elmt;
	}else{
  		(*Q).last->next=elmt;
	}
	(*Q).last=elmt;
 	elmt=NULL;
}

void del(queue *Q){
	if((*Q).first != 0){
  		elemen *elmt =(*Q).first;
  		(*Q).first=(*Q).first->next;
  		elmt->next=NULL;
  		free(elmt);
 	}
}

void printQueue(queue Q){
 	if(Q.first!=NULL){
  		printf("==========ISI QUEUE==========\n");
  		elemen *elmt=Q.first;
  		int i=1;
  		while(elmt !=NULL){
   		printf("=============================\n");
   		printf("Elemen ke-%d\n",i);
   		printf("No Meja : %d\n",elmt->elmt.noMeja);
   		printf("Nama Pemesan : %s\n",elmt->elmt.namaPemesan);
   		printf("No Pesanan : %d\n",elmt->elmt.noPesanan);
   		printf("Pesanan : %s\n",elmt->elmt.pesanan);
   		elmt=elmt->next;
   		i++;
  	}
   printf("=============================\n");
 	}else{
  		printf("kosong\n");
 	}
}

int main(){
 	queue Q;
 	createEmpty(&Q);
 	printf("=============================\n");
 	add(1,"Purnama",1,"Ayam Goreng",&Q);
 	add(2,"Yanrie",2,"Bakmi",&Q);
 	add(3,"Ramdan",3,"Mie Goreng",&Q);
 	printQueue(Q);
 	printf("=============================\n");
 	del(&Q);
 	del(&Q);
 	printQueue(Q);
 	printf("=============================\n");
 	
	return 0;
}

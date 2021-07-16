#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER 20

void * Media2(void * vett){

  float * vet2 = (float *) vett;
  float tot2=0;
  float media2;
  int i;

    for(i=BUFFER/2; i<BUFFER; i++){
        float m2;
        m2=vet2[i];
        tot2+=m2;
    }
   media2=tot2/(BUFFER/2);
   printf("Media2: %f\n", media2);
}



int main (void){

 pthread_t tid;
 float vet[BUFFER];
 int ris;
 float tot=0;
 float media1;
 int i;

   for(i=0;i<BUFFER;i++){
       vet[i]=rand()%10;
       printf("%f \n",vet[i]);
   }

//CREAZIONE THREAD
   ris = pthread_create(&tid ,NULL,Media2, (void*) vet);
   
   if(ris!= 0 ){
     fprintf(stderr,"ERRORE CREAZIONE THREAD");
     exit(EXIT_FAILURE);
   }

// JOIN SERVE A FAR ASPETTARE IL MAIN CHE IL THREAD CREATO FINISCA (metodo sincrono) E A PRENDERE IL VALORE RITORNATO DAL THREAD (attraverso il return(), o il pthread_exit((void *)) 
   ris=pthread_join(tid,NULL);

     if(ris!= 0 ){
       fprintf(stderr,"ERRORE CREAZIONE THREAD");
       exit(EXIT_FAILURE);
     }

    for(i=0;i<BUFFER/2;i++){
        float m;
        m=vet[i];
        tot+=m;
    }
  
   media1=tot/(BUFFER/2);
   printf("Media1: %f\n", media1);
   
   exit(EXIT_SUCCESS);
}

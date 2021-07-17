#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
const double N_t = 1;
#define tamanho 1000000000

void *criaThread(void *id);
double calcPi();

double calcPi(){

double pi ;
double rPi=4;

for(int i=0; i< tamanho; i++){

    rPi += (-1) *(4/(3+2*i));
}


if (N_t == 1) {
    
    return rPi; 
  }
  else if (N_t == 2) {
    pi = rPi/ 2;
    return pi ; 
  }
  return 0;
}

void *criaThread(void *id){
    long tid = (long) id;
    double calc = 0;
    
    printf("thread - %02ld sendo criada\n",tid);
   
    for(int i=0; i<N_t; i++){
        printf("calculando PI...\n");
        calc += calcPi();
    }
   printf("o calculo efetuado resultou em  \npi == %15lf, utilizando %02ld Threads\n", calc,tid);
    pthread_exit(NULL);
}


int main(int argc, char *argv[]){
    pthread_t thread ;
    long  status;
    int i = 1;
  

        if(N_t ==1){
        
            status = pthread_create(&thread,NULL, criaThread, (void *)i);
            
        }else if(N_t==2){
            
            while(i <= N_t){ 
            status = pthread_create(&thread,NULL, criaThread, (void *)i);
            i++;
            }
        }
        if(status) {
           perror("pthread_crate");
           exit(1);
       }
       
 
    
   //printf("soma para encontrar pi = %f\n",soma);
    pthread_exit(NULL);
     
}


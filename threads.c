#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdint.h>



int array[1000];

void * sumF(void *argu){
      int sum2=0;
      int start = (intptr_t)argu;
      int end=start+100;
      for(int i=start; i<end;i++){
        sum2=sum2+array[i];
      }

      return((void *)sum2);
}


int main(){

   int chunk=100;
   int sum1=0;
 
   for(int i=0;i<1000;i++){
    array[i]=i;
   }

   pthread_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
  
   int status_t1, status_t2,status_t3,status_t4, status_t5, status_t6, status_t7, status_t8,status_t9, status_t10; 
   
   pthread_create(&t1,NULL,sumF,(void*)(0*100));
   pthread_create(&t2,NULL,sumF,(void*)(1*100));
   pthread_create(&t3,NULL,sumF,(void*)(2*100));
   pthread_create(&t4,NULL,sumF,(void*)(3*100));
   pthread_create(&t5,NULL,sumF,(void*)(4*100));
   pthread_create(&t6,NULL,sumF,(void*)(5*100));
   pthread_create(&t7,NULL,sumF,(void*)(6*100));
   pthread_create(&t8,NULL,sumF,(void*)(7*100));
   pthread_create(&t9,NULL,sumF,(void*)(8*100));
   pthread_create(&t10,NULL,sumF,(void*)(9*100));

   pthread_join(t1, (void**) & status_t1);
   pthread_join(t2, (void**) & status_t2);
   pthread_join(t3, (void**) & status_t3);
   pthread_join(t4, (void**) & status_t4);
   pthread_join(t5, (void**) & status_t5);
   pthread_join(t6, (void**) & status_t6);
   pthread_join(t7, (void**) & status_t7);
   pthread_join(t8, (void**) & status_t8);
   pthread_join(t9, (void**) & status_t9);
   pthread_join(t10, (void**) & status_t10);

   
   sum1= status_t1+status_t2+status_t3+status_t4+status_t5+status_t6+status_t7+status_t8+status_t9+status_t10;

   printf("\n Sum of 1000 size array is:%d\n",sum1);
}



// Name: Ivan Martinez
// Compile: gcc -o proj-2-1.out proj-2-1.c -lpthread
// Execute: ./proj-2-1.out
/////////////////////////////////////////
/////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define NUM 9 // Must divide by 3
void *addThread(void *param);

int A[NUM] = {10, 20, 30, 40, 50, 60, 70, 80, 90}; // Must fill all array spots

int main()
{
        pthread_t tid[NUM/3];
        int i;
        for(i = 1; i < (NUM/3)+1;i++)
        {
                pthread_create(&tid[i-1],NULL,addThread,(void*)(intptr_t)i);
        }
        pthread_exit(NULL);
        return 0;

}

void *addThread(void *param)
{
        int c = (intptr_t)param;
        c = (c*3)-1;
        A[c] = A[c-2] + A[c-1] + A[c];
        if(c == NUM-1)
	{
                usleep(1); //Wait for last threads to finish
                int total = 0;
                for(int j = 2;j < NUM;j+=3)
                {
                        total += A[j];
                }
                printf("total sum  = %d\n",total);
        }
}

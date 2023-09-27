/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#include <iostream>
#include <cstdlib>
#include "scopelock.hpp" 
/*******Defines******/

#define NO_USE(A)  ((void)(A))
/*Excersice - */
#if 0

#endif

/*******Structs******/

typedef struct thread_data
{
    int id;
    int max_skip;
}thread_data_struct;

/*******Service Funcs******/

static void *FibonacciThread(void *thread_id);

/*******Funcs Funcs******/

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        std::cout << argv[0] << " <num threads> <number of skips>" << std::endl;
        return 1;
    } 

    int num_threads = atoi(argv[1]);
    thread_data_struct* thread_data = new thread_data_struct[num_threads];
    pthread_t* threadonaccis = new pthread_t[num_threads];
    int thread_id = 0, ret_code = 0;

    for (thread_id = 0; thread_id < num_threads; ++thread_id)
    {
        thread_data[thread_id].id = thread_id;
        thread_data[thread_id].max_skip = atoi(argv[2]);

        ret_code = pthread_create(&threadonaccis[thread_id], NULL,FibonacciThread,&thread_data[thread_id]);
        if(ret_code)
        {
            std::cout << thread_id << " <== thread_num; with return code " << ret_code << std::endl;
        }
    }

    for (thread_id = 0; thread_id < num_threads; thread_id++) 
    {
        ret_code = pthread_join(threadonaccis[thread_id], NULL);
        if (ret_code) {
            std::cout << "%d <thread_id> with return code %d" << thread_id << ret_code << std::endl;
            return 1;
        }
    }

    delete[] thread_data;
    delete[] threadonaccis;

    NO_USE(argc);
    NO_USE(argv);
    
    return 0;
}


void *FibonacciThread(void *thread_id)
{
    thread_data_struct * data = reinterpret_cast<thread_data_struct *>(thread_id);
    int i = 0, value = 0;

    Fibonacci fib;
    for (i = 0; i < data->max_skip ; ++i)
    {
        value = fib.NextNum();
        std::cout << "Thread " << data->id << " wrote " << value << " on step -> "<< i << std::endl;
        usleep(150);
    }

    pthread_exit(NULL);
}

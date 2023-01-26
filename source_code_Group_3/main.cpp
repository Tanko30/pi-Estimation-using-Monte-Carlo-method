/*********************************************************************************************
 *
 * [Authors]:(CCI, 2021) Group 3, [BAYA Ernest Kwame, BOUBAKAR Zourkalaini, JAWLA Haddy]
 * [Date]: Mon Jun 14, 2021 
 * [Goal]: Estimate pi value using Monte Carlo method through parallel programing with pthreads
 * [Version]: 1.4 (last version)
 * 
 * *******************************************************************************************/

#include <iostream>
#include <time.h>
#include <pthread.h>

double randDoubleGenerator(); // signautre of the random generator function (from helpers.cpp)
double isInsideCircle(double x, double y); // signature of the function that checks if a point is inside the circle

#define NUM_THREADS_MAX 8 // Maximum number of threads on this computer
#define npoints 1000000000 // total number of point inside the square

using namespace std;


/**************************************************************************************************************
 *     
 *  GOAL: compute the number of random point that fall in the circle. This computation is done by each thread
 *  RETURN: void
 * 
 * ************************************************************************************************************/
void* computeCircleCount(void *threadarg){
    long longThreadID;
    longThreadID = (long)threadarg;
    int threadID = (int)longThreadID; //convert thread id into integer value

    double *circle_count = (double*)malloc(sizeof(double)); //allocating memory for circle_count will avoid its destruction after eache iteration
    *circle_count = 0; //initialise its value to 0

    for (int i = 0; i < npoints/NUM_THREADS_MAX; i++)
    {
        double xcoordinate = randDoubleGenerator();
        double ycoordinate = randDoubleGenerator();

        if (isInsideCircle(xcoordinate, ycoordinate))
        {
            *circle_count += 1; //incremente circle_count if the point is inside the circle
        }
        

    }
    cout <<"[          "<<threadID<<"           ||"<<"  "<<*circle_count<<"          ]"<<endl;
    cout <<"================================================"<<endl;
    pthread_exit((void*)circle_count); // return circle_count value
     
}

int main(){
    
    pthread_t myThreads[NUM_THREADS_MAX]; //Table of pthread type elements
    int result;
    void *status;
    double total_circle_count = 0;
    double PI;

    //create threads and assignes computeCircleCount function to eache thread
    cout <<"================================================"<<endl;
    cout <<"[      THREAD ID       ||  Circle_count Values  ]"<<endl;
    cout <<"================================================"<<endl;
    for (long i = 0; i < NUM_THREADS_MAX; i++)
    {
        result = pthread_create(&myThreads[i], NULL, computeCircleCount, (void*)i);
        if (result)
        {
            cout <<"Error: unable to create thread, "<< result <<endl;
            exit(-1);
        }
        
    }
    //join the created threads
    for (int i = 0; i < NUM_THREADS_MAX; i++)
    {
        pthread_join(myThreads[i], &status);
        total_circle_count += *(double*)status; //compute total from eache circle_count
    }

    //print estimated pi value
    PI = 4*(total_circle_count/npoints);
    cout.precision(40);//to have 40 digits after the dot.
    cout <<"\nEstimated value, PI = "<< PI <<endl;

    pthread_exit(NULL);
    
    return 0;
}
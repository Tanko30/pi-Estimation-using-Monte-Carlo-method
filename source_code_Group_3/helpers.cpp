/***********************************************************************************************************************
 *
 * [Authors]:(CCI, 2021) Group 3, [BAYA Ernest Kwame, BOUBAKAR Zourkalaini, JAWLA Haddy]
 * [Date]: Mon Jun 14, 2021 
 * [Description]: contains the method to generate the random values and the one to check if a point is inside a circle
 * [Version]: 1.2 (last version)
 * 
 * ********************************************************************************************************************/
#include <stdlib.h>
#include <math.h>



/********************************************************************************************
 *     
 *  GOAL: Generates a random number between 0 and 1
 *  RETURN: returns the generated number
 * 
 * ******************************************************************************************/

double randDoubleGenerator(){
    double random_number = (double) rand(); // Generate a random nummer
    double unit_value = random_number / (double) RAND_MAX; //make it between 0 and 1
    return unit_value;
}

/*******************************************************************************************
 *  
 *  GOAL: checks if a point is inside a unit cercle
 *  RETURN: True if the point is inside othewise False
 * 
 * *****************************************************************************************/

double isInsideCircle(double x, double y){
    double distance = sqrt((x*x) + (y*y)); // Computer the distance point-origine
    if (distance <= 1)
    {
        return true;
    }
    return false;
    
}
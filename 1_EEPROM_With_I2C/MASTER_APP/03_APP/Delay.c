/*
 * Delay.c
 *
 * Created: 12/19/2023 3:08:16 AM
 *  Author: FatmaEzzat
 */ 
#include "../00_Lib/Delay.h"
/*
*@brief : The function satisfies a certain delay 
*@param : The delay time 
*@return: void
*/
void Delay(double time){
	long double N = (time * F_CPU)/200;
	long double i;
	for( i = 0 ;i < N ; i++);
}
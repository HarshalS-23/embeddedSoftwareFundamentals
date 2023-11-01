/******************************************************************************
 * Copyright (C) 2023 Harshal Sinkar
 *
 * Redistribution, modification or use of this software in source is allowed for
 * peers to grade this assignment.
 *
 ******************************************************************************
 * @file stats.c
 * @brief This file contains some user defined c functions which performs
 * basic statistical operation on array and main function.
 *
 * This file has print array(),fin_maximum(),find_minimum(),find_mean(),
 * find_median(),sort_array(),print_statistics() functions .
 *
 * @author <Harshal Sinkar>
 * @date 1-11-2023
 *
 */




#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
}

void print_array(int array[], int len)     /*FUNCTION WHICH WILL PRINT ARRAY*/

int find_maximum(int array[],int len)    /*FUNCTION WHICH WILL RETURN MAXIMUM ELEMENT*/

int find_minimum(int array[],int len)    /*FUNCTION WHICH WILL RETURN MINIMUM ELEMENT*/

void sort_array(int* array, int len)       /*FUNCTION WHICH WILL SORT THE ARRAY*/

double find_mean(int array[],int len)     /*FUNCTION WHICH WILL RETURN THE MEAN OF ELEMENTS OF ARRAY*/

double find_median(int array[], int len)      /*FUNCTION WHICH WILL RETURN MEDIAN OF ELEMENTS OF ARRAY*/

void print_statistics(int array[], int len)    /*FUNCTION WHICH WILL PRINT BASIC STATISTICAL INFORMATION ABOUT ARRAY*/


/*END*/



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

void print_array(int array[], int len){     /*FUNCTION WHICH PRINTS ARRAY*/
        for(int i=0;i<len;i++){
                printf(" %d ,",array[i]);
        }
        printf("\n");
}

int find_maximum(int array[],int len){     /*FUNCTION WHICH RETURNS MAXIMUM ELEMENT*/
  int  max = array[0];
  for(int i = 0;i<len;i++){
    if(array[i]>=max){
    max = array[i];
    }
  }
  return max;
}
int find_minimum(int array[],int len){     /*FUNCTION WHICH RETURNS MINIMUM ELEMENT*/
  int  min = array[0];
  for(int i = 0;i<len;i++){
    if(array[i] <= min){
    min = array[i];
    }
  }
  return min;
}
void sort_array(int* array, int len){       /*FUNCTION WHICH SORTS THE ARRAY*/
	int *current, *j;
	for(current=array+1;current<array+len;current++){
	int key = *current;
	for(j = current-1;j >= array && *j >key;j--){
		*(j+1) = *j;
	}
	*(j+1) = key;
  }
}
double find_mean(int array[],int len){     /*FUNCTION WHICH RETURNS THE MEAN OF ELEMENTS OF ARRAY*/
  int  sum = 0;
  for(int i = 0; i < len ;i++){
    sum += array[i];
  }
  double mean = (double)sum/len;
  return mean;
}
double find_median(int array[], int len){      /*FUNCTION WHICH RETURNS MEDIAN OF ELEMENTS OF ARRAY*/
	sort_array(array,len);
	if(len%2 == 0){
		return (array[len/2 - 1]+array[len/2])/2.0;
	}
	else{
		return array[(len-1)/2];
        }
}
void print_statistics(int array[], int len){     /*FUNCTION WHICH PRINTS BASIC STATISTICAL INFORMATION ABOUT ARRAY*/
	printf("The maximum element in the given array is : %d\n",find_maximum(array,len));
	printf("The minimum element in the given array is : %d\n",find_minimum(array,len));
	printf("The mean of  elements in the given array is : %lf\n",find_mean(array,len));
	printf("The median of the given array is : %lf\n",find_median(array,len));
}
void main() {

  unsigned int test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  printf("Unsorted array:"); print_array(test, SIZE);
  printf("sorted array:");
  sort_array(test,SIZE);
  print_array(test, SIZE);
  print_statistics(test,SIZE);
}


/*END*/



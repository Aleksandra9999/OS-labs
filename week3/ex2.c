#include <stdio.h>



int main(void) {

	
int len;

	
printf("¬ведите размер массива:\n");


	scanf("%d", &len);

	
int a[len];

	
printf("¬ведите массив:\n");


	for (int i = 0; i < len; i++)


		scanf("%d", &a[i]);


	bubblesort(a, len);


	for (int i = 0; i < len; i++)


		printf("%d ", a[i]);


	return 0;


}



void bubblesort(int arr[], int n)
 {


   int i, j;


   for (i = 0; i < n-1; i++)

   	for (j = 0; j < n-i-1; j++)

 
           if (arr[j] > arr[j+1]) {


           	int temp = arr[j];


            	arr[j] = arr[j+1];


            	arr[j+1] = temp;


           }


}

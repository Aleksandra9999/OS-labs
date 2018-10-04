#include <stdio.h>
#include <stdlib.h>

int main(){

	printf("Введите размер массива: \n");
	int N;
	scanf("%d", &N);
	int *arr = malloc(N * sizeof(int));
	int i;
	for (i = 0; i < N; i++){
		arr[i] = i;
		printf("%d ", arr[i]);
	}

	free(arr);
	return 0;
}
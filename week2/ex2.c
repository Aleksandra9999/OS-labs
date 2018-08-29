#include <stdio.h>


int main()

{
    
	char str[1000], str2[1000];

	scanf("%s", str);

	for(int i = 0; i < strlen(str); i++)

        	str2[i] = str[strlen(str)-i-1];

	puts(str2);

	return 0;

}
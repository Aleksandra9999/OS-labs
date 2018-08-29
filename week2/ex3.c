#include <stdio.h>
#include <math.h>
void pyramid(int n){
  
        int x,y;
        for (y= 1; y <= n; y++)
        {
            for (x= 0; x < n-y; x++)
                putchar(' ');
            for (x= 0; x < 2*y-1; x++)
                putchar('*');
            putchar('\n');
        }
        
    }

int main(int argc, char**argv) {
    int n;
    sscanf(argv[1], "%d ", &n);
    pyramid(n);
    
    return 0;
    
}
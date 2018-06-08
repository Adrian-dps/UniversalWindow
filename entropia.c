#include <stdio.h>
#include <string.h>
#include <ctype.h>
#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#endif
#include <math.h>
#include <stdlib.h>


double Log2( double n )  
{  
    // log(n)/log(2) is log2.  
    return log( n ) / log( 2 );  
}  

double calcularEntropia(unsigned char * array1, int tam)
{
    int n = tam;
    long    array[256];
    memset(array, 0, sizeof(array));
    long    size = 0;
    int     oc;
    int     cont = 0;
    while (cont < n) {
        oc = array1[cont];
        array[(unsigned char)oc]++;
        size++;
        cont++;
    }
    

    double  entropy = 0;
    int     i;
    
    //printf("%d",n);
    for (i = 0; i < 256; i++) {
        if (array[i] == 0)
            continue;
        double  p = 1.0 * array[i] / n;
        entropy += p * Log2 (1 / p);
    }

   
    //printf("La ENTROPIA del archivo es: %f [bits/byte]\n", entropy);
    return entropy;
}

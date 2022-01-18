//
// Created by xzh on 2022/1/18.
//

// crt_fseek.c
// This program opens the file FSEEK.OUT and
// moves the pointer to the file's beginning.

#include <stdio.h>

int main( void )
{
    FILE *stream;
    char line[91];
    int  result;
    stream= fopen( "fseek.out", "w+" );
    if (stream==NULL)
    {
        printf( "The file fseek.out was not opened\n" );
        return -1;
    }
    fprintf( stream, "The fseek begins here: "
                     "This is the file 'fseek.out'.\n" );
    result = fseek( stream, 0L, SEEK_SET);
    fprintf(stream,"abc");
    fputs("cdf",stream);
    if( result )
        perror( "Fseek failed" );
    else
    {
        printf( "File pointer is set to middle of first line.\n" );
        //大小只要足够大就行
        fgets( line, 90, stream );

        printf( "%s", line );
    }


    fclose( stream );
}
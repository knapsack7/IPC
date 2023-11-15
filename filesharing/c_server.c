#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>

/** define input buffer for below **/
#define BUFFER 4096

static const char* exFile = "ap.txt";
static char inputBuffer[ BUFFER ];

int main(int argc, const char** argv){
   FILE *fp = fopen(exFile,"r");
   /**
    * check and see if the pointer is null in otherwords 
    * see if the memory location refered to by fp is set...no 
    * memory location should be zero if you want to reference
    * it.  Here are some good ways to do this other than the 
    * way I did it below:
    *    if(!fp) {do error}
    *    if(fp == NULL) {do error}
    * and then there's the way I did it below:
    */
   if(fp == 0 )
   {
      fprintf(stderr,"Null pointer exception, check file name.\n");
      exit( EXIT_FAILURE );
   }

   //double check and see if an error occured during open
   const int err = ferror(fp);
   if(err != 0)
   {
      const char* errMessage = strcat("Something bad happened while opening file ",exFile);
      perror( errMessage );
      fclose( fp );
      exit( EXIT_FAILURE );
   }

   setbuf(fp,inputBuffer); //set a buffer for input

   uint64_t num = 0;
   uint64_t total = 0;
   uint64_t n = 0;

   /**
    *  test for eof, feof(*fp) - returns a boolean 1 (true) if at end of 
    *  file and  0 (false) otherwise
    */
   while( !feof( fp ) )
   {
      /**
       * fscanf returns the number of items it converted using the format
       * that PRIu64 macro (defined in stdint.h) represents, 
       * if it's not equal to 1 we don't want to continue
       */
      if( fscanf( fp,"%"PRIu64"", &num) != 1 )
      {
         /**
          * you could do a lot of stuff here as far as error 
          * handling but basically something bad has happened
          */
         break; 
      }
      printf("num : %d\n", num);
      total += num; //add to total the value at memory location num
      n++;
   }  

   const double average = (double) total / (double) n;
   //close the inputfile
   fclose(fp);

   //set outfile to FIFO name
   static const char* outFile = "temp";

   /**
    * open FIFO for writing, we'll skip the open check 
    * since we just opened it externally...for production
    * code you should check the return of fopen.
    */
   FILE *fp_out = fopen(outFile,"w");

   fprintf(fp_out,"%"PRIu64",%"PRIu64",%f\n",total,n,average);

   /** 
    * close output FIFO, this leaves the FIFO but closes the 
    * file pointer
    */
   fclose(fp_out);
   return( EXIT_SUCCESS );
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printarray(int* input, int* arraylength);
void swap(int input[], int i);
int mediancalc(int* len);
float meanvaluecalc(int input[], int* len);
int readfromfile(char filename[], int* inputstream, int* len);

int main() {

     char inputfile[9] = "input.txt";
     int* len = (int*) malloc(sizeof(int));
     *len = 0;
     int* inputstream = (int*) malloc(sizeof(int) * 100);
     if (readfromfile(inputfile, inputstream, len) == EXIT_FAILURE) {
         return EXIT_FAILURE;
      }	 

      int revcounter = 0, oordning = 0;

      do {
        int i = 0;
	revcounter = oordning;
	do {
 		if (inputstream[i+1] < inputstream[i]) {
                        oordning++;    /* vi hittade en till höger i arrayen som är mindre */
			swap(inputstream, i);
		}
        } while (i++ < len[0]-2);
      } while (oordning > revcounter ); // snurra runt tills det inte hittas några mindre till höger om elementet
      printarray(inputstream, len);

      if (len[0] > 0) {
        printf("Median värde: %d\n", inputstream[mediancalc(len)]); 
        printf("Medelvärde: %f\n", meanvaluecalc(inputstream, len));
      }
      free(inputstream);
      free(len);
}

void swap(int input[], int i) {
	input[i] = (input[i] * input[i+1]) / (input[i+1] = input[i]);  /* swap positions */
}

void printarray(int* input, int* arraylength) {
    int j;
    for (j = 0; j < *arraylength; j++) {
	    printf("Element[%d] = %d\n", j, input[j]);
    }
}

int mediancalc(int* len) {
      float fullmedian = len[0]/2.0;
      int integermedian = fullmedian;
      return ((fullmedian - integermedian) >= 0.5) ? integermedian + 1 : integermedian;  // if larger than 0.5 move to next     
}

float meanvaluecalc(int input[], int* len) {
	int i = 0;
	int meanvalue = 0;
	do {
		meanvalue += input[i];
	} while (i++ < len[0] - 1);
        return (float) meanvalue/len[0];
}


int readfromfile(char filename[], int* inputstream, int* len) {
        printf("Inputfil namn: %s\n", filename);
	FILE* integers = fopen(filename, "r");
	if (!integers) {
		fprintf(stderr, "File opening failed!\n");
		return EXIT_FAILURE;
	}
        int i = 0;
	while (fscanf(integers, "%d\n", inputstream++) > 0) {
                *len += 1;
	}

}












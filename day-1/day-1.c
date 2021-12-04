#include <stdio.h>
#include <stdlib.h>

#define MAX_READ_SIZE 512000

int main(int argc, char *argv[])
{
  FILE *challenge_input_file;
  challenge_input_file = fopen(argv[1], "r");  

  // check if it can read the file
  if (challenge_input_file == NULL) {
    printf("Error:\n");
    printf("Could not find the challenge input file?\n");
    exit(EXIT_FAILURE);
  }

  size_t ln = 0;
  int time_increased = 0, time_decreased = 0, previous_numb, amount_invalid_char = 0; 

  char currentline[8];
  while (fgets(currentline, sizeof(currentline), challenge_input_file) != NULL) {
    int currentnumber;
    char** invalid_chars = malloc(sizeof(char*) * 100);
    currentnumber = strtol(currentline, invalid_chars, 10);

    if (!previous_numb) {
      previous_numb = currentnumber;
      free(invalid_chars);
      continue;
    }
    if (currentnumber >= previous_numb)
      time_increased++;
    previous_numb = currentnumber;
    free(invalid_chars);
  }



  printf("Results:\n");
  printf("Increase count: %d\n", time_increased - amount_invalid_char);

  return 0; 
}
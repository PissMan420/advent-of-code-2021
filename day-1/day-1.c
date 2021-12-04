#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_READ_SIZE 512000

void
usage(char *argv[]);
bool
has_invalid_char(char **invalid_parts);

int
main(int argc, char *argv[])
{
  printf("%d\n", argc);
  if (argc < 4){
    usage(argv);
    exit(0);
  }

  char **part_arg_invalid_part = malloc(100 * sizeof(char*));
  int challenge_part = strtol(argv[3], part_arg_invalid_part, 10);
  // Check if there is any error parsing the argument
  if (has_invalid_char(part_arg_invalid_part)){
    printf("Invalid usage!\n");
    printf("Argument --part must be a number\n");
    usage(argv);
    exit(1);
  }
  FILE *challenge_input_file;
  challenge_input_file = fopen(argv[1], "r");  

  // check if it can read the file
  if (challenge_input_file == NULL) {
    printf("Error: did not provided an existing file at parameter 1\n");
    usage();
    exit(EXIT_FAILURE);
  }

  if (challenge_part == 1) {
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
  }

  printf("Increase count: %d\n", time_increased - amount_invalid_char);

  return 0; 
}

void
usage(char *argv[]) {
  printf("%s [input] --part [part]\n", argv[0]);
  printf("--part: the part of the challenge\n");
  printf("[input]: the puzzle input, eg: input.txt\n");
}

/**
 * @brief Helper function for `strtol` that verify if any error has occured while parsing a string
 * 
 * @param invalid_parts __endptr 
 * @return true 
 * @return false 
 */
bool
has_invalid_char(char **invalid_parts) {
  for (int partidx = 0; partidx < sizeof(invalid_parts); partidx++) {
    char *part = invalid_parts[partidx];
    if (!part)
      continue;
    if (strlen(part) > 0){
      return true;
    }
  }

  return false;
}
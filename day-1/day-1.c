#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

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
  int time_increased = 0, time_decreased = 0, previous_numb; 
  for (char *line; line = fgetln(challenge_input_file, &ln); ) {
    int number = atoi(line);
    if (!previous_numb) {
      previous_numb = number;
      continue;
    }
    if (previous_numb > number)
      time_increased++;
    else
      time_decreased++;

    previous_numb = number;
  }
  printf("Results:\n");
  printf("Increase count: %d\n", time_increased);
  printf("Decrease count: %d\n", time_decreased);
  return 0; 
}
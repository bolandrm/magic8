#include "eight.h"
#include <stdio.h>
#include <stddef.h>

int main() {
  eight_setup();



  printf("Testing without additional option: \n");

  eight_options opts;
  opts.has_additional_response = 0;
  opts.additional_response = "Yeah, right";

  for(int i = 0; i < 20; i++) {
    printf("\"%s\", ", eight_shake(&opts));
  }


  printf("\n\n");


  printf("Testing WITH additional option: \n");

  eight_options opts2;
  opts2.has_additional_response = 1;
  opts2.additional_response = "Not on my watch!";

  for(int i = 0; i < 20; i++) {
   printf("\"%s\", ", eight_shake(&opts2));
  }


  return 0;
}

#include "eight.h"
#include <stdio.h>
#include <stddef.h>

char *callback_funct() {
  return "Hello!";
}

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


  printf("\n\n");


  printf("Testing with callback option: \n");

  eight_options opts3;
  opts3.has_additional_response = 0;
  opts3.has_callback_response = 1;
  opts3.callback_response = callback_funct;

  for(int i = 0; i < 20; i++) {
   printf("\"%s\", ", eight_shake(&opts3));
  }

  return 0;
}

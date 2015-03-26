#include "eight.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static char *responses[] = {
  "It is certain",
  "It is decidedly so",
  "Without a doubt",
  "Yes definitely",
  "You may rely on it",
  "As I see it, yes",
  "Most likely",
  "Outlook good",
  "Yes",
  "Signs point to yes",
  "Reply hazy try again",
  "Ask again later",
  "Better not tell you now",
  "Cannot predict now",
  "Concentrate and ask again",
  "Don't count on it",
  "My reply is no",
  "My sources say no",
  "Outlook not so good",
  "Very doubtful"
};

void eight_setup() {
  srand(time(NULL));
}

char *eight_shake(eight_options *options) {
  if (options->has_additional_response) {
    int num = rand() % (NUM_STANDARD_RESPONSES + 1);

    if (num < NUM_STANDARD_RESPONSES) {
      return responses[num];
    } else {
      return options->additional_response;
    }

  } else if (options->has_callback_response) {
    int num = rand() % (NUM_STANDARD_RESPONSES + 1);

    if (num < NUM_STANDARD_RESPONSES) {
      return responses[num];
    } else {
      return options->callback_response();
    }

  } else {
    int num = rand() % NUM_STANDARD_RESPONSES;
    return responses[num];
  }
}

char *eight_quick_shake() {
  int num = rand() % NUM_STANDARD_RESPONSES;
  return responses[num];
}


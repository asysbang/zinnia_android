#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdbool.h>
#include "zinnia.h"

static const char *input =
  "(character (width 1000)(height 1000)"
  "(strokes ((243 273)(393 450))((700 253)(343 486)(280 716)(393 866)(710 880))))";

int main() {
  printf("=====main\n");
  zinnia_recognizer_t *recognizer = zinnia_recognizer_new();
  zinnia_character_t  *character  = zinnia_character_new();


  if (!zinnia_recognizer_open(recognizer, "/sdcard/handwriting-zh_CN.model")) {
    fprintf(stderr, "ERROR1: %s\n", zinnia_recognizer_strerror(recognizer));
    return -1;
  }

  if (!zinnia_character_parse(character, input)) {
    fprintf(stderr, "ERROR: %s %s\n", zinnia_character_strerror(character), input);
    return -1;
  }
  zinnia_result_t *result = zinnia_recognizer_classify(recognizer, character, 10);
  size_t i; 
  if (!result) {
    fprintf(stderr, "ERROR: %s %s\n", zinnia_recognizer_strerror(recognizer), input);
    return -1;
  }
  for (i = 0; i < zinnia_result_size(result); ++i) {
    fprintf(stdout, "====%s\t%f\n",
            zinnia_result_value(result, i),
            zinnia_result_score(result, i));
  }
  zinnia_result_destroy(result);

  zinnia_character_clear(character);

//汉字  “你”
  zinnia_character_set_width(character, 300);
  zinnia_character_set_height(character, 300);
zinnia_character_add(character, 0,87,45);
zinnia_character_add(character, 0,47,107);
zinnia_character_add(character, 1,81,92);
zinnia_character_add(character, 1,82,211);
zinnia_character_add(character, 2,157,26);
zinnia_character_add(character, 2,125,84);
zinnia_character_add(character, 3,150,158);
zinnia_character_add(character, 3,257,58);
zinnia_character_add(character, 3,242,102);
zinnia_character_add(character, 4,191,68);
zinnia_character_add(character, 4,191,217);
zinnia_character_add(character, 4,136,182);
zinnia_character_add(character, 5,155,110);
zinnia_character_add(character, 5,129,145);
zinnia_character_add(character, 6,215,120);
zinnia_character_add(character, 6,260,172);
   
  {
    zinnia_result_t *result = zinnia_recognizer_classify(recognizer, character, 10);
    size_t i;  
    if (!result) {
      fprintf(stderr, "%s\n", zinnia_recognizer_strerror(recognizer));
      return -1;
    }
    for (i = 0; i < zinnia_result_size(result); ++i) {
      fprintf(stdout, "---------%s\t%f\n",
              zinnia_result_value(result, i),
              zinnia_result_score(result, i));
    }
    zinnia_result_destroy(result);
  }

  zinnia_character_destroy(character);
  zinnia_recognizer_destroy(recognizer);

  return 0;
}

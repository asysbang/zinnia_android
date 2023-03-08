#include "android/log.h"
#include "zinnia.h"
#include <jni.h>
#include <string>

#define LOG_TAG    "zinnia"
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)


static const char *input =
        "(character (width 1000)(height 1000)"
        "(strokes ((243 273)(393 450))((700 253)(343 486)(280 716)(393 866)(710 880))))";

zinnia_recognizer_t *recognizer ;
zinnia_character_t  *character ;
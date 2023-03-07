#include <jni.h>
#include <string>
#include "native-lib.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_asysbang_zinnia_ZinniaHelper_stringFromJNI(JNIEnv *env, jobject thiz) {
    std::string hello = "Hello from zinnia C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_asysbang_zinnia_ZinniaHelper_createRecognizer(JNIEnv *env, jobject thiz) {
    LOGE("========create recognizer");
    recognizer = zinnia_recognizer_new();
    character = zinnia_character_new();
    zinnia_character_set_width(character, 300);
    zinnia_character_set_height(character, 300);

    if (!zinnia_recognizer_open(recognizer, "/sdcard/handwriting-zh_CN.model")) {
        fprintf(stderr, "ERROR1: %s\n", zinnia_recognizer_strerror(recognizer));
        LOGE("========%s", zinnia_recognizer_strerror(recognizer));
        return -1;
    }
    return 1;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_asysbang_zinnia_ZinniaHelper_addCharacterTest(JNIEnv *env, jobject thiz) {
    zinnia_character_add(character, 0, 97, 34);
    zinnia_character_add(character, 0, 92, 42);
    zinnia_character_add(character, 0, 86, 50);
    zinnia_character_add(character, 0, 78, 58);
    zinnia_character_add(character, 0, 71, 64);
    zinnia_character_add(character, 0, 67, 69);
    zinnia_character_add(character, 0, 60, 75);
    zinnia_character_add(character, 0, 54, 80);
    zinnia_character_add(character, 0, 48, 85);
    zinnia_character_add(character, 0, 41, 91);
    zinnia_character_add(character, 0, 35, 97);
    zinnia_character_add(character, 0, 30, 104);
    zinnia_character_add(character, 0, 29, 106);
    zinnia_character_add(character, 1, 66, 80);
    zinnia_character_add(character, 1, 66, 85);
    zinnia_character_add(character, 1, 66, 98);
    zinnia_character_add(character, 1, 66, 110);
    zinnia_character_add(character, 1, 66, 120);
    zinnia_character_add(character, 1, 67, 129);
    zinnia_character_add(character, 1, 67, 138);
    zinnia_character_add(character, 1, 68, 145);
    zinnia_character_add(character, 1, 68, 152);
    zinnia_character_add(character, 1, 68, 160);
    zinnia_character_add(character, 1, 68, 167);
    zinnia_character_add(character, 1, 68, 173);
    zinnia_character_add(character, 1, 68, 178);
    zinnia_character_add(character, 1, 69, 183);
    zinnia_character_add(character, 1, 69, 191);
    zinnia_character_add(character, 1, 69, 196);
    zinnia_character_add(character, 1, 69, 202);
    zinnia_character_add(character, 1, 70, 207);
    zinnia_character_add(character, 1, 70, 214);
    zinnia_character_add(character, 1, 71, 222);
    zinnia_character_add(character, 1, 71, 226);
    zinnia_character_add(character, 2, 144, 29);
    zinnia_character_add(character, 2, 138, 43);
    zinnia_character_add(character, 2, 130, 57);
    zinnia_character_add(character, 2, 124, 67);
    zinnia_character_add(character, 2, 122, 73);
    zinnia_character_add(character, 2, 117, 83);
    zinnia_character_add(character, 2, 114, 89);
    zinnia_character_add(character, 2, 112, 95);
    zinnia_character_add(character, 2, 111, 97);
    zinnia_character_add(character, 3, 137, 57);
    zinnia_character_add(character, 3, 142, 56);
    zinnia_character_add(character, 3, 152, 56);
    zinnia_character_add(character, 3, 169, 56);
    zinnia_character_add(character, 3, 187, 56);
    zinnia_character_add(character, 3, 198, 57);
    zinnia_character_add(character, 3, 204, 58);
    zinnia_character_add(character, 3, 210, 58);
    zinnia_character_add(character, 3, 216, 59);
    zinnia_character_add(character, 3, 224, 61);
    zinnia_character_add(character, 3, 231, 62);
    zinnia_character_add(character, 3, 230, 71);
    zinnia_character_add(character, 3, 227, 77);
    zinnia_character_add(character, 3, 224, 82);
    zinnia_character_add(character, 3, 220, 88);
    zinnia_character_add(character, 3, 217, 93);
    zinnia_character_add(character, 3, 215, 95);
    zinnia_character_add(character, 4, 178, 62);
    zinnia_character_add(character, 4, 178, 67);
    zinnia_character_add(character, 4, 178, 77);
    zinnia_character_add(character, 4, 179, 88);
    zinnia_character_add(character, 4, 179, 106);
    zinnia_character_add(character, 4, 179, 131);
    zinnia_character_add(character, 4, 178, 153);
    zinnia_character_add(character, 4, 178, 166);
    zinnia_character_add(character, 4, 177, 173);
    zinnia_character_add(character, 4, 177, 180);
    zinnia_character_add(character, 4, 176, 190);
    zinnia_character_add(character, 4, 176, 202);
    zinnia_character_add(character, 4, 176, 211);
    zinnia_character_add(character, 4, 176, 217);
    zinnia_character_add(character, 4, 176, 223);
    zinnia_character_add(character, 4, 175, 230);
    zinnia_character_add(character, 4, 166, 219);
    zinnia_character_add(character, 4, 160, 209);
    zinnia_character_add(character, 4, 156, 199);
    zinnia_character_add(character, 4, 152, 191);
    zinnia_character_add(character, 4, 149, 185);
    zinnia_character_add(character, 4, 149, 183);
    zinnia_character_add(character, 5, 143, 114);
    zinnia_character_add(character, 5, 139, 125);
    zinnia_character_add(character, 5, 134, 135);
    zinnia_character_add(character, 5, 128, 146);
    zinnia_character_add(character, 5, 124, 154);
    zinnia_character_add(character, 5, 121, 160);
    zinnia_character_add(character, 5, 119, 164);
    zinnia_character_add(character, 6, 198, 124);
    zinnia_character_add(character, 6, 204, 137);
    zinnia_character_add(character, 6, 210, 149);
    zinnia_character_add(character, 6, 214, 159);
    zinnia_character_add(character, 6, 217, 167);
    zinnia_character_add(character, 6, 219, 172);
    zinnia_character_add(character, 6, 221, 178);
    zinnia_character_add(character, 6, 224, 186);
    zinnia_character_add(character, 6, 224, 188);
    return -1;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_asysbang_zinnia_ZinniaHelper_addCharacter(JNIEnv *env, jobject thiz, jint index,
                                                   jint x_poi, jint y_poi) {
    zinnia_character_add(character, index, x_poi, y_poi);
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_asysbang_zinnia_ZinniaHelper_destroyRecognizer(JNIEnv *env, jobject thiz) {
    zinnia_character_destroy(character);
    zinnia_recognizer_destroy(recognizer);
    return 1;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_asysbang_zinnia_ZinniaHelper_getResult(JNIEnv *env, jobject thiz) {
    zinnia_result_t *result = zinnia_recognizer_classify(recognizer, character, 10);
    size_t i;
    if (!result) {
        LOGE("=====getresult error===%s\t%f", zinnia_recognizer_strerror(recognizer));
        fprintf(stderr, "%s\n", zinnia_recognizer_strerror(recognizer));
        return -1;
    }
    //LOGE("=====getresult size===%s\t%f", zinnia_result_size(result));
    for (i = 0; i < zinnia_result_size(result); ++i) {
        LOGE("========%s\t%f", zinnia_result_value(result, i), zinnia_result_score(result, i));
        fprintf(stdout, "---------%s\t%f\n",
                zinnia_result_value(result, i),
                zinnia_result_score(result, i));
    }
    zinnia_result_destroy(result);
    zinnia_character_clear(character);
    return 1;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_asysbang_zinnia_ZinniaHelper_addCharacterTest1(JNIEnv *env, jobject thiz) {
    zinnia_character_add(character, 0, 97, 34);
    zinnia_character_add(character, 0, 92, 42);
    zinnia_character_add(character, 0, 86, 50);
    zinnia_character_add(character, 0, 78, 58);
    zinnia_character_add(character, 0, 71, 64);
    zinnia_character_add(character, 0, 67, 69);
    zinnia_character_add(character, 0, 60, 75);
    zinnia_character_add(character, 0, 54, 80);
    zinnia_character_add(character, 0, 48, 85);
    zinnia_character_add(character, 0, 41, 91);
    zinnia_character_add(character, 0, 35, 97);
    zinnia_character_add(character, 0, 30, 104);
    zinnia_character_add(character, 0, 29, 106);
    zinnia_character_add(character, 1, 66, 80);
    zinnia_character_add(character, 1, 66, 85);
    zinnia_character_add(character, 1, 66, 98);
    zinnia_character_add(character, 1, 66, 110);
    zinnia_character_add(character, 1, 66, 120);
    zinnia_character_add(character, 1, 67, 129);
    zinnia_character_add(character, 1, 67, 138);
    zinnia_character_add(character, 1, 68, 145);
    zinnia_character_add(character, 1, 68, 152);
    zinnia_character_add(character, 1, 68, 160);
    zinnia_character_add(character, 1, 68, 167);
    zinnia_character_add(character, 1, 68, 173);
    zinnia_character_add(character, 1, 68, 178);
    zinnia_character_add(character, 1, 69, 183);
    zinnia_character_add(character, 1, 69, 191);
    zinnia_character_add(character, 1, 69, 196);
    zinnia_character_add(character, 1, 69, 202);
    zinnia_character_add(character, 1, 70, 207);
    zinnia_character_add(character, 1, 70, 214);
    zinnia_character_add(character, 1, 71, 222);
    zinnia_character_add(character, 1, 71, 226);
    zinnia_character_add(character, 2, 144, 29);
    zinnia_character_add(character, 2, 138, 43);
    zinnia_character_add(character, 2, 130, 57);
    zinnia_character_add(character, 2, 124, 67);
    zinnia_character_add(character, 2, 122, 73);
    zinnia_character_add(character, 2, 117, 83);
    zinnia_character_add(character, 2, 114, 89);
    zinnia_character_add(character, 2, 112, 95);
    zinnia_character_add(character, 2, 111, 97);
    zinnia_character_add(character, 3, 137, 57);
    zinnia_character_add(character, 3, 142, 56);
    zinnia_character_add(character, 3, 152, 56);
    zinnia_character_add(character, 3, 169, 56);
    zinnia_character_add(character, 3, 187, 56);
    zinnia_character_add(character, 3, 198, 57);
    zinnia_character_add(character, 3, 204, 58);
    zinnia_character_add(character, 3, 210, 58);
    zinnia_character_add(character, 3, 216, 59);
    zinnia_character_add(character, 3, 224, 61);
    zinnia_character_add(character, 3, 231, 62);
    zinnia_character_add(character, 3, 230, 71);
    zinnia_character_add(character, 3, 227, 77);
    zinnia_character_add(character, 3, 224, 82);
    zinnia_character_add(character, 3, 220, 88);
    zinnia_character_add(character, 3, 217, 93);
    zinnia_character_add(character, 3, 215, 95);
    zinnia_character_add(character, 4, 178, 62);
    zinnia_character_add(character, 4, 178, 67);
    zinnia_character_add(character, 4, 178, 77);
    zinnia_character_add(character, 4, 179, 88);
    zinnia_character_add(character, 4, 179, 106);
    zinnia_character_add(character, 4, 179, 131);
    zinnia_character_add(character, 4, 178, 153);
    zinnia_character_add(character, 4, 178, 166);
    zinnia_character_add(character, 4, 177, 173);
    zinnia_character_add(character, 4, 177, 180);
    zinnia_character_add(character, 4, 176, 190);
    zinnia_character_add(character, 4, 176, 202);
    zinnia_character_add(character, 4, 176, 211);
    zinnia_character_add(character, 4, 176, 217);
    zinnia_character_add(character, 4, 176, 223);
    zinnia_character_add(character, 4, 175, 230);
    zinnia_character_add(character, 4, 166, 219);
    zinnia_character_add(character, 4, 160, 209);
    zinnia_character_add(character, 4, 156, 199);
    zinnia_character_add(character, 4, 152, 191);
    zinnia_character_add(character, 4, 149, 185);
    zinnia_character_add(character, 4, 149, 183);
    zinnia_character_add(character, 5, 143, 114);
    zinnia_character_add(character, 5, 139, 125);
    zinnia_character_add(character, 5, 134, 135);
    zinnia_character_add(character, 5, 128, 146);
    zinnia_character_add(character, 5, 124, 154);
    zinnia_character_add(character, 5, 121, 160);
    zinnia_character_add(character, 5, 119, 164);
    zinnia_character_add(character, 6, 198, 124);
    zinnia_character_add(character, 6, 204, 137);
    zinnia_character_add(character, 6, 210, 149);
    zinnia_character_add(character, 6, 214, 159);
    zinnia_character_add(character, 6, 217, 167);
    zinnia_character_add(character, 6, 219, 172);
    zinnia_character_add(character, 6, 221, 178);
    zinnia_character_add(character, 6, 224, 186);
    zinnia_character_add(character, 6, 224, 188);
    return -1;
}
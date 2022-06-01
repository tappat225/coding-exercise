#ifdef IFDEF_TEST_H
#define IFDEF_TEST_H

int ok();

inline int ok() {
    printf("ok\n");
    return 0;
}

#endif
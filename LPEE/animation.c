#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>
    #define sleep(x) Sleep(x)
#else
    #include <unistd.h>
    #define sleep(x) usleep(x*1000)
#endif

#define ANIMATION_TIME 32
#define SLEEP_TIME 200

void loadingAnimation() {
    char* spinner[8] = {"⣷", "⣯", "⣟", "⡿", "⢿", "⣻", "⣽", "⣾"};
    for(int i = 0; i < ANIMATION_TIME; i++) {
        printf("\r%s Loading...", spinner[i % 8]);
        fflush(stdout);
        sleep(SLEEP_TIME);
    }
    printf("\n");
}

int main() {
    loadingAnimation();
    return 0;
}

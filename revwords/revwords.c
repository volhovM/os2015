#include <helpers.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int BUFFER_SIZE = 4096;

int main() {
    int res;
    char buf[BUFFER_SIZE];
    int margin = 0;
    while (1) {
        int got = read_until(STDIN_FILENO, buf + margin, BUFFER_SIZE, ' ');
        if (got == -1) return -1;
        if (got == 0) {
            int j;
            for (j = 0; j < margin / 2; j++) {
                char temp = buf[margin - j - 1];
                buf[margin - j - 1] = buf[j];
                buf[j] = temp;
            }
            write_(STDOUT_FILENO, buf, margin);
            break;
        }
        int i;
        int last_mark = 0;
        for (i = margin; i < margin + got; i++) {
            if (buf[i] == ' ') {
                int tmpsize = i - last_mark;
                char currstr[tmpsize];
                memcpy(currstr, buf + last_mark, tmpsize);
                int j;
                for (j = 0; j < tmpsize / 2; j++) {
                    char temp = currstr[tmpsize - j - 1];
                    currstr[tmpsize - j - 1] = currstr[j];
                    currstr[j] = temp;
                }
                res = write_(STDOUT_FILENO, currstr, tmpsize);
                if (res == -1) return -1;
                res = write_(STDOUT_FILENO, " ", 1);
                if (res == -1) return -1;
                fflush(stdout);
                last_mark = i + 1;
            }
        }
        memmove(buf, buf + last_mark * sizeof (char), got + margin - last_mark + 1);
        margin = got + margin - last_mark;
    }
    return 0;
}

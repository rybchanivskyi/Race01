#include <unistd.h>

void mx_printchar(char c) {
    char* d = &c;

    write(1, d, 1);
    //std::cout<<c;
}
void printSpace(int x) {
    for (int j = 0; j < x; ++j) {
        mx_printchar(' ');
    }
}
void printline (int n) {
    mx_printchar('+');
    for (int i = 0; i < 2 * n ; ++i) {
        mx_printchar('-');
    }
    mx_printchar('+');
}
void dig1(int n, int i) {
    int space = n / 2 + 1 - i;

    printSpace(space);
    mx_printchar('/');
    printSpace(2 * n);
    mx_printchar('/');
    printSpace(i - 1);
    mx_printchar('|');

}
void mx_cube(int n) {
    if (n > 1) {
        int temp = n * 3 / 2 + 3;

        for (int i = 0; i < temp; ++i) {
            if (i == 0) {
                printSpace(n / 2 + 1);
                printline(n);
            }
            else if (i <= n / 2) {
                dig1(n, i);
            }
            else if ( i == n / 2 + 1) {
                printline(n);
                printSpace(n / 2);
                mx_printchar('|');
            }
            else if (i <= n + 1) {
                mx_printchar('|');
                printSpace(n * 2);
                mx_printchar('|');
                printSpace(n / 2);
                if (i == n + 1) {
                    mx_printchar('+');
                }
                else {
                    mx_printchar('|');
                }

            }
            else if (i < temp - 1) {
                mx_printchar('|');
                printSpace(n * 2);
                mx_printchar('|');
                printSpace(temp - i - 2);
                mx_printchar('/');
            }
            else if ( i == temp - 1) {
                printline(n);
            }
            mx_printchar('\n');
        }
    }
}
int main() {
    mx_cube(45);
    return 0;
}

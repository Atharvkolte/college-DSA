// in this we access terminal and perform some operation
// what we are doing we are is print previous value in variable and it is editable 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int main() {
    char buffer[100] = "DefaultValue"; // The value to edit
    int pos = strlen(buffer);
    char ch;

    // 1. Set terminal to "raw" mode to get keys immediately
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable buffering and automatic echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    printf("Edit value (Press Enter when done): %s", buffer);

    while (1) {
        ch = getchar();

        if (ch == '\n' || ch == '\r') { // Enter key
            break;
        } 
        else if (ch == 127 || ch == 8) { // Backspace key
            if (pos > 0) {
                pos--;
                buffer[pos] = '\0';
                printf("\b \b"); // Move back, print space, move back again
            }
        } 
        else if (pos < 99) { // Regular character
            buffer[pos++] = ch;
            buffer[pos] = '\0';
            putchar(ch);
        }
    }

    // 2. Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    printf("\nFinal Result: %s\n", buffer);
    return 0;
}

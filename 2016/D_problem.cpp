#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}


int charToNum(char c) {
    if (c == '+') return 0;
    if (c >= 'A' && c <= 'Z') return (c - 'A' + 1);
    if (c >= '0' && c <= '9') return (c - '0' + 27);
    return -1; 
}


char numToChar(int num) {
    if (num == 0) return '+';
    if (num >= 1 && num <= 26) return ('A' + num - 1);
    if (num >= 27 && num <= 36) return ('0' + num - 27);
    return ' '; 
}


void decryptMessage(char* message, int key) {
    int inverseKey = modInverse(key, 37);
    size_t len = strlen(message);
    for (size_t i = 0; i < len; i++) {
        int num = charToNum(message[i]);
        if (num >= 0) { 
            int originalNum = (inverseKey * num) % 37;
            message[i] = numToChar(originalNum);
        }
    }
}

int main() {
    int T, key;
    char message[71]; 

    scanf("%d", &T); 

    for(int i = 0; i < T; i++) {
        scanf("%d", &key); 
        scanf("%s", message); 

        decryptMessage(message, key);
        printf("%s\n", message);
    }

    return 0;
}
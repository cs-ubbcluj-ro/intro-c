#include <stdio.h>
#include <string.h>

void printTwoIntegerSum() {
    int m = 0;
    int n = 0;
    int sum = 0;
    printf("Input the first number: ");
    scanf("%d", &m);
    printf("Input the second number: ");
    scanf("%d", &n);
    sum = m + n;
    printf("The total is: %d.\n", sum);
}

char toUpperCase(const char c) {
    if (c >= 'a' && c <= 'z') {
        return (char) (c - 'a' + 'A');
    }

    return c;
}

void printGreeting() {
    constexpr int bufferLength = 50;
    char readingFormat[8];
    snprintf(readingFormat, sizeof(readingFormat), "%%%ds", bufferLength-1);

    char firstName[bufferLength];
    printf("Enter your first name, in lowercase: ");
    scanf(readingFormat, firstName);
    firstName[0] = toUpperCase(firstName[0]);

    char lastName[bufferLength];
    printf("Enter your lastName: ");
    scanf(readingFormat, lastName);
    lastName[0] = toUpperCase(lastName[0]);

    printf("Hello, %s %s! :)\n", firstName, lastName);
    printf("Your firstName contains %lu characters.\n", strlen(firstName));
}

void printSequenceSum() {
    int n;
    int sum = 0;
    int ok = 0;
    while (ok == 0) {
        scanf("%d", &n);
        if (n == 0) {
            printf("The sum of elements is: %d", sum);
            ok = 1;
        }
        sum = sum + n;
    }
}

void printLengthOfLongestSubsequenceWithEqualElements() {
    int n;
    printf("Input the length of the array: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("The longest subsequence of equal elements has size: %d", n);
        return;
    }

    int previousItem, currentItem, maxLength = 0, currentLength = 1;
    printf("Input the array: ");
    scanf("%d", &previousItem);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &currentItem);
        if (previousItem == currentItem) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1;
        }
        previousItem = currentItem;

    }
    printf("The longest subsequence of equal elements has size: %d", maxLength);
}

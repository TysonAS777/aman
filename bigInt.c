#ifndef BIGINT_H
#define BIGINT_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int sign; // 1 for positive, -1 for negative
} BigInteger;

// Function to initialize a BigInteger with a value
BigInteger* createBigInteger(const char* value);

// Function to destroy a BigInteger and free the memory
void destroyBigInteger(BigInteger* num);

// Function to add two BigIntegers
BigInteger* addBigIntegers(const BigInteger* num1, const BigInteger* num2);

// Function to subtract two BigIntegers
BigInteger* subtractBigIntegers(const BigInteger* num1, const BigInteger* num2);

// Function to multiply two BigIntegers
BigInteger* multiplyBigIntegers(const BigInteger* num1, const BigInteger* num2);

// Function to divide two BigIntegers
BigInteger* divideBigIntegers(const BigInteger* num1, const BigInteger* num2);

// Function to compare two BigIntegers
int compareBigIntegers(const BigInteger* num1, const BigInteger* num2);

// Function to print a BigInteger
void printBigInteger(const BigInteger* num);

#endif


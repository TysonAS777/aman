#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bigInt.h"

// Define functions for digit nodes
DigitNode* DigitNode_Init(int digit) {
    DigitNode* newNode = (DigitNode*)malloc(sizeof(DigitNode));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

// Function to add a digit at the beginning of a BigInt
void BigInt_AddDigit(BigInt* num, int digit) {
    DigitNode* newDigit = DigitNode_Init(digit);
    newDigit->next = num->head;
    num->head = newDigit;
}

BigInt* BigInt_Init(int sign, char* str) {
    // Implementation of initialization from a sign and string
}

BigInt* BigInt_Add(const BigInt* a, const BigInt* b) {
    // Implementation of addition
}

BigInt* BigInt_Subtract(const BigInt* a, const BigInt* b) {
    // Implementation of subtraction
}

BigInt* BigInt_Multiply(const BigInt* a, const BigInt* b) {
    // Implementation of multiplication
}

BigInt* BigInt_Divide(const BigInt* a, const BigInt* b) {
    // Implementation of division
}
void BigInt_AddDigit(BigInt* num, int digit) {
    DigitNode* newDigit = DigitNode_Init(digit);
    newDigit->next = num->head;
    num->head = newDigit;
} 

// Define functions for digit nodes
DigitNode* DigitNode_Init(int digit) {
    DigitNode* newNode = (DigitNode*)malloc(sizeof(DigitNode));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

// Function to add a digit at the beginning of a BigInt
void BigInt_AddDigit(BigInt* num, int digit) {
    DigitNode* newDigit = DigitNode_Init(digit);
    newDigit->next = num->head;
    num->head = newDigit;
}

BigInt* BigInt_Init(int sign, char* str) {
    // Implementation of initialization from a sign and string
}

BigInt* BigInt_Add(const BigInt* a, const BigInt* b) {
    // Implementation of addition
}

BigInt* BigInt_Subtract(const BigInt* a, const BigInt* b) {
    // Implementation of subtraction
}

BigInt* BigInt_Multiply(const BigInt* a, const BigInt* b) {
    // Implementation of multiplication
}

BigInt* BigInt_Divide(const BigInt* a, const BigInt* b) {
    // Implementation of division
}
void BigInt_AddDigit(BigInt* num, int digit) {
    DigitNode* newDigit = DigitNode_Init(digit);
    newDigit->next = num->head;
    num->head = newDigit;
} 


// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add two BigIntegers
BigInteger* addBigIntegers(const BigInteger* num1, const BigInteger* num2) {
    BigInteger* result = (BigInteger*)malloc(sizeof(BigInteger));
    result->head = NULL;
    result->sign = 1; // Initialize result as positive

    Node* p = num1->head;
    Node* q = num2->head;
    Node* current = NULL;
    Node* prev = NULL;
    int carry = 0;

    while (p || q) {
        int x = (p) ? p->data : 0;
        int y = (q) ? q->data : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        sum %= 10;

        current = createNode(sum);

        if (result->head == NULL) {
            result->head = current;
        } else {
            prev->next = current;
        }
        prev = current;

        if (p) p = p->next;
        if (q) q = q->next;
    }

    if (carry > 0) {
        current = createNode(carry);
        prev->next = current;
    }

    return result;
}


// Function to subtract two BigIntegers
BigInteger* subtractBigIntegers(const BigInteger* num1, const BigInteger* num2) {
    BigInteger* result = (BigInteger*)malloc(sizeof(BigInteger));
    result->head = NULL;
    result->sign = 1; // Initialize result as positive

    Node* p = num1->head;
    Node* q = num2->head;
    Node* current = NULL;
    Node* prev = NULL;
    int borrow = 0;

    while (p || q) {
        int x = (p) ? p->data : 0;
        int y = (q) ? q->data : 0;

        // Handle borrow
        x -= borrow;
        if (x < y) {
            x += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        int diff = x - y;

        current = createNode(diff);

        if (result->head == NULL) {
            result->head = current;
        } else {
            prev->next = current;
        }
        prev = current;

        if (p) p = p->next;
        if (q) q = q->next;
    }

    // Remove leading zeroes
    while (result->head && result->head->data == 0) {
        Node* temp = result->head;
        result->head = result->head->next;
        free(temp);
    }

    return result;
}


// Function to multiply two BigIntegers
BigInteger* multiplyBigIntegers(const BigInteger* num1, const BigInteger* num2) {
    int m = 0;  // Counter for the number of multiplication operations
    BigInteger* result = createBigInteger("0");

    Node* p = num1->head;
    while (p) {
        int x = p->data;
        Node* q = num2->head;
        BigInteger* temp = (BigInteger*)malloc(sizeof(BigInteger));
        temp->head = NULL;
        temp->sign = 1;

        // Multiply num2 with a single digit of num1
        for (int i = 0; i < m; i++) {
            Node* zero = createNode(0);
            zero->next = temp->head;
            temp->head = zero;
        }

        int carry = 0;
        while (q) {
            int y = q->data;
            int product = x * y + carry;
            carry = product / 10;
            int digit = product % 10;
            Node* newNode = createNode(digit);
            newNode->next = temp->head;
            temp->head = newNode;
            q = q->next;
        }
        if (carry > 0) {
            Node* newNode = createNode(carry);
            newNode->next = temp->head;
            temp->head = newNode;
        }

        // Add the temporary result to the final result
        BigInteger* tempResult = addBigIntegers(result, temp);
        destroyBigInteger(result);
        destroyBigInteger(temp);
        result = tempResult;

        m++;
        p = p->next;
    }

    return result;
}


// Helper function to compare two BigIntegers
int compareBigIntegers(const BigInteger* num1, const BigInteger* num2) {
    // Implement the comparison logic based on your data structure
    // Return 1 if num1 > num2, -1 if num1 < num2, and 0 if they are equal
    // This function is not included in the previous example but is necessary for division.
}

// Function to divide two BigIntegers
BigInteger* divideBigIntegers(const BigInteger* num1, const BigInteger* num2) {
    BigInteger* result = createBigInteger("0");
    BigInteger* remainder = createBigInteger("0");
    BigInteger* current = createBigInteger("0");

    Node* p = num1->head;

    while (p) {
        appendNode(current, p->data);  // Append one digit at a time from num1
        int cmp = compareBigIntegers(current, num2);

        if (cmp < 0) {
            appendNode(result, 0);
        } else if (cmp == 0) {
            appendNode(result, 1);
            resetBigInteger(current);
        } else {
            // Perform long division
            int quotient = 0;
            while (compareBigIntegers(current, num2) >= 0) {
                subtractBigIntegers(current, num2);
                quotient++;
            }
            appendNode(result, quotient);
        }
        p = p->next;
    }

    // Clean up
    destroyBigInteger(current);
    destroyBigInteger(remainder);

    return result;
}

int main() {
    // Example usage of addition
    BigInteger* num1 = createBigInteger("123456789");
    BigInteger* num2 = createBigInteger("987654321");

    BigInteger* sum = addBigIntegers(num1, num2);

    printf("Sum: ");
    printBigInteger(sum);
    
    BigInteger* num1 = createBigInteger("123458789");
    BigInteger* num2 = createBigInteger("987654321");
    BigInteger* difference = subtractBigIntegers(num1, num2);

    printf("Difference: ");
    printBigInteger(difference);
    
    BigInteger* num1 = createBigInteger("124356789");
    BigInteger* num2 = createBigInteger("987654321");
    BigInteger* product = multiplyBigIntegers(num1, num2);

    printf("Product: ");
    printBigInteger(product);
    
    BigInteger* num1 = createBigInteger("987654321");
    BigInteger* num2 = createBigInteger("12345");
    
    BigInteger* quotient = divideBigIntegers(num1, num2);

    printf("Quotient: ");
    printBigInteger(quotient);


    // Don't forget to free the memory allocated for the BigIntegers
    destroyBigInteger(num1);
    destroyBigInteger(num2);
    destroyBigInteger(sum);

    return 0;
}

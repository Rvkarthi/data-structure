#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for a polynomial
typedef struct Node {
    int coeff;        // Coefficient of the term
    int pow;          // Power of the term
    struct Node* next; // Pointer to the next term
} Node;

// Function to create a new node
Node* CreateNode(int coeff, int pow) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to add two polynomials
void AddPoly(Node* poly1, Node* poly2, Node** poly) {
    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 != NULL && (poly2 == NULL || poly1->pow > poly2->pow)) {
            *poly = CreateNode(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly2 != NULL && (poly1 == NULL || poly2->pow > poly1->pow)) {
            *poly = CreateNode(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            // Both powers are equal
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                *poly = CreateNode(sumCoeff, poly1->pow);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if (*poly) {
            poly = &((*poly)->next);
        }
    }
}

// Function to display a polynomial
void DisplayPoly(Node* poly) {
    while (poly != NULL) {
        printf("%d*x^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    // Creating first polynomial: 3x^3 + 5x^2 + 6
    Node* poly1 = CreateNode(3, 3);
    poly1->next = CreateNode(5, 2);
    poly1->next->next = CreateNode(6, 0);

    // Creating second polynomial: 4x^2 + 2x + 1
    Node* poly2 = CreateNode(4, 2);
    poly2->next = CreateNode(2, 1);
    poly2->next->next = CreateNode(1, 0);

    // Adding the two polynomials
    Node* poly = NULL;
    AddPoly(poly1, poly2, &poly);

    // Displaying the polynomials
    printf("First Polynomial: ");
    DisplayPoly(poly1);

    printf("Second Polynomial: ");
    DisplayPoly(poly2);

    printf("Resultant Polynomial: ");
    DisplayPoly(poly);

    return 0;
}

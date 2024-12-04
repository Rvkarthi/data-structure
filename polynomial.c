#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a polynomial
struct node {
    int coeff;         // Coefficient of the term
    int pow;           // Power of the term
    struct node* next; // Pointer to the next term
};

// Function to create a new node
struct node* createNode(int coeff, int pow) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to add two polynomials
void addPoly(struct node* poly1, struct node* poly2, struct node** poly) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            *poly = createNode(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly2->pow > poly1->pow) {
            *poly = createNode(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            // Both powers are equal
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                *poly = createNode(sumCoeff, poly1->pow);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if (*poly) {
            poly = &((*poly)->next);
        }
    }

    // Add remaining terms of poly1, if any
    while (poly1 != NULL) {
        *poly = createNode(poly1->coeff, poly1->pow);
        poly1 = poly1->next;
        poly = &((*poly)->next);
    }

    // Add remaining terms of poly2, if any
    while (poly2 != NULL) {
        *poly = createNode(poly2->coeff, poly2->pow);
        poly2 = poly2->next;
        poly = &((*poly)->next);
    }
}

// Function to display a polynomial
void displayPoly(struct node* poly) {
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
    struct node* poly1 = createNode(3, 3);
    poly1->next = createNode(5, 2);
    poly1->next->next = createNode(6, 0);

    // Creating second polynomial: 4x^2 + 2x + 1
    struct node* poly2 = createNode(4, 2);
    poly2->next = createNode(2, 1);
    poly2->next->next = createNode(1, 0);

    // Adding the two polynomials
    struct node* poly = NULL;
    addPoly(poly1, poly2, &poly);

    // Displaying the polynomials
    printf("First Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    printf("Resultant Polynomial: ");
    displayPoly(poly);

    return 0;
}

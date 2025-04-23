#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int age;                 // Ηλικία (>= 0)
    int cholesterol;         // Συνολική χοληστερίνη (π.χ. 200-280)
    int HDLcholesterol;      // HDL χοληστερίνη (π.χ. 40-60)
    int SystolicBP;          // Συστολική πίεση (π.χ. 120-160)
    int smoke_status;        // Καπνιστής (1 = ναι, 0 = όχι)
    int diabetes;            // Διαβήτης (1 = ναι, 0 = όχι)
};

// Συνάρτηση για την είσοδο δεδομένων από τον χρήστη
void getUserInput(struct Patient *patient) {
    printf("Enter Age (>= 0): ");
    scanf("%d", &patient->age);

    printf("Enter Total Cholesterol Level (200-280): ");
    scanf("%d", &patient->cholesterol);

    printf("Enter HDL Cholesterol Level (40-60): ");
    scanf("%d", &patient->HDLcholesterol);

    printf("Enter Systolic Blood Pressure (120-160): ");
    scanf("%d", &patient->SystolicBP);

    printf("Are you a smoker? (1 = Yes, 0 = No): ");
    scanf("%d", &patient->smoke_status);

    printf("Do you have diabetes? (1 = Yes, 0 = No): ");
    scanf("%d", &patient->diabetes);
}

int ageScore(struct Patient *patient) {
    if (patient->age > 70) {
        return 8;
    } else if (patient->age >= 60) {
        return 6;
    } else if (patient->age >= 50) {
        return 3;
    } else if (patient->age >= 40) {
        return 1;
    } else {
        printf("Invalid age choice\n");
        return 0;
    }
}

int Cholesterol(struct Patient *patient) {
    if (patient->age >= 70) {
        if (patient->cholesterol >= 280) return 3;
        else if (patient->cholesterol >= 240) return 2;
        else if (patient->cholesterol >= 200) return 1;
    } else if (patient->age >= 60) {
        if (patient->cholesterol >= 280) return 3;
        else if (patient->cholesterol >= 240) return 2;
        else if (patient->cholesterol >= 200) return 1;
    } else if (patient->age >= 50) {
        if (patient->cholesterol >= 280) return 3;
        else if (patient->cholesterol >= 240) return 2;
        else if (patient->cholesterol >= 200) return 1;
    } else if (patient->age >= 40) {
        if (patient->cholesterol >= 280) return 3;
        else if (patient->cholesterol >= 240) return 2;
        else if (patient->cholesterol >= 200) return 1;
    }
    return 0;
}

int HDL(struct Patient *patient) {
    if (patient->HDLcholesterol >= 60) {
        return -1;
    } else if (patient->HDLcholesterol >= 50) {
        return 0;
    } else if (patient->HDLcholesterol >= 40) {
        return 1;
    } else {
        return 1;
    }
}

int Systolic(struct Patient *patient) {
    if (patient->SystolicBP >= 160) {
        return 2;
    } else if (patient->SystolicBP >= 140) {
        return 1;
    } else if (patient->SystolicBP >= 120) {
        return 0;
    }
    return 0;
}

int calculateTotalScore(struct Patient *patient) {
    int totalScore = 0;
    totalScore += ageScore(patient);
    totalScore += Cholesterol(patient);
    totalScore += HDL(patient);
    totalScore += Systolic(patient);
    totalScore += patient->smoke_status ? 2 : 0;
    totalScore += patient->diabetes ? 2 : 0;
    return totalScore;
}

void displayRiskLevel(int score) {
    printf("Final score Framingham is: %d\n", score);
    if (score <= 4) {
        printf("Low risk\n");
    } else if (score >= 5 && score < 9) {
        printf("Medium risk\n");
    } else if (score >= 10 && score <= 14) {
        printf("Moderate high risk\n");
    } else {
        printf("High risk\n");
    }
}

int main() {
    struct Patient example;
    getUserInput(&example);

    int totalScore = calculateTotalScore(&example);
    displayRiskLevel(totalScore);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;
struct Patient {
    int id;
    string name;
    int age;
    string condition;
    string status;
};

Patient patients[100];
int patientCount = 0;
int nextId = 1;
void addPatient() {
    patients[patientCount].id = nextId++;
    cout << "Enter patient's name: ";
    cin >> patients[patientCount].name;

    cout << "Enter patient's age: ";
    cin >> patients[patientCount].age;

    cout << "Enter patient's condition: ";
    cin >> patients[patientCount].condition;

    cout << "Enter patient's status (e.g., Critical, Stable, Discharged): ";
    cin >> patients[patientCount].status;

    patientCount++;
    cout << "Patient added successfully with ID " << patients[patientCount - 1].id << "!\n";
}

void displayPatients() {
    cout << "List of Patients:\n";
    for (int i = 0; i < patientCount; i++) {
        cout << "ID: " << patients[i].id << ", Name: " << patients[i].name 
             << ", Age: " << patients[i].age << ", Condition: " << patients[i].condition 
             << ", Status: " << patients[i].status << "\n";
    }
}

void searchPatientById() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            cout << "ID: " << patients[i].id << ", Name: " << patients[i].name 
                 << ", Age: " << patients[i].age << ", Condition: " << patients[i].condition 
                 << ", Status: " << patients[i].status << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No patient found with the ID '" << id << "'\n";
    }
}

void searchPatientByCondition() {
    string condition;
    cout << "Enter condition to search: ";
    cin >> condition;

    bool found = false;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].condition == condition) {
            cout << "ID: " << patients[i].id << ", Name: " << patients[i].name 
                 << ", Age: " << patients[i].age << ", Condition: " << patients[i].condition 
                 << ", Status: " << patients[i].status << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No patient found with the condition '" << condition << "'\n";
    }
}

void countPatients() {
    cout << "Total number of patients: " << patientCount << "\n";
}

void deletePatient() {
    int id;
    cout << "Enter ID of the patient to delete: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            found = true;
            cout << "Patient with ID '" << id << "' deleted successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "No patient found with the ID '" << id << "'\n";
    }
}

void updatePatientCondition() {
    int id;
    cout << "Enter ID of the patient to update condition: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            cout << "Enter new condition for patient with ID '" << id << "': ";
            cin >> patients[i].condition;
            found = true;
            cout << "Condition updated successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "No patient found with the ID '" << id << "'\n";
    }
}

void checkPatientStatus() {
    int id;
    cout << "Enter ID of the patient to check status: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            cout << "Status of patient with ID '" << id << "': " << patients[i].status << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No patient found with the ID '" << id << "'\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nHospital Management System\n";
        cout << "1. Add New Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient by ID\n";
        cout << "4. Search Patient by Condition\n";
        cout << "5. Count Patients\n";
        cout << "6. Delete Patient\n";
        cout << "7. Update Patient Condition\n";
        cout << "8. Check Patient Status\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                searchPatientById();
                break;
            case 4:
                searchPatientByCondition();
                break;
            case 5:
                countPatients();
                break;
            case 6:
                deletePatient();
                break;
            case 7:
                updatePatientCondition();
                break;
            case 8:
                checkPatientStatus();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}

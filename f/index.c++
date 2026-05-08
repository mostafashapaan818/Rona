#include <iostream>
#include <string>

using namespace std;

int main() {
    // Constants and arrays to store student data
    const int MAX_STUDENTS = 100;
    string names[MAX_STUDENTS];
    float rawGrades[MAX_STUDENTS];
    float percentages[MAX_STUDENTS];
    
    int studentCount = 0; // Tracks the number of students currently in the database
    int choice;           // Stores the user's menu choice

    // Main program loop using do-while
    do {
        // Display the menu options
        cout << "\n--- Student Database Menu ---\n";
        cout << "1. Add student\n";
        cout << "2. Print all students\n";
        cout << "3. Search by raw grade\n";
        cout << "4. Search by name\n";
        cout << "5. Print passed students (percentage >= 50)\n";
        cout << "6. Print failed students (percentage < 50)\n";
        cout << "7. Edit a student's grades\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Clear the buffer to prevent infinite loop or skipping getline
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cin.ignore(10000, '\n');
        }

        switch (choice) {
            case 1: { // Add student
                if (studentCount >= MAX_STUDENTS) {
                    cout << "Database is full. Cannot add more students.\n";
                    break;
                }
                
                cout << "Enter student's full name: ";
                getline(cin, names[studentCount]);
                
                cout << "Enter raw grade: ";
                cin >> rawGrades[studentCount];
                
                cout << "Enter percentage grade: ";
                cin >> percentages[studentCount];
                
                studentCount++; // Increment the number of students
                cout << "Student added successfully!\n";
                break;
            }
            case 2: // Print all students
                if (studentCount == 0) {
                    cout << "No students in the database.\n";
                } else {
                    cout << "\n--- All Students ---\n";
                    for (int i = 0; i < studentCount; i++) {
                        cout << "Index: " << i 
                             << " | Name: " << names[i] 
                             << " | Raw Grade: " << rawGrades[i] 
                             << " | Percentage: " << percentages[i] << "%\n";
                    }
                }
                break;
            case 3: { // Search by raw grade
                float searchGrade;
                cout << "Enter raw grade to search: ";
                cin >> searchGrade;
                
                bool found = false;
                for (int i = 0; i < studentCount; i++) {
                    if (rawGrades[i] == searchGrade) {
                        cout << "Found - Index: " << i 
                             << " | Name: " << names[i] 
                             << " | Percentage: " << percentages[i] << "%\n";
                        found = true;
                    }
                }
                if (!found) cout << "No student found with that raw grade.\n";
                break;
            }
            case 4: { // Search by name
                string searchName;
                cout << "Enter name to search: ";
                getline(cin, searchName);
                
                bool found = false;
                for (int i = 0; i < studentCount; i++) {
                    if (names[i] == searchName) { // Exact match
                        cout << "Found - Index: " << i 
                             << " | Raw Grade: " << rawGrades[i] 
                             << " | Percentage: " << percentages[i] << "%\n";
                        found = true;
                    }
                }
                if (!found) cout << "No student found with that name.\n";
                break;
            }
            case 5: // Print passed students
                cout << "\n--- Passed Students ---\n";
                {
                    bool found = false;
                    for (int i = 0; i < studentCount; i++) {
                        if (percentages[i] >= 50.0) {
                            cout << "Index: " << i 
                                 << " | Name: " << names[i] 
                                 << " | Percentage: " << percentages[i] << "%\n";
                            found = true;
                        }
                    }
                    if (!found) cout << "No passed students found.\n";
                }
                break;
            case 6: // Print failed students
                cout << "\n--- Failed Students ---\n";
                {
                    bool found = false;
                    for (int i = 0; i < studentCount; i++) {
                        if (percentages[i] < 50.0) {
                            cout << "Index: " << i 
                                 << " | Name: " << names[i] 
                                 << " | Percentage: " << percentages[i] << "%\n";
                            found = true;
                        }
                    }
                    if (!found) cout << "No failed students found.\n";
                }
                break;
            case 7: { // Edit a student's grades
                if (studentCount == 0) {
                    cout << "No students available to edit.\n";
                    break;
                }
                
                // Display all students to let the user pick an index
                cout << "\n--- Select a student to edit ---\n";
                for (int i = 0; i < studentCount; i++) {
                    cout << i << ". " << names[i] << "\n";
                }
                
                int indexToEdit;
                cout << "Enter the student's index number: ";
                cin >> indexToEdit;
                
                // Validate index
                if (indexToEdit >= 0 && indexToEdit < studentCount) {
                    cout << "Editing grades for: " << names[indexToEdit] << "\n";
                    cout << "Enter new raw grade: ";
                    cin >> rawGrades[indexToEdit];
                    cout << "Enter new percentage: ";
                    cin >> percentages[indexToEdit];
                    cout << "Grades updated successfully!\n";
                } else {
                    cout << "Invalid index number.\n";
                }
                break;
            }
            case 0: // Exit program
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
#include "DoublyLinkedList.h"

void DisplayMenu() {
    cout << "-------Menu--------\n";
    cout << "1. Add Runs at the start\n";
    cout << "2. Add Runs at the end\n";
    cout << "3. Delete Scores\n";
    cout << "4. Display Scores in Forward Sequence.\n";
    cout << "5. Display Scores in Reverse Sequence.\n";
    cout << "6. Find Highest and Lowest Scores.\n";
    cout << "7. Exit\n";
}

int main() {
    DoublyLinkedList teamPerf;
    char choice;
    int runs, matchNumber;

    DisplayMenu();
    do {
        cout << "Choose an option (1-7): ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Enter match number and runs: ";
            cin >> matchNumber >> runs;
            teamPerf.addRunsAtStart(runs, matchNumber);
            break;
        case '2':
            cout << "Enter match number and runs: ";
            cin >> matchNumber >> runs;
            teamPerf.addRunsAtEnd(runs, matchNumber);
            break;
        case '3':
            cout << "Enter Scores to Delete: ";
            cin >> runs;
            teamPerf.deleteAllOccurrences(runs);
            break;
        case '4':
            teamPerf.displayScoresForward();
            break;
        case '5':
            teamPerf.displayScoresReverse();
            break;
        case '6':
            teamPerf.findHighestAndLowestScores();
            break;
        case '7':
            cout << "Exiting......";
            exit(0);
        default:
            cout << "Invalid Choice. Please Choose between (1-7)" << endl;
            break;
        }
    } while (choice != '7');
    return 0;
}

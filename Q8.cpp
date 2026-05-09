#include <iostream>
#include <vector>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

int main() {
    string name;

    // Take input from user
    cout << "Enter student name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "Please enter a valid name!" << endl;
        return 0;
    }

    // Store excuse templates in a vector
    vector<string> excuses = {
        "{name} couldn't complete the homework because the laptop updated for 5 hours.",
        "{name} was about to submit the assignment when the Wi-Fi stopped working.",
        "{name}'s dog accidentally deleted the entire project folder.",
        "{name} tried to study, but there was a sudden power cut all night.",
        "{name} forgot the notebook at home in a hurry.",
        "{name}'s system crashed right before saving the work.",
        "{name} was helping a friend and didn’t get time to finish the assignment.",
        "{name} got confused with the deadline date.",
        "{name} was not feeling well and had to rest the whole day.",
        "{name}'s keyboard stopped working in the middle of typing.",
        "{name} accidentally submitted the wrong file and is fixing it now."
    };

    // Seed random number generator (important for different output each run)
    srand(time(0));

    // Generate random index
    int index = rand() % excuses.size();

    // Select random excuse
    string selectedExcuse = excuses[index];

    // Replace {name} with actual name
    size_t pos = selectedExcuse.find("{name}");
    if (pos != string::npos) {
        selectedExcuse.replace(pos, 6, name);
    }

    // Print result
    cout << "\n📢 Generated Excuse:\n";
    cout << selectedExcuse << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

int main() {
    string name;

    // Ask user for name
    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "Bro at least enter a name 😭" << endl;
        return 0;
    }

    // Vector storing roast templates
    vector<string> roasts = {
        "{name}, you are proof that even evolution makes mistakes.",
        "{name}, if laziness were a sport, you'd come second... because you wouldn’t try enough to win.",
        "{name}, your brain is like a web browser... 100 tabs open and none of them working.",
        "{name}, you bring everyone so much joy... when you leave the room.",
        "{name}, you're not stupid, you just have bad luck thinking.",
        "{name}, I'd explain it to you, but I left my crayons at home.",
        "{name}, you're like a cloud... when you disappear, it's a beautiful day.",
        "{name}, even Google can't find your logic.",
        "{name}, you have something on your chin... no, the third one down.",
        "{name}, your secrets are always safe with me. I never even listen.",
        "{name}, you’re like a software bug... always appearing at the worst time."
    };

    // Seed random number generator (important for different output every time)
    srand(time(0));

    // Pick random roast
    int randomIndex = rand() % roasts.size();
    string selectedRoast = roasts[randomIndex];

    // Replace {name} with actual name
    size_t pos = selectedRoast.find("{name}");
    if (pos != string::npos) {
        selectedRoast.replace(pos, 6, name);
    }

    // Print final roast
    cout << "\n🔥 Your Roast 🔥\n";
    cout << selectedRoast << endl;

    return 0;
}

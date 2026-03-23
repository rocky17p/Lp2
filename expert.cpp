#include <iostream>
using namespace std;

int main() {
    int fever, cough, headache, cold;

    cout << "===== CITY HOSPITAL EXPERT SYSTEM =====\n";

    cout << "Do you have fever? (1-Yes / 0-No): ";
    cin >> fever;

    cout << "Do you have cough? (1-Yes / 0-No): ";
    cin >> cough;

    cout << "Do you have headache? (1-Yes / 0-No): ";
    cin >> headache;

    cout << "Do you have cold/runny nose? (1-Yes / 0-No): ";
    cin >> cold;

    cout << "\n--- RESULT ---\n";

    // 🔹 Conditions
    if (fever == 1 && cough == 1 && cold == 1) {
        cout << "Possible Illness: FLU\n";
        cout << "Advice: Take rest, drink warm fluids, consult doctor.\n";
    }
    else if (fever == 1 && headache == 1 && cough == 0) {
        cout << "Possible Illness: FEVER\n";
        cout << "Advice: Take paracetamol, rest, drink water.\n";
    }
    else if (cold == 1 && cough == 1 && fever == 0) {
        cout << "Possible Illness: COMMON COLD\n";
        cout << "Advice: Take steam, warm drinks, rest.\n";
    }
    else if (headache == 1 && fever == 0 && cough == 0) {
        cout << "Possible Illness: STRESS / HEADACHE\n";
        cout << "Advice: Take rest, reduce screen time.\n";
    }
    else {
        cout << "Condition unclear.\n";
        cout << "Advice: Please consult a doctor.\n";
    }

    return 0;
}

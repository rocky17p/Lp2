#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;

    cout << "===== CITY HOSPITAL CHATBOT =====\n";
    cout << "Type 'exit' to stop\n";

    while (true) {
        cout << "\nYou: ";
        getline(cin, input);

        // convert to lowercase (simple)
        for (int i = 0; i < input.length(); i++) {
            input[i] = tolower(input[i]);
        }

        if (input == "exit") {
            cout << "Bot: Thank you! Stay healthy 😊\n";
            break;
        }

        // 🔹 Doctor
        else if (input.find("doctor") != string::npos) {
            cout << "Bot: We have specialists like Cardiologist, Orthopedic, and General Physician.\n";
        }

        // 🔹 Appointment
        else if (input.find("appointment") != string::npos || input.find("book") != string::npos) {
            cout << "Bot: You can book appointment at reception or call 123-456-7890.\n";
        }

        // 🔹 Emergency
        else if (input.find("emergency") != string::npos) {
            cout << "Bot: Emergency services are available 24/7. Call 108 immediately.\n";
        }

        // 🔹 Timing
        else if (input.find("time") != string::npos || input.find("timing") != string::npos) {
            cout << "Bot: Hospital timings are 9 AM - 8 PM.\n";
        }

        // 🔹 Location
        else if (input.find("location") != string::npos || input.find("address") != string::npos) {
            cout << "Bot: City Hospital is near Main Square, Pune.\n";
        }

        // 🔹 Fees
        else if (input.find("fee") != string::npos || input.find("cost") != string::npos) {
            cout << "Bot: Consultation fee starts from Rs. 300.\n";
        }

        // 🔹 Default
        else {
            cout << "Bot: Sorry, I didn't understand. Please ask about doctors, appointment, emergency, etc.\n";
        }
    }

    return 0;
}

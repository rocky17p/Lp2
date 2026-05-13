#include <bits/stdc++.h>
using namespace std;

int getInput(string question) {
    int x;

    while (true) {
        cout << question;
        cin >> x;

        if (x >= 1 && x <= 5)
            return x;

        cout << "Enter value between 1 and 5\n";
    }
}

string getRating(double score) {
    if (score >= 90)
        return "Outstanding";
    else if (score >= 80)
        return "Excellent";
    else if (score >= 70)
        return "Very Good";
    else if (score >= 60)
        return "Good";
    else if (score >= 50)
        return "Average";
    else
        return "Needs Improvement";
}

int main() {
    cout << "EMPLOYEE PERFORMANCE EXPERT SYSTEM\n";

    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "\nEmployee " << i << endl;

        int productivity = getInput("Productivity (1-5): ");
        int quality = getInput("Quality of Work (1-5): ");
        int teamwork = getInput("Teamwork (1-5): ");
        int attendance = getInput("Attendance (1-5): ");
        int initiative = getInput("Initiative (1-5): ");

        double score =
            productivity * 0.30 +
            quality * 0.25 +
            teamwork * 0.20 +
            attendance * 0.15 +
            initiative * 0.10;

        score = score * 20;

        // Expert Rules
        if (attendance == 5)
            score += 3;

        if (teamwork <= 2)
            score -= 5;

        if (productivity >= 4 && quality >= 4)
            score += 5;

        if (initiative <= 2)
            score -= 3;

        if (score > 100)
            score = 100;

        if (score < 0)
            score = 0;

        cout << "\nFinal Score: " << score << "%\n";
        cout << "Rating: " << getRating(score) << endl;

        cout << "Advice: ";
        if (score >= 90)
            cout << "Promotion Recommended\n";
        else if (score >= 70)
            cout << "Eligible for Bonus\n";
        else if (score >= 50)
            cout << "Needs Improvement\n";
        else
            cout << "Training Required\n";
    }

    return 0;
}

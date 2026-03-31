#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

void DisplayMenu(string date, string the_day, int kills, int deaths, int hours, int minutes, float seconds, char yfnc, float KDA) {
    cout << "\n================================" << endl;
    cout << "          Display Menu          " << endl;
    cout << "================================" << endl;
    cout << "Date: " << date << endl;
    cout << "Day: " << the_day.substr(0, 3) << endl;
    cout << "Time: " << hours << ":" << minutes << ":" << fixed << setprecision(2) << seconds << endl;
    cout << "First Initial: " << yfnc << endl;
    cout << "Kills: " << kills << " | Deaths: " << deaths << endl;
    cout << "Your KDA: " << fixed << setprecision(2) << KDA << endl;
}

int main() {
    string date, the_day;
    int hours, minutes, kills, deaths, day, month, year;
    float seconds, KDA;
    char yfnc, s1, s2;
	ofstream outputFile("game_stats.txt");
    cout << "Enter the date (year / month / day): ";
    cin >> year >> s1 >> month >> s2 >> day;
    if (cin.fail()) {
        cout << "Error: Please use the format year / month / day" << endl;
        return 1;
    }
	if (month > 12 || day > 31) {
        cout << "Error: Invalid date format! Please restart." << endl;
        return 1;
    }
    cout << "Enter the day: ";
    cin >> the_day;
    cout << "Enter the time (hours minutes seconds): ";
    cin >> hours >> minutes >> seconds;
    if (hours > 24 || minutes > 60 || seconds > 60) {
        cout << "Error: Invalid time format! Please restart." << endl;
        return 1;
    }

  cin.ignore(100, '\n');
  cout << "Enter your first name character: ";
  cin >> ws; // Clear leading whitespace (so if someone clicked the space bar before entering the character, it won't be read as the character and the other lines won't abbear)
  cin.get(yfnc);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Kills: ";
    cin >> kills;
    cout << "Deaths: ";
    cin >> deaths;

    if (deaths > 0) {
        KDA = static_cast<float>(kills) / deaths;
    }
    else {
        KDA = static_cast<float>(kills);
    }
	date = to_string(year) + "/" + to_string(month) + "/" + to_string(day);
    DisplayMenu(date, the_day, kills, deaths, hours, minutes, seconds, yfnc, KDA);
    outputFile << "\n================================" << endl;
    outputFile << "          Display Menu          " << endl;
    outputFile << "================================" << endl;
    outputFile << "Date: " << date << endl;
    outputFile << "Day: " << the_day.substr(0, 3) << endl;
    outputFile << "Time: " << hours << ":" << minutes << ":" << fixed << setprecision(2) << seconds << endl;
    outputFile << "First Initial: " << yfnc << endl;
    outputFile << "Kills: " << kills << " | Deaths: " << deaths << endl;
    outputFile << "Your KDA: " << fixed << setprecision(2) << KDA << endl;
	outputFile.close();
    return 0;
}
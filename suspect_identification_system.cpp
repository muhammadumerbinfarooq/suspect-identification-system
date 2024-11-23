#include <iostream>
#include <string>
#include <vector>

struct Suspect {
    std::string name;
    int height;
    int weight;
    std::string hairColor;
    std::string eyeColor;
};

std::vector<Suspect> suspects = {
    {"John Doe", 180, 70, "Brown", "Blue"},
    {"Jane Doe", 160, 60, "Blonde", "Green"},
    // Add more suspects here...
};

void displaySuspects(const std::vector<Suspect>& suspects) {
    for (const auto& suspect : suspects) {
        std::cout << "Name: " << suspect.name << std::endl;
        std::cout << "Height: " << suspect.height << " cm" << std::endl;
        std::cout << "Weight: " << suspect.weight << " kg" << std::endl;
        std::cout << "Hair Color: " << suspect.hairColor << std::endl;
        std::cout << "Eye Color: " << suspect.eyeColor << std::endl;
        std::cout << std::endl;
    }
}

std::vector<Suspect> matchSuspects(const Suspect& input) {
    std::vector<Suspect> matchedSuspects;
    for (const auto& suspect : suspects) {
        if (suspect.height == input.height &&
            suspect.weight == input.weight &&
            suspect.hairColor == input.hairColor &&
            suspect.eyeColor == input.eyeColor) {
            matchedSuspects.push_back(suspect);
        }
    }
    return matchedSuspects;
}

int main() {
    Suspect input;
    std::cout << "Enter suspect characteristics:" << std::endl;
    std::cout << "Name: ";
    std::cin.ignore();
    std::getline(std::cin, input.name);
    std::cout << "Height (cm): ";
    std::cin >> input.height;
    std::cout << "Weight (kg): ";
    std::cin >> input.weight;
    std::cout << "Hair Color: ";
    std::cin.ignore();
    std::getline(std::cin, input.hairColor);
    std::cout << "Eye Color: ";
    std::getline(std::cin, input.eyeColor);

    std::vector<Suspect> matchedSuspects = matchSuspects(input);

    if (!matchedSuspects.empty()) {
        std::cout << "Matched Suspects:" << std::endl;
        displaySuspects(matchedSuspects);
    } else {
        std::cout << "No matched suspects found." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <map>

using namespace std;
const string findIntersection(const string& firstString, const string& secondString);
const void fillMapWithDigitsFromString(map<int, int>& directMap, const string& directString);


int main() {

	string firstInputString{};
	string secondInputString{};

	cout << "Enter fisrt string: ";
	getline(cin, firstInputString);

	cout << "Enter second string: ";
	getline(cin, secondInputString);

	cout << findIntersection(firstInputString, secondInputString);

	return 0;
}

const string findIntersection(const string& firstString, const string& secondString)
{
	if (firstString.empty() || secondString.empty()) {
		return "One or both strings if empty ";
	}

	string resultString{};
	
	map<int, int> intersectionCounter{};

	fillMapWithDigitsFromString(intersectionCounter, firstString);
	fillMapWithDigitsFromString(intersectionCounter, secondString);

	
	for (auto it : intersectionCounter) {
		if (it.second > 1) {
			resultString += (to_string(it.first) + ",");
		}
	}

	if (resultString.empty()) {
		return "there is no intersection";
	}

	resultString.pop_back();
	return resultString;
}

const void fillMapWithDigitsFromString(map<int, int>& directMap, const string& directString)
{
	string digitsBuffer{};

	for (size_t i = 0; i < directString.length(); i++) {
		while (isdigit(directString[i])) {
			digitsBuffer += directString[i++];
		}

		if (!digitsBuffer.empty()) {
			directMap[stoi(digitsBuffer)]++;
			digitsBuffer = "";
		}
	}
}


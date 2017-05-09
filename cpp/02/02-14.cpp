#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다." << endl;

	int count[26] = { 0, };
        int charCounter = 0;
    string lines;
    int endCharacter;
    do{
        endCharacter = 1;
        cin >> lines;

        if(lines.find(";") == string::npos) {
            for (auto iterator = begin(lines); iterator != end(lines); ++iterator) {
                transform(lines.begin(), lines.end(), lines.begin(), (int (*)(int))tolower); // transform to lowercase
                int index = *iterator - 97;
                count[index] += 1;
                charCounter += 1;
            }
        } else {
            for (int i = 0; i < lines.find(";"); i++) {
                transform(lines.begin(), lines.end(), lines.begin(), (int (*)(int))tolower); // transform to lowercase
                int index = lines[i] - 97;
                count[index] += 1;
                charCounter += 1;
            }
          endCharacter = 0;
        }
    }while(endCharacter);


	cout << "글의 총 길이: " << charCounter << endl;
	for (int alphabets = 0; alphabets < 26; alphabets++) {
		cout << (char)(alphabets + 97) << " (" << count[alphabets] << ")" << '\t' << ": ";
		for (int i = 0; i < count[alphabets]; i++) {
			cout << '*';
		}
		cout << endl;
	}

	return 0;
}

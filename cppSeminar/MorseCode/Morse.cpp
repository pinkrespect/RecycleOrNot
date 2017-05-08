// C++ 14 version
#include <iostream>
#include <locale>
#include <codecvt>
#include <regex>

using namespace std;

// Auto Type의 Variables로 만드는 이유는
// sregex_token_iterator() 같은 경우에는 Variable Type 이름이 너무 길어서임
// 너무너무너무너무너무나 길어서 그런 것임(정말 너무너무너무너무나의 글자수 보다 김)


auto text_into_morse(const string &input){
	auto output = string();

	auto regexp = regex(R"(\s+)"); // 정규 표현식(regualar expression): 스페이스바 여러개의 경우
	// 스페이스바 여러개는 어차피 모스부호에서 의미가 없음
	auto tokens = sregex_token_iterator(input.begin(), input.end(), regexp, -1);
	// tokens에 위에서 정한 regexp를 기준으로 자름(문장 처음부터 끝까지)
	// 여기서 iteratori 형식의 tokens가 반환이 됨
	const auto end = sregex_token_iterator();
	// 이 함수는 아무 인자가 없을 때 dereferenced한 end-of-sequence를 반환함 그래서 const임 	
	for (auto i = 0; tokens != end; ++tokens, ++i){
		if(i != 0){
			output += "   ";
		}// 한 단어를 다 바꾸면 스페이스바가 있기 때문에 스페이스바 3개를 더함

		auto token = tokens->str();
		// 현재 차례의 iterator tokens의 한글자를 string으로 바꿈
		auto j = 0;

		for (auto ch : token) {
			if ((j++) != 0) {
				output += " ";
			}
			// 첫 문자(ch)를 읽고 나서 그 다움 문자부터 스페이스바가 들어가야 하기 때문에
			// 처음 한번의 루프는 보내고 나중에 j++가 되어서 스페이스바가 1회 추가됨

			ch = toupper(ch);
			// 소문자인줄 모르고 대문자로 밑에껄 써버려서 소문자로 바꾸기 좀 그래서
			// 대문자로 바꾸게 만들어버림

			switch (ch) {
				case 'A': output += ".-"  ; break;
				case 'B': output += "-..."; break;
				case 'C': output += "-.-."; break;
				case 'D': output += "-.." ; break;
				case 'E': output += "."   ; break;
				case 'F': output += "..-."; break;
				case 'G': output += "--." ; break;
				case 'H': output += "...."; break;
				case 'I': output += ".."  ; break;
				case 'J': output += ".---"; break;
				case 'K': output += "-.-" ; break;
				case 'L': output += ".-.."; break;
				case 'M': output += "--"  ; break;
				case 'N': output += "-."  ; break;
				case 'O': output += "---" ; break;
				case 'P': output += ".--."; break;
				case 'Q': output += "--.-"; break;
				case 'R': output += ".-." ; break;
				case 'S': output += "..." ; break;
				case 'T': output += "-"   ; break;
				case 'U': output += "..-" ; break;
				case 'V': output += "...-"; break;
				case 'W': output += ".--" ; break;
				case 'X': output += "-..-"; break;
				case 'Y': output += "-.--"; break;
				case 'Z': output += "--.."; break;
				case '0': output += "-----"; break;
				case '1': output += ".----"; break;
				case '2': output += "..---"; break;
				case '3': output += "...--"; break;
				case '4': output += "....-"; break;
				case '5': output += "....."; break;
				case '6': output += "-...."; break;
				case '7': output += "--..."; break;
				case '8': output += "---.."; break;
				case '9': output += "----."; break;
				case '/': output += "-..-."; break;
				case '?': output += "..--.."; break;
				case ',': output += "--..--"; break;
				case '.': output += ".-.-.-"; break;
				case '+': output += ".-.-."; break;
				case '=': output += "-...-"; break;
			}
		}
		// 포룹이 끝나면 output(모스 부호화)가 끝나고 이걸 리턴
	}

	return output;

}

auto text_from_morse(const string& input) {
	// 이게 위에꺼랑 대다수는 같은데 달라진 부분만 주석 달것임
	auto output = string();


	auto regexp = regex("   ");
	// 아까는 정규식이 필요했지만 지금은 그냥 스페이스바 3개를 스페이스바 1개로 바꾸면 됨
	auto words = sregex_token_iterator(input.begin(), input.end(), regexp, -1);
	// 위에서 -1의 의미를 안적었는데 1은 regexp에 있는 단어만 추출하는거고
	// 이건 저걸 제외하고 추출한다는 뜻임
	const auto end = sregex_token_iterator();
	for (auto i = 0; words != end; ++words, ++i) {
		auto word = words->str();

		if (i != 0) {
			output += " ";
		}

		auto regexp = regex(" ");
		// 이제 위의 regexp에서 스페이스 세개짜리가 다 제외되고 추출되었으므로 쓸모가 없어서
		// regexp는 스페이스 한개만 찾게 바꿈
		auto chars = sregex_token_iterator(word.begin(), word.end(), regexp, -1);
		for (; chars != end; ++chars) {
			auto ch = chars->str();
			// compare() 함수가 사실 c 함수라서 다른 함수를 찾았으나 없어서
			// 울며 겨자먹기로 씀

			if (ch.compare(".-") == 0) { output +=          'A'; }
			else if (ch.compare("-...") == 0) { output +=   'B'; }
			else if (ch.compare("-.-.") == 0) { output +=   'C'; }
			else if (ch.compare("-..") == 0) { output +=    'D'; }
			else if (ch.compare(".") == 0) { output +=      'E'; }
			else if (ch.compare("..-.") == 0) { output +=   'F'; }
			else if (ch.compare("--.") == 0) { output +=    'G'; }
			else if (ch.compare("....") == 0) { output +=   'H'; }
			else if (ch.compare("..") == 0) { output +=     'I'; }
			else if (ch.compare(".---") == 0) { output +=   'J'; }
			else if (ch.compare("-.-") == 0) { output +=    'K'; }
			else if (ch.compare(".-..") == 0) { output +=   'L'; }
			else if (ch.compare("--") == 0) { output +=     'M'; }
			else if (ch.compare("-.") == 0) { output +=     'N'; }
			else if (ch.compare("---") == 0) { output +=    'O'; }
			else if (ch.compare(".--.") == 0) { output +=   'P'; }
			else if (ch.compare("--.-") == 0) { output +=   'Q'; }
			else if (ch.compare(".-.") == 0) { output +=    'R'; }
			else if (ch.compare("...") == 0) { output +=    'S'; }
			else if (ch.compare("-") == 0) { output +=      'T'; }
			else if (ch.compare("..-") == 0) { output +=    'U'; }
			else if (ch.compare("...-") == 0) { output +=   'V'; }
			else if (ch.compare(".--") == 0) { output +=    'W'; }
			else if (ch.compare("-..-") == 0) { output +=   'X'; }
			else if (ch.compare("-.--") == 0) { output +=   'Y'; }
			else if (ch.compare("--..") == 0) { output +=   'Z'; }
			else if (ch.compare("-----") == 0) { output +=  '0'; }
			else if (ch.compare(".----") == 0) { output +=  '1'; }
			else if (ch.compare("..---") == 0) { output +=  '2'; }
			else if (ch.compare("...--") == 0) { output +=  '3'; }
			else if (ch.compare("....-") == 0) { output +=  '4'; }
			else if (ch.compare(".....") == 0) { output +=  '5'; }
			else if (ch.compare("-....") == 0) { output +=  '6'; }
			else if (ch.compare("--...") == 0) { output +=  '7'; }
			else if (ch.compare("---..") == 0) { output +=  '8'; }
			else if (ch.compare("----.") == 0) { output +=  '9'; }
			else if (ch.compare("-..-.") == 0) { output +=  '/'; }
			else if (ch.compare("..--..") == 0) { output += '?'; }
			else if (ch.compare("--..--") == 0) { output += ','; }
			else if (ch.compare(".-.-.-") == 0) { output += '.'; }
			else if (ch.compare(".-.-.") == 0) { output +=  '+'; }
			else if (ch.compare("-...-") == 0) { output +=  '='; }
		}
	}
	
	return output;
}

int main() {
	cout << "모스 부호로 변환할 문장을 입력하세요. (영문)" << endl;

	auto input = string();
	cout << "> "<< flush;
	getline(cin, input);

	auto morse = text_into_morse(input);
	auto roundtrip = text_from_morse(morse);

	cout
		<< "모스 부호: " << morse << endl
		<< "왕복 결과: " << roundtrip << endl
		<< endl;
}

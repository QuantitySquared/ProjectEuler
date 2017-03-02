#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<int, std::string> numberToWord;
	std::map<int, std::string>::iterator it;

	int ones, tens, hundreds, thousands;
	int totalLetters = 0;
	int temp;
	std::string numString = "";


	numberToWord.insert(std::pair<int,std::string>(0, ""));
	numberToWord.insert(std::pair<int,std::string>(1, "one"));
	numberToWord.insert(std::pair<int,std::string>(2, "two"));
	numberToWord.insert(std::pair<int,std::string>(3, "three"));
	numberToWord.insert(std::pair<int,std::string>(4, "four"));
	numberToWord.insert(std::pair<int,std::string>(5, "five"));
	numberToWord.insert(std::pair<int,std::string>(6, "six"));
	numberToWord.insert(std::pair<int,std::string>(7, "seven"));
	numberToWord.insert(std::pair<int,std::string>(8, "eight"));
	numberToWord.insert(std::pair<int,std::string>(9, "nine"));
	numberToWord.insert(std::pair<int,std::string>(10, "ten"));
	numberToWord.insert(std::pair<int,std::string>(11, "eleven"));
	numberToWord.insert(std::pair<int,std::string>(12, "twelve"));
	numberToWord.insert(std::pair<int,std::string>(13, "thirteen"));
	numberToWord.insert(std::pair<int,std::string>(14, "fourteen"));
	numberToWord.insert(std::pair<int,std::string>(15, "fifteen"));
	numberToWord.insert(std::pair<int,std::string>(16, "sixteen"));
	numberToWord.insert(std::pair<int,std::string>(17, "seventeen"));
	numberToWord.insert(std::pair<int,std::string>(18, "eighteen"));
	numberToWord.insert(std::pair<int,std::string>(19, "nineteen"));
	numberToWord.insert(std::pair<int,std::string>(20, "twenty"));
	numberToWord.insert(std::pair<int,std::string>(30, "thirty"));
	numberToWord.insert(std::pair<int,std::string>(40, "forty"));
	numberToWord.insert(std::pair<int,std::string>(50, "fifty"));
	numberToWord.insert(std::pair<int,std::string>(60, "sixty"));
	numberToWord.insert(std::pair<int,std::string>(70, "seventy"));
	numberToWord.insert(std::pair<int,std::string>(80, "eighty"));
	numberToWord.insert(std::pair<int,std::string>(90, "ninety"));

	for(int i=1; i<=1000; i++) {
		temp = i;
		thousands=0;
		hundreds=0;
		tens=0;
		ones=0;

		if(temp>=1000){
			thousands = temp/1000;
			numString.append(numberToWord.find(thousands)->second);
			numString.append("thousand");
			temp%=1000;
		}
		if(temp>=100){
			hundreds = temp/100;
			numString.append(numberToWord.find(hundreds)->second);
			numString.append("hundred");
			if(temp%100!=0)
				numString.append("and");
			temp%=100;
		}
		if(temp>=20){
			tens = temp/10;
			tens *= 10;
			numString.append(numberToWord.find(tens)->second);
			numString.append(numberToWord.find(temp%10)->second);
		}
		else{
			numString.append(numberToWord.find(temp)->second);
		}

		std::cout << numString << std::endl; 

		totalLetters += numString.size();

		 
		numString.clear();

	}
	
	std::cout << totalLetters << std::endl;

	return 0;

}


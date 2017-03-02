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


	numberToWord[0]="";
	numberToWord[1]="one";
	numberToWord[2]="two";
	numberToWord[3]="three";
	numberToWord[4]="four";
	numberToWord[5]="five";
	numberToWord[6]="six";
	numberToWord[7]="seven";
	numberToWord[8]="eight";
	numberToWord[9]="nine";
	numberToWord[10]="ten";
	numberToWord[11]="eleven";
	numberToWord[12]="twelve";
	numberToWord[13]="thirteen";
	numberToWord[14]="fourteen";
	numberToWord[15]="fifteen";
	numberToWord[16]="sixteen";
	numberToWord[17]="seventeen";
	numberToWord[18]="eighteen";
	numberToWord[19]="nineteen";
	numberToWord[20]="twenty";
	numberToWord[30]="thirty";
	numberToWord[40]="forty";
	numberToWord[50]="fifty";
	numberToWord[60]="sixty";
	numberToWord[70]="seventy";
	numberToWord[80]="eighty";
	numberToWord[90]="ninety";

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


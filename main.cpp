
#include "main.h"

//this parameter is used when need to format string
#define FORMATTING

//predefined values of reservation for set
#define GB32_MEMORY 34359738368
#define GB16_MEMORY 17179869184
#define GB8_MEMORY 8589934592
#define GB4_MEMORY 4294967296
#define GB2_MEMORY 2147483648
#define GB1_MEMORY 1073741824 

using namespace std;

int main(int argc, char** argv) {
	
	cout<<"Please insert text"<<endl;
	string input;
	getInput(input);

	cout<<input<<" - here what you input"<<endl;
	
	#ifdef FORMATTING
	addSpacesWhereIsNeeded(input);
	ignoreDotsAndCommas(input);
	#endif
	
	unordered_set<string> s;
	
	//reserv memory for unordered set
	s.reserve(GB1_MEMORY);
	
	Extract(input, s);
	
	//change reserved bucket count for upcomming usage(if necessary)
	s.rehash(s.size());
	
	outputSet(s);

	
	//final check and cout used bucket in set
	cout<<"The number of distinct unique words: "<< s.size()<<endl;
	cout<<s.bucket_count()<<" - bucket count"<<endl;
	
	return 0;
}

void getInput(string &input){
	getline(cin, input);
}

void outputSet(unordered_set<string>& input2){
	cout<<"Here start set"<<endl;
	for(auto& x : input2)
	{
		cout<<x<<endl;	
	}
}

void Extract(string& Text, unordered_set<string>& out) {
	istringstream iss(Text);
    string word;

    while(iss >> word) {  
            out.insert(word);
        } 
}

void ignoreDotsAndCommas(string& input){	
	input.erase(remove_if(input.begin(), input.end(), \
	[](char c) { return c==','&& (*((&c+1)))==' '||c=='.'&& (*((&c+1)))==' '||c=='!'&& (*((&c+1)))==' '||c=='?'&& (*((&c+1)))==' '; }), input.end());
}

void addSpacesWhereIsNeeded(string& input){	
	replace_if(input.begin(), input.end(), \
	[](char c) { return c==','&& (*((&c+1)))!=' '||c=='.'&& (*((&c+1)))!=' '||c=='!'&& (*((&c+1)))!=' '||c=='?'&& (*((&c+1)))!=' '; }, ' ');
}



  

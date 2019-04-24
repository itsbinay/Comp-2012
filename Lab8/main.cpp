#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

// Check whether a character is an operator.
// You may use it if needed.
bool is_an_operator(char c){
	if(c == '(' || c == ')' || c == '+' || c =='-' || c =='*' || c =='/'){
		return true;
	}
	return false;
}

// Check for a given string whether it contains only digits.
// You may use it if needed.
bool is_digits(const std::string &str){
    return str.find_first_not_of("0123456789") == std::string::npos;
}

// TODO read numbers and operators from the parameter "formula"
vector<string> read_numbers_and_operators(string formula){
	vector<string> a;
	string c,d,e;
	for(int i=0;i<formula.size();i++){

			c=formula[i];
			d=formula[i+1];
			if(c!=" "&&d!=" "&&(i+1)!=formula.size()){
				e=c+d;
				a.push_back(e);
				i+=1;
			}
			else if(c!=" "){
				a.push_back(c);
			}

		}


	return a;

}

// TODO get the calculation result of the given expression
int get_result(vector<string> reverse_polish){
	double l, r;
	double ans;
	stack<double> a;
	string c;
	for(int i=0;i<reverse_polish.size();i++){
		c=reverse_polish[i];

		if(!is_an_operator(c[0])){

			a.push(atof(reverse_polish[i].c_str()));
			cout<<"push "<<a.top()<<" to the stack."<<endl;
		}
		else{
		r=a.top();
		cout<<"pop "<<a.top()<<" from the stack."<<endl;
		a.pop();
		l=a.top();
		cout<<"pop "<<a.top()<<" from the stack."<<endl;
		a.pop();

		if(reverse_polish[i]=="+"){
			ans=l+r;

			cout<<l<<"+"<<r<<"="<<ans<<endl;
		}
		else if(reverse_polish[i]=="-"){
			ans=l-r;
			cout<<l<<"-"<<r<<"="<<ans<<endl;
		}
		else if(reverse_polish[i]=="*"){
					ans=l*r;
					cout<<l<<"*"<<r<<"="<<ans<<endl;
		}
		else if(reverse_polish[i]=="/"){
					ans=l/r;
					cout<<l<<"/"<<r<<"="<<ans<<endl;
		}

		a.push(ans);

		cout<<"push "<<a.top()<<" to the stack."<<endl;
		}
	}
	return a.top();
}


// Calculate the result for a given expression represented in reverse polish notation
void calculation_result(string formula){
	// Transfer the formula to the format of Reverse Polish Notation
	vector<string> reverse_polish = read_numbers_and_operators(formula);

	for(int i=0; i<reverse_polish.size(); i++){
		cout << reverse_polish[i] << " ";
	}
	cout << endl;
	int result = get_result(reverse_polish);
	cout << "Result: " << result << endl;
}

int main(){
	string formula1 = "9 3 1 - 3 * 10 2 / + +";
	calculation_result(formula1);
	cout << "===========" << endl;
	string formula2 = "5 1 2 + 4 * + 3 -";
	calculation_result(formula2);
	return 0;
}

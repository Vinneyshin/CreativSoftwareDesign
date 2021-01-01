#include "point2d.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<Point> pointVec;
	pointVec.clear();
	
	while(true) {
		string command;
		getline(cin, command);
		
		if(command == "quit") break;
		else if(command.find("set") != string::npos) {
			string* argv = new string[command.length()];
			int argc = 0;
			command.erase(0,4);
			size_t pos;
			while(true) {
				pos = command.find(" ");
				*&*&*&*&*&*&argv[argc++] = command.substr(0,pos);

				
				if(pos >= command.length()) break;
				else command.erase(0,pos+1);
			}
			
			for(int i=0;i<pointVec.size();i++) {
				if(argv[0] == pointVec[i].string_) {
					pointVec.erase(pointVec.begin()+i);
					i--;
				}
			}
			Point point_(argv[0],atoi(argv[1].c_str()),atoi(argv[2].c_str()));
			pointVec.push_back(point_);
		}
		else if(command.find("eval") != string::npos) {
			string* argv = new string[command.length()];
			int argc = 0, operation;
			
			bool minusState = false;
			command.erase(0,5);
			size_t pos;
			
			while(true) {
				pos = command.find(" ");
				argv[argc++] = command.substr(0,pos);
				
				if(pos >= command.length()) break;
				else command.erase(0,pos+1);
			}
			
			Point lhs_, rhs_, eva;
			
			for(int i=0;i<argc;i++) {
				string arg = argv[i];
				
				if(isdigit(arg[arg.length() - 1]) && (lhs_.string_.size() == 0)) {
					Point lhs(atoi(arg.c_str()));
					lhs_ = lhs;
				}
				else if(isdigit(arg[arg.length() - 1]) && (lhs_.string_.size() != 0)) {
					Point rhs(atoi(arg.c_str()));
					rhs_ = rhs;
				}
				else if(arg == "+") operation = PLUS;
				else if(arg == "-") operation = MINUS;
				else if(arg == "*") operation = MULTI;
				else if(lhs_.string_.size() == 0) {
					if(arg.find("-") != string::npos) {
						minusState = true;
						arg.erase(0,1);
					}
					for(int j=0;j<pointVec.size();j++) {
						if(arg == pointVec[i].string_) {
							lhs_ = pointVec[i];
							break;
						}
						if(j==pointVec.size()-1) arg = ".";
					}
					if(pointVec.size()==0) arg = ".";
					if(minusState == true) {
						lhs_ = lhs_ - lhs_ - lhs_;
						minusState = false;
					}
					
				}
				else if(lhs_.string_.size() != 0) {
					if(arg.find("-") != string::npos) {
						minusState = true;
						arg.erase(0,1);
					}
					for(int j=0;j<pointVec.size();j++) {
						if(arg == pointVec[j].string_) {
							rhs_ = pointVec[j];
							break; 
						}
						if(j==pointVec.size()-1) arg = ".";
					}
					if(pointVec.size()==0) arg = ".";
					if(minusState == true) {
						lhs_ = lhs_ - lhs_ - lhs_;
						minusState = false;
					}
				}
				
				if(arg == ".") {
					operation = ERROR;
					break;
				}
			}
			
			switch(operation) {
				case PLUS:
					eva = lhs_ + rhs_;
					cout << "(" << eva.x_ << ", " << eva.y_ << ")" << endl;
					break;
				case MINUS:
					eva = lhs_ - rhs_;
					cout << "(" << eva.x_ << ", " << eva.y_ << ")" << endl;
					break;
				case MULTI:
					eva = lhs_ * rhs_;
					cout << "(" << eva.x_ << ", " << eva.y_ << ")" << endl;
					break;
				case ERROR:
					cout << "input error" << endl;
					break;
				default:
					break;
		 	}
		}
	}
	return 0;
}

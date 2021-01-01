#include "draw_shape.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int main() {
	size_t _row, _col;
	cin >> _col >> _row;
	
	Canvas* _canvas = new Canvas(_row, _col);
	_canvas->Draw(cout);
	
	while(true) {
		string command;
		command.clear();
		getline(cin,command);
		
		if(command.find("draw") != string::npos) _canvas->Draw(cout);
		else if(command.find("add") != string::npos) {
			command.erase(0,4);
			
			string* argv = new string[command.length()];
			Shape drawingShape = { };
			int argc = 0;
			size_t pos = 0;
			char _brush;
			
			while(true) {
				pos = command.find(' ');
				argv[argc++] = command.substr(0,pos);
				
				if(pos >= command.length()) break;
				else command.erase(0,pos+1);
			}
			
			drawingShape.x = atoi(argv[1].c_str());
			drawingShape.y = atoi(argv[2].c_str());
			
			if(argv[0] == "tri_up") {
				drawingShape.type = TRIANGLE_UP;
				drawingShape.height = atoi(argv[3].c_str());
				sscanf(argv[4].c_str(),"%c",&_brush);
				drawingShape.brush = _brush;
			}
			else if(argv[0] == "tri_down") {
				drawingShape.type = TRIANGLE_DOWN;
				drawingShape.height = atoi(argv[3].c_str());
				sscanf(argv[4].c_str(),"%c",&_brush);
				drawingShape.brush = _brush;
			}
			else if(argv[0] == "rect") {
				drawingShape.type = RECTANGLE;
				drawingShape.width = atoi(argv[3].c_str());
				drawingShape.height = atoi(argv[4].c_str());
				sscanf(argv[5].c_str(),"%c",&_brush);
				drawingShape.brush = _brush;
			}
			
			delete[] argv;
			
			int check = _canvas->AddShape(drawingShape);
				
			switch(check) {
				case ERROR_OUT_OF_CANVAS:
					cout << "error out of canvas" << endl; break;
				case ERROR_INVALID_INPUT:
					cout << "error invalid input" << endl; break;
				default: break;
			}
		}
		else if(command.find("dump") != string::npos) _canvas->Dump(cout);
		else if(command.find("delete") != string::npos) {
			int index;
			sscanf(command.c_str(),"delete %d", &*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&index);
			_canvas->DeleteShape(index);
		}
		else if(command.find("quit") != string::npos) break;
	}
	
	delete _canvas;
	return 0;
}

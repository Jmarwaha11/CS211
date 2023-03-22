#include "File.h"
#include "ImageFile.h"
#include "TextFile.h"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;

vector<File*> searchfiles (const vector<File*>& files, std::string ext);
void recursive_element_search_files (vector<File*>& sourceVector, vector<File*>& destVector, std::string ext);
void output (const vector<File*>& files);
void recursive_element_output (vector<File*>& files);

int main( ) {
	vector<File*> v1;
	int dh, dw,size;
    cout<<"input a height then widith then size of a .gif file (file 1) to be added to the vector"<<std::endl;
    std::cin>>dh>>dw>>size;
	v1.push_back(new ImageFile("1st file(.gif)", dh, dw, size));
	v1.push_back(new TextFile("2nd file(.txt) "));
	v1.push_back(new ImageFile("3rd file(.gif)", 40, 10, 900));

	cout << "a demonstration of the search function and the output function  ";
	vector<File*> s1 = searchfiles(v1, "txt");
	output(s1);
	vector<File*> s2 = searchfiles(v1, "gif");
	output(s2);	
	return 0;
}

void output(const vector<File*>& files) {
	vector<File*> temp(files);
	recursive_element_output(temp);
}

void recursive_element_output(vector<File*>& files) {
	if (files.size() != 0) {
		File* end = files.back();
		files.pop_back();
		output(files);
		cout << "The type of the file is: " + end->getExt() <<std::endl;
		cout << "The name of the file is: " + end->getName() <<std::endl;
		if (end->getExt() == "gif") {
			ImageFile* if1 = dynamic_cast<ImageFile*>(end);
			cout << "The dimensions are: " << if1->getDimensionHeight() << " x "
					<< if1->getDimensionWidth() <<std:: endl;
		}
		cout << "Size: " << end->getSize() << " bytes"<<std::endl;
	}
}

vector<File*> searchfiles(const vector<File*>& files, std::string ext) {
	vector<File*> temp(files), filesToReturn;
	recursive_element_search_files(temp, filesToReturn, ext);
	return filesToReturn;
}

void recursive_element_search_files(vector<File*>& sourceVector, vector<File*>& destVector, std::string ext) {
	if (sourceVector.size() <= 0) {
		return;
	}
	File* lastfile = sourceVector.back();
	sourceVector.pop_back();
	recursive_element_search_files(sourceVector, destVector, ext);
	if (lastfile->getExt() == ext) {
		destVector.push_back(lastfile);
	}
}
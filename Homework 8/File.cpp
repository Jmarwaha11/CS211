#include "File.h"
#include <string>

using std::string;

File::File( ) : name(""), ext("") { }

File::File(std::string ext) : name(""), ext(ext) {}

File::File(std::string name, std::string ext) : name(name), ext(ext) { }

File::~File( ) {}

string File::getName( ) const {
	return name;
}

string File::getExt( ) const {
	return ext;
}
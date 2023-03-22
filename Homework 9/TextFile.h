#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "File.h"
#include "Safearray.h"
#include <string>

class TextFile : public File{
private:
	SafeArray<int> char_array;
	int char_counter;
	static const std::string ext;
public:
	TextFile ( );
	TextFile (std::string file_name);
	TextFile (std::string file_name, SafeArray<int> char_array);
	int getSize ( ) const override;
	int getCharCounter ( ) const;

};

#endif 

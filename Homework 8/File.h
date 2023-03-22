#ifndef FILE_H
#define FILE_H
#include <string>

class File {
public:
	File ( );
	
	File (std::string ext);

	File (std::string name, std::string ext);
	
	virtual ~File ( );
	
	std::string getName ( ) const;
	
	std::string getExt ( ) const;
	
	virtual int getSize ( ) const = 0;
private:
	std::string name;
	std::string ext;
};

#endif
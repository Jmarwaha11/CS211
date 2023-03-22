#include "TextFile.h"

 const 
 std::string
  TextFile::ext = "txt";

 
TextFile::TextFile ():File (ext), char_array (SafeArray < int >(0)),
char_counter (0)
{} 
 
TextFile::TextFile (std::string file_name):File (file_name, ext), char_array (SafeArray < int >(0)),
char_counter (0)
{} 
 
TextFile::TextFile (std::string file_name, SafeArray < int >char_array):
File (file_name, ext),
char_array (char_array),
char_counter (char_array.length ())
{} 
 
int
TextFile::getSize () const 
{
return char_counter / 8;
}

int
TextFile::getCharCounter () const 
{
return char_counter;
}

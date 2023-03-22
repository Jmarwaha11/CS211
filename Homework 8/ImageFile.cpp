#include "ImageFile.h"

 const
  std::string
  ImageFile::ext = "gif";

 
ImageFile::ImageFile ():File (ext), pixels (SafeMatrix < int >(0, 0)),
color_depth (0)
{} 
 
ImageFile::ImageFile (std::string file_name, int height, int width,
			   int cD):
File (file_name, ext),
pixels (SafeMatrix < int >(height, width)),color_depth (cD)
{} 
 
ImageFile::ImageFile (std::string file_name, SafeMatrix < int >pixels,
			   int color_depth):
File (file_name, ext),
pixels (pixels),
color_depth (color_depth)
{} 
 
int
ImageFile::getColorDepth () const 
{
  
return color_depth;

}


 
int
ImageFile::getDimensionHeight () const 
{
  
return pixels.length ();

}


 
int
ImageFile::getDimensionWidth () const 
{
  
return pixels.width ();

}


 
int
ImageFile::getSize () const 
{
  
return static_cast <
    double >(pixels.length () * pixels.width () * color_depth) / 8;

}

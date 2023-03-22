#ifndef IMAGEFILE_H
#define IMAGEFILE_H

#include "File.h"
#include "Safematrix.h"
#include <string>

class ImageFile : public File {
public:
	ImageFile( );

	ImageFile(std::string file_name, int height, int width, int color_depth);

	ImageFile (std::string file_name, SafeMatrix<int> pixels, int color_depth);

	int getColorDepth( ) const;

	int getDimensionHeight( ) const;

	int getDimensionWidth( ) const;

	int getSize( ) const override;
private:
	SafeMatrix<int> pixels;
	int color_depth;
	static const std::string ext;
};

#endif 
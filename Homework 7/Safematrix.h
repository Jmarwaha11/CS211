#ifndef SAFEMATRIX_H
#define SAFEMATRIX_H
#include "Safearray.h"

using std::ostream;
template <class T>

class SafeMatrix{
    public:
SafeMatrix(int r, int c);
int length ()const;
SafeArray<T>& operator[](int );
friend ostream& operator<<(ostream& output,const SafeMatrix& otherSafeMatrix){
for (int i = 0; i < otherSafeMatrix.size; ++i) {
			output << otherSafeMatrix.array[i] << "\n";
		}
		return output;
}
private:
int size;
SafeArray<SafeArray<T>> array;
};
template <class T>
SafeMatrix<T>::SafeMatrix(int r , int c ) : size(r), array(SafeArray<SafeArray<T>>(size)) {
	for (int i = 0; i < size; ++i) {
		array[i] = SafeArray<T>(c);
	}
}



template <class T>
int SafeMatrix<T>::length( ) const {
	return size;
}

template <class T>
SafeArray<T>& SafeMatrix<T>::operator[](int index)
{
	return array[index];
}

#endif
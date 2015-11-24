#ifndef ARRAY2D_H_
#define ARRAY2D_H_
#include "Array.h"
#include<stdexcept>
template<class T>
class Array2D
{
protected:
	unsigned int numberOfRows;
	unsigned int numberOfColumns;
	Array<T> array;
public:
	class Row<T>
	{
		Array2D<T>& array2D;
		unsigned int const row;
	public:
		Row<T>(Array2D<T>& _array2D, unsigned int _row) :
			array2D(_array2D), row(_row){}
		T & operator[](unsigned int column) const
		{
			return array2D.Select(row, column);
		}
	};

	Array2D(unsigned int, unsigned int);
	T & Select(unsigned int, unsigned int);
	Row<T> operator[](unsigned int row);
};

template<class T>
Array2D<T>::Array2D(unsigned int m, unsigned int n) :
numberOfRows(m),
numberOfColumns(n),
array(m * n)
{}

template<class T>
Array2D<T>::Row<T> Array2D<T>::operator[](unsigned int row)
{
	return Row<T>(*this, row);
}

template<class T>
T & Array2D<T>::Select(unsigned int i, unsigned int j)
{
	if (i >= numberOfRows)
		throw std::out_of_range("invalid row");
	if (j >= numberOfColumns)
		throw std::out_of_range("invalid column");
	return array[i * numberOfColumns + j];
}


#endif
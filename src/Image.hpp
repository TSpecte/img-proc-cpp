#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include "stdint.h"
#include <iostream>
#include <cassert>
#include <cstring> // memcpy
#include <limits>  // std::numeric_limits<T>::max() / min()

template <class T>
class Image
{

protected:
	//Image dimensions
	int _width;
	int _height;
	int _channels;
	int _prec;

	int _dim; // = _width * _height * _channels

	/*	Image pixels
	*	data[height][width][channels]
	*/ 
	T * _data;

public:

	Image (
			const int width
		,	const int height
		,	const int channels
	);

	Image (const Image& in);

	Image zeros (
			const int width
		,	const int height
		,	const int channels
	);


	Image& operator<  (T val);
	Image& operator<= (T val);
	Image& operator>  (T val);
	Image& operator>= (T val);

	Image  operator+  (const Image& other);
	Image  operator+  (const T val);
	Image& operator+= (const Image& other);
	Image  operator-  (const Image& other);
	Image& operator-= (const Image& other);

	Image& operator/= (const T val); // Done & Tested


	Image& operator= (const Image& other); //assert les images doivent avoir meme dimensions

	T& operator[] (int rank); // L value
	const T& operator[] (int rank) const; // R value

	/*
	*	Getters
	*/
	int height()  {return _height;}
	int width()   {return _width;}
	int channels(){return _channels;}
	int prec()    {return _prec;}
	int dim()     {return _dim;} 

}; //class Image

// ################################################################
// #                        CONSTRUCTORS                          #
// ################################################################

template <class T>
Image<T>::Image (
		const int width
	,	const int height
	,	const int channels
): _width(width), _height(height), _channels(channels)
{
	_dim = _width * _height * _channels;
	_data = new T[_dim];
}

/*
	Copy constructor
*/
template <class T>
Image<T>::Image(
		const Image& in
): _width(in._width), _height(in._height), _channels(in._channels), _dim(in._dim)
{
	// Check if input data is allocated
	assert(in._data);
	// Allocate data array for new image
	_data = new T[_width*_height*_channels];
	// Copy data from old image to new
	memcpy(_data, in._data, _width*_height*_channels*sizeof(T));		
}


// ################################################################
// #                        OPERATORS                             #
// ################################################################

template <class T>
Image<T> Image<T>::operator+ (const Image<T>& in)
{
	// Preliminary checks
	assert(in._width  == this->_width)
	assert(in._height  == this->_height)
	assert(in._channels  == this->_channels)
	assert(in._data && this->_data);

	// Allocate memory and compute sum
	Image<T> out(this->_width, this->_height, this->_channels);
	for(int i=0; i < in.dim(); i++)
		out[i] = this->_data[i] + in._data[i];

	return out;
}

template <class T>
Image<T> Image<T>::operator+ (const T val)
{
	// Preliminary checks
	assert(this->_data);

	// Allocate memory and compute sum
	Image<T> out(this->_width, this->_height, this->_channels);
	for(int i=0; i < (*this).dim(); i++)
		out[i] = this->_data[i] + val;

	return out;
}

template <class T>
Image<T>& Image<T>::operator/= (const T val)
{
	// Preliminary checks
	assert(this->_data);

	// Allocate memory and compute sum
	for(int i=0; i < (*this).dim(); i++)
		this->_data[i] /= val;

	return *this;
}



// #################################################################

// L value
template <class T>
T& Image<T>::operator[] (int rank)
{
	assert(rank >= 0 && rank < dim());
	return _data[rank];
}

// R value
template <class T>
const T& Image<T>::operator[] (int rank) const
{
	assert(rank >= 0 && rank < dim());
	return _data[rank];
}


#endif
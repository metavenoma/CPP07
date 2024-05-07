/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Array.tpp                                     ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-07                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array(void): _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	this->_array = new T[this->_size]();
}

template <typename T>
Array<T>::Array(const Array<T> &array)
{
	this->_size = array._size;
	this->_array = new T[this->_size]();
	if (this->_size != 0)
	{
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = array._array[i];
	}
}

template <typename T>
Array<T>::~Array(void)
{
	if (this->_size != 0)
		delete[] this->_array;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &array)
{
	if (this->_size != 0)
		delete[] this->_array;
	this->_size = array._size;
	this->_array = new T[this->_size]();
	if (this->_size != 0)
	{
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = array._array[i];
	}
	return (*this);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
T	&Array<T>::operator[](unsigned int n)
{
	if (this->_array == NULL)
		throw std::logic_error("Trying to access empty array");
	if (n >= this->_size)
		throw std::out_of_range("Index is out of bonds");
	return (this->_array[n]);
}

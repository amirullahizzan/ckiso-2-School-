#include "FileException.h"

FileException::FileException(const char* error) : m_error(error)
{

}

const char* FileException::What() const
{
	return m_error.c_str();
}

OpenFileException::OpenFileException(const char* filename) : FileException("�t�@�C�����J���܂���ł����I")
{
	m_error += "\n�t�@�C���� : ";
	m_error += filename;
}

ReadFileException::ReadFileException() : FileException("�t�@�C�����J���܂���ł����I")
{

}
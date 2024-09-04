#pragma once

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

class Exception
{

public :
	virtual ~Exception();

public :
	virtual const char* What() const = 0;


private :


#endif // #ifndef EXCEPTION_H_


};
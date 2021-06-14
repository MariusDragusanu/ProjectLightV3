#include <string>
#include "__Exception.h"

__Exception::__Exception(int line, const char* file)noexcept
	:Line(line),
	File_Name(file)
{

}
const char* __Exception::what()const noexcept
{
	
	std::ostringstream Oss;
	Oss << GetType() << std::endl 
		 << GetOriginString();
	What_Buffer = Oss.str();
	return What_Buffer.c_str();

}
const char* __Exception::GetType()const noexcept
{
	return "Basic Exception";
}
const std::string& __Exception::GetFileName()const noexcept
{
	return File_Name;
}
std::string __Exception::GetOriginString()const noexcept
{
	std::ostringstream oss;
	oss << "[File]" << File_Name << std::endl << "[Line]" << Line;
	return oss.str();
}
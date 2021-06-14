#pragma once


class __Exception :public std::exception
{
private:
	    std::string File_Name;
	    int Line;

protected:	
	    mutable std::string What_Buffer;

public: 
									__Exception(int line, const char* file)noexcept;
		const char*				what()const noexcept override;
		virtual const char*		GetType()const noexcept;
		int							GetLine()const noexcept { return Line; };
		const std::string&		GetFileName()const noexcept;
		std::string				GetOriginString()const noexcept;
};

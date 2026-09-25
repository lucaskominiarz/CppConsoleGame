#pragma once
class Cell
{
public :
	Cell();
	virtual bool IsEmpty() { return true; };
	virtual ~Cell() = default;
};


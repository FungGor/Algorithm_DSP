class Singly_linked_list
{
public:
	Singly_linked_list()
	{
		nextPtr = 0;
	}

	int GetNum()
	{
		return number;
	}

	void SetNum(int num)
	{
		number = num;
	}

	Singly_linked_list*GetNext()
	{
		return nextPtr;
	}

	void SetNext(Singly_linked_list*ptr)
	{
		nextPtr = ptr;
	}

private:
	int number;
	Singly_linked_list*nextPtr;
};


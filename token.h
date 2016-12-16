// Интерфейс для токена, это у нас или число или операция
struct IToken
{
	virtual bool isOperator() = 0;
	virtual double value() = 0;
	virtual char operation() = 0;
};

template <typename T>
class Token : public IToken
{
	T _token;
	bool _op;

public:
	Token(T t, bool op) : _token(t), _op(op){}

	bool isOperator() override
	{
		return _op;
	}

	double value() override
	{
		return _token;
	}

	char operation() override
	{
		return _token;
	}

};

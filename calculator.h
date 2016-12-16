#include <stack>
#include <memory>
#include <string>

#include "token.h"
#include "types.h"
#include "operations.h"

using namespace std;

class Calculator
{
private:	
	// для хранения выражения в постфиксной нотации
	// сделаем отдельный класс?? 
	deque<shared_ptr<IToken>> _rpn;

public:
	Number calc(Operations& operations);

	// Разбор выражения и преобразование его к RPN нотации
	bool parse(string& expression, Operations& operations, string& error);
};

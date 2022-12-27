#include "func.h"
int main()
{
	char* String = "12345";
	char* Substring = "234";
	int Search = SearchSubStringInString(String, Substring);
	if (Search > 0) printf_s("Substring %s in string %s\n", Substring, String);
	else ("There is not Substring %s in String %s", Substring, String);
	printf_s("%d\n", SearchSubStringInString(String, Substring));
	printf_s("%d\n", CountSubstring(String, Substring));
	String = SubstringReplacement(String, "12", "00");
	printf_s("%s\n", String);
}

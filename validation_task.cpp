#include <iostream>
#include <regex>
bool email_validation(std::string email)
{
	//LOCAL_PART
	//uppercaseand lowercase Latin letters A to Zand a to z
	//digits 0 to 9
	//printable characters !#$%&'*+-/=?^_`{|}~  
	//dot ., provided that it is not the first or last character and provided also that it does not appear consecutively
	
	//@
	
	//DOMAIN
	//uppercaseand lowercase Latin letters A to Zand a to z;
	//digits 0 to 9, provided that top level domain names are not all numeric;
	//hyphen - , provided that it is not the first or last characte
	int at_the_rate_sign_place = -1;

	for (int i = 0; i < email.size(); i++)
	{
		if (email[i] == '@') at_the_rate_sign_place = i;
	}

	if (at_the_rate_sign_place == -1) return false;
	if (email[email.size() - 1] == at_the_rate_sign_place) return false;
	if (email[0] == '.' || email[email.size() - 1] == '.') return false;
	if (email[at_the_rate_sign_place + 1] == '-' || email[email.size() - 1] == '-') return false;
	for (int i = 1; i < email.size(); i++)
	{
		if (email[i] == '.')
		{
			if (email[i - 1] == '.')
			{
				return false;
			}
		}
	}

	for (int i = 0; i < at_the_rate_sign_place ; i++)
	{
		if((email[i] >= 'a' && email[i] <= 'z')||(email[i] >= 'A' && email[i] <= 'Z')||
			(email[i] >= '0' && email[i] <= '9')||email[i]=='!' || email[i] == '#'
			|| email[i] == '$' || email[i] == '%' || email[i] == '&' || email[i] == '\''
			|| email[i] == '*' || email[i] == '+' || email[i] == '-' || email[i] == '/'
			|| email[i] == '=' || email[i] == '?' || email[i] == '^' || email[i] == '_'
			|| email[i] == '`' || email[i] == '{' || email[i] == '}' || email[i] == '|'
			|| email[i] == '~' || email[i] == '.')
		{

		}
		else
		{
			return false;
		}
	}

	for (int i = at_the_rate_sign_place + 1; i < email.size(); i++)
	{
		if ((email[i] >= 'a' && email[i] <= 'z') || (email[i] >= 'A' && email[i] <= 'Z') ||
			(email[i] >= '0' && email[i] <= '9') || email[i] == '-' || email[i] == '.')
		{
		}
		else
		{
			return false;
		}
	}

	int all_numeric_domein_check = 0;
	for (int i = at_the_rate_sign_place + 1; i < email.size(); i++)
	{
		if ((email[i] >= 'a' && email[i] <= 'z') || (email[i] >= 'A' && email[i] <= 'Z') ||
			(email[i] >= '0' && email[i] <= '9') || email[i] == '-' || email[i] == '.')
		{
			if (email[i] < '0' || email[i] > '9')
			{
				all_numeric_domein_check++;
			}
		}
	}
	if (all_numeric_domein_check == 0)return false;
	return true;
}
bool number_validation(std::string number)
{
	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] < '0' || number[i] > '9') 
		{
			return false;
		}
	}
	return true;
}
bool website_validation(std::string website)
{
	if (std::regex_match(website, std::regex("^((https?|ftp|smtp):\/\/)?(www.)?[a-z0-9]+\.[a-z]+(\/[a-zA-Z0-9-_#]+\/?)*$"))) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool credit_validation(std::string credit)
{
	int num = 0, sum = 0;
	for (int i = credit.size() - 2; i >= 0; i-=2)
	{
		num = credit[i] - '0';
		num = num * 2;
		if (num >= 10)
		{
			num = num / 10 + num % 10;
		}
		sum = sum + num;
	}

	for (int i = credit.size() - 1; i >= 0; i -= 2)
	{
		num = credit[i] - '0';
		sum = sum + num;
	}
 
	if (sum % 10 == 0)
	{
		return true;
	}
	return false;
}
bool phone_validation(std::string phone)
{
	if (phone[0] != '+') return false;
	for (int i = 1; i < phone.size(); i++)
	{
		if (phone[i] < '0' || phone[i] > '9')
		{
			return false;
		}
	}
	if (phone.size() > 18) return false;
	return true;
}
bool date_validation(std::string date)
{
	if (date[2] != '.' || date[5] != '.') return false;
	int day = (date[0] - '0') * 10 + (date[1] - '0');
	if (day > 31) return false;
	int mounth = (date[3] - '0') * 10 + (date[4] - '0');
	if (mounth > 12) return false;
	if (date.size() > 10) return false;
	for (int i = 6; i < 10; i++)
	{
		if (date[i] < '0' || date[i]>'9')
		{
			return false;
		}
	}
	return true;
}
bool validation_system(std::string tmp)
{
	std::cout << "What do I need to check?" << std::endl;
	std::cout << "[1] Email address" << std::endl;
	std::cout << "[2] Number" << std::endl;
	std::cout << "[3] Website address" << std::endl;
	std::cout << "[4] Credit card number" << std::endl;
	std::cout << "[5] Phone number" << std::endl;
	std::cout << "[6] Data validation" << std::endl;
	std::cout << "_";
	int num;
	std::cin >> num;
	if (num == 1)
	{
		return email_validation(tmp);
	}
	else if (num == 2)
	{
		return number_validation(tmp);
	}
	else if (num == 3)
	{
		return website_validation(tmp);
	}
	else if (num == 4)
	{
		return credit_validation(tmp);
	}
	else if (num == 5)
	{
		return phone_validation(tmp);
	}
	else
	{
		std::cout << "Error: Such a choice is not possible.";
		return false;
	}
}

int main()
{
	std::cout << email_validation("qocharyannnorik@gmail.com");
	std::cout << website_validation("https://stackoverflow.com/questions/42618872/regex-for-website-or-url-validation");
	std::cout << number_validation("43885760184026k6");
	std::cout << credit_validation("379354508162306");
	std::cout << phone_validation("+37491048040");
	std::cout << date_validation("12.13.2022");
}
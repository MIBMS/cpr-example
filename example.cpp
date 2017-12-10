#include <iostream>
#include <string>

#include <cpr/cpr.h>
#include <json.hpp>


#include<conio.h>

std::string getpass() {
	std::string a = "";
	char c;
	for (int i = 0; i<1000; i++)
	{
		c = getch();
		if (c == '\r')
			break;
		std::cout << "*";
		a += c;
	}
	return a;
}


int main(int argc, char** argv) {
	std::string password = getpass();
    auto response = cpr::Get(cpr::Url{"https://ocp-console-risk.np.ocp.standardchartered.com:8443/oauth/authorize?client_id=openshift-challenging-client&response_type=token"},
		cpr::Header{ {"X-CSRF-Token", "1"} },
		cpr::Authentication{"1576835", password});
    auto json = nlohmann::json::parse(response.text);
    std::cout << json.dump(4) << std::endl;
	std::cout << response.text << std::endl;
}

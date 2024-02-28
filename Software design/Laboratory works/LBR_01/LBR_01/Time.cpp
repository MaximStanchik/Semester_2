
#include"stdafx.h"

using namespace std;
string currentDateTime() {
	time_t t = time(nullptr);
	tm* now = localtime(&t);
	char buffer[128];
	strftime(buffer, sizeof(buffer), "%d%m%Y", now);
	return buffer;
}
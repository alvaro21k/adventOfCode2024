#include "./day_mains/dayone.h"
#include <direct.h>

int main(){
    char buffer[256];
    char* val = _getcwd(buffer, sizeof(buffer));
    if (val) {
        std::cout << buffer << std::endl;
    }
	//first day
	day1part1();

}
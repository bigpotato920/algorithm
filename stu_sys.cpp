#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>

class Student
{
public:
	Student(std::string &name, std::string &no,
		int age, int score);
private:
	std::string name;
	std::string	no;
	int age;
	int score;

};

int main(int argc, char const *argv[])
{
	char line[256];
	char name[256];
	char no[256];
	int age;
	int s1, s2, s3, s4;

	char *token;

	scanf("%s", line);
	token = strtok(line, ",");
	strcpy(name, token);
	token = strtok(NULL, ",");
	age = atoi(token);
	token = strtok(NULL, ",");
	strcpy(no, token);
	token = strtok(NULL, ",");
	s1 = atoi(token);
	token = strtok(NULL, ",");
	s2 = atoi(token);
	token = strtok(NULL, ",");
	s3 = atoi(token);
	token = strtok(NULL, ",");
	s4= atoi(token);

	printf("%s,%d,%s,%d\n", name, age, no, (s1+s2+s3+s4)/4);

	return 0;
}
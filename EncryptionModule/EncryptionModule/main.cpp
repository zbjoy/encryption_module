#include <iostream>
#include <string>
#include "Person.pb.h"
#include "Info.pb.h"

int main(void)
{
	Person::Person p;
	Info::Info* info = p.mutable_info();
	p.set_id(1);
	p.set_name("老张");
	p.set_age(12);
	p.set_type(Person::Teacher);
	info->set_phonenum(123456);
	info->set_address("张家界");
	info->set_emil("123456@qq.com");
	std::string output = p.SerializeAsString();


	/*------------------------------------------------*/


	Person::Person pp;
	pp.ParseFromString(output);
	Info::Info* tempInfo = pp.mutable_info();

	std::cout << "id: " << pp.id() << std::endl
		<< "name: " << pp.name() << std::endl
		<< "age: " << pp.age() << std::endl
		<< "Info: " << std::endl
		<< "phoneNumber: " << tempInfo->phonenum() << std::endl
		<< "address: " << tempInfo->address() << std::endl
		<< "emil: " << tempInfo->emil() << std::endl;
	return 0;
}
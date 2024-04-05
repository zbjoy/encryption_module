#include <iostream>
#include <fstream>
#include <json/value.h>
#include <json/reader.h>
#include <json/writer.h>

using namespace std;

void writeJson()
{
	Json::Value root;
	root.append(12);
	root.append(13.45);
	root.append("hello world");
	root.append(true);
	root.append(false);
	Json::Value sub;
	sub.append(1);
	sub.append(2);
	sub.append("aa");
	root.append(sub);
	Json::Value obj;
	obj["a"] = "b";
	root.append(obj);

	//std::string json = root.toStyledString();
	Json::FastWriter fw;
	std::string json = fw.write(root);

	std::ofstream ofs("test.json");
	ofs << json;
}

void readJson()
{
	std::ifstream ifs("test.json");

	//Json::Reader ;
	Json::Reader rd;
	Json::Value root;
	rd.parse(ifs, root);

	for (int i = 0; i < root.size(); ++i)
	{
		if (root[i].isInt())
		{
			std::cout << root[i].asInt() << " ";
		}
		else if (root[i].isDouble())
		{
			std::cout << root[i].asDouble() << " ";
		}
		else if (root[i].isBool())
		{
			std::cout << root[i].asBool() << " ";
		}
		else if (root[i].isString())
		{
			std::cout << root[i].asString() << " ";
		}
		else if (root[i].isArray())
		{
			for (int j = 0; j < root[i][j].size(); ++i)
			{
				if (root[i][j].isInt())
				{
					std::cout << root[i][j].asInt() << " ";
				}
				else if (root[i][j].isDouble())
				{
					std::cout << root[i][j].asDouble() << " ";
				}
				else if (root[i][j].isBool())
				{
					std::cout << root[i][j].asBool() << " ";
				}
				else if (root[i][j].isString())
				{
					std::cout << root[i][j].asString() << " ";
				}

			}
		}
		else if (root[i].isObject())
		{
			for (int j = 0; j < root[i].size(); ++i)
			{
				std::cout << root[i]["a"].asString() << std::endl;
			}
		}
		
	}
	
}

int main()
{
	writeJson();
	readJson();
	return 0;
}
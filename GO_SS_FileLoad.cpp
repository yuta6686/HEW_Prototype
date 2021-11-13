#include "GO_SS_FileLoad.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

std::vector<std::string> split(std::string str, char del);

void GO_SS_FileLoad::Initialize(void)
{
	MapData.resize(MAP_HEIGHT_DIV);
	for (int i = 0; i < MAP_HEIGHT_DIV; i++)
	{
		MapData[i].resize(MAP_WIDTH_DIV);
	}
}

void GO_SS_FileLoad::Finalize(void)
{
}

void GO_SS_FileLoad::Update(void)
{
}

void GO_SS_FileLoad::Draw(void)
{
}

vector<vector<int>> GO_SS_FileLoad::MapFileLoad(void)
{
	ifstream ifs;	//ファイルストリーム
	string line;	//バッファ
	vector<stri> data;

	//ファイルオープン
	ifs.open("data/MapData.csv", ios::in);
	if (!ifs)
	{
		cerr <<"data/MapData.csvを読み込めません" << endl;
	}

	for (int y = 0; y < MAP_HEIGHT_DIV; y++)
	{
		getline(ifs, line);

		//,を空白に置き換え
		//replace(line.begin(), line.end(), ',', ' ');

		data = split(line, ',');

		//1数値ずつ取り出し
		MapData[y].push_back(data);
		
	}


	ifs.close();
	return MapData;
}

vector<int> split(string str, char del) 
{
	int first = 0;
	int last = str.find_first_of(del);
	vector<string> result;

	while (first < str.size())
	{
		string subStr(str, first, last - first);
		result.push_back(subStr);
		first = last + 1;
		last = str.find_first_of(del, first);
		if (last == string::npos) 
		{
			last = str.size();
		}
	}
	return result;
}
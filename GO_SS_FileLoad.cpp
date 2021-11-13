#include "GO_SS_FileLoad.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;


void GO_SS_FileLoad::Initialize(void)
{
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

int* GO_SS_FileLoad::MapFileLoad(void)
{
	ifstream ifs;	//ファイルストリーム
	string line;	//バッファ
	int data;

	//ファイルオープン
	ifs.open("data/MapData.csv");
	if (!ifs)
	{
		cerr <<"data/MapData.csvを読み込めません" << endl;
	}

	for (int y = 0; y < MAP_HEIGHT_DIV; y++)
	{
		getline(ifs, line);

		//,を空白に置き換え
		replace(line.begin(), line.end(), ',', ' ');

		istringstream iss(line); //文字列をistringstreamに代入

		//1数値ずつ取り出し
		for (int x = 0; x < MAP_WIDTH_DIV, iss >> data; x++)
		{
			MapData[y][x] = data;
		}
	}


	ifs.close();
	return *MapData;
}
#include "GO_SS_FileLoad.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


void GO_SS_FileLoad::Initialize(void)
{
	ifs.open(MapFileName);
	if (!ifs)
	{
		cerr << "マップデータの読み込みに失敗" << endl;
	}
}

void GO_SS_FileLoad::Finalize(void)
{
	ifs.close();
}

void GO_SS_FileLoad::Update(void)
{
}

void GO_SS_FileLoad::Draw(void)
{
}

void GO_SS_FileLoad::MapFileLoad(void)
{
	string line;
	for (int y = 0; y < MAP_HEIGHT_DIV; y++)
	{
		////取り出し
		//getline(ifs,line);

		////置き換え
		//line.replace(line.begin(), line.end(), ',', ' ');

		for (int x = 0; x < MAP_WIDTH_DIV; x++)
		{
			////iss
			//istringstream iss(line);

			////取り出し
			//iss >> MapData[y][x];

			//取り出し
			ifs >> MapData[y][x];
		}
	}
}
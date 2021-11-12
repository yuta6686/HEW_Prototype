#include "GO_SS_Map.h"
#include "GO_SS_FileLoad.h"

void GO_SS_Map::Initialize(void)
{
	p_MapData = m_pFileLoad->MapFileLoad();
}

void GO_SS_Map::Finalize(void)
{
}

void GO_SS_Map::Update(void)
{

}

void GO_SS_Map::Draw(void)
{
}
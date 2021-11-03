#pragma once
#include "scene.h"

class CompositScene :
    public Scene
{
private:
	
public:
	//子シーンを追加
	virtual void AddScene(Scene* s) {
		m_SceneAry.push_back(s);
	}

	//子シーンを取り除く
	virtual void RemoveScene(Scene* s) {
		for (int i = 0; i < m_SceneAry.size(); i++) {
			if (m_SceneAry.at(i) == nullptr)continue;
			if (m_SceneAry.at(i) == s) {
				m_SceneAry.pop_back();
			}
			break;
		}
	}

	//子シーンにアクセス
	virtual Scene* GetChild(int num) {
		if (m_SceneAry.size() < num)
			return nullptr;
		return m_SceneAry[num];
	}

	//シーン開始
	virtual void Begin();

	
};


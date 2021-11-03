#pragma once
#include "scene.h"

class CompositScene :
    public Scene
{
private:
	
public:
	//�q�V�[����ǉ�
	virtual void AddScene(Scene* s) {
		m_SceneAry.push_back(s);
	}

	//�q�V�[������菜��
	virtual void RemoveScene(Scene* s) {
		for (int i = 0; i < m_SceneAry.size(); i++) {
			if (m_SceneAry.at(i) == nullptr)continue;
			if (m_SceneAry.at(i) == s) {
				m_SceneAry.pop_back();
			}
			break;
		}
	}

	//�q�V�[���ɃA�N�Z�X
	virtual Scene* GetChild(int num) {
		if (m_SceneAry.size() < num)
			return nullptr;
		return m_SceneAry[num];
	}

	//�V�[���J�n
	virtual void Begin();

	
};


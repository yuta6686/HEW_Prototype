#pragma once
#include <vector>

// 登録シーン一覧
enum SCENE
{
	SCENE_NONE,		//シーン処理なし
	SCENE_TITLE,	//タイトル
	SCENE_GAME,		//ゲーム
	SCENE_RESULT,	//リザルト
	SCENE_GAMEOVER,	//ゲームオーバー

	SCENE_MAX		//最後だとわかる奴をいれる
};

void InitScene(SCENE index);
void UninitScene(void);
void UpdateScene(void);
void DrawScene(void);

void SetScene(SCENE index);
void CheckScene(void);

class Scene
{
protected:
	//子シーン配列
	std::vector<Scene*> m_SceneAry;

	//親シーン
	Scene* m_pParent;

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

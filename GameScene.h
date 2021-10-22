#pragma once
//---------------------------
//	[GameScene.h]
//	Yuta Yanagisawa 
//---------------------------

//ゲーム内でのシーン遷移を管理します。


enum GAMESCENE{
    GAMESCENE_VORTEX,       //納豆混ぜるシーン
    GAMESCENE_BUNGEE_JUMP,  //バンジージャンプのシーン
    GAMESCENE_MAX
};

class GameScene
{
public:

    //ゲームオブジェクトのレジスタ順で数える。
    //GAMESCENEによってGameObjectのUpdateとDrawの範囲を設定する
    //[GameScene][最初なら0,後なら1]
    const int GameSceneSelect[GAMESCENE_MAX][2] = {
        {0,3},          //納豆混ぜる
        {4,10},         //バンジージャンプ
    };

    //ここをBUNGEE_JUMPに変えてGameFrameworkのレジスタに後ろから詰め込めば4から10番目のオブジェクトだけが
    //UpdateとDrawを行います。
    int m_GameScene = GAMESCENE_VORTEX;
};

/*
*   GameSceneSelectはわからなかったら聞いてください。
* 
*   0から3までは納豆混ぜるシーン用のゲームオブジェクト
*   4から10まではバンジージャンプ用のゲームオブジェクト
*   （↑数字が変わる可能性がある。）
* 
*/
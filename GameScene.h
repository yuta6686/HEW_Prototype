#pragma once

enum GAMESCENE{
    GAMESCENE_VORTEX,
    GAMESCENE_BUNGEE_JUMP,
    GAMESCENE_MAX
};

class GameScene
{
public:

    //ゲームオブジェクトのレジスタ順で数える。
    //GAMESCENEによってGameObjectのUpdateとDrawの範囲を設定する
    //[GameScene][最初なら0,後なら1]
    const int GameSceneSelect[GAMESCENE_MAX][2] = {
        {0,3},
        {4,10},
    };

    //ここをBUNGEE_JUMPに変えてGameFrameworkのレジスタに後ろから詰め込めば4から10番目のオブジェクトだけが
    //UpdateとDrawを行います。
    int m_GameScene = GAMESCENE_VORTEX;
};


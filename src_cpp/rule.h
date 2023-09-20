﻿#pragma once

#include <array>

struct Rule {
    /* 点数関連 */
    // 配給原点
    int startingPoints = 25000;
    // 順位点
    std::array<int, 4> rankPoints = { 20, 10, -10, -20 };
    // 連風牌は2符
    bool doubleWindTileScore = false;

    /* 赤牌有無/クイタンなど */
    // 赤牌
    std::array<int, 3> hongpai = { 1, 1, 1 };
    int hongpai_(const char s) const {
        switch (s)
        {
        case 'm':
            return hongpai[0];
        case 'p':
            return hongpai[1];
        case 's':
            return hongpai[2];
        default:
            throw std::invalid_argument(std::string(1, s));
        }
    }
    // クイタンあり
    bool canduan = true;
    // 喰い替え許可レベル
    int canChangePermissionLevel = 0; // 0: 喰い替えなし, 1: スジ喰い替えあり,  2: 現物喰い替えもあり

    /* 局数関連 */
    // 場数
    int roundsType = 2; // 0: 一局戦, 1: 東風戦, 2： 東南戦, 4: 一荘戦
    // 途中流局あり
    bool abortiveDraw = true;
    // 流し満貫あり
    bool liujumanguan = true;
    // ノーテン宣言あり
    bool notenDeclaration = false;
    // ノーテン罰あり
    bool notenPenalty = true;
    // 最大同時和了数
    int maxSimultaneousWinners = 2; // 1: 頭ハネ, 2: ダブロンあり, 3: トリロンあり
    // 連荘方式
    int dealerContinuationType = 2; // 0: 連荘なし, 1: 和了連荘, 2: テンパイ連荘, 3: ノーテン連荘
    // トビ終了あり
    bool bankruptcyEndAll = true;
    // オーラス止めあり
    bool lastRoundStop = true;
    // 延長戦方式
    int overtimeType = 1; // 0: 延長戦なし, 1: サドンデス, 2: 連荘優先サドンデス, 3: 4局固定

    /* リーチ/ドラ関連 */
    // 一発あり
    bool yifa = true;
    // 裏ドラあり
    bool fubaopai = true;
    // カンドラあり
    bool gangbaopai = true;
    // カン裏あり
    bool ganglibaopai = true;
    // カンドラ後乗せ
    bool gangbaopaiPostAddition = true;
    // ツモ番なしリーチあり
    bool lizhiWithoutTsumoBonus = false;
    // リーチ後暗槓許可レベル
    int lizhiPostClosedGangPermissionLevel = 2; // 0: 暗槓不可, 1: 牌姿の変わる暗槓不可, 2： 待ちの変わる暗槓不可

    /* 役満関連 */
    // 役満の複合あり
    bool damanguanCombination = true;
    // ダブル役満あり
    bool doubleDamanguan = true;
    // 数え役満あり
    bool countedDamanguan = true;
    // 役満パオあり
    bool damanguanPao = true;
    // 切り上げ満貫あり
    bool roundUpManguan = false;
};

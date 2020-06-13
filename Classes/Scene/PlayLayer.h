#pragma once
#ifndef PLAYLAYER_H_
#define PLAYLAYER_H_
#include "cocos2d.h"
#include"keyBoardDelegate.h"
#include"KeyboardControl.h"
#include"Player.h"
#include"ProgressViewBlood.h"
#include"prop.h"
#include"PlayScene.h"

USING_NS_CC;
class Player;
class PlayScene;

class playLayer:public cocos2d::Layer,public keyBoardDelegate
{
public:
	virtual bool init();
	
	void initMap();
	void initHero();
	void initBattleRoom();
	void initNextLevelRoom();
	void initBloodProgress();


	//���º������ڽ�ɫ�ƶ�����
	Point tileToWin(Point position);
	Point winToTile(Point position);
	bool isTileBlocked(Point position);
    void setViewPointCenter(cocos2d::Point position);
	void update(float delta) override;
	void updatePosition();
	
	//�̳���keyBoardDelegate����������
	virtual void didChangeDirectionTo(cocos2d::CCPoint direction);
	virtual void isHoldingDirection(cocos2d::CCPoint direction);
	
	//���º���������Ϸ��ͣ
	void menuPauseCallback(Ref* pSender);

	//���ý���
	void menuSetCallback(Ref* pSender);

	//��ȡ����
	void getProps(Ref* pSender);

	//��һ��
	void nextLevel(Ref* pSender);

	CC_SYNTHESIZE(KeyboardControl*, _control, Control);
	CREATE_FUNC(playLayer);


private:
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keySituation;
	//��ͼ���
	TMXTiledMap *map=NULL;
	TMXLayer *block=NULL;
	Point _direction;
	
	//�����Ѫ��
	Player *knight = NULL;
	ProgressViewBlood* bloodView;

	//��ť���
	CCMenu *pMenu1 = NULL;
	CCMenu *pMenu2 = NULL;

	//����
	CCMenu *pboxMenu1 = NULL;
	CCMenu *pboxMenu2 = NULL;
	prop *props = NULL;
};
#endif


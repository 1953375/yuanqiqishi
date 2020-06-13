#ifndef __Player_H__
#define __Player_H__

#include "cocos2d.h"
#include"ProgressViewBlood.h"

USING_NS_CC;

class Player :public Sprite
{
public:
	Player(void);
	~Player(void);
	static Player* createWithFileName(const char*name);//����
	void InitPlayerSprite(char* xueback, char* xuefore);

	void setCurrentBlood(int blood);
	int getCurrentBlood();
	void attacked(int attack);
	void died();

	void init(Point point);
	int existLife;//����ʣ��Ѫ�� Ϊ�ٷ��� �Դ˿���Ѫ��
	//bool IsRunning();//�Ƿ��ܶ�
	//void StopAnimation();//�ܲ�����ֹͣ
	//bool Direction();

	void update(float delta)override;
	void walkWithDirection(Point direction);
	CC_SYNTHESIZE(float, _walkSpeed, WalkSpeed);
	CC_SYNTHESIZE(cocos2d::CCPoint, _velocity, Velocity);
	CC_SYNTHESIZE(cocos2d::CCPoint, _desiredPosition, DesiredPosition);

private:
	int currentBlood;

	ProgressViewBlood * bloodView;
};

#endif
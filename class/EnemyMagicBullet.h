
/**
*���� ����ħ��������ʼ��ħ�������˶��켣
*/
#include "cocos2d.h"
USING_NS_CC;

class EnemyMagicBullet : public cocos2d::Layer
{
public:
	EnemyMagicBullet(CCNode* monsterwitcher);
	~EnemyMagicBullet();
	virtual bool init();

	//����ħ����
	static  EnemyMagicBullet* create(CCNode* monsterwitcher);

	//�Ƴ�������Ļ���ӷ�Χ��ħ����������ײ���ħ�������
	void removeBullet(Node* pNode);

	//����ħ�����������н���ħ��������Ⱦ��ħ�����Ķ�����Ĭ��Ϊ��ħ����
	void ShootBullet1(float dt);
	void ShootBullet2(float dt);
	void ShootBullet3(float dt);
	void ShootBullet4(float dt);

	
	//�����ӵ��б�
	Vector <Sprite*>& GetBullet();
public:
	Vector <Sprite*>vecBullet;//ħ��������
	SpriteBatchNode* bulletBatchNode;//������Ⱦ�ڵ�
	CCNode* monsterwitcher;
};



/**
*���� �����ӵ�����ʼ���ӵ����˶��켣
*/
#include "cocos2d.h"
USING_NS_CC;
const float FlYVElOCITY = 500;//�����ٶȣ������Լ����ƣ�ÿ�����ߵ�����
class EnemyBulletLayer : public cocos2d::Layer
{
public:
	EnemyBulletLayer(CCNode* monstershooter);
	~EnemyBulletLayer();
	virtual bool init();

	//����Ӣ�۷ɻ������ӵ�
	static EnemyBulletLayer* create(CCNode* monstershooter);

	//�Ƴ�������Ļ���ӷ�Χ���ӵ�������ײ����ӵ����
	void removeBullet(Node* pNode);

	//�����ӵ��������н����ӵ�����Ⱦ���ӵ��ķ��ж�����Ĭ��Ϊ���ӵ�
	void ShootBullet(float dt);

	//�����ӵ��б�
	Vector <Sprite*>& GetBullet();
public:
	Vector <Sprite*>vecBullet;//�ӵ�����
	SpriteBatchNode* bulletBatchNode;//������Ⱦ�ڵ�
	CCNode*monstershooter ;
};



/**
*���� ����ħ��������ʼ��ħ�������˶��켣
*/
#include "EnemyMagicBullet.h"
EnemyMagicBullet::EnemyMagicBullet(Node* monsterwitcher) {
	this->monsterwitcher = monsterwitcher;
}
EnemyMagicBullet::~EnemyMagicBullet() {
}
/**
*����ħ�����ľ�̬����
*/
EnemyMagicBullet* EnemyMagicBullet::create(Node* monsterwitcher) {
	EnemyMagicBullet* pRet = new EnemyMagicBullet(monsterwitcher);
	if (pRet && pRet->init()) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = NULL;
		return NULL;
	}

}
bool EnemyMagicBullet::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());

		//����BatchNode�ڵ�
		bulletBatchNode = SpriteBatchNode::create("bullet.png");
		this->addChild(bulletBatchNode);

		//ÿ��0.2S����һ�η����ӵ�����
		this->schedule(schedule_selector(EnemyMagicBullet::ShootBullet1), 1.2f);
		this->schedule(schedule_selector(EnemyMagicBullet::ShootBullet2), 1.2f);
		this->schedule(schedule_selector(EnemyMagicBullet::ShootBullet3), 1.2f);
		this->schedule(schedule_selector(EnemyMagicBullet::ShootBullet4), 1.2f);
		bRet = true;
	} while (0);
	return bRet;
}
/**
*�û���ķ��������ӵ�������ʼ���ӵ����˶����˶�����¼�
*/
void EnemyMagicBullet::ShootBullet1(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto Pos = monsterwitcher->getPosition();
	//�ӻ����д����ӵ�
		auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
		//�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
		bulletBatchNode->addChild(spritebullet);
		//�������õ��ӵ���ӵ�����
		vecBullet.pushBack(spritebullet);

		Point bulletPos1 = (Point(Pos.x,
			Pos.y + monsterwitcher->getContentSize().height / 2 + 20));
		spritebullet->setPosition(bulletPos1);
		spritebullet->setScale(0.8f);
	


	float flyLen = winSize.height - Pos.y;
	float realFlyDuration = flyLen / 200;//ʵ�ʷ��е�ʱ��

	
	auto actionMove = MoveTo::create(realFlyDuration,
		Point(bulletPos1.x, winSize.height));

	//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyMagicBullet::removeBullet, this));

	//�ӵ���ʼ�ܶ�
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}
void EnemyMagicBullet::ShootBullet2(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto Pos = monsterwitcher->getPosition();
	//�ӻ����д����ӵ�
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	//�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
	bulletBatchNode->addChild(spritebullet);
	//�������õ��ӵ���ӵ�����
	vecBullet.pushBack(spritebullet);

	Point bulletPos1 = (Point(Pos.x ,
		Pos.y+ monsterwitcher->getContentSize().height / 2 + 20));
	spritebullet->setPosition(bulletPos1);
	spritebullet->setScale(0.8f);



	float flyLen = winSize.height - Pos.y;
	float realFlyDuration = flyLen / 200;//ʵ�ʷ��е�ʱ��

	
	auto actionMove = MoveTo::create(realFlyDuration,
		Point(winSize.width, bulletPos1.y));

	//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyMagicBullet::removeBullet, this));

	//�ӵ���ʼ�ܶ�
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}
void EnemyMagicBullet::ShootBullet3(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto Pos = monsterwitcher->getPosition();
	//�ӻ����д����ӵ�
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	//�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
	bulletBatchNode->addChild(spritebullet);
	//�������õ��ӵ���ӵ�����
	vecBullet.pushBack(spritebullet);

	Point bulletPos1 = (Point(Pos.x,
		Pos.y + monsterwitcher->getContentSize().height / 2 + 20));
	spritebullet->setPosition(bulletPos1);
	spritebullet->setScale(0.8f);



	float flyLen = winSize.height - Pos.y;
	float realFlyDuration = flyLen / 70;//ʵ�ʷ��е�ʱ��


	auto actionMove = MoveTo::create(realFlyDuration,
		Point(bulletPos1.x, -winSize.height));

	//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyMagicBullet::removeBullet, this));

	//�ӵ���ʼ�ܶ�
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}
void EnemyMagicBullet::ShootBullet4(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto Pos = monsterwitcher->getPosition();
	//�ӻ����д����ӵ�
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	//�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
	bulletBatchNode->addChild(spritebullet);
	//�������õ��ӵ���ӵ�����
	vecBullet.pushBack(spritebullet);

	Point bulletPos1 = (Point(Pos.x,
		Pos.y + monsterwitcher->getContentSize().height / 2 + 20));
	spritebullet->setPosition(bulletPos1);
	spritebullet->setScale(0.8f);



	float flyLen = winSize.height - Pos.y;
	float realFlyDuration = flyLen / 70;//ʵ�ʷ��е�ʱ��

	//�ӵ����еľ����ʱ�䣬�ӷɻ�����ʼ���е���Ļ����
	auto actionMove = MoveTo::create(realFlyDuration,
		Point(-winSize.width, bulletPos1.y));

	//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyMagicBullet::removeBullet, this));

	//�ӵ���ʼ�ܶ�
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}


/**
 * �Ƴ��ӵ������ӵ����������Ƴ���ͬʱҲ��SpriteBatchNode���Ƴ�
 */
void EnemyMagicBullet::removeBullet(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	Sprite* bullet = (Sprite*)pNode;
	this->bulletBatchNode->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}
/**
*�����ӵ��б�������л�����ײ���
*/
Vector <Sprite*>& EnemyMagicBullet::GetBullet() {
	return vecBullet;
}
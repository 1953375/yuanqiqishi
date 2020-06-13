
/**
*���� �����ӵ�����ʼ���ӵ����˶��켣
*/
#include "EnemyBulletLayer.h"
EnemyBulletLayer::EnemyBulletLayer(Node* monstershooter) {
	this->monstershooter = monstershooter;
}
EnemyBulletLayer::~EnemyBulletLayer() {
}
/**
*�����ӵ��ľ�̬����
*/
EnemyBulletLayer* EnemyBulletLayer::create(Node* monstershooter) {
	EnemyBulletLayer* pRet = new EnemyBulletLayer(monstershooter);
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
bool EnemyBulletLayer::init() {
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());

		//����BatchNode�ڵ�
		bulletBatchNode = SpriteBatchNode::create("bullet.png");
		this->addChild(bulletBatchNode);

		//ÿ��0.2S����һ�η����ӵ�����
		this->schedule(schedule_selector(EnemyBulletLayer::ShootBullet), 1.2f);
		bRet = true;
	} while (0);
	return bRet;
}
/**
*�û���ķ��������ӵ�������ʼ���ӵ����˶����˶�����¼�
*/
void EnemyBulletLayer::ShootBullet(float dt) {
	Size winSize = Director::getInstance()->getWinSize();
	auto Pos = monstershooter->getPosition();
	//�ӻ����д����ӵ�
	auto spritebullet = Sprite::createWithTexture(bulletBatchNode->getTexture());
	//�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ
	bulletBatchNode->addChild(spritebullet);
	//�������õ��ӵ���ӵ�����
	vecBullet.pushBack(spritebullet);

	Point bulletPos = (Point(Pos.x,
		Pos.y + monstershooter->getContentSize().height / 2 + 20));
	spritebullet->setPosition(bulletPos);
	spritebullet->setScale(0.8f);


	float flyLen = winSize.height - Pos.y;
	float realFlyDuration = flyLen / 300;//ʵ�ʷ��е�ʱ��

	auto actionMove = MoveTo::create(realFlyDuration,
		Point(bulletPos.x, winSize.height));

	//�ӵ�ִ���궯������к����ص��������Ƴ��ӵ�����
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyBulletLayer::removeBullet, this));

	//�ӵ���ʼ�ܶ�
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	spritebullet->runAction(sequence);


}

/**
 * �Ƴ��ӵ������ӵ����������Ƴ���ͬʱҲ��SpriteBatchNode���Ƴ�
 */
void EnemyBulletLayer::removeBullet(Node* pNode) {
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
Vector <Sprite*>& EnemyBulletLayer::GetBullet() {
	return vecBullet;
}
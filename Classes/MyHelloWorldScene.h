#ifndef _MYHELLOWORLDSCENE_H_
#define _MYHELLOWORLDSCENE_H_
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
using namespace extension;
class MyHelloWorldScene:public CCLayer{
public:
	static CCScene* scene();
	virtual bool init();
	void menuCloseCallback(CCObject* pSender);
	virtual void ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent);//��Ļ������ʼ
	virtual void ccTouchesMoved(CCSet* pTouches,CCEvent* pEvent);//��Ļ�����ƶ�
	virtual void ccTouchesEnded(CCSet* pTouches,CCEvent* pEvent);//��Ļ��������
	virtual void ccTouchesCancelled(CCSet* pTouches,CCEvent* pEvent);//��ϴ����¼���ϵͳ����Ϣ�����绰��
	CREATE_FUNC(MyHelloWorldScene);
private:
	void touchDown(CCObject* pSender,CCControlEvent event );
	void onValueChange(CCObject* pSender,CCControlEvent event);
	void playmusic();
};
#endif
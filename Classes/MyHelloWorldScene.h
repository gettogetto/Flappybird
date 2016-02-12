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
	virtual void ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent);//屏幕触摸开始
	virtual void ccTouchesMoved(CCSet* pTouches,CCEvent* pEvent);//屏幕触摸移动
	virtual void ccTouchesEnded(CCSet* pTouches,CCEvent* pEvent);//屏幕触摸结束
	virtual void ccTouchesCancelled(CCSet* pTouches,CCEvent* pEvent);//打断触摸事件，系统级消息如来电话了
	CREATE_FUNC(MyHelloWorldScene);
private:
	void touchDown(CCObject* pSender,CCControlEvent event );
	void onValueChange(CCObject* pSender,CCControlEvent event);
	void playmusic();
};
#endif
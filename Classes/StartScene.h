#ifndef __Start_SCENE_H__
#define __Start_SCENE_H__
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
using namespace extension;
class StartScene : public cocos2d::CCLayer{
public:
	virtual bool init(); 
	static cocos2d::CCScene* scene();
	CCAnimate* creatBirdAnimate();
	void menuSceneChangeCallback(CCObject* pSender);
	CREATE_FUNC(StartScene);
private:
	CCSprite* bird0_0;
	CCSprite* title;
	CCSprite* background;
	CCMenuItemImage *pSceneChangeItem;
	CCMenu* pMenu;
	CCActionInterval* pAction;
};
#endif//StartScene.h
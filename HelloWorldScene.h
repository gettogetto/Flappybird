#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
using namespace extension;
class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
	void menuReplayCallback(CCObject* pSender);
	void showScoreBoard();
	void calScore();
	void gameOver();
	CCAnimate* creatBirdAnimate();
	CCRect getBird0_0Rect(float a,float b);
	CCRect getPipedown1Rect();
	CCRect getPipeup1Rect();
	CCRect getPipedown2Rect();
	CCRect getPipeup2Rect();
	bool isCollideWithPipe();
	bool isCollideWithLand();
	/*
	//以下四个函数继承自CCLayer，复数表示可以被多个Layer截获
    virtual void ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent);//屏幕触摸开始
	virtual void ccTouchesMoved(CCSet* pTouches,CCEvent* pEvent);//屏幕触摸移动
	virtual void ccTouchesEnded(CCSet* pTouches,CCEvent* pEvent);//屏幕触摸结束
	virtual void ccTouchesCancelled(CCSet* pTouches,CCEvent* pEvent);//打断触摸事件，系统级消息如来电话了
	*/
	virtual bool ccTouchBegan(CCTouch* pTouches,CCEvent* pEvent);//屏幕触摸开始
	virtual void ccTouchMoved(CCTouch* pTouches,CCEvent* pEvent);//屏幕触摸移动
	virtual void ccTouchEnded(CCTouch* pTouches,CCEvent* pEvent);//屏幕触摸结束
	virtual void registerWithTouchDispatcher(void);
	virtual void update(float delta);
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
private:
	CCSize visibleSize;
	CCPoint origin;
	unsigned int score;
	static int highestScore;
	int rank;
	int pipe_distace;
	int pipe_highdistance;
	static bool firstTouch;
	CCMenuItemImage *pCloseItem;
	CCMenuItemImage *pReplayItem;
	CCMenu* pMenu;
	CCLabelTTF* pLabel;
	CCLabelTTF* pScoreLabel;

	CCLabelTTF* finalScore;
	CCLabelTTF* bestScore;

	CCSprite* tutorial;
	CCSprite* background;
	CCSprite* land1;
	CCSprite* land2;
	CCSprite* bird0_0;
	CCSprite* text_ready;
	CCSprite* pipe_down1;
	CCSprite* pipe_up1;
	CCSprite* pipe_down2;
	CCSprite* pipe_up2;
	CCActionInterval* pAction;
	CCSprite* gameOverImage;
	CCSprite* scoreBoard;
	CCSprite* medal;
	CCControlButton* replayBtn;

	CCSprite* score0001,*score0010,*score0100,*score1000;

};

#endif // __HELLOWORLD_SCENE_H__

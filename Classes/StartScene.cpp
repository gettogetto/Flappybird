#include "StartScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
CCScene* StartScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    StartScene *layer = StartScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
bool StartScene::init(){
	if( !CCLayer::init() ){
		return false;
	}
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	//预加载音效
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sfx_wing.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sfx_point.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sfx_hit.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sfx_die.wav");
	//背景
	background = CCSprite::create("bg_night.png");//288*512
    background->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(background, 0);
	//title
	title=CCSprite::create("title.png");
	title->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height/2+200));
	this->addChild(title,0);
	/////////////////////////////////
    pSceneChangeItem = CCMenuItemImage::create(
                                        "button_play.png",
                                        "button_play.png",
                                        this,
                                        menu_selector(StartScene::menuSceneChangeCallback));
    
	pSceneChangeItem->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/4));

    // create menu, it's an autorelease object
    pMenu = CCMenu::create(pSceneChangeItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
	//小鸟
	bird0_0 = CCSprite::create("bird0_0.png");
	bird0_0->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2+50));
	this->addChild(bird0_0,1);

	CCAnimate* swingAction=creatBirdAnimate();//扇动翅膀
	pAction=CCSpawn::create(swingAction,NULL);//同时发生
	bird0_0->runAction(pAction);
	return true;
}
CCAnimate* StartScene::creatBirdAnimate(){
	int iFrameNum=3;
	CCSpriteFrame* frame=NULL;
	CCArray* frameArray=CCArray::create();

	for(int i=0;i<iFrameNum;i++){
		frame=CCSpriteFrame::create(CCString::createWithFormat("bird0_%d.png",i)->getCString(),CCRectMake(0,0,48,48));
		frameArray->addObject(frame);
	}
	CCAnimation* animation=CCAnimation::createWithSpriteFrames(frameArray);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.15f);
	CCAnimate* action=CCAnimate::create(animation);
	return action;
}
void StartScene::menuSceneChangeCallback(CCObject* pSender){
	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

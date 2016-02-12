#include"MyHelloWorldScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;//必须先#include "SimpleAudioEngine.h"


//#include "HelloWorldScene.h"
using namespace cocos2d;


CCScene* MyHelloWorldScene::scene(){
	CCScene* scene=CCScene::create();
	MyHelloWorldScene* layer=MyHelloWorldScene::create();
	scene->addChild(layer);
	return scene;
}
bool MyHelloWorldScene::init(){
    //音乐


	//获取屏幕大小
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCSprite* sprite=CCSprite::create("CloseNormal.png");
	CCSprite* sprite2=CCSprite::create("CloseSelected.png");


	CCLabelTTF* label=CCLabelTTF::create("heheheheh","Arial",40);


	CCMenuItemLabel* pLabelItem=CCMenuItemLabel::create(label,this,menu_selector(MyHelloWorldScene::menuCloseCallback));
	CCMenuItemSprite* pSpriteItem=CCMenuItemSprite::create(sprite,sprite2,this,menu_selector(MyHelloWorldScene::menuCloseCallback));
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(MyHelloWorldScene::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

	CCMenu* pMenu = CCMenu::create(pCloseItem,pLabelItem,pSpriteItem,NULL);
	pMenu->alignItemsHorizontally();
	pMenu->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
    this->addChild(pMenu, 2);
	//九妹与按钮
	CCScale9Sprite* btnNormal=CCScale9Sprite::create("1.jpg");
	CCScale9Sprite* btnDown=CCScale9Sprite::create("1.jpg");
	CCLabelTTF* title=CCLabelTTF::create("touchme","Marker Felt",20);
	CCControlButton* controlBtn=CCControlButton::create(title,btnNormal);
	//给按钮添加监听
	controlBtn->addTargetWithActionForControlEvents(this,
												cccontrol_selector(MyHelloWorldScene::touchDown),
												CCControlEventTouchDown);
	controlBtn->setTitleColorForState(ccRED,CCControlStateHighlighted);//出发按钮文字颜色
	controlBtn->setPosition(ccp(100,200));
	this->addChild(controlBtn);
	//电位计按钮
	CCControlPotentiometer* potrntiometer=CCControlPotentiometer::create(
											"CloseNormal.png",
											"CloseNormal.png",
											"CloseNormal.png");
	potrntiometer->setPosition(ccp(30,70));
	potrntiometer->addTargetWithActionForControlEvents(this,
													cccontrol_selector(MyHelloWorldScene::onValueChange),
													CCControlEventValueChanged);
	this->addChild(potrntiometer);
	//滚动条
	CCControlSlider* slider=CCControlSlider::create(
											"1.jpg",//背景
											"CloseNormal.png",//进度
											"bird0_0.png");//滑块，设成透明可做血量条
	slider->setPosition(ccp(130,70));
	slider->setMinimumValue(0);
	slider->setMaximumValue(10000);
	slider->setValue(1000);
	slider->setTouchEnabled(true);
	this->addChild(slider);

	//直线运动
	CCSprite* bird0_0=CCSprite::create("bird0_0.png");
	bird0_0->setPosition(ccp(90,132));//起点
	this->addChild(bird0_0);
	//CCMoveTo* moveto=CCMoveTo::create(2.0f,ccp(400,132));//创建动作对象，参数为用时与目的地坐标
	//bird0_0->runAction(moveto);
	CCMoveBy* moveby=CCMoveBy::create(1.5f,ccp(200,30));//创建动作对象，参数为用时与移动距离
	//bird0_0->runAction(moveby);

	//CCCallFunc回调动作
	CCCallFunc* callfunc=CCCallFunc::create(this,callfunc_selector(MyHelloWorldScene::playmusic));
	CCSequence* sequence0=CCSequence::create(moveby,callfunc,NULL);//直线运动完，调用playmusic函数
	bird0_0->runAction(sequence0);
	//缩放
	//CCScaleTo* scaleto=CCScaleTo::create(2.0f,0.5,1.2);//参数，时间、x和y方向缩放到原来的几倍
	//bird0_0->runAction(scaleto);

	//旋转
	CCRotateTo* rotateto=CCRotateTo::create(0.3f,-30,-30);
	bird0_0->runAction(rotateto);

	//精灵闪烁
	CCSprite* bird0_01=CCSprite::create("bird0_0.png");
	bird0_01->setPosition(ccp(90,300));//起点
	this->addChild(bird0_01);
	CCBlink* blink=CCBlink::create(10.0f,30);//闪烁总时间和次数
	bird0_01->runAction(blink);
	//重复动作
	CCSprite* bird0_02=CCSprite::create("bird0_0.png");
	bird0_02->setPosition(ccp(190,150));
	this->addChild(bird0_02);
	CCRotateTo* rotateto2=CCRotateTo::create(0.2f,-50,-50);
	CCRotateTo* rotateto3=CCRotateTo::create(1.0f,60,60);
	CCSequence* sequence1=CCSequence::create(rotateto2,rotateto3,NULL);//动作先后发生
	CCJumpBy* jumpby1=CCJumpBy::create(1.2f,ccp(0,0),100,1);
	CCSpawn* spawn1=CCSpawn::create(sequence1,jumpby1,NULL);//动作同时发生
	CCRepeatForever* repeatforever=CCRepeatForever::create(spawn1);//永久重复
	//CCRepeat* repeat=CCRepeat::create(jumpby,8);//指定次数
	bird0_02->runAction(repeatforever);
	return true;
}
void MyHelloWorldScene::menuCloseCallback(CCObject* pSender)
{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	//CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//#else
    //CCDirector::sharedDirector()->end();
	//CCDirector::sharedDirector()->popScene();
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  //  exit(0);
//#endif
//#endif
}
void MyHelloWorldScene::touchDown(CCObject* pSender, CCControlEvent event){
	CCLOG("touchDown");
}
void MyHelloWorldScene::onValueChange(CCObject* pSender,CCControlEvent event){
	CCControlPotentiometer* potentiometer=(CCControlPotentiometer*)pSender;
	CCString* valueStr=CCString::createWithFormat("%f",potentiometer->getValue());
	CCLOG(valueStr->getCString());
}
void MyHelloWorldScene::playmusic(){
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("sfx_wing.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sfx_wing.mp3");
}
void MyHelloWorldScene::ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent){
	
}//屏幕触摸开始
void MyHelloWorldScene::ccTouchesMoved(CCSet* pTouches,CCEvent* pEvent){
	
}//屏幕触摸移动
void MyHelloWorldScene::ccTouchesEnded(CCSet* pTouches,CCEvent* pEvent){
	
}//屏幕触摸结束
void MyHelloWorldScene::ccTouchesCancelled(CCSet* pTouches,CCEvent* pEvent){
	
}//打断触摸事件，系统级消息如来电话了
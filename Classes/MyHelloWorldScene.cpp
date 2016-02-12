#include"MyHelloWorldScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;//������#include "SimpleAudioEngine.h"


//#include "HelloWorldScene.h"
using namespace cocos2d;


CCScene* MyHelloWorldScene::scene(){
	CCScene* scene=CCScene::create();
	MyHelloWorldScene* layer=MyHelloWorldScene::create();
	scene->addChild(layer);
	return scene;
}
bool MyHelloWorldScene::init(){
    //����


	//��ȡ��Ļ��С
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
	//�����밴ť
	CCScale9Sprite* btnNormal=CCScale9Sprite::create("1.jpg");
	CCScale9Sprite* btnDown=CCScale9Sprite::create("1.jpg");
	CCLabelTTF* title=CCLabelTTF::create("touchme","Marker Felt",20);
	CCControlButton* controlBtn=CCControlButton::create(title,btnNormal);
	//����ť��Ӽ���
	controlBtn->addTargetWithActionForControlEvents(this,
												cccontrol_selector(MyHelloWorldScene::touchDown),
												CCControlEventTouchDown);
	controlBtn->setTitleColorForState(ccRED,CCControlStateHighlighted);//������ť������ɫ
	controlBtn->setPosition(ccp(100,200));
	this->addChild(controlBtn);
	//��λ�ư�ť
	CCControlPotentiometer* potrntiometer=CCControlPotentiometer::create(
											"CloseNormal.png",
											"CloseNormal.png",
											"CloseNormal.png");
	potrntiometer->setPosition(ccp(30,70));
	potrntiometer->addTargetWithActionForControlEvents(this,
													cccontrol_selector(MyHelloWorldScene::onValueChange),
													CCControlEventValueChanged);
	this->addChild(potrntiometer);
	//������
	CCControlSlider* slider=CCControlSlider::create(
											"1.jpg",//����
											"CloseNormal.png",//����
											"bird0_0.png");//���飬���͸������Ѫ����
	slider->setPosition(ccp(130,70));
	slider->setMinimumValue(0);
	slider->setMaximumValue(10000);
	slider->setValue(1000);
	slider->setTouchEnabled(true);
	this->addChild(slider);

	//ֱ���˶�
	CCSprite* bird0_0=CCSprite::create("bird0_0.png");
	bird0_0->setPosition(ccp(90,132));//���
	this->addChild(bird0_0);
	//CCMoveTo* moveto=CCMoveTo::create(2.0f,ccp(400,132));//�����������󣬲���Ϊ��ʱ��Ŀ�ĵ�����
	//bird0_0->runAction(moveto);
	CCMoveBy* moveby=CCMoveBy::create(1.5f,ccp(200,30));//�����������󣬲���Ϊ��ʱ���ƶ�����
	//bird0_0->runAction(moveby);

	//CCCallFunc�ص�����
	CCCallFunc* callfunc=CCCallFunc::create(this,callfunc_selector(MyHelloWorldScene::playmusic));
	CCSequence* sequence0=CCSequence::create(moveby,callfunc,NULL);//ֱ���˶��꣬����playmusic����
	bird0_0->runAction(sequence0);
	//����
	//CCScaleTo* scaleto=CCScaleTo::create(2.0f,0.5,1.2);//������ʱ�䡢x��y�������ŵ�ԭ���ļ���
	//bird0_0->runAction(scaleto);

	//��ת
	CCRotateTo* rotateto=CCRotateTo::create(0.3f,-30,-30);
	bird0_0->runAction(rotateto);

	//������˸
	CCSprite* bird0_01=CCSprite::create("bird0_0.png");
	bird0_01->setPosition(ccp(90,300));//���
	this->addChild(bird0_01);
	CCBlink* blink=CCBlink::create(10.0f,30);//��˸��ʱ��ʹ���
	bird0_01->runAction(blink);
	//�ظ�����
	CCSprite* bird0_02=CCSprite::create("bird0_0.png");
	bird0_02->setPosition(ccp(190,150));
	this->addChild(bird0_02);
	CCRotateTo* rotateto2=CCRotateTo::create(0.2f,-50,-50);
	CCRotateTo* rotateto3=CCRotateTo::create(1.0f,60,60);
	CCSequence* sequence1=CCSequence::create(rotateto2,rotateto3,NULL);//�����Ⱥ���
	CCJumpBy* jumpby1=CCJumpBy::create(1.2f,ccp(0,0),100,1);
	CCSpawn* spawn1=CCSpawn::create(sequence1,jumpby1,NULL);//����ͬʱ����
	CCRepeatForever* repeatforever=CCRepeatForever::create(spawn1);//�����ظ�
	//CCRepeat* repeat=CCRepeat::create(jumpby,8);//ָ������
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
	
}//��Ļ������ʼ
void MyHelloWorldScene::ccTouchesMoved(CCSet* pTouches,CCEvent* pEvent){
	
}//��Ļ�����ƶ�
void MyHelloWorldScene::ccTouchesEnded(CCSet* pTouches,CCEvent* pEvent){
	
}//��Ļ��������
void MyHelloWorldScene::ccTouchesCancelled(CCSet* pTouches,CCEvent* pEvent){
	
}//��ϴ����¼���ϵͳ����Ϣ�����绰��
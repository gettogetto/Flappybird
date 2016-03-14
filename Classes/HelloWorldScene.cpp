#include "HelloWorldScene.h"
#include "StartScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

bool HelloWorld::firstTouch=false;
int threeScore[3]={45,30,15};
int HelloWorld::highestScore=CCUserDefault::sharedUserDefault()->getIntegerForKey("bestScoreData",0);//��ȡ�洢����߷�
CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{

    if ( !CCLayer::init() )
    {
        return false;
    }
    
    visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    origin = CCDirector::sharedDirector()->getVisibleOrigin();

	//����
	score=0;
	//����
    background = CCSprite::create("bg_day.png");//288*512
    background->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(background, 0);
	//ready
	text_ready=CCSprite::create("text_ready.png");
	text_ready->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y+50));
	this->addChild(text_ready,0);

	//tourial
	tutorial=CCSprite::create("tutorial.png");
	tutorial->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2-50));
	this->addChild(tutorial,0);
	//С��
    bird0_0 = CCSprite::create("bird0_0.png");
	bird0_0->setPosition(ccp(origin.x + visibleSize.width/3,origin.y + visibleSize.height/2));
	this->addChild(bird0_0,1);

	CCAnimate* swingAction=creatBirdAnimate();//�ȶ����

	pAction=CCSpawn::create(swingAction,NULL);//ͬʱ����
	bird0_0->runAction(pAction);

	//�ܵ�
	int firstdistance=200;//����ʼ��Ҫ����ܵ�Զһ��
	pipe_highdistance=450;//���¹ܵ����
	
	pipe_up1=CCSprite::create("pipe_up.png");
	pipe_up1->setPosition(ccp(origin.x + visibleSize.width+firstdistance,origin.y+15+CCRANDOM_0_1()*200));
	this->addChild(pipe_up1,0);
	pipe_down1=CCSprite::create("pipe_down.png");
	pipe_down1->setPosition(ccp(origin.x + visibleSize.width+firstdistance,pipe_up1->getPositionY()+pipe_highdistance));
	this->addChild(pipe_down1,0);

	pipe_distace=visibleSize.width/2+pipe_down1->getContentSize().width/2.0f;//�ܵ�ˮƽ���
	
	pipe_up2=CCSprite::create("pipe_up.png");
	pipe_up2->setPosition(ccp(origin.x + visibleSize.width+pipe_distace+firstdistance,origin.y+15+CCRANDOM_0_1()*200));
	this->addChild(pipe_up2,0);
	pipe_down2=CCSprite::create("pipe_down.png");
	pipe_down2->setPosition(ccp(origin.x + visibleSize.width+pipe_distace+firstdistance,pipe_up2->getPositionY()+pipe_highdistance));
	this->addChild(pipe_down2,0);
	//��
    land1 = CCSprite::create("land.png");//336*112
	CCSize landSize=land1->getContentSize();//ͼƬ��С
	land1->setPosition(ccp(origin.x+landSize.width/2, origin.y+landSize.height/2));
    this->addChild(land1, 0);
    land2 = CCSprite::create("land.png");//336*112
    land2->setPosition(ccp(origin.x+landSize.width*3/2, origin.y+landSize.height/2));
    this->addChild(land2, 0);
	//����
	score0001=CCSprite::create();
	score0010=CCSprite::create();
	score0100=CCSprite::create();
	score1000=CCSprite::create();

	score0001->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2+130));
	this->addChild(score0001,1);
	score0010->setPosition(ccp(origin.x + visibleSize.width/2-25,origin.y + visibleSize.height/2+130));
	this->addChild(score0010,1);
	score0100->setPosition(ccp(origin.x + visibleSize.width/2-50,origin.y + visibleSize.height/2+130));
	this->addChild(score0100,1);
	score1000->setPosition(ccp(origin.x + visibleSize.width/2-75,origin.y + visibleSize.height/2+130));
	this->addChild(score1000,1);
	//
	this->setTouchEnabled(true);//������Ļ�����¼�
	this->unscheduleUpdate();//������֡
    return true;
}

//�����ȶ������
CCAnimate* HelloWorld::creatBirdAnimate(){
	int iFrameNum=3;
	CCSpriteFrame* frame=NULL;
	CCArray* frameArray=CCArray::create();

	for(int i=0;i<iFrameNum;i++){
		frame=CCSpriteFrame::create(CCString::createWithFormat("bird0_%d.png",i)->getCString(),
									CCRectMake(0,0,48,48));
		frameArray->addObject(frame);
	}
	CCAnimation* animation=CCAnimation::createWithSpriteFrames(frameArray);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.15f);
	CCAnimate* action=CCAnimate::create(animation);
	return action;
}
//��ȡ��͹ܵ��ľ���
CCRect HelloWorld::getBird0_0Rect(float a,float b){
	CCPoint birdPoint=bird0_0->getPosition();
	CCSize birdSize=bird0_0->getContentSize();
	return CCRect(birdPoint.x-birdSize.width/2+a,birdPoint.y-birdSize.height/2+b,birdSize.width-2*a,birdSize.height-2*b);
}
CCRect HelloWorld::getPipedown1Rect(){
	CCPoint Pipedown1Point=pipe_down1->getPosition();
	CCSize Pipedown1Size=pipe_down1->getContentSize();
	return CCRect(Pipedown1Point.x-Pipedown1Size.width/2,Pipedown1Point.y-Pipedown1Size.height/2,
					Pipedown1Size.width,Pipedown1Size.height);
}
CCRect HelloWorld::getPipeup1Rect(){
	CCPoint Pipeup1Point=pipe_up1->getPosition();
	CCSize Pipedup1Size=pipe_up1->getContentSize();
	return CCRect(Pipeup1Point.x-Pipedup1Size.width/2,Pipeup1Point.y-Pipedup1Size.height/2,
					Pipedup1Size.width,Pipedup1Size.height);
}
CCRect HelloWorld::getPipedown2Rect(){
	CCPoint Pipedown2Point=pipe_down2->getPosition();
	CCSize Pipedown2Size=pipe_down2->getContentSize();
	return CCRect(Pipedown2Point.x-Pipedown2Size.width/2,Pipedown2Point.y-Pipedown2Size.height/2,
					Pipedown2Size.width,Pipedown2Size.height);
}
CCRect HelloWorld::getPipeup2Rect(){
	CCPoint Pipeup2Point=pipe_up2->getPosition();
	CCSize Pipedup2Size=pipe_up2->getContentSize();
	return CCRect(Pipeup2Point.x-Pipedup2Size.width/2,Pipeup2Point.y-Pipedup2Size.height/2,
					Pipedup2Size.width,Pipedup2Size.height);
}
//��ײ���
bool HelloWorld::isCollideWithPipe(){
	CCRect bird0_0Rect=getBird0_0Rect(18,18);
	CCRect pipedown1Rect=getPipedown1Rect();
	CCRect pipeup1Rect=getPipeup1Rect();
	CCRect pipedown2Rect=getPipedown2Rect();
	CCRect pipeup2Rect=getPipeup2Rect();
	
	return bird0_0Rect.intersectsRect(pipedown1Rect)||
		   bird0_0Rect.intersectsRect(pipeup1Rect)||
		   bird0_0Rect.intersectsRect(pipedown2Rect)||
		   bird0_0Rect.intersectsRect(pipeup2Rect); 
}
bool HelloWorld::isCollideWithLand(){
	CCRect bird0_0Rect=getBird0_0Rect(6,6);
	bool isBlowland=bird0_0Rect.containsPoint(ccp(bird0_0->getPositionX(),land1->getPositionY()+land1->getContentSize().height/2));
	return isBlowland;
}

//��Ļ������ʼ
bool HelloWorld::ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent){
	//CCLOG("HelloWorldScene touch! ");
	bird0_0->stopAction(pAction);
	SimpleAudioEngine::sharedEngine()->playEffect("sfx_wing.wav");
	if(firstTouch==false){
		this->scheduleUpdate();//��ʼÿһ֡ˢ��
		firstTouch=true;
		tutorial->removeFromParent();
		text_ready->removeFromParent();
		
	}

	CCMoveBy* moveby=CCMoveBy::create(0.16f,ccp(0,85));
	CCEaseOut* easeout=CCEaseOut::create(moveby,1.5);
	CCRotateTo* rotateto=CCRotateTo::create(0.05f,-30,-30);
	CCEaseOut* easeout2=CCEaseOut::create(rotateto,1.5);
	CCAnimate* swingAction=creatBirdAnimate();//�ȶ����

	pAction=CCSpawn::create(swingAction,easeout,easeout2,NULL);
	bird0_0->runAction(pAction);
	return true;
}
//��Ļ�����ƶ�
void HelloWorld::ccTouchMoved(CCTouch* pTouch,CCEvent* pEvent){
	//CCLOG("HelloWorldScene touch! Moved!");
}
//��Ļ��������
void HelloWorld::ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent){

	bird0_0->stopAction(pAction);
	CCMoveTo* moveto=CCMoveTo::create(1.2f,ccp(bird0_0->getPositionX(),-210));
	CCEaseIn* easein=CCEaseIn::create(moveto,2.4f);
	CCRotateTo* rotateto=CCRotateTo::create(1.05f,90,90);
	CCEaseIn* easein2=CCEaseIn::create(rotateto,0.7f);
	CCAnimate* swingAction=creatBirdAnimate();//�ȶ����
	pAction=CCSpawn::create(swingAction,easein,easein2,NULL);
	bird0_0->runAction(pAction);
	
	//CCLOG("%d",score);
}
void HelloWorld::registerWithTouchDispatcher(void){
	//CCLayer::registerWithTouchDispatcher();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
}
void HelloWorld::update(float delta){

	//��ײ���
	if(isCollideWithPipe()||isCollideWithLand()){
		SimpleAudioEngine::sharedEngine()->playEffect("sfx_hit.wav");
		
		gameOver();
		return;
	}
	//��������γɵ�ͼ���޵ļ���
	//��������
	float landx1=land1->getPositionX();
	float landx2=land2->getPositionX();
	float speed=2.0;
	landx1-=speed;
	landx2-=speed;
	CCSize landSize=land1->getContentSize();
	if(landx1<=-landSize.width/2){
		landx1=landSize.width*3.0f/2;
	}
	if(landx2<=-landSize.width/2){
		landx2=landSize.width*3.0f/2;
	}
	land1->setPositionX(landx1);
	land2->setPositionX(landx2);
	//���¹ܵ�
	float pipex1=pipe_up1->getPositionX();
	float pipey1=pipe_up1->getPositionY();
	float pipex2=pipe_up2->getPositionX();
	float pipey2=pipe_up2->getPositionY();
	pipex1-=speed;
	pipex2-=speed;

	CCSize pipeSize=pipe_down1->getContentSize();
	if(pipex1<=-pipeSize.width/2){//��ܵ���ȫ�뿪��Ұʱ�������趨��ܵ�λ�ô�����Ļ�Ҳ�
		pipex1=pipeSize.width/2.0f+visibleSize.width;
		pipey1=15+CCRANDOM_0_1()*200;//����趨�ܵ�y����
	}
	if(pipex2<=-pipeSize.width/2){
		pipex2=pipeSize.width/2.0f+visibleSize.width;
		pipey2=15+CCRANDOM_0_1()*200;
	}
	pipe_down1->setPositionX(pipex1);
	pipe_up1->setPositionX(pipex1);

	pipe_down1->setPositionY(pipey1+pipe_highdistance);
	pipe_up1->setPositionY(pipey1);

	pipe_down2->setPositionX(pipex2);
	pipe_up2->setPositionX(pipex2);

	pipe_down2->setPositionY(pipey2+pipe_highdistance);
	pipe_up2->setPositionY(pipey2);
	//���·���
	calScore();
}
//���·���
void HelloWorld::calScore(){
	if(int(pipe_up1->getPositionX())==int(bird0_0->getPositionX())||
		int(pipe_up2->getPositionX())==int(bird0_0->getPositionX())){
			SimpleAudioEngine::sharedEngine()->playEffect("sfx_point.wav");
			score++;
			unsigned int s0001,s0010,s0100,s1000;
			s0001=score%10;
			s0010=score/10%10;
			s0100=score/100%10;
			s1000=score/1000;
			score0001->initWithFile(CCString::createWithFormat("font_0%d.png",s0001+48)->getCString());
			if(score>=10){
				score0010->initWithFile(CCString::createWithFormat("font_0%d.png",s0010+48)->getCString());
			}
			if(score>=100){
				score0100->initWithFile(CCString::createWithFormat("font_0%d.png",s0100+48)->getCString());
			}
			if(score>=1000){
				score1000->initWithFile(CCString::createWithFormat("font_0%d.png",s1000+48)->getCString());
			}
	}
}
///////////////////////////
void HelloWorld::saveBestScore(){
	//�ж�����
	int tmp=CCUserDefault::sharedUserDefault()->getIntegerForKey("bestScoreData",0);
	if(tmp){
	   //�д浵
	   if(highestScore>tmp) CCUserDefault::sharedUserDefault()->setIntegerForKey("bestScoreData",highestScore);

	}else{
	   //û�浵
	   CCUserDefault::sharedUserDefault()->setIntegerForKey("bestScoreData",highestScore);
	   //����
	   CCUserDefault::sharedUserDefault()->flush();
	}
}

///////////////////////
void HelloWorld::gameOver(){
	this->unscheduleUpdate();//�ر�ÿһ֡��update
	this->setTouchEnabled(false);//�ر���Ļ��������
	bird0_0->stopAction(pAction);//ֹͣ����

	//������ײ���ѡ����Ķ���
	if(isCollideWithPipe()){
		CCMoveTo* moveto=CCMoveTo::create(0.42f,
								ccp(bird0_0->getPositionX(),
								land1->getPositionY()+land1->getContentSize().height/2+14));
		CCEaseIn* easein=CCEaseIn::create(moveto,2.4f);//������ת
		CCRotateTo* rotateto=CCRotateTo::create(0.1f,90,90);
		CCEaseIn* easein2=CCEaseIn::create(rotateto,1.7f);//��������
		pAction=CCSpawn::create(easein,easein2,NULL);
		SimpleAudioEngine::sharedEngine()->playEffect("sfx_die.wav");
	}
	else if(isCollideWithLand()){
		pAction=CCRotateTo::create(0.0f,90,90);
	}else;
	bird0_0->runAction(pAction);
	showScoreBoard();
	score=0;//��������
}
//��ʾ�������
void HelloWorld::showScoreBoard(){
	//�������¿�ʼ��ť
	pReplayItem=CCMenuItemImage::create("button_play.png",
									    "button_play.png",
										this,
										menu_selector(HelloWorld::menuReplayCallback));
	pReplayItem->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2-85));
	//�����뿪��Ϸ��ť
	pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    pMenu = CCMenu::create(pReplayItem,pCloseItem,NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
	//����Ƿְ��
	scoreBoard=CCSprite::create("score_panel.png");
	scoreBoard->setPosition(ccp(origin.x+visibleSize.width/2,origin.y-100));
	this->addChild(scoreBoard,1);
	CCMoveTo* scoreBoardMoveTo=CCMoveTo::create(0.5f,ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	scoreBoard->runAction(scoreBoardMoveTo);
	//�������շ���
	finalScore=CCLabelTTF::create(CCString::createWithFormat("%d",score)->getCString(),"Arial", 20);
	finalScore->setPosition(ccp(origin.x+visibleSize.width/2+75,origin.y-100));
	finalScore->setColor(ccBLUE);
	CCMoveTo* finalScoreMoveTo=CCMoveTo::create(0.5f,ccp(origin.x+visibleSize.width/2+75,origin.y+visibleSize.height/2+18));
	this->addChild(finalScore,1);
	finalScore->runAction(finalScoreMoveTo);
	//����
	if(score>=threeScore[0]){
		threeScore[2]=threeScore[1];
		threeScore[1]=threeScore[0];
		threeScore[0]=score;
		rank=1;
	}else if(score>=threeScore[1]){
		threeScore[2]=threeScore[1];
		threeScore[1]=score;
		rank=2;
	}else if(score>=threeScore[2]){
		threeScore[2]=score;
		rank=3;
	}else rank=0;

	medal=CCSprite::create(CCString::createWithFormat("medals_%d.png",rank)->getCString());
	medal->setPosition(ccp(origin.x+visibleSize.width/2-65,origin.y+visibleSize.height+100));
	CCMoveTo* medalMoveTo=CCMoveTo::create(0.5f,ccp(origin.x+visibleSize.width/2-65,origin.y+visibleSize.height/2-5));
	this->addChild(medal,1);
	medal->runAction(medalMoveTo);	
	//
	if(score>highestScore){
		highestScore=score;
		saveBestScore();//���´洢��߷�
		CCSprite *newpng=CCSprite::create("new.png");
		newpng->setPosition(ccp(origin.x+visibleSize.width/2+52,origin.y-100));
		CCMoveTo* bestScoreMoveTo=CCMoveTo::create(0.5f,ccp(origin.x+visibleSize.width/2+52,origin.y+visibleSize.height/2-20));
		this->addChild(newpng,1);
		newpng->runAction(bestScoreMoveTo);
	}
	//��߷�
	bestScore=CCLabelTTF::create(CCString::createWithFormat("%d",highestScore)->getCString(),"Arial", 20);
	bestScore->setPosition(ccp(origin.x+visibleSize.width/2+75,origin.y-100));
	bestScore->setColor(ccBLUE);
	CCMoveTo* bestScoreMoveTo=CCMoveTo::create(0.5f,ccp(origin.x+visibleSize.width/2+75,origin.y+visibleSize.height/2-20));
	this->addChild(bestScore,1);
	bestScore->runAction(bestScoreMoveTo);
	//gameoverͼƬ
	gameOverImage=CCSprite::create("text_game_over.png");
	gameOverImage->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2+200));
	this->addChild(gameOverImage,1);
}
//������Ϸ
void HelloWorld::menuReplayCallback(CCObject* pSender){
	firstTouch=false;
	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}
//�ر���Ϸ
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
/*
void HelloWorld::ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent){
	CCTouch* touch=static_cast<CCTouch* >(pTouches->anyObject());
	CCPoint pos1=touch->getLocation();//3D����
	CCPoint pos2=touch->getLocationInView();//2D�������Ͻ�ԭ��
	CCPoint pos3=CCDirector::sharedDirector()->convertToUI(pos2);//ת��Ϊcocos2dxʹ�õ����½�ԭ�㣬�ѿ���
	CCLOG("HelloWorldScene touch! pos1 x=%f,y=%f",pos1.x,pos1.y);
	CCLOG("HelloWorldScene touch! pos2 x=%f,y=%f",pos2.x,pos2.y);
	CCLOG("HelloWorldScene touch! pos3 x=%f,y=%f",pos3.x,pos3.y);

}//��Ļ������ʼ
void HelloWorld::ccTouchesMoved(CCSet* pTouches,CCEvent* pEvent){
	CCLOG("HelloWorldScene touch! Moved!");
}//��Ļ�����ƶ�
void HelloWorld::ccTouchesEnded(CCSet* pTouches,CCEvent* pEvent){
	CCLOG("HelloWorldScene touch! Ended!");
}//��Ļ��������
void HelloWorld::ccTouchesCancelled(CCSet* pTouches,CCEvent* pEvent){
	CCLOG("HelloWorldScene touch! Cancelled!");
}//��ϴ����¼���ϵͳ����Ϣ�����绰��
*/

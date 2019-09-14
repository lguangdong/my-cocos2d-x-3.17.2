

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include<string>

USING_NS_CC;
HelloWorld::HelloWorld() {
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUME; j++) {
			m_pSquare[i][j] = NULL;
		}
	}
	//构造的时候获取一个方块类型
	newSquareType();
}
HelloWorld::~HelloWorld() {

}
Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
};

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	auto sizeOverLayer = Director::getInstance()->getWinSize();
	LayerColor* maskColorLayer = LayerColor::create(ccc4(255, 255, 255, 255));
	this->addChild(maskColorLayer);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
	//添加一个分数显示板
	char buf[4] = "0"; //初始值
	CCLabelTTF* m_pLabel = CCLabelTTF::create(buf, "arial", 15);
	m_pLabel->setColor(ccColor3B(0, 0, 0));
	m_pLabel->setAnchorPoint(Vec2(0, 0));
	m_pLabel->setPosition(Vec2(origin.x + 100,origin.y+100)); 
	this->addChild(m_pLabel, 1);

	//初始化格子
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUME; j++) {
			m_pSquare[i][j] = CCSprite::create("square.png");
			m_pSquare[i][j]->setPosition(CCDirector::sharedDirector()->convertToGL(ccp(j * 20 + j * 2 + 10, i * 20 + i * 2 + 10)));
			m_pSquare[i][j]->setName(0);
			m_pSquare[i][j]->setColor(ccColor3B(255, 255, 255));
			this->addChild(m_pSquare[i][j]);
		}
	}

    return true;
}
void HelloWorld::newSquareType() {
	m_nCurSquareType = rand() % 19 + 1;  //获取一个1~19范围内的随机数
	CCLOG("new type: %d",m_nCurSquareType);
	switch (m_nCurSquareType) {
	case 1:
	case 3:
	case 4:
	case 9:
	case 10:
	case 11:
	case 12:
	case 15:
	case 16:
		m_nCurLine = 0;
		m_nCurColume = 3;
		break;
	case 2:
	case 5:
	case 6:
	case 7:
	case 8:
	case 13:
	case 14:
	case 17:
	case 18:
	case 19:
		m_nCurLine = 0;
		m_nCurColume = 4;
		break;
	}
 }
void HelloWorld::updateDown(float dt) {
	
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}



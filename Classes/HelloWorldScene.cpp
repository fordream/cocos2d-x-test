#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Director::getInstance()->setDisplayStats(false);
    count = 0;


    label = Label::createWithTTF("はろーわーるど", "fonts/Hiragino_mincho.otf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);


    auto label1 = Label::createWithTTF("左上", "fonts/Hiragino_mincho.otf", 24);
    label1->setAnchorPoint(Vec2(0, 1));
    label1->setPosition(origin.x, origin.y + visibleSize.height);
    this->addChild(label1, 1);

    auto label2 = Label::createWithTTF("右上", "fonts/Hiragino_mincho.otf", 24);
    label2->setAnchorPoint(Vec2(1, 1));
    label2->setPosition(origin.x + visibleSize.width, origin.y + visibleSize.height);
    this->addChild(label2, 1);

    auto label3 = Label::createWithTTF("左下", "fonts/Hiragino_mincho.otf", 24);
    label3->setAnchorPoint(Vec2(0, 0));
    label3->setPosition(origin.x, origin.y);
    this->addChild(label3, 1);

    auto label4 = Label::createWithTTF("右下", "fonts/Hiragino_mincho.otf", 24);
    label4->setAnchorPoint(Vec2(1, 0));
    label4->setPosition(origin.x + visibleSize.width, origin.y);
    this->addChild(label4, 1);

    auto label5 = Label::createWithTTF("中央", "fonts/Hiragino_mincho.otf", 24);
    label5->setAnchorPoint(Vec2(0.5, 0.5));
    label5->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    this->addChild(label5, 1);



    // add "HelloWorld" splash screen"
    sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

    auto slistener = EventListenerTouchOneByOne::create();
    slistener->onTouchBegan = [this](cocos2d::Touch *touch, cocos2d::Event *event)-> bool {
        Point p = touch->getLocation();
        Rect r = sprite->boundingBox();
        if (r.containsPoint(p)) {
            sprite->setVisible(false);
        }
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(slistener, this);

    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
//    listener->onTouchBegan = [this](cocos2d::Touch *touch, cocos2d::Event *event)->bool {
//        auto str = String::create("No, ");
//        str->appendWithFormat("%i", count++);
//        label->setString(str->getCString());
//        return true;
//    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


    return true;
}


bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
    auto str = String::create("No, ");
    str->appendWithFormat("%i", count++);
    label->setString(str->getCString());
    return true;
}
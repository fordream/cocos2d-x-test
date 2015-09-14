//
//  HelloGravity.cpp
//  Cocostest
//
//  Created by KeigoOgawa on 9/9/15.
//
//

#include "HelloGravity.h"

using namespace cocos2d;

Scene* HelloGravity::createScene() {
	auto scene = Scene::createWithPhysics();
    PhysicsWorld* world = scene->getPhysicsWorld();
    world->setGravity(Vec2(0, -500));
    world->setSpeed(1.0f);
    world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = HelloGravity::create();
	scene->addChild(layer);
	
    return scene;
}

bool HelloGravity::init() {
    if (!Layer::init()) {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Director::getInstance()->setDisplayStats(false);

    auto material = PHYSICSBODY_MATERIAL_DEFAULT;
    material.density = 1.0f;
    material.restitution = 1.0f;
    material.friction = 0.5f;

    sprite1 = Sprite::create("asiba.png");
    sprite1->setPosition(origin.x + visibleSize.width/2, origin.y + 100);
    this->addChild(sprite1, 1);

    auto baseBody = PhysicsBody::createBox(sprite1->getContentSize(), material);
    baseBody->setDynamic(false);
    baseBody->setRotationEnable(false);
    baseBody->setCategoryBitmask(1);
    baseBody->setCollisionBitmask(1);
    baseBody->setContactTestBitmask(1);
    sprite1->setPhysicsBody(baseBody);

    sprite1->setScaleX(2.0);
    sprite1->setRotation(10.0f);

    sprite2 = Sprite::create("character.png");
    sprite2->setPosition(origin.x + visibleSize.width/2, origin.y + 300);
    this->addChild(sprite2, 1);

    auto charBody = PhysicsBody::createCircle(sprite2->boundingBox().size.width/2, material);
    charBody->setMass(10.0f);
    charBody->setDynamic(true);
    charBody->setRotationEnable(true);
    charBody->setCategoryBitmask(1);
    charBody->setCollisionBitmask(1);
    charBody->setContactTestBitmask(1);
    sprite2->setPhysicsBody(charBody);

    auto listener = EventListenerPhysicsContact::create();
    listener->onContactBegin = [this](PhysicsContact &contact)-> bool {
        auto nodeA = contact.getShapeA()->getBody()->getNode();
        auto nodeB = contact.getShapeB()->getBody()->getNode();
        nodeA->removeFromParent();
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}
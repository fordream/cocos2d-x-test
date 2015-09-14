//
//  HelloGravity.h
//  Cocostest
//
//  Created by KeigoOgawa on 9/9/15.
//
//

#ifndef __Cocostest__HelloGravity__
#define __Cocostest__HelloGravity__

#include "cocos2d.h"

class HelloGravity : public cocos2d::Layer
{
private:
    cocos2d::Sprite* sprite1;
    cocos2d::Sprite* sprite2;
public:
    virtual bool init();
    static cocos2d::Scene *createScene();
    CREATE_FUNC(HelloGravity);
};

#endif /* defined(__Cocostest__HelloGravity__) */
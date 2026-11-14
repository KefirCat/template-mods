#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(FPSPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }
        
        // Переводим камеру в чистый 2D-режим без лишних расчетов глубины (снижает нагрузку на GPU и CPU)
        if (auto* director = cocos2d::CCDirector::sharedDirector()) {
            director->setProjection(cocos2d::kCCDirectorProjection2D);
        }
        
        log::info("FPS Boost activated for level!");
        return true;
    }
};

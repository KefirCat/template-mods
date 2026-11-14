#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(FPSPlayLayer, PlayLayer) {
    void update(float dt) {
        PlayLayer::update(dt);
        // Ограничиваем количество активных частиц на уровне для повышения FPS
        if (this->m_particleSystems) {
            for (auto* ps : CCArrayExt<cocos2d::CCParticleSystem*>(this->m_particleSystems)) {
                if (ps && ps->getTotalParticles() > 35) {
                    ps->setTotalParticles(35);
                }
            }
        }
    }
};

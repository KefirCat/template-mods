#include <Geode/Geode.hpp>
#include <Geode/modify/CCParticleSystem.hpp>

using namespace geode::prelude;

class $modify(SmartParticles, cocos2d::CCParticleSystem) {
    bool initWithTotalParticles(unsigned int numberOfParticles) {
        if (numberOfParticles > 35) {
            numberOfParticles = 35;
        }
        return CCParticleSystem::initWithTotalParticles(numberOfParticles);
    }
};

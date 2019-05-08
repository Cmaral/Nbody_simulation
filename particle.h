#ifndef PARTICLE_H
#define PARTICLE_H


#include "glm/glm.hpp"

#define STAR_TEXTURE_SIZE 16

class Particle
{
public:
    Particle();

    float getMass() const;
    void setMass(float value);

    float getRadius() const;
    void setRadius(float value);

    void calculateStep(float deltaTime);

    glm::vec3 getPosition() const;
    void setPosition(const glm::vec3 &value);

    glm::vec3 getVelocity() const;
    void setVelocity(const glm::vec3 &value);

    glm::vec3 getForce() const;
    void setForce(const glm::vec3 &value);

private:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 force;
    float mass;
    float radius;

};

#endif // PARTICLE_H

#include "particle.h"

static float* load_star_texture() {
    float* texture = (float *)calloc(STAR_TEXTURE_SIZE * STAR_TEXTURE_SIZE, sizeof(float));
    float radius = ((float) STAR_TEXTURE_SIZE) / 2.0f;
    float sigma_2 = 8.0f;

    for (size_t i = 0; i < STAR_TEXTURE_SIZE; ++i) {
        for (size_t j = 0; j < STAR_TEXTURE_SIZE; ++j) {
            float x = ((float) i) - radius;
            float y = ((float) j) - radius;

            float exponent = ((x * x) / (2.0f * sigma_2)) + ((y * y) / (2.0f * sigma_2));
            float alpha = expf(-exponent);

            size_t index = i + (STAR_TEXTURE_SIZE * j);
            texture[index] = alpha;
        }
    }
    return texture;
}

Particle::Particle()
{
    this->velocity = glm::vec3(0.0f,0.0f,0.0f);
    this->position = glm::vec3(0.0f,0.0f,0.0f);
    this->force= glm::vec3(0.0f,0.0f,0.0f);

    this->mass = 0.5f;
    this->radius = 1.0f;

}

void Particle::calculateStep(float deltaTime){
    this->velocity += (this->force/this->mass)*deltaTime;
    this->position += this->velocity*deltaTime;
}




/* GETTERS AND SETTERS
 */
float Particle::getMass() const
{
    return mass;
}

void Particle::setMass(float value)
{
    mass = value;
}


float Particle::getRadius() const
{
    return radius;
}

void Particle::setRadius(float value)
{
    radius = value;
}

glm::vec3 Particle::getPosition() const
{
    return position;
}

void Particle::setPosition(const glm::vec3 &value)
{
    position = value;
}

glm::vec3 Particle::getVelocity() const
{
    return velocity;
}

void Particle::setVelocity(const glm::vec3 &value)
{
    velocity = value;
}

glm::vec3 Particle::getForce() const
{
    return force;
}

void Particle::setForce(const glm::vec3 &value)
{
    force = value;
}

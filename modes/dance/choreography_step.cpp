#include "choreography_step.h"

ChoreographyStep::ChoreographyStep(int left_engine, int right_engine, unsigned long duration_ms) : left_engine(
        left_engine), right_engine(right_engine), duration_ms(duration_ms) {}

int ChoreographyStep::getLeftEngine() const {
    return this->left_engine;
}

int ChoreographyStep::getRightEngine() const {
    return this->right_engine;
}

unsigned long ChoreographyStep::getDurationMs() const {
    return this->duration_ms;
}

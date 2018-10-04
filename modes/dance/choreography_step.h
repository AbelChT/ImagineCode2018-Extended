#pragma once

class ChoreographyStep {
private:
    int left_engine, right_engine;
    unsigned long duration_ms;
public:
    ChoreographyStep(int left_engine, int right_engine, unsigned long duration_ms);

    int getLeftEngine() const;

    int getRightEngine() const;

    unsigned long getDurationMs() const;
};

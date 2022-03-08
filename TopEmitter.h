#pragma once
#include "Emitter.h"
class TopEmitter : public Emitter
{
public:
	int width;
	TopEmitter(int width);
	void ResetParticle(Particle& particle) override;
};


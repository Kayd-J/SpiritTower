#include "Spectrum.h"

Spectrum::Spectrum()
{
}

int Spectrum::getSrch_speed() const
{
	return srch_speed;
}

void Spectrum::setSrch_speed(int srch_speed_)
{
	srch_speed = srch_speed_;
}

int Spectrum::getChase_speed() const
{
	return chase_speed;
}

void Spectrum::setChase_speed(int chase_speed_)
{
	chase_speed = chase_speed_;
}

int Spectrum::getRange() const
{
	return range;
}

void Spectrum::setRange(int range_)
{
	range = range_;
}

int Spectrum::getExtra() const
{
	return extra;
}

void Spectrum::setExtra(int extra_)
{
	extra = extra_;
}

string Spectrum::getId() const
{
	return id;
}

void Spectrum::setId(string id_)
{
	id = id_;
}

int Spectrum::getFitness() const
{
	return fitness;
}

void Spectrum::setFitness()
{
	fitness = srch_speed + chase_speed + range + extra;
}

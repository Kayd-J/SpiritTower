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

string Spectrum::getId() const{
	return idGen.substr(0, 1);
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
	fitness = srch_speed + chase_speed + range;
	if ((srch_speed == 0) || (chase_speed == 0) || (range == 0)) {
		fitness -= 2;
	}
}

string Spectrum::getIdGen() const
{
	return idGen;
}

void Spectrum::setIdGen(string idgen_)
{
	idGen = idgen_;
}


#include "stdafx.h"
#include "CircleInfo.h"

CircleInfo::CircleInfo(){}

CircleInfo::CircleInfo(int nCenterX, int nCenterY, int nRadius)
{
	m_CenterX = nCenterX;
	m_CenterY = nCenterY;
	m_Radius = nRadius;
}


void CircleInfo::set_params(int nCenterX, int nCenterY, int nRadius)
{
	m_CenterX = nCenterX;
	m_CenterY = nCenterY;
	m_Radius = nRadius;
}

int CircleInfo::get_centerX()
{
	return m_CenterX;
}

int CircleInfo::get_centerY()
{
	return m_CenterY;
}

int CircleInfo::get_radius()
{
	return m_Radius;
}

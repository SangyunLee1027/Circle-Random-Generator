#pragma once

class CircleInfo {
public:
	CircleInfo();
	CircleInfo(int m_CenterX, int m_CenterY, int m_Radius);
	
	void set_params(int nCenterX, int nCenterY, int nRadius);

	int get_centerX();
	int get_centerY();
	int get_radius();

private:
	int m_CenterX;
	int m_CenterY;
	int m_Radius;

};

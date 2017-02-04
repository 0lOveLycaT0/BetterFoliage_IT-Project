#pragma once

class Weather;

class Dimension
{
public:
	float getFogDistanceScale(void)const;
	Color getSkyColor(Entity const&,float);
	Color getSunriseColor(float)const;
	float getStarBrightness(float);
	unsigned int getBrightnessRamp(float)const;
	bool isNaturalDimension(void)const;
	Weather* getWeather()const;
};

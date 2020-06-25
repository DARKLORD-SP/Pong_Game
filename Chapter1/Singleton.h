#pragma once

class Singleton
{
public:
	static Singleton* instance;

	static Singleton* GetInstance();

};


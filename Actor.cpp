#include "Actor.h"
#include <iostream>

using namespace std;
AActor::AActor()
{
	HP = 100;
}

AActor::~AActor()
{
}

void AActor::Move()
{
	cout << "ÀÌµ¿" << endl;
}

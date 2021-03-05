#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"

class Graphics;

class Player : public AnimatedSprite {
	public:
		Player();
		Player(Graphics& graphics, float x, float y);
		void draw(Graphics& graphics);
		void update(float elapsedTime);

			//moves the player left with -dx
		void moveLeft();
	
			//moves the player right with dx
		void moveRight();

			//stops moving the player
		void stopMoving();

		virtual void animationDone(std::string currentAnimation);
		virtual void setupAnimations();

	private:
		float _dx, _dy;
		Direction _facing;
};

#endif
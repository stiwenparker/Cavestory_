#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

	//class that hold logic for animated sprites

class AnimatedSprite : public Sprite {
	public:
		AnimatedSprite();
		AnimatedSprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
			float posX, float posY, float timeToUpdate);

			//plays the animation if not already played
		void playAnimation(std::string animation, bool once = false);

			//timer to update current animation
		void update(int elapsedTime);

			//draws the sprite to window
		void draw(Graphics& graphics, int x, int y);

	protected:
		double _timeToUpdate;
		bool _currentAnimationOnce;
		std::string _currentAnimation;



			//adds an anmiation to the animation map
		void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

			//resets all animation associated with that sprite
		void resetAnimations();

			//stops the animation
		void stopAnimation();

			//changes the visibility of animated sprite
		void setVisible(bool visible);

			//it gets called when animation is over
		virtual void animationDone(std::string currentAnimation) = 0;

			//function that set ups all animations for the sprite
		virtual void setupAnimations() = 0;

	private:

		std::map<std::string, std::vector<SDL_Rect> > _animations;
		std::map<std::string, Vector2> _offsets;

		int _frameIndex;
		double _timeElapsed;
		bool _visible;
};

#endif
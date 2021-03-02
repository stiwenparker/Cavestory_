#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

/* AnimatedSprite class
 * Holds logic for animating sprites
 */

class AnimatedSprite : public Sprite {
	public:
		AnimatedSprite();
		AnimatedSprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
			float posX, float posY, float timeToUpdate);

		/* void playAnimation
		 * Plays the animation provided if it's not already playing
		 */
		void playAnimation(std::string animation, bool once = false);

		/* void update
		 * Updates the animated sprite (timer)
		 */
		void update(int elapsedTime);

		/* void draw
		 * Draws the sprite to the screen
		 */
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
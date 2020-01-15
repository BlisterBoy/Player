/*
 * This file is part of EasyRPG Player.
 *
 * EasyRPG Player is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Player is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EP_GRAPHICS_H
#define EP_GRAPHICS_H

// Headers
#include <vector>
#include "bitmap.h"
#include "drawable.h"
#include "drawable_list.h"

class MessageOverlay;
class Scene;

/**
 * Graphics namespace.
 * Handles screen drawing.
 */
namespace Graphics {
	/**
	 * Initializes Graphics.
	 */
	void Init();

	/**
	 * Disposes Graphics.
	 */
	void Quit();

	/**
	 * Updates the screen.
	 */
	void Update();

	/**
	 * Resets the fps count.
	 * Don't call this. Use Player::FrameReset instead.
	 *
	 * @param start_ticks time in ticks
	 */
	void FrameReset(uint32_t start_ticks);

	/**
	 * Gets a bitmap with the actual contents of the screen.
	 * @return screen contents
	 */
	BitmapRef SnapToBitmap(int priority = Priority::Priority_Maximum);

	void Draw(Bitmap& dst);

	void UpdateSceneCallback();

	/**
	 * Gets target frame rate.
	 *
	 * @return target frame rate
	 */
	constexpr int GetDefaultFps() { return DEFAULT_FPS; }

	/**
	 * Returns a handle to the message overlay.
	 * Only used by Output to put messages.
	 *
	 * @return message overlay
	 */
	MessageOverlay& GetMessageOverlay();
}

#endif
